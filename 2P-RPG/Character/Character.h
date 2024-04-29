//
// Created by Victor Navarro on 15/02/24.
//

#ifndef RPG_CHARACTER_H
#define RPG_CHARACTER_H
#include <string>

using namespace std;

class Character {
protected:
    char name[30];
    int health;
    int attack;
    int initialHealth;
    int defense;
    int initialDefense;
    int speed;
    bool isPlayer;
    bool defenseActive = false;
public:
    Character(char _name[], int _health, int _attack, int _defense, int _speed, bool _isPlayer);

    virtual void doAttack(Character *target) = 0;
    virtual void takeDamage(int damage) = 0;

    //TODO: Implementar metodo de defensa
    //Incrementar la defensa un 20% solo por el turno actual

    bool flee(Character* target);
    int getHealth();
    int getInitialHealth();
    void upInitialHealth(int newStat);
    int getAttack();
    void upAttack(int newStat);
    int getDefense();
    void upDefense(int newStat);
    void defend();
    void undefend();
    void upInitialDefense(int newStat);
    bool getIsPlayer();
    int getSpeed();
    void upSpeed(int newStat);
    string toString();
};


#endif //RPG_CHARACTER_H
