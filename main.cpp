#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include "Files/FileHandler.h"
#include <fstream>

using namespace std;

Player* loadPlayerInfo() {
    try {
        char buffer[Player::BUFFER_SIZE];
        FileHandler fileHandler = FileHandler();
        fileHandler.readFromFile("PlayerInfo.data", buffer, Player::BUFFER_SIZE);
        return Player::unserialize(buffer);
    } catch(int error) {
        char nombre[30];
        cout<<"Digite su nombre:"; cin.getline(nombre, 30, '\n');
        //Preguntar al usuario el nombre de jugador
        return new Player(nombre, 40, 40, 10, 10, 8);
    }
}

int main() {

    Player *player = loadPlayerInfo();
    Enemy *enemy = new Enemy("Goblin", 15, 15, 14, 7, 5, 100, 0);
    Enemy *enemy2 = new Enemy("Orc", 15, 15, 14, 7, 5, 100, 1);

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();
    
    delete player;
    delete enemy;
    delete combat;
    return 0;
}

//g++ main.cpp Player/Player.cpp Enemy/Enemy.cpp Combat/Combat.cpp Combat/Action.cpp Character/Character.cpp Files/FileHandler.cpp -o main ; ./main.exe