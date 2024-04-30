# OrangePI zero 3 board with RFID-RC522 - mfrc522

A python library to read/write RFID tags via the budget MFRC522 RFID module. This is a copy of repo https://github.com/pimylifeup/MFRC522-python/tree/master adapted for usage with Orange PI zero3.

## Changes made from original repo

Deleted the GPIO lib reference to work with Orange PI devices. It is enough usage of SPI to work. The SPI bus and device was set to 1 instead of 0 to work with OrangePI zero 3 in MFRC522.py. 
Read this thread for more understanding https://www.reddit.com/r/OrangePI/comments/15vtbs5/rc522_rfid_gpio_connected_to_orangepi5plus/

## Wire mapping

The next picture shows the pinout within two boards (Orange PI zero 3 and RFID-RC522):
![Pinout-rfid](/sensors/RFID-RC522/PinOUT-RFID.jpg)
Note that first 4 pins are required, and also 2 power pins (3.3v and GND). Other are optional and can be ommited.

## Installation

1. Clone the repo. 
` mkdir ~/opirc522 && git clone https://github.com/SecurityPhoton/OrangePi.git ~/opirc522`
2. Make venv and activate it. 

```bash
cd ~/orangepi/sensors/RFID-RC522
python3 -m venv venv
source venv/bin/activate
```

3. Run `python setup.py install` in the top level directory.

P.S. Consult the ![file](/sensors/RFID-RC522/setup.sh) for quick install option:
`wget https://raw.githubusercontent.com/SecurityPhoton/OrangePi/main/sensors/RFID-RC522/setup.sh && bash setup.sh` 

## Example Code

The following code will read a tag from the MFRC522

```python
from time import sleep
import sys
from mfrc522 import SimpleMFRC522
reader = SimpleMFRC522()

try:
    while True:
        print("Hold a tag near the reader")
        id, text = reader.read()
        print("ID: %s\nText: %s" % (id,text))
        sleep(5)
except KeyboardInterrupt:
    GPIO.cleanup()
    raise
```
You can use the ![read-rfid.py](read-rfid.py) file for reference. This exapmle read rfid card in loop and checks if the correct card is placed. It also light the external leds (but you can ommit this section and comment it out) for demo. The 3 led board lights Green led if card is OK and red if not recognised card is used.
