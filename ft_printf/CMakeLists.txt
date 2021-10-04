cmake_minimum_required(VERSION 3.14)
project(ft_printf)
set(CMAKE_CXX_STANDARD 11)
add_subdirectory(libft) # path to libft
add_compile_options(-Wall -Wextra -Werror)
add_library(libftprintf STATIC ft_printf.c)
