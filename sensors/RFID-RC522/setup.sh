#!/bin/bash
# Clone the repository
mkdir ~/orangepi
git clone https://github.com/SecurityPhoton/OrangePi.git ~/orangepi
# Navigate into the cloned repository folder
cd ~/orangepi/sensors/RFID-RC522
# Create a virtual environment
python3 -m venv venv
# Activate the virtual environment
source venv/bin/activate
# Install the library
python3 setup.py install
