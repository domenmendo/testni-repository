#include <iostream>
#include <SDL.h>
#include <ctime>
#include <vector>
#include "window.hpp"
#include "rect.h"
#include "enemy.h"
#include "utils.h"
#include "seal.h"

using namespace std;

void pollEvents(window& window, Rect& rect, Enemy& enemy,Seal& seal) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if(rect.pollEvents(event)==1)
            enemy.pollEvents(event);
        window.pollEvents(event);
        seal.pollEvents(event);
    }
}

int main(int argc, char* args[]){
    srand(time(NULL));
    window window("SDL test", 800, 600);
    Rect rect(window, 120, 120, 100, 100, "res/eskim.png");
    Seal seal(window, 120, 120, rand() % (700) + 1, rand() % (500) + 1, "res/seal.png");
    Enemy enemy(window, 120, 120, rand() % (700) + 1, rand() % (500) + 1, "res/lovec.png");
    Enemy enemy1(window, 120, 120, rand() % (700) + 1, rand() % (500) + 1, "res/lovec.png");

    /*std::vector<Enemy> enemy2 = {
        Enemy(window, 120, 120, rand() % (700) + 1, rand() % (500) + 1, "res/lovec.png"),
    };

    vector<int> array = { 1,2,3,4 };
    for (int i : array) {
        cout << i;
    }*/
    
    while (!window.isClosed()) {
        pollEvents(window, rect, enemy, seal);
        //cout << utils::timeInSeconds() << endl;
        rect.draw();
        seal.draw();
        enemy.draw();
        enemy1.draw();
        window.clear();
    }
    return 0;
}