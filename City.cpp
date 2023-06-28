#include "City.h"

City::City(const string& cityName)
    : name(cityName), inventory(), battle(), pokedex(), pokemon(), lordMayor(battle, pokedex, pokemon, inventory), dungeon(), shop(inventory) {
	}
    // Rest of the constructor's implementation

void City::visitCity() 
{
    cout << endl;
    cout << "Welcome to " << name << "!" << endl;
    cout << "---------------------" << endl << endl;
	pokemon.startingPokemon();
	pokedex.initializePokedex();
	pokemon.displayPokemon();
	
	    while (true) {
        cout << "What would you like to do?" << endl;
        cout << "1. Inventory" << endl;
        cout << "2. Shop" << endl;
        cout << "3. Dungeon" << endl;
        cout << "4. Lord Mayor" << endl;
        cout << "5. Pokemon" << endl;
        cout << "6. Pokedex" << endl;
        cout << "7. Save Game " << endl;
        cout << "8. Back" << endl;

        int choice;
        while (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore();        }
		
        switch (choice) {
            case 1:
                cout << "Displaying inventory..." << endl;
                inventory.display();
                break;
            case 2:
                cout << "Visiting shop..." << endl;
                shop.visitShop(inventory);
                break;
            case 3:
                cout << "Generating dungeon..." << endl;
                dungeon.generateDungeon(name);
                dungeon.explore(4, inventory, pokemon);
                break;
            case 4:
                cout << "Visiting Lord Mayor..." << endl;
                lordMayor.beforeBattle(name, inventory , pokemon, win);
                if(battle.getHP() <= 0)
			    {
			    	win = true;
			    	lordMayor.afterBattle(name);
				}
				else
				{
					cout << "You has lose the battle. " << endl;
				}
                break;
            case 5:
                cout << "Displaying Pokemon..." << endl;
                pokemon.displayPokemon();
                break;
            case 6:
                cout << "Displaying Pokedex..." << endl;
                pokedex.findPokemonByType();
                break;
            case 7:
                cout<<"Saving Game..."<<endl;
                saveGame(pokemon,inventory);
            case 8:
            	cout << "Returning to the main menu..." << endl;
                return;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }
}

const string& City::getName() const {
    return name;
}

void City::setWin(bool win)
{
	win = true;
}

bool City::getWin()
{
	return win;
}
void City::saveGame(Pokemon& pokemon,Inventory& inventory) {
	string filename= "Database.txt";
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        return;
    }

    // Write the Pokemon linked list
    pokemon.writeToFile(filename);

    // Write the Inventory linked list
    inventory.writeToFile(filename);

    file.close();
}
