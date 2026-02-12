cmake_minimum_required(VERSION 3.10)
project(SnakeGame)

# Configurar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar el paquete SFML en el sistema
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Definir el ejecutable y sus fuentes
add_executable(snake_game src/main.cpp src/Snake.cpp)

target_include_directories(snake_game PRIVATE include)

# Enlazar las librerías de SFML con nuestro ejecutable
target_link_libraries(snake_game sfml-graphics sfml-window sfml-system)