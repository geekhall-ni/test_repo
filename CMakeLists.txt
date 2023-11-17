cmake_minimum_required(VERSION 3.19)
project(test)

set(CMAKE_CXX_STANDARD 14)

add_executable(test main.cpp
        parser/parser.cpp
		database
        placement/placement.cpp
        exporter/exporter.cpp
	)


target_include_directories(test PRIVATE
		parser
		database
		placement
        exporter
	)