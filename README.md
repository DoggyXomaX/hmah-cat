# hmah-cat

### ⚡ Blazingly slow ⚡

Unix cat utility!

![hmah picture](.assets/hmah.png)

## Requirements

![CMake ^3.14](https://img.shields.io/badge/CMake-%5E3.14-green?logo=cmake)

## Build

```shell
# CMake standard
mkdir build
cd build
cmake -S .. -B .
cmake --build .
```

## Install

```shell
# From the build directory
ln -sf <build_directory>/bin/hmah /usr/bin/hmah
```

## Usage

```shell
hmah file1.txt file2.txt
```

## License

MIT