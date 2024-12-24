# -*- coding: utf-8 -*-
#!/usr/bin/env python3

import os
import sys
import time
import struct
import queue
import threading
import logging
import datetime

from PyQt5.QtWidgets import (
    QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel,
    QGridLayout, QCheckBox, QFrame, QGroupBox,
    QSpacerItem, QSizePolicy, QPushButton  
)
from PyQt5.QtGui import QFont, QPixmap
from PyQt5.QtCore import Qt, QTimer, QDateTime, QCoreApplication

from pymodbus.client import ModbusTcpClient as ModbusClient
from pymodbus.exceptions import ModbusIOException

import requests


# TCP Serial Server settings


TCP_IP = '10.85.5.13'
LOAD_CELL_PORT = 5005
ULTRASONIC_PORT = 5004
WEATHER_STATION_PORT = 5007
BALLONET_PRESSURE_PORT = 5002
HULL_PRESSURE_PORT = 5001
AHRS_PORT = 5003
TEMP_HUMIDITY_TCP_PORT = 5006

# Register details
LOAD_CELL_REGISTER = 0x9C40
ULTRASONIC_REGISTER = 0x0101
PRESSURE_SENSOR_REGISTER = 0x0004
WEATHER_REGISTERS = {
    "wind_direction": (0x0001, 1, 'int'),
    "wind_speed": (0x0002, 2, 'float'),
    "temperature": (0x0004, 2, 'float'),
    "humidity": (0x0006, 2, 'float'),
    "air_pressure": (0x0008, 2, 'float')
}
AHRS_GPS_REGISTERS = {
    'roll': 0x3D, 'pitch': 0x3E, 'yaw': 0x3F,
    'LonL': 0x49, 'LonH': 0x4A, 'LatL': 0x4B, 'LatH': 0x4C,
    'GPSHeight': 0x4D, 'GPSYAW': 0x4E, 'GPSVL': 0x4F, 'GPSVH': 0x50,
    'SVNUM': 0x55, 'PDOP': 0x56, 'HDOP': 0x57, 'VDOP': 0x58,
    'AccX': 0x35, 'AccY': 0x36, 'AccZ': 0x37
}
# Modbus registers for temperature and humidity
HUMIDITY_REGISTER = 0
TEMPERATURE_REGISTER = 1

PRESSURE_SCALING_FACTOR = 4.01463
LOAD_CELL_SCALING = 3.4
running = False

