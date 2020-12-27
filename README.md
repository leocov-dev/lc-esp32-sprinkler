# lc-esp32-sprinkler

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

### Standalone SDL2 Build

```
$ bin/do-spl.sh
```