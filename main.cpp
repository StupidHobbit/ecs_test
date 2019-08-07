#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "SystemManager.h"
#include "GameManager.h"

int main() {
    GameManager gm;
    gm.run();

    return 0;
}