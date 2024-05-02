# OrangePi :orange: board
Orange Pi projects. Orange Pi zero 3 is used as test board.

## Contents

1. MQ3 sensor test for Alcohol detection. :wine_glass: ![Read More](/sensors/MQ3/README.md) :traffic_light:
2. RFID RC-522 board test for reading the cards :mahjong: ![Read More](/sensors/RFID-RC522/README.md) 

## Tips

### How to disable blinking leds :flashlight:

If you want enable and disable the leds on the board, for example disable blinking status green led you should use this command:

`echo none > /sys/class/leds/green_led/trigger` :low_brightness:
and to revert all back:
`echo heartbeat > /sys/class/leds/green_led/trigger` :high_brightness:

You can make an alias to enable and disable leds on the run, simply add lines to .bashrc file:
```
nano ~/.bashrc

alias disable_led='echo none > /sys/class/leds/green_led/trigger'
alias enable_led='echo heartbeat > /sys/class/leds/green_led/trigger'
```
and execute `source ~/.bashrc`. This allows any changes or additions made to the ~/.bashrc file to take effect immediately, without needing to start a new shell session.
