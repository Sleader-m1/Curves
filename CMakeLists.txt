cmake_minimum_required(VERSION 3.26.4 FATAL_ERROR)

project(Test)

set (CMAKE_CXX_STANDARD 17)
set (SOURCE_FILES src/main.cpp lib/Circle.cpp lib/Circle.h
				  lib/Figure.h lib/Helix.cpp lib/Helix.h
				  lib/Ellipse.cpp lib/Ellipse.h lib/Curves.h
				  lib/Point.h lib/Point.cpp)

add_executable (curves ${SOURCE_FILES})
