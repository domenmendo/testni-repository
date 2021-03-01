#include <iostream>
#include <SDL.h>
#include <ctime>
#include <vector>
#include "window.hpp"
#include "rect.h"
#include "enemy.h"
#include "utils.h"
#include "seal.h"
#include "aktivist.h"

using namespace std;

void pollEvents(window& window, Rect& rect, Enemy& enemy,Seal& seal,Act& activist) {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        if (rect.pollEvents(event) == 1) {
            enemy.pollEvents(event);
            activist.pollEvents(event);
        }
        window.pollEvents(event);
        seal.pollEvents(event);
    }
}

int main(int argc, char* args[]){
    int stage = 1;
    srand(time(NULL));
    vector<Enemy> nasprotnik;
    window window("SDL test", 800, 600);
    Rect rect(window, 80, 80, 100, 100, "res/eskim.png");
    Seal seal(window, 80, 80, rand() % (700) + 1, rand() % (500) + 1, "res/bear.png");
    Act activist(window, 80, 80, rand() % (700) + 1, rand() % (500) + 1, "res/aktivist.png");
    Enemy enemy(window, 80, 80, rand() % (700) + 1, rand() % (500) + 1, "res/lovec.png");
    //Enemy neki(window, 80, 80, rand() % (700) + 1, rand() % (500) + 1, "res/lovec.png");
    
    /*for (int i = 0; i < stage; i++) {
        nasprotnik.push_back(neki);
    }
    for (int i = 0; i < nasprotnik.size(); i++) {
        //cout << "loop:" << i << endl;
        nasprotnik[i].draw();
    }*/

    while (!window.isClosed()) {
        pollEvents(window, rect, enemy, seal, activist);
        //cout << utils::timeInSeconds() << endl;
        rect.draw();
        seal.draw();
        enemy.draw();
        activist.draw();
        if (rect.CollisionDetection(enemy)||rect.CollisionDetection(seal)) {
            cout << "nibba.\n";
        }
        window.clear();
    }
    return 0;
}