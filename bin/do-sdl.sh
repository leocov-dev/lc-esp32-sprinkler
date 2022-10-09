#!/usr/bin/env bash

set -e

DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" >/dev/null 2>&1 && pwd)"

ROOT="$DIR/.."
BUILD_DIR="$ROOT/build"

cd "$ROOT"
cmake -GNinja -Wno-dev -B"$BUILD_DIR" .

ninja -C"$BUILD_DIR"

echo
echo "###################  OPEN APP  ###################"
echo

"$BUILD_DIR/sdl2/sprinkler-sdl"