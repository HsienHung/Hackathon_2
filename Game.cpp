#include <iostream>
#include "Game.h"
#include <fstream>	
#include <sstream>
#include "Pokemon.h"
#include "Inventory.h"
using namespace std;

Game::Game() : inventory(), map(), pokemon(), gameName()//, shop(inventory, "HI", pokemon)//, gameList()
{
    // Constructor implementation
}
		
//Flow of the game
		void Game::StartGame()
		{
			while(true)
			{
				cout << "Welcome to the Game!" << endl;
    			cout << "---------------------" << endl << endl;
    			cout << " 1.Enter City " << endl;
    			cout << " 2.Back "<<endl;
    			cout << "Enter your choice: " ;
    			int choice;
    			cin>>choice;
    			
    			switch(choice)
    			{
    				case 1:
    					map.chooseCity();
    					break;
    				case 2:
    					return;
				}
			}
		}

