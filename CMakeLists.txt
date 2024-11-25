cmake_minimum_required(VERSION 3.30)
project(Israel_Lara_Caso_integrador_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(ejercicio)

add_executable(Israel_Lara_Caso_integrador_3
    ejercicio/script_loader.cpp
    ejercicio/script_loader.h
    main.cpp)
