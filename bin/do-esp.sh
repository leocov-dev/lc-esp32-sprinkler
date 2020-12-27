#!/usr/bin/env bash

set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"

cd "$DIR/../esp-idf"

if [[ -z "$IDF_PATH" ]]; then
  source "$HOME/.esp/esp-idf/export.sh" > /dev/null
fi

idf.py -p "${ESP_PORT:-/dev/ttyUSB0}" -b "${ESP_FLASH_BAUD:-921600}" "$@"
