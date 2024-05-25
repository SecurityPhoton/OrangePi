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

To disable permanently add line to /etc/rc.local
```
echo none > /sys/class/leds/green_led/trigger
```
### Jellyfin Mediaserver :movie_camera: setup
You can use a docker image of Jellyfin mediaserver for home :house: use. Prepare the external disk :minidisc: and mount it to SBC (or you can use blkid for uid of disk) and add /etc/fstab:
```
UUID=12E3FB44C8FB1C1B /media ntfs defaults 0 0
```
then run docker :whale: container
```
docker run -d \
 --name jellyfin \
 --net=host \
 --volume jellyfin-config:/config \
 --volume jellyfin-cache:/cache \
 --mount type=bind,source=/media,target=/media \
 --restart=unless-stopped \
 jellyfin/jellyfin
```
After start use this link for initial config (change to your board ip address):
```
http://your.board.ip.address:8096/web/index.html#!/wizardstart.html
```
Consult this ![link](https://jellyfin.org/docs/general/installation/container) for more unstall options.
