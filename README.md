# ConnectFour
Console implementation of the game Connect Four in C

## Featuring

Four different gamemodes

1. Two player     (Player vs Player)
2. One player     (Player vs Computer)
3. Computer Fight (Computer vs Computer)
4. Practice       (Player vs Player N games)

Computer movements are developed with Enhanced AI Technology.

## Insights

### One player gameplay

### AI vs AI


More: <a href='./documentation/screenshots'> /documentation/screenshots

## Setup & Run

### Prerequisite

The project contains CUnit test cases. You must install it first. <br>

```shell
sudo apt-get install libcunit1 libcunit1-doc libcunit1-dev
```

### Build

```sh
cmake -H. -Bbuild [-DCMAKE_BUILD_TYPE=Debug]
make -C build -j
./build/src/main/main
[./build/src/main/utest]
rm -rf build
```

Or with bash scripts:
```shell
./cmake.sh [Debug]
./main.sh
[./test.sh]
./clean.sh
```

(Give permissions to the script files) <br>
(Commands in "[ ]" are optional)

If you want to run the scripts without "./" you can even add current directory to the PATH:
```shell
export PATH="$PATH:."
```

## Configurations

If the TOKEN "⬤" is wider than your ascii characters, you can replace it with "O" in the board.h header.

### Github link
https://github.com/LeventeWolf/ConnectFour
