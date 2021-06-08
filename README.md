# ConnectFour
Console implementation of the game Connect Four in C

## Setup & Run

```sh
cmake -H. -Bbuild
make -C build -j
./build/main/main
rm -rf build
```

Or run the bash scripts
```sh
./cmake.sh
./main.sh
./clean.sh
```
Give permissions to the script files (with chmod)

If you want to run the scripts without "./" you can can even add current directory to the PATH:
```shell
export PATH="$PATH:."
```
