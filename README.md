# IDEAHacks2020 - One Punch Pillow (ワンパン枕)

# Dependencies & Prereqs
* [Arduino-Makefile](https://github.com/sudar/Arduino-Makefile)
* Please set the `MONITOR_PORT` variable in the `Makefile` to reflect your system.

# Building

```sh
# clone submodules
git submodule init
git submodule update

# build src
g++ -c src/*

# build project
make

# upload
make upload

# monitor output
make monitor
```