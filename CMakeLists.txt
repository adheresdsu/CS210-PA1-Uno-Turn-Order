cmake_minimum_required(VERSION 4.3)
project(CS210_PA1_Uno_Turn_Order)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(CS210_PA1_Uno_Turn_Order
        main.cpp
        Node.h
        Player.h
        Stack.h
        List.h

)
