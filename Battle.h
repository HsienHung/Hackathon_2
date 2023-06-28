#ifndef BATTLE_H
#define BATTLE_H
#include <string>
#include "pokemon.h"
#include "Inventory.h"
using namespace std;

class Battle {
private:
	string type;
    string name;
    int HP;
    int energy;
    int attack;
    string normalAttack;
    string skill1;
    string skill2;
    int level;
    int exp;
	int damage;
	int MyHP;
	int faitedPokemon;
	
public:
    Battle();
    ~Battle(){};
    void setType(const string& t);
    void setName(const string& n);
    void setHP(int hp);
    void setEnergy(int e);
    void setAttack(int a);
    void setNormalAttack(const string& na);
    void setSkill1(const string& s1);
    void setSkill2(const string& s2);
    void enemyStatus();
    void battleStart(Pokemon& ,Inventory& );
    void enemyDamage(Pokemon&);
    void bossStatus();
    int getHP();
};

#endif // BATTLE_H
