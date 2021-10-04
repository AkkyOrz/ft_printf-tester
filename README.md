# ft_printf-tester(2021+)

This is a tester for the `ft_printf` project of 42 school.
Clone this tester in your `ft_printf` repository.
And prepare `CMakeLists.txt` for every your repository you use.

**only the 'mandatory' part is supported now**

## dependency

- cmake
- g++

## How to prepare your test (commands)

```bash
cd /path/to/ft_printf
git clone https://github.com/AkkyOrz/ft_printf-tester.git
cd ft_printf-tester
cp ./ft_printf/CMakeLists.txt ../
cp ./ft_printf/libft/CMakeLists.txt ../libft/
cmake -S . -B build && cmake --build build && ./build/main
```

## How to prepare your test


Prepare `CMakeLists.txt` every in your repository to create your library.

For example, add `CMakeLists.txt` like below in your `libft` repository.

`ft_printf/libft/CMakeLists.txt`
(`cp ./ft_printf/libft/CMakeLists.txt ../` )

```txt
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)
project(libft)
add_compile_options(-Wall -Wextra -Werror)
file(GLOB LIBFT "ft_*.c") # you can include files explicitly
add_library(libft STATIC ${LIBFT})
```

`ft_printf/CMakeLists.txt`

(`cp ./ft_printf/libft/CMakeLists.txt ../libft/` )

```txt
cmake_minimum_required(VERSION 3.14)
project(ft_printf)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(libft) # path to libft
add_compile_options(-Wall -Wextra -Werror)
add_library(libftprintf STATIC ft_printf.c)
```

## my directories

```bash
$ tree
.
├── CMakeLists.txt
├── ft_printf-tester
│  ├── build
│  ├── CMakeLists.txt
│  ├── main.cpp
│  └── README.md
├── ft_printf.c
├── ft_printf.h
├── libft
│  ├── CMakeLists.txt # new
│  ├── ft_atoi.c
│  ├── ft_bzero.c
|  ...
│  ├── ft_toupper.c
│  ├── libft.h
│  └── Makefile
└── Makefile
```

## command

replace `./build/main` to your executable file.

```bash
cmake -S . -B build && cmake --build build && ./build/main
```


## CMake installation

### on macOS without root

install in `~/bin` folder

```bash
mkdir ~/bin
curl -LO https://github.com/Kitware/CMake/releases/download/v3.21.2/cmake-3.21.2-macos-universal.tar.gz
tar xf cmake-3.21.2-macos-universal.tar.gz
cd cmake-3.21.2-macos-universal
mv ./CMake.app ~
echo "export PATH=$HOME/CMake.app/Contents/bin:$PATH" >> ~/.zshrc
source ~/.zshrc
`````

### on macOS with MacPorts or brew

```bash
sudo port install cmake
brew install cmake
`````

cmake is maybe installed in `/usr/loca/bin`


### on Ubuntu

you can install via `snap`, `apt` or compile with src
