# lc-esp32-sprinkler

## WIP
This is currently still a work in progress, the SDL build should produce some 
output but the esp-idf build will likely not work until I have completed the 
abstracted app and it is fully working in the SDL desktop environment.

### Dependencies
```
cmake >3.16
ninja
esp-idf
sdl2
```

### ESP Build

```
# build
$ bin/do-esp.sh build

# flash and open monitor
$ bin/do-esp.sh flash monitor

# can be combined
$ bin/do-esp.sh build flash monitor
```
Device port defaults to `/dev/ttyUSB0` but can be set with env var `ESP_PORT`
Device flash baud defaults to `921600` but can be set with env var `ESP_FLASH_BAUD`

Arguments for `bin/do-esp.sh` are the same as `idf.py`

### SDL2 Build ( desktop development )

```
$ bin/do-spl.sh
```

### Acknowledgements
* [Deskmate by Raphael Baron](https://github.com/rbaron/deskmate)
    * Much of this code and the SDL build was inspired by the `deskmate` project especially the design of the App and Display classes, thanks!
* [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)
    * This project uses Adafruit `GFXFont` compatible font rendering at this time, but I may switch to another bitmap font format