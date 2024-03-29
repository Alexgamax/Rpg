//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
#include <iostream>
Character::Character(string _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    name = _name;
    health = _health;
    initialHealth = _health;
    attack = _attack;
    defense = _defense;
    initialDefense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
}

string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getInitialHealth() {
    return initialHealth;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getInitialDefense() {
    return initialDefense;
}

void Character::defend() {

    cout<<getName()<<" se ha defendido, su defensa ha aumentado un 20%"<<endl;


    defenseActive = true;
    defense += (initialDefense * .2);

    cout<<"Su defensa es: "<<defense<<endl;
}

void Character::undefend() {

    defense = initialDefense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "Name: " + name + "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
}

bool Character::getIsPlayer() {
    return isPlayer;
}

bool Character::flee(Character*target) {
    if(this->speed > target->speed)
        return true;

    int chance = rand() % 100;
    return chance > 30;
}