# Relay configuration
RELAY_IP = '10.85.5.12'
RELAY_PORT = 4196
RELAY_FUNCTIONS = {
    3: "Primary Blower",
    4: "Strobe Light 1",
    5: "Secondary Blower",
    6: "Strobe Light 2",
    7: "Payload Power"
}
class SensorReaderDashboard(QWidget):
    def __init__(self):
        super().__init__()
        self.relay_buttons = {}
        self.initUI()
        self.initSensors()
        self.client = ModbusClient(RELAY_IP, port=RELAY_PORT)  # Initialize relay client
        if not self.client.connect():
            print("Failed to connect to relay Modbus server.")
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.update_time_date)
        self.timer.start(1000)
        self.update_time_date()
        
        self.start_readings()
        self.stop_event = threading.Event()

           
    def initUI(self):
        self.setWindowTitle('AlfaCOR - Telemetry & Control Dashboard TCP Version')
        self.showFullScreen()
        self.setGeometry(100, 100, 1200, 800)
        self.setStyleSheet("""
            QWidget {background-color: #342800; color: #FFFFFF;}
            QLabel {font-family: 'Good Times'; font-size: 16px; padding: 10px; border: 2px solid #ac8400; border-radius: 8px; background-color: #342800;}
        """)

        layout = QVBoxLayout()
        layout.setContentsMargins(20, 20, 20, 20)
        
        header_layout = QHBoxLayout()
        logo_label = QLabel(self)
        logo_pixmap = QPixmap("/home/a6admin/Documents/logo.png")
        
        if not logo_pixmap.isNull():
            logo_pixmap = logo_pixmap.scaled(500, 100, Qt.KeepAspectRatio, Qt.SmoothTransformation)
            logo_label.setPixmap(logo_pixmap)
        else:
            logo_label.setText("Logo not found")

        logo_label.setAlignment(Qt.AlignCenter)
        header_layout.addWidget(logo_label)
        
        title = QLabel("AlfaOPS - Telemetry & Control Dashboard 1.0")
        title.setFont(QFont('Beklon', 18, QFont.Bold))
        title.setAlignment(Qt.AlignCenter)
        title.setStyleSheet("color: #FFFFFF; padding: 5px;")
        header_layout.addWidget(title)

        # AlfaCOR box for Temperature and Humidity with title
        alfa_box = QGroupBox("AlfaCOR")
        alfa_box.setStyleSheet("font-weight: bold; font-size: 16px; color: #FFFFFF; border: 2px solid #ac8400; border-radius: 5px; padding: 10px;")
        temp_humidity_box = QVBoxLayout()
        self.temp_label = QLabel("Temperature: -- °C")
        self.humidity_label = QLabel("Humidity: -- %")
        temp_humidity_box.addWidget(self.temp_label)
        temp_humidity_box.addWidget(self.humidity_label)
        alfa_box.setLayout(temp_humidity_box)

        header_layout.addWidget(alfa_box)

        header_layout.setStretch(0, 1)
        header_layout.setStretch(1, 4)
        
        self.time_date_label = QLabel()
        self.time_date_label.setFont(QFont('Arial', 14))
        self.time_date_label.setAlignment(Qt.AlignCenter)
        self.time_date_label.setStyleSheet("color: #f5ae78; padding: 5px;")
        layout.addWidget(self.time_date_label)
        layout.addLayout(header_layout)

        sensor_grid = QGridLayout()
        sensor_grid.setSpacing(10)
        
        layout.addLayout(sensor_grid)

        self.create_relay_controls(layout)  # Add relay controls section to layout

        layout.addSpacerItem(QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding))
        self.setLayout(layout)
        
        # Adding all sensor labels
        self.add_sensor_label("load_cell_tension", "Load Cell Tension:", "0.00 kg", sensor_grid, 0, 0)
        self.add_sensor_label("ultrasonic_distance", "Ballonet Curtain:", "0.00 m", sensor_grid, 6, 0)
        self.add_sensor_label("wind_direction", "Wind Direction:", "0°", sensor_grid, 1, 0)
        self.add_sensor_label("wind_speed", "Wind Speed:", "0.00 m/s", sensor_grid, 2, 0)
        self.add_sensor_label("temperature", "Temperature:", "0.00 °C", sensor_grid, 3, 0)
        self.add_sensor_label("humidity", "Humidity:", "0.00 %", sensor_grid, 4, 0)
        self.add_sensor_label("air_pressure", "Barometric Pressure:", "0.00 hPa", sensor_grid, 5, 0)
        self.add_sensor_label("roll", "Roll:", "0.00 °", sensor_grid, 0, 1)
        self.add_sensor_label("pitch", "Pitch:", "0.00 °", sensor_grid, 1, 1)
        self.add_sensor_label("yaw", "Yaw:", "0.00 °", sensor_grid, 2, 1)
        self.add_sensor_label("ballonet_pressure", "Ballonet Pressure:", "0.00 inWG", sensor_grid, 7, 0)
        self.add_sensor_label("hull_pressure", "Hull Pressure:", "0.00 inWG", sensor_grid, 8, 0)
        self.add_sensor_label("longitude", "Longitude:", "N/A", sensor_grid, 3, 1)
        self.add_sensor_label("latitude", "Latitude:", "N/A", sensor_grid, 4, 1)
        self.add_sensor_label("altitude", "Altitude:", "N/A", sensor_grid, 5, 1)
        self.add_sensor_label("heading", "Heading:", "N/A", sensor_grid, 8, 1)
        self.add_sensor_label("ground_speed", "Ground Speed:", "N/A", sensor_grid, 7, 1)
        self.add_sensor_label("position_accuracy", "Position Accuracy:", "N/A", sensor_grid, 6, 1)
        
        layout.addSpacerItem(QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding))
        self.setLayout(layout)

    def add_sensor_label(self, name, text, initial_value, layout, row, col):
        label = QLabel(text)
        value_label = QLabel(initial_value)
        value_label.setStyleSheet("font-weight: bold; font-size: 14px; padding: 5px; background-color: #3B4252; border-radius: 5px;")
        value_label.setFixedWidth(200)
        container = QHBoxLayout()
        container.addWidget(label)
        container.addWidget(value_label)
        layout.addLayout(container, row, col)
        setattr(self, f"{name}_value", value_label)

    def initSensors(self):
        self.load_cell_client = connect_client(TCP_IP, LOAD_CELL_PORT)
        self.ultrasonic_client = connect_client(TCP_IP, ULTRASONIC_PORT)
        self.weather_station_client = connect_client(TCP_IP, WEATHER_STATION_PORT)
        self.ahrs_client = connect_client(TCP_IP, AHRS_PORT)
        self.ballonet_pressure_client = connect_client(TCP_IP, BALLONET_PRESSURE_PORT)
        self.hull_pressure_client = connect_client(TCP_IP, HULL_PRESSURE_PORT)
        self.temp_humidity_client = connect_client(TCP_IP, TEMP_HUMIDITY_TCP_PORT)

    def start_readings(self):
        global running
        if not running:
            running = True

            # Define the threads correctly
            threads = [
                threading.Thread(target=self.read_load_cell, daemon=True),
                threading.Thread(target=self.read_ultrasonic, daemon=True),
                threading.Thread(target=self.read_weather_station, daemon=True),
                threading.Thread(target=self.read_ahrs_gps, daemon=True),
                threading.Thread(target=self.read_pressure_sensor, args=(self.ballonet_pressure_client, 'ballonet_pressure'), daemon=True),
                threading.Thread(target=self.read_pressure_sensor, args=(self.hull_pressure_client, 'hull_pressure'), daemon=True),
                threading.Thread(target=self.update_temp_humidity, daemon=True)
            ]

            # Start all threads
            for thread in threads:
                thread.start()

    def create_relay_controls(self, layout):
        """Creates relay controls in the UI."""
        # Relay group box with border and title styling
        relay_group = QGroupBox("Relay Controls")
        relay_group.setFont(QFont("Good Times", 14, QFont.Bold))
        relay_group.setStyleSheet("""
            QGroupBox {
                font-weight: bold;
                color: #FFFFFF;
                border: 2px solid #ac8400;
                border-radius: 5px;
                margin-top: 10px;
            }
            QGroupBox::title {
                subcontrol-origin: margin;
                subcontrol-position: top center;
            }
        """)

        # Layout for relay controls
        relay_layout = QGridLayout()

        # Define relay button configurations
        relay_configs = [
            {"name": "Primary Blower", "relay_num": 3},
            {"name": "Secondary Blower", "relay_num": 5},
            {"name": "Strobe Lights", "relay_nums": [4, 6]},  # Controls both relays 4 and 6
            {"name": "Payload Power", "relay_num": 7}
        ]

        # Create buttons based on configurations
        for idx, config in enumerate(relay_configs):
            button = QPushButton(f"{config['name']}: OFF")
            button.setCheckable(True)
            button.setStyleSheet("background-color: red; color: white;")

            # Set up click event for toggling the relay(s)
            if "relay_nums" in config:
                # Strobe Lights button to control both relays 4 and 6
                button.clicked.connect(lambda _, rns=config["relay_nums"], btn=button: self.toggle_multiple_relays(rns, btn))
            else:
                # Single relay control
                button.clicked.connect(lambda _, rn=config["relay_num"], btn=button: self.toggle_relay(rn, btn))

            # Add button to the grid layout
            relay_layout.addWidget(button, idx // 2, idx % 2)
            # Store button in the relay_buttons dictionary with a key based on the relay name
            self.relay_buttons[config["name"]] = button

        relay_group.setLayout(relay_layout)
        layout.addWidget(relay_group)

    def update_relay_status(self):
        """Updates the relay button statuses based on current relay states."""
        result = self.client.read_coils(0, 8)
        if not result.isError():
            # Iterate through each relay in RELAY_FUNCTIONS and update the corresponding button
            for relay_num, relay_name in RELAY_FUNCTIONS.items():
                button = self.relay_buttons.get(relay_name)  # Access button directly by relay name
                if button:
                    state = result.bits[relay_num - 1]
                    button.setChecked(state)
                    button.setText(f"{relay_name}: {'ON' if state else 'OFF'}")
                    button.setStyleSheet("background-color: green;" if state else "background-color: red;")

    def toggle_relay(self, relay_num, button):
        """Toggles a single relay ON/OFF."""
        current_state = button.isChecked()
        result = self.client.write_coil(relay_num - 1, current_state)
        if not result.isError():
            # Directly update button appearance
            button.setText(f"{button.text().split(':')[0]}: {'ON' if current_state else 'OFF'}")
            button.setStyleSheet("background-color: green;" if current_state else "background-color: red;")
        else:
            print(f"Error toggling relay {relay_num}.")
    
    def toggle_multiple_relays(self, relay_nums, button):
        """Toggles multiple relays on/off together."""
        current_state = button.isChecked()
        errors = []
        # Toggle each relay individually and collect errors
        for relay_num in relay_nums:
            result = self.client.write_coil(relay_num - 1, current_state)
            if result.isError():
                errors.append(relay_num)
                print(f"Error toggling relay {relay_num}.")
        if errors:
            print("Errors occurred for relays:", errors)

        # Directly update button appearance
        button.setText(f"{button.text().split(':')[0]}: {'ON' if current_state else 'OFF'}")
        button.setStyleSheet("background-color: green;" if current_state else "background-color: red;")

    def update_temp_humidity(self):
        """Fetch and display the AlfaCOR temperature and humidity continuously."""
        while running:
            try:
                # Read Humidity
                humidity_response = self.temp_humidity_client.read_holding_registers(HUMIDITY_REGISTER, 1)
                if not humidity_response.isError():
                    humidity_value = humidity_response.registers[0] / 10.0  # Assuming scaling by 10
                    self.humidity_label.setText(f"Humidity: {humidity_value:.1f} %")
                else:
                    self.humidity_label.setText("Humidity: Error")

                # Read Temperature
                temperature_response = self.temp_humidity_client.read_holding_registers(TEMPERATURE_REGISTER, 1)
                if not temperature_response.isError():
                    temperature_value = temperature_response.registers[0] / 10.0  # Assuming scaling by 10
                    self.temp_label.setText(f"Temperature: {temperature_value:.1f} °C")
                else:
                    self.temp_label.setText("Temperature: Error")
                
            except Exception as e:
                self.humidity_label.setText("Humidity: Error")
                self.temp_label.setText("Temperature: Error")
                print(f"Error reading temperature or humidity: {e}")
        
            # Add a delay to prevent continuous polling
            time.sleep(1)

    def read_load_cell(self):
        """Reads data from the load cell and updates the weight display."""
        while running:
            try:
                # Read two registers (16 bits each) from the load cell
                response = self.load_cell_client.read_holding_registers(LOAD_CELL_REGISTER, 2, slave=1)

                # Ensure the response is valid and contains two registers
                if not response.isError() and len(response.registers) == 2:
                    high_value, low_value = response.registers

                    # Perform the weight calculation with scaling adjustment
                    differential_value = high_value - low_value
                    max_raw_value = 0xFFFF  # 16-bit max value
                    scaling_adjustment = -3.4  # Adjustable scaling factor
                    max_weight = 2000  # Maximum weight in kg

                    # Calculate the weight in kilograms
                    adjusted_max_weight = max_weight * scaling_adjustment
                    weight = (differential_value / max_raw_value) * adjusted_max_weight

                    # Update the display label with the calculated weight
                    self.update_label(self.load_cell_tension_value, f"{weight:06.2f} kg")
                else:
                    logging.error(f"Invalid load cell response: {response.registers}")
                    self.update_label(self.load_cell_tension_value, "Error")

            except Exception as e:
                # Log any exceptions that occur and display an error message
                logging.error(f"Error reading load cell data: {e}")
                self.update_label(self.load_cell_tension_value, "Error")

            # Add a small delay to avoid excessive polling
            time.sleep(0.2)


    def read_ultrasonic(self):
        while running:
            try:
                response = self.ultrasonic_client.read_holding_registers(ULTRASONIC_REGISTER, 1, slave=1)
                if not response.isError():
                    distance = response.registers[0] / 1000.0  # Converted to meters
                    self.update_label(self.ultrasonic_distance_value, f"{distance:.2f} m")
                    
            except:
                 self.update_label(self.ultrasonic_distance_value, "Error")
            time.sleep(0.2)

    def read_weather_station(self):
        while running:
            try:
                sensor_data = {}
                for key, (address, count, data_type) in WEATHER_REGISTERS.items():
                    response = self.weather_station_client.read_holding_registers(address, count, slave=1)
                    if not response.isError():
                        if data_type == 'int':
                            value = response.registers[0]
                        elif data_type == 'float':
                            value = struct.unpack('<f', struct.pack('<HH', *response.registers))[0]
                        else:
                            value = None
                        sensor_data[key] = value
            
                # Updating labels based on available data
                self.update_label(self.wind_direction_value, f"{sensor_data.get('wind_direction', 'N/A')}°")
                self.update_label(self.wind_speed_value, f"{sensor_data.get('wind_speed', 'N/A'):.2f} m/s")
                self.update_label(self.temperature_value, f"{sensor_data.get('temperature', 'N/A'):.2f} °C")
                self.update_label(self.humidity_value, f"{sensor_data.get('humidity', 'N/A'):.2f} %")
                self.update_label(self.air_pressure_value, f"{sensor_data.get('air_pressure', 'N/A'):.2f} hPa")
            except:
                self.update_label(self.wind_direction_value, "Error")
            time.sleep(0.2)

    def read_ahrs_gps(self):
        while running:
            try:
                data = {}
                position_accuracy = 0.0  # Initialize position_accuracy to a default value
                for key, reg in AHRS_GPS_REGISTERS.items():
                    response = self.ahrs_client.read_holding_registers(reg, 1, slave=0x50)
                    if not response.isError():
                        data[key] = response.registers[0]

                # Extract AHRS readings
                roll = (data.get('roll', 0) / 32768.0) * 180.0
                pitch = (data.get('pitch', 0) / 32768.0) * 180.0
                yaw = (data.get('yaw', 0) / 32768.0) * 180.0
                longitude = ((data.get('LonH', 0) << 16) | data.get('LonL', 0)) / 1000000.0
                latitude = ((data.get('LatH', 0) << 16) | data.get('LatL', 0)) / 1000000.0
                altitude = data.get('GPSHeight', 0) / 10.0
                heading = data.get('GPSYAW', 0) / 100.0
                ground_speed = ((data.get('GPSVH', 0) << 16) | data.get('GPSVL', 0)) * 0.01
                pdop = data.get('PDOP', 0) / 100.0
                hdop = data.get('HDOP', 0) / 100.0
                vdop = data.get('VDOP', 0) / 100.0

                # Calculate Position Accuracy using PDOP, HDOP, and VDOP
                position_accuracy = self.calculate_position_accuracy(pdop, hdop, vdop)

                # Update AHRS readings on the GUI
                self.update_label(self.roll_value, f"{roll:.2f} °")
                self.update_label(self.pitch_value, f"{pitch:.2f} °")
                self.update_label(self.yaw_value, f"{yaw:.2f} °")
                self.update_label(self.longitude_value, f"{longitude:.6f}")
                self.update_label(self.latitude_value, f"{latitude:.6f}")
                self.update_label(self.altitude_value, f"{altitude:.1f} m")
                self.update_label(self.heading_value, f"{heading:.3f}°")
                self.update_label(self.position_accuracy_value, f"{position_accuracy:.2f}%")

            except Exception as e:
                error_message = f"Error reading AHRS/GPS data: {e}"
                print(error_message)  # Print the error message for debugging
                self.update_label(self.roll_value, "Error")
                self.update_label(self.position_accuracy_value, "Error")
            time.sleep(0.2)

    def read_pressure_sensor(self, client, sensor_name):
        while running:
            try:
                response = client.read_holding_registers(PRESSURE_SENSOR_REGISTER, 1, slave=1)
                if not response.isError():
                    raw_value = response.registers[0]
                    pressure_kpa = raw_value / 1000
                    pressure_inwg = pressure_kpa * PRESSURE_SCALING_FACTOR
                    self.update_label(getattr(self, f"{sensor_name}_value"), f"{pressure_inwg:.2f} inWG")
                                    
            except Exception as e:
                self.update_label(getattr(self, f"{sensor_name}_value"), "Error")
                print(f"Error reading pressure sensor {sensor_name}: {e}")  # Log the error for debugging
            time.sleep(0.2)

            
    def calculate_position_accuracy(self, pdop, hdop, vdop):
        # Typical DOP values range from 1 (best) to >20 (worst)
        min_dop = 1.0
        max_dop = 20.0
    
        # Normalizing accuracy values (higher DOP = lower accuracy)
        pdop_accuracy = max(0, min(100, 100 - ((pdop - min_dop) / (max_dop - min_dop)) * 100))
        hdop_accuracy = max(0, min(100, 100 - ((hdop - min_dop) / (max_dop - min_dop)) * 100))
        vdop_accuracy = max(0, min(100, 100 - ((vdop - min_dop) / (max_dop - min_dop)) * 100))
    
        # The overall position accuracy will be the minimum of these three values
        return min(pdop_accuracy, hdop_accuracy, vdop_accuracy)

    def update_time_date(self):
        current_datetime = QDateTime.currentDateTime()
        formatted_datetime = current_datetime.toString("dddd, MMMM d yyyy, hh:mm:ss AP")
        self.time_date_label.setText(formatted_datetime)

    def update_label(self, label, text):
        label.setText(text)

    def closeEvent(self, event):
        global running
        running = False
        self.stop_event.set()  # Signal all threads to stop
        self.client.close()
        time.sleep(1)
        QCoreApplication.instance().quit()
        event.accept()

def connect_client(ip, port):
    client = ModbusClient(host=ip, port=port)
    if client.connect():
        return client
    else:
        print(f"Failed to connect to {ip}:{port}")
        return None

def main():
    app = QApplication(sys.argv)
    dashboard = SensorReaderDashboard()
    dashboard.show()
    sys.exit(app.exec_())

if __name__ == "__main__":
    main()

