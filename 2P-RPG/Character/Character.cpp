//
// Created by Victor Navarro on 15/02/24.
//

#include "Character.h"
#include <iostream>
#include <string.h>

Character::Character(char _name[], int _health, int _attack, int _defense, int _speed, bool _isPlayer) {
    strcpy(name, _name);
    health = _health;
    initialHealth = _health;
    attack = _attack;
    defense = _defense;
    initialDefense = _defense;
    speed = _speed;
    isPlayer = _isPlayer;
}

int Character::getHealth() {
    return health;
}

void Character::upInitialHealth(int newStat) {
    initialHealth = newStat + initialHealth;

    cout<<"Su vida maxima ha aumentado en: "<<newStat<<endl;
}

int Character::getInitialHealth() {
    return initialHealth;
}

void Character::upAttack(int newStat) {
    attack = newStat + attack;

    cout<<"Su ataque ha aumentado en: "<<newStat<<endl;
}

int Character::getAttack() {
    return attack;
}

void Character::upDefense(int newStat) {
    defense = newStat + defense;


}

int Character::getDefense() {
    return defense;
}

void Character::defend() {

    cout<<name<<" se ha defendido, su defensa ha aumentado un 20%"<<endl;


    defenseActive = true;
    defense += (initialDefense * .2);

    cout<<"Su defensa es: "<<defense<<endl;
}

void Character::undefend() {

    defense = initialDefense;
}

void Character::upInitialDefense(int newStat) {
    initialDefense = newStat + initialDefense;

    cout<<"Su defensa maxima ha aumentado en: "<<newStat<<endl;
}

void Character::upSpeed(int newStat) {
    speed = newStat + speed;

    cout<<"Su velocidad ha aumentado en: "<<newStat<<endl;
}

int Character::getSpeed() {
    return speed;
}

string Character::toString() {
    cout<<"Name : "<<name;
    return "\nHealth: " + to_string(health) + "\nAttack: " + to_string(attack) + "\nDefense: " + to_string(defense) + "\nSpeed: " + to_string(speed);
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