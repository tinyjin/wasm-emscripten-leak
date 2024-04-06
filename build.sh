#!/bin/bash

if [ ! -d "./build_wasm" ]; then
    sed "s|EMSDK:|$1|g" ./cross.txt > /tmp/.cross.txt
    meson -Db_lto=true -Ddefault_library=static --cross-file /tmp/.cross.txt build_wasm
fi

ninja -C build_wasm/
ls -lrt build_wasm/test-wasm.*
