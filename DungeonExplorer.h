#ifndef DUNGEONEXPLORER_H
#define DUNGEONEXPLORER_H
#include "pokedex.h"
//#include "battle.h"
#include<string>
using namespace std;
class DungeonExplorer 
{
	private:
	    int chosenDestinations[4] = {0}; // Array to store chosen destinations (initialized with 0)
	    // Counter to keep track of chosen destinations
	    string cityName;
	    Pokedex pokedex;
	    Battle battle;
	    Pokemon pokemon;
	    Inventory inventory;
	
	public:
	    void generateDungeon(string cityName);
	    void explore(int num, Inventory&, Pokemon&);
	    void treasure(Inventory& );
};

#endif

