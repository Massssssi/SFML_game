cmake_minimum_required(VERSION 3.5)

project(SFML_game_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfml_game
		
	src/main.cpp
	src/Game.cpp
	include/Game.h

	
)

install(TARGETS sfml_game
  DESTINATION lib/${PROJECT_NAME})