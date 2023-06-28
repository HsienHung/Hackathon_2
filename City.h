#ifndef CITY_H
#define CITY_H
#include "Shop.h"
#include "Inventory.h"
#include "Battle.h"
#include "pokedex.h"
#include "pokemon.h"
#include"LordMayor.h"
#include"DungeonExplorer.h"
#include <iostream>
#include <string>

using namespace std;

class City 
{
	private:
	    string name;
	    Inventory inventory;
	    Battle battle;
	    Pokedex pokedex;
	    Pokemon pokemon;
	    LordMayor lordMayor;
	    DungeonExplorer dungeon;
		Shop shop;
		bool win;
		
	
	public:
		City city();
	    City(const string& cityName);
	    void visitCity();
	    const string& getName() const;
	    void setWin(bool);
	    bool getWin();
	    void saveGame(Pokemon& ,Inventory& );
};

#endif

