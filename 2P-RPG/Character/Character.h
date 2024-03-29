//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>

using namespace std;

class Character {
protected:
    string name;
    int health;
    int attack;
    int initialHealth;
    int defense;
    int initialDefense;
    int speed;
    bool isPlayer;
    bool defenseActive = false;
public:
    Character(string _name, int _health, int _attack, int _defense, int _speed, bool _isPlayer);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    //TODO: Implementar metodo de defensa
    //Incrementar la defensa un 20% solo por el turno actual


    bool flee(Character* target);
    string getName();
    int getHealth();
    int getInitialHealth();
    int getAttack();
    int getDefense();
    void defend();
    void undefend();
    int getInitialDefense();
    bool getIsPlayer();
    int getSpeed();
    string toString();
};


#endif //RPG_CHARACTER_H
