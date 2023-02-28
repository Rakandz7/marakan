cmake_minimum_required(VERSION 3.23)
project(marakan C)

set(CMAKE_C_STANDARD 99)

add_executable(marakan consigne.c regulation.c simulateur.c test_simulateur.c visualisationC.c visualisationT.c autotests.c autotests.h main.c)
