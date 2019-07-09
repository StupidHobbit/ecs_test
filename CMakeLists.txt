cmake_minimum_required(VERSION 3.14)
project(Tetris)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(lib/googletest)
include_directories(lib/googletest/googletest/include)

include_directories(lib/entt/src)

include_directories(lib/SFML/include)
link_directories(lib/SFML/lib)

include_directories(lib/imgui)
include_directories(lib/imgui-sfml)

add_executable(Tetris main.cpp lib/imgui/imgui.cpp lib/imgui/imgui_draw.cpp lib/imgui-sfml/imgui-SFML.cpp lib/imgui/imgui_widgets.cpp systems/System.h Components.h Systems.h GameManager.cpp GameManager.h components/Controls.h components/Player.h)
add_executable(Tetris_test tests/tests.cpp lib/imgui/imgui.cpp lib/imgui/imgui_draw.cpp lib/imgui-sfml/imgui-SFML.cpp lib/imgui/imgui_widgets.cpp tests/tests.cpp systems/System.h tests/test_systems.cpp Systems.h GameManager.cpp GameManager.h tests/test_GameManager.cpp)

target_link_libraries(Tetris sfml-graphics sfml-window sfml-system GL)
target_link_libraries(Tetris_test gtest gtest_main sfml-graphics sfml-window sfml-system GL)
