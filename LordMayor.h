#ifndef LORDMAYER_H
#define LORDMAYER_H
#include "pokedex.h"
#include "Battle.h"
#include "Pokemon.h"
#include "Inventory.h"
#include<string>
using namespace std;

class LordMayor 
{
	private:
		Battle battle;
		Pokedex pokedex;
		Pokemon& pokemon;
		Inventory& inventory;
	
	public:
		LordMayor(Battle& battleRef, Pokedex& pokedexRef, Pokemon& pokemonRef, Inventory& inventoryRef)
        : battle(battleRef), pokedex(pokedexRef), pokemon(pokemonRef), inventory(inventoryRef){}
	   void beforeBattle(string, Inventory&, Pokemon&, bool&);
	   void mayorBattle(string, Inventory&, Pokemon&, bool&);
	   void afterBattle(string);
};

#endif

