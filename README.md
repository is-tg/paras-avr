## USAGE

#### IDE steps

copy the raw URL to the package index
```
https://raw.githubusercontent.com/is-tg/paras-n76-core/refs/heads/main/package_paras_index.json
```
navigate to **File > Preferences > Additional boards manager URLs** field

paste the URL

navigate to **Tools > Board > Boards Manager**

search `Paras` and click install

yay!

#### CLI steps

ensure config file is created
```
arduino-cli config init
```
add the URL to config
```
arduino-cli config add board_manager.additional_urls https://raw.githubusercontent.com/is-tg/paras-n76-core/refs/heads/main/package_paras_index.json
```
arduino-cli.yaml:
```
board_manager:
    additional_urls:
        - https://raw.githubusercontent.com/is-tg/paras-n76-core/refs/heads/main/package_paras_index.json
```
update local cache and install the core
```
arduino-cli core update-index
arduino-cli core install paras:mcs51
```
write a sketch then compile and upload by running

replace `sketch.ino` and port `/dev/ttyUSB0` accordingly
```
arduino-cli compile --fqbn paras:mcs51:paras sketch.ino
arduino-cli upload -p /dev/ttyUSB0 --fqbn paras:mcs51:paras sketch.ino
```
NOTE: you may need to trigger RESET to begin the flash process

yay!

## BUILT WITH

- [SDCC - patched to allow *.o and *.a file extensions](https://sdcc.sourceforge.net/)
- [nvtispflash](https://github.com/frank-zago/nvtispflash)

## PROGRESS

Refer the [Arduino API](https://docs.arduino.cc/learn/programming/reference/)

#### Digital I/O
- [x] pinMode
- [x] digitalRead
- [x] digitalWrite
#### Time
- [x] delay

## CONTRIBUTE

[Need windows support!](https://github.com/is-tg/paras-n76-core/issues/1)

resources:

- [N76E003 Datasheet](https://www.nuvoton.com/export/resource-files/DS_N76E003_EN_Rev1.09.pdf)
- [The Official Arduino AVR core for reference](https://github.com/arduino/ArduinoCore-avr/tree/master)
