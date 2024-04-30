#!/bin/bash
# Clone the repository
mkdir ~/opirc522
git clone https://github.com/SecurityPhoton/OrangePi.git ~/opirc522
# Navigate into the cloned repository folder
cd ~/opirc522/sensors/RFID-RC522
# Create a virtual environment
python3 -m venv venv
# Activate the virtual environment
source venv/bin/activate
# Install the library
pip install spidev
python3 setup.py install
