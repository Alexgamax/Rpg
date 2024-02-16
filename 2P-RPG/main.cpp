#include <iostream>
#include "Player/Player.h"
#include "Enemy/Enemy.h"

int main() {
    Player *player = new Player("Alexis", 100, 8, 3, 10);
    Enemy *enemy = new Enemy("Destello absoluto", 50, 6, 2, 5, 10);
    int cont = 0;
    int auxPlayer, auxEnemy;

    while(player->getHealth() > 0 && enemy->getHealth() > 0){
        auxPlayer = player->getHealth();
        auxEnemy = enemy->getHealth();

        cout<<player->toString()<<endl;
        cout<<enemy->toString()<<endl;

        player->doAttack(enemy);
        enemy->doAttack(player);

        cout<<"\n";

        cout<<player->getName()<<" ha atacado a "<<enemy->getName()<<" con "<<auxEnemy - enemy->getHealth()<<" puntos de vida"<<endl;
        cout<<enemy->getName()<<" ha atacado a "<<player->getName()<<" con "<<auxPlayer - player->getHealth()<<" puntos de vida"<<endl;

        cout<<"---------------------";
    }

    cout<<player->toString()<<endl;
    cout<<enemy->toString()<<endl;

    if(auxPlayer <= 0) cout<<"\nEl jugador ha perdido."<<endl;
    else cout<<"\nEl enemigo ha perdido."<<endl;

    delete player;
    delete enemy;
    return 0;
}
