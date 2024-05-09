#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"
#include "Combat/Combat.h"
#include "Files/FileHandler.h"
#include <fstream>

int main() {
    Player *player = new Player("Victor", 40, 10, 10, 3);
    FileHandler *fileHandler = new FileHandler();

    char* buffer = player->serialize();

    fileHandler->writeToFile("Personaje1.data", buffer, Player::BUFFER_SIZE);

    char *bufferLectura = nullptr;
    fileHandler->readFromFile("Personaje1.data", bufferLectura, Player::BUFFER_SIZE);

    Player *unserializedPlayer = Player::unserialize(bufferLectura);
    cout<<unserializedPlayer->toString();

    /*Enemy *enemy = new Enemy("Goblin", 15, 14, 7, 5, 100, 0);
    Enemy *enemy2 = new Enemy("Orc", 15, 14, 7, 5, 100, 1);

    vector<Character*> participants;

    participants.push_back(player);
    participants.push_back(enemy);
    participants.push_back(enemy2);

    Combat *combat = new Combat(participants);
    combat->doCombat();
    */
    delete player;
    //delete enemy;
    //delete combat;
    return 0;
}

//g++ main.cpp Player/Player.cpp Enemy/Enemy.cpp Combat/Combat.cpp Combat/Action.cpp Character/Character.cpp -o main ; ./main.exe