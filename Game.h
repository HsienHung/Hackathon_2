#ifndef GAME_H
#define GAME_H
#include "Shop.h"
#include "Pokedex.h"
#include "GameList.h"
#include "Map.h"
#include <string>

class Game
{
		private:
			Inventory inventory;
			Map map;
			Pokemon pokemon;	
			//Shop shop;//(inventory,map,pokemon);
			string gameName;
			//GameList gameList;
			
			
		public:
			Game();
			//GameList loadAllGames(const string& filename);//Load all gamestate into gamelist
			//void loadGame(); //load desired gamestate into object 
			void StartGame();
};
#endif
