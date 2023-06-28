#include "DungeonExplorer.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void DungeonExplorer::generateDungeon(string cityName) 
{
    unsigned seed = time(0);
    srand(seed);

    int dungeonNumber = (rand() % 5)+1;

    if(dungeonNumber == 1)
	{	
		cout << endl;
		cout << "                     ###########                  "<< endl;
		cout << "                     #         #                  "<< endl;
		cout << "                     #    1    #                  "<< endl;
		cout << "                     #         #                  "<< endl;
		cout << "                     ###     ###                  "<< endl;
		cout << "                       #     #                    "<< endl;
		cout << "       ##########    ###     ###    ##########    "<< endl;
		cout << "       #        ######         ######        #    "<< endl;
		cout << "       ENTRANCE           3              4   EXIT "<< endl;
		cout << "       #        ######         ######        #    "<< endl;
		cout << "       ##########    ###     ###    ##########    "<< endl;
    	cout << "                       #     #                    "<< endl;
		cout << "                     ###     ###                  "<< endl;
		cout << "                     #         #                  "<< endl;
		cout << "                     #    2    #                  "<< endl;
		cout << "                     #         #                  "<< endl;
		cout << "                     ###########                  "<< endl;
	
	}
	
    else if(dungeonNumber == 2)
    {
    	cout << "             ###### EXIT ####"<< endl;
		cout << "             ######      ####"<< endl;
		cout << "             ###           ##"<< endl;
		cout << "################           ##"<< endl;
		cout << "################           ##"<< endl;
    	cout << "##           ###     4     ##"<< endl;
    	cout << "##           ###           ##"<< endl;
    	cout << "##    3      ###           ##"<< endl;
    	cout << "##                         ##"<< endl;
    	cout << "#################     #######"<< endl;
    	cout << "#################     ##"<< endl;
    	cout << "               ##     ##"<< endl;
    	cout << "  ##########   ##     ##"<< endl;
    	cout << "  ##      ##   ##     ##"<< endl;
    	cout << "  ##  2   #######     ##"<< endl;
    	cout << "  ##                  ##"<< endl;
    	cout << "  ###############     ##"<< endl;
    	cout << "               ##     ##"<< endl;
    	cout << "      ###########     ##"<< endl;
    	cout << "      ##              ##"<< endl;
    	cout << "      ##  1           ##"<< endl;
    	cout << "      ##              ##"<< endl;
    	cout << "      #######     ######"<< endl;
    	cout << "           ##     ##"<< endl;
    	cout << "           ##     ##"<< endl;
    	cout << "           ##     ##"<< endl;
    	cout << "           ENTRANCE"<< endl;
  	
	}	
	
	else if(dungeonNumber == 3)
    {
    	cout << "           ENTRANCE          "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "      #######     ######     "<< endl;
        cout << "      ##              ##     "<< endl;
        cout << "      ##   1          ##     "<< endl;
        cout << "      ##              ##     "<< endl;
        cout << "      ###########     ##     "<< endl;
        cout << "               ##     ##     "<< endl;
        cout << "  ###############     ##     "<< endl;
        cout << "  ##                  ##     "<< endl;
        cout << "  ##   2   #######    ##     "<< endl;
        cout << "  ##                  ##     "<< endl;
        cout << "  ###############     ##     "<< endl;
        cout << "               ##     ##     "<< endl;
        cout << "      ###########     ##     "<< endl;
        cout << "      ##              ##     "<< endl;
        cout << "      ##   3          ##     "<< endl;
        cout << "      ##              ##     "<< endl;
        cout << "      #######     ######     "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "           ##     ##         "<< endl;
        cout << "################  ###########"<< endl;
        cout << "################           ##"<< endl;
        cout << "##           ###     4     ##"<< endl;
        cout << "##           ###           ##"<< endl;
        cout << "##           ###           ##"<< endl;
        cout << "##                         ##"<< endl;
        cout << "##        ###### EXIT #######"<< endl;
        cout << "##        ######      #######"<< endl;
        cout << "##        ######             "<< endl;
        cout << "################             "<< endl;
        cout << "################             "<< endl;

  	
  		
	}	
	
	else if(dungeonNumber == 4)
    {
    	cout << "###########             ###########" << endl;
        cout << "#         #             #         #" << endl;
        cout << "#    3    #             #    4    #" << endl;
        cout << "#         #             #         #" << endl;
        cout << "###     ###             ###     ###" << endl;
        cout << "###     ###             ###     ###" << endl;
        cout << "###     ###################     ###" << endl;
        cout << "###                             ###" << endl;
        cout << "##############     ################" << endl;
        cout << "             #     #" << endl;
        cout << "   ##########      ###############" << endl;
        cout << "   #                             #" << endl;
        cout << "   #   2     ###############     #" << endl;
        cout << "   #             #               #" << endl;
        cout << "   ###############     ###########" << endl;
        cout << "                 #     #" << endl;
        cout << "    ##############     ###########" << endl;
        cout << "    #                            #" << endl;
        cout << "    #   1     ###############    #" << endl;
        cout << "    #         #####              #" << endl;
        cout << "    #         #####     ###########" << endl;
        cout << "    #             #     #" << endl;
        cout << "    #             #     #" << endl;
        cout << "    #             #     #" << endl;
        cout << "    #             #     #" << endl;
        cout << "###########       #     ###############" << endl;
        cout << "#         #       #     #     ##" << endl;
        cout << "#   ENTRANCE      #    EXIT   ##" << endl;
        cout << "#         #       #     #     ##" << endl;
        cout << "################################" << endl;
  	
  	
	}	
	
	else if(dungeonNumber == 5)
    {
    	cout << "###################################" << endl;
        cout << "#                                 #" << endl;
        cout << "#   ##########       #########    #" << endl;
        cout << "#            #       #            #" << endl;
        cout << "#       3    #       #    2       #" << endl;
        cout << "#            #       #            #" << endl;
        cout << "#   ##########       #########    #" << endl;
        cout << "#         ####       ########     #" << endl;
        cout << "#####    ####################     ##" << endl;
        cout << "#                 #                #" << endl;
        cout << "#   ###########   ############     #" << endl;
        cout << "#   #             #                #" << endl;
        cout << "#   #   4     ################     #" << endl;
        cout << "#   #             #                #" << endl;
        cout << "#   ###############      ###########" << endl;
        cout << "#                 #                #" << endl;
        cout << "##########    ################     #####" << endl;
        cout << "#                            #  1  #" << endl;
        cout << "#   EXIT        ###############    #" << endl;
        cout << "#               #                  #" << endl;
        cout << "#################    ##########    #" << endl;
        cout << "                #    #             #" << endl;
        cout << "                #    #             #" << endl;
        cout << "                #    #             #" << endl;
        cout << "                #    #             #" << endl;
        cout << "#################    #       ########" << endl;
        cout << "#         #          #             #" << endl;
        cout << "#  ENTRANCE          #             #" << endl;
        cout << "#         #          #             #" << endl;
        cout << "####################################" << endl;

  	
	}	
}

