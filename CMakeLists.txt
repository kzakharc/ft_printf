cmake_minimum_required(VERSION 3.6)
project(printf)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES ft_printf.c ft_printf.h libft/libft.h main.c for_bs.c for_bc.c ft_it_base.c tp_f.c tp_s.c wid_prec.c all_for_flags.c for_print.c else.c)
add_executable(printf ${SOURCE_FILES})
target_link_libraries(printf ${CMAKE_SOURCE_DIR}/libft.a)