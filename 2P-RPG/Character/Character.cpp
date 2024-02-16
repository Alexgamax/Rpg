//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
Character::Character(string _name, int _health, int _attack, int _defense, int _speed) {
    name = _name;
    health = _health;
    attack = _attack;
    defense = _defense;
    speed = _speed;
}

string Character::getName() {
    return name;
}

int Character::getHealth() {
    return health;
}

int Character::getAttack() {
    return attack;
}

int Character::getDefense() {
    return defense;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    return "\nVida actual: " + to_string(health);
}