void DungeonExplorer::explore(int num, Inventory& inventory, Pokemon& pokemon) {
    unsigned seed = time(0);
    srand(seed);
	int counter = 0;
    int destination;
	cout << "\n-------------" << endl;
    cout << "   DUNGEON " << endl;
    cout << "-------------" << endl;
    cout << "!!!Press 0 for exit!!!" << endl;
    
    while (num != 0 && counter < 4) 
	{
        int choice = (rand() % 2) + 1;
        cout << "\nPlease select your destination (0-4): ";
        cin >> destination;

        if (destination == 0) 
		{
            cout << "\nEXIT. You had leaved the dungeon." << endl;
            break;
        }
		
		else if (destination < 0 || destination >4)
		{
			cout << "\nPlease select your destination (0-4):";
			cin >> destination;
			continue;
		}
		
        bool destinationExists = false;

        // Check if destination already exists in chosenDestinations
        for (int i = 0; i < 4; i++) {
            if (chosenDestinations[i] == destination) {
                destinationExists = true;
                break;
            }
        }

        if (destinationExists) {
            cout << "Destination already chosen. Please select a different destination." << endl;
            continue;
        }

        // Find an empty slot in chosenDestinations and store the new destination
        for (int i = 0; i < 4; i++) {
            if (chosenDestinations[i] == 0) {
                chosenDestinations[i] = destination;
                break;
            }
        }

        if (choice == 1) {
            cout << "-----------------------" << endl;
            cout << "  Pokemon Encounter!!! " << endl;
            cout << "-----------------------" << endl;
            pokedex.initializePokedex();
			pokedex.generatePokemon(battle, "Lavaridge Town");
			battle.enemyStatus();			
			battle.battleStart(pokemon, inventory);
			
            
        } else {
            cout << "------------------" << endl;
            cout << " Treasure Found!!! " << endl;
            cout << "------------------" << endl;
            treasure(inventory);
        }
        num--;
        counter++;
    }

    if (counter == 4) {
        cout << "\n---------------------------------------------------" << endl;
        cout << "Congratulations!!! Dungeon Exploration Completed!!!" << endl;
        cout << "---------------------------------------------------" << endl;
        return;
    }
}

	void DungeonExplorer::treasure(Inventory& inventory)
	{
			unsigned seed = time(0);
		    srand(seed);
		    
		    cout<<"The treasure contains the following items: "<<endl;
			for(int i=0; i<3; i++)
			{
		    	int treasure = (rand() % 52)+1;
				if(treasure >=0 && treasure <=6)
				{
					cout <<"Super Potion";
					inventory.increaseQuantity("Super Potion",1);
				}	
				else if(treasure >=7 && treasure <=13)
				{
					cout << "Pokeball";
					inventory.increaseQuantity("Pokeball",1);
				}	
				else if(treasure >=14 && treasure <=19)
				{
					cout << "EnergyWave Spark";
					inventory.increaseQuantity("EnergyWave Spark",1);
				}	
				else if(treasure >=20 && treasure <=21)
				{
					cout << "Hyper Potion";
					inventory.increaseQuantity("Hyper Potion",1);
				}	
				else if(treasure >=22 && treasure <=23)
				{
					cout << "Great Ball";
					inventory.increaseQuantity("Great Ball",1);
				}	
				else if(treasure == 24)
				{
					cout << "Ultra ball";
					inventory.increaseQuantity("Ultra ball",1);
				}	
				else if(treasure  == 25)
				{
					cout << "Max Potion";
					inventory.increaseQuantity("Max Potion",1);
				}	
				else if(treasure  == 26)
				{
					cout << "EnergyWave Blast";
					inventory.increaseQuantity("EnergyWave Blast",1);
				}	
				else
				{
//					int random= (rand()%30)+1;
//					cout<<random<< " coins"<<endl;
					//coins+=random;
					
				}
				cout<<endl;	
		}
	}

