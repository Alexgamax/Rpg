//
// Created by Victor Navarro on 15/02/24.
//

#include "Enemy.h"
#include "../Utils.h"
#include <iostream>
#include <string.h>

using namespace std;
using namespace combat_utils;

Enemy::Enemy(char _name[], int _health, int _attack, int _defense, int _speed, int _experience) : Character(_name, _health, _attack, _defense, _speed, false) {
    experience = _experience;
}

void Enemy::doAttack(Character *target) {
    target->takeDamage(getRolledAttack(attack));
}

void Enemy::takeDamage(int damage) {
    int trueDamage = damage - defense;
    health-= trueDamage;

    cout << name << " took " << trueDamage << " damage!" << endl;
    if(health <= 0) {
        cout << name << " has been defeated!" << endl;
    }
}

int Enemy::getExperience() {
    return experience;
}

Character* Enemy::selectTarget(vector<Player*> possibleTargets) {
    //target with less health
    int lessHealth = 9999999;
    Character* target = nullptr;
    for(auto character : possibleTargets) {
        if(character->getHealth() < lessHealth) {
            lessHealth = character->getHealth();
            target = character;
        }
    }
    return target;
}

Action Enemy::takeAction(vector<Player*> partyMembers) {
    int chance  = 1+rand()%(101-1);
    Action currentAction;
    currentAction.speed = getSpeed();

    undefend();

    //Si la vida del enemigo está por debajo del 55 por ciento, hay un 70 por ciento que se defienda
    if(getHealth() < getInitialHealth() * .55 && chance <= 70){
        currentAction.action = [this]() {
            defend();
        };
    } else {
        Character* target = selectTarget(partyMembers);
        currentAction.target = target;
        currentAction.action = [this, target](){
            doAttack(target);
        };


    }
    return currentAction;

}

void Enemy::printName() {
    for (int i=0;i<strlen(name);i++){
        cout<<name[i];
    }
    cout<<endl;
}