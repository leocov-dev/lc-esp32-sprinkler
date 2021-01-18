# lc-esp32-sprinkler

## WIP
This is currently still a work in progress, the SDL build should produce some 
output but the esp-idf build will likely not work until I have completed the 
abstracted app and it is fully working in the SDL desktop environment.

### Dependencies
```
cmake >3.16
ninja (if using scripts in bin/ folder)
esp-idf (if building esp32 firmware)
sdl2 (if building desktop executable)
```

### Structure
```
├── lib-lc-sprinkler 
│    - platform independent application lib
├── sdl2
│    - SDL2 implementation for desktop
├── esp-idf
│    - esp32 microcontroller firmware implementation using esp-idf sdk
├── +pcb
│    - reference pcb hardware design for use with esp32 module (KiCad)
```

### ESP32 Firmware Build

``` bash
# build
$ bin/do-esp.sh build

# flash and open monitor
$ bin/do-esp.sh flash monitor

# can be combined
$ bin/do-esp.sh build flash monitor
```
Arguments for `bin/do-esp.sh` are the same as `idf.py` for the most part

#### Env Vars:

`ESP_PORT` - set the upload port (defaults to `/dev/ttyUSB0`)

`ESP_FLASH_BAUD` - set the upload baud (defaults to `921600`)


### SDL2 Executable Build 
Meant for rapid development on the desktop, not intended to be used as a final 
product although it would be possible to run directly on a raspberry pi for example.

``` bash
$ bin/do-spl.sh
```

### Development
I develop on linux so my experience compiling this application is limited to that operating system.
For anyone looking to build and try this out please ensure you have the dependencies mentioned above
and try the SDL2 build first. For the esp-idf build you need more than just an esp32 development board.
You should follow the circuit diagram and hardware schematics to create a test setup and proceed from there.

### Acknowledgements
* [Deskmate by Raphael Baron](https://github.com/rbaron/deskmate)
    * Much of this code and the SDL build was inspired by the `deskmate` project especially the design of the App and Display classes, thanks!
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
    * This project uses Adafruit `GFXFont` compatible font rendering at this time, but I may switch to another bitmap font format