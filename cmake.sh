#!/bin/bash
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE="$1"
make -C build -j
