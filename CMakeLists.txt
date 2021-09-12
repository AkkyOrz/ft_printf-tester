# general settings
cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++11
set(CMAKE_CXX_STANDARD 11)
set(LIBFT_PATH ../ft_printf)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# test specific
enable_testing()

add_subdirectory(${PRITNF_PATH})


add_library(libftprintf STATIC ft_printf.c)

add_executable(
  main
  main.cpp
)
target_link_libraries(
  main
  gtest_main
  libftprintf
  libft
)

include(GoogleTest)
gtest_discover_tests(main)
