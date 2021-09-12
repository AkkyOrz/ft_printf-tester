# ft_printf-tester(2021+)

This is a tester for the `ft_printf` project of 42 school.
Clone this tester in your `ft_printf` repository.
And prepare `CMakeLists.txt` for every your repository you use.

## dependency

- cmake
- g++

## How to prepare your test

Prepare `CMakeLists.txt` every in your repository to create your library.

For example, add `CMakeLists.txt` like below in your `libft` repository.

`ft_printf/libft/CMakeLists.txt`

```txt
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)
project(cmake_example C CXX)
add_compile_options(-Wall -Wextra -Werror)
file(GLOB LIBFT "ft_*.c")
add_library(libft STATIC ${LIBFT})
```

`ft_printf/CMakeLists.txt`

```txt
cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 11)
set(LIBFT_PATH ./libft)

project(cmake_example C CXX)
add_compile_options(-Wall -Wextra -Werror)
add_subdirectory(${LIBFT_PATH})
add_library(libftprintf STATIC ft_printf.c)
```

## command

```bash
cmake -S . -B build && cmake --build build && ./build/
```
