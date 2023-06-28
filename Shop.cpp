#include "Shop.h"
#include <iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

Shop::Shop(Inventory& inventory)
    : inventory(inventory), coins(100) {
    // Rest of the constructor's implementation
}

//Shop::Shop(const Inventory& inventory, const string& cityname, Pokemon& pokemon)
//    : coins(0), inventory(inventory), pokemon(pokemon), name(cityname) {}

	int Shop::getCoins()const
	{
		return coins;
	}
	void Shop::setCoins(int num)
	{
		coins=num;
	}

    void Shop::visitShop(Inventory& inventory) {
        cout << endl;
        cout << "Welcome to the Shop!" << endl;
        cout << "---------------------" << endl << endl;

        while (true) {
            cout << "What would you like to do?" << endl;
            cout << "1. Buy items" << endl;
            cout << "2. Return to main menu" << endl;

            int choice;
            while (!(cin >> choice)) {
                cout << "Invalid input. Please enter a number." << endl;
                cin.clear();
            }

            switch (choice) {
                case 1:
                    buyItems(inventory);
                    break;
                case 2:
                    cout << "Returning to the main menu..." << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        }
    }


    void Shop::buyItems(Inventory& inventory) {
        cout << endl;
        cout << "Your current coins: " << getCoins() << endl;
        cout << "1. Pokeball" << endl;
        cout << "2. Health Reagent" << endl;
        cout << "3. EnergyWave" << endl;
        cout << "4. Elixir" << endl;
        cout << "5. Back" << endl;
		cout << "What would you like to buy?";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << endl;
                cout << "Pokeball options:" << endl;
                cout << "1. Pokeball - Cost: 5 coins" << endl;
                cout << "2. Great ball - Cost: 10 coins" << endl;
                cout << "3. Ultra ball - Cost: 15 coins" << endl;

                int pokeballChoice;
                cin >> pokeballChoice;

                switch (pokeballChoice) {
                    case 1:
                        buyPokeball("Pokeball");
                        inventory.increaseQuantity("Pokeball",1);
                        break;
                    case 2:
                        buyPokeball("Great ball");
                        inventory.increaseQuantity("Great ball",1);
                        break;
                    case 3:
                        buyPokeball("Ultra ball");
                        inventory.increaseQuantity("Ultra ball",1);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            }
            case 2: {
                cout << endl;
                cout << "Health Reagent options:" << endl;
                cout << "1. Super Potion - Cost: 10 coins" << endl;
                cout << "2. Hyper Potion - Cost: 20 coins" << endl;
                cout << "3. Max Potion - Cost: 30 coins" << endl;

                int healthReagentChoice;
                cin >> healthReagentChoice;

                switch (healthReagentChoice) {
                    case 1:
                        buyHealthReagent("Super Potion");
                        inventory.increaseQuantity("Super Potion",1);
                        break;
                    case 2:
                        buyHealthReagent("Hyper Potion");
                        inventory.increaseQuantity("Hyper Potion",1);
                        break;
                    case 3:
                        buyHealthReagent("Max Potion");
                        inventory.increaseQuantity("Max Potion",1);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            }
            case 3: {
                cout << endl;
                cout << "EnergyWave options:" << endl;
                cout << "1. EnergyWave Spark - Cost: 10 coins" << endl;
                cout << "2. EnergyWave Surge - Cost: 20 coins" << endl;
                cout << "3. EnergyWave Blast - Cost: 30 coins" << endl;

                int energyWaveChoice;
                cin >> energyWaveChoice;

                switch (energyWaveChoice) {
                    case 1:
                        buyEnergyWave("EnergyWave Spark");
                        inventory.increaseQuantity("EnergyWave Spark",1);
                        break;
                    case 2:
                        buyEnergyWave("EnergyWave Surge");
                        inventory.increaseQuantity("EnergyWave Surge",1);
                        break;
                    case 3:
                        buyEnergyWave("EnergyWave Blast");
                        inventory.increaseQuantity("EnergyWave Blast",1);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            }
            case 4: {
                cout << endl;
                cout << "Elixir options:" << endl;
                cout << "1. Novice Elixir - Cost: 10 coins" << endl;
                cout << "2. Adept Elixir - Cost: 20 coins" << endl;
                cout << "3. Elite Elixir - Cost: 30 coins" << endl;

                int elixirChoice;
                cin >> elixirChoice;

                switch (elixirChoice) {
                    case 1:
                        buyElixir("Novice Elixir");
                        inventory.increaseQuantity("Novice Elixir",1);
                        break;
                    case 2:
                        buyElixir("Adept Elixir");
                        inventory.increaseQuantity("Adept Elixir",1);
                        break;
                    case 3:
                        buyElixir("Elite Elixir");
                        inventory.increaseQuantity("Elite Elixir",1);
                        break;
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                }
                break;
            }
            case 5:
                cout << "Returning to Shop menu..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    void Shop::buyPokeball(const string& pokeball) {
        cout << endl;
        cout << "Buying " << pokeball << "..." << endl;
        cout << "You have successfully bought " << pokeball << "!" << endl;

        // Deduct coins based on pokeball type
        int cost = getPokeballCost(pokeball);
        coins -= cost;

        cout << "Remaining coins: " << coins << " coins" << endl;
    }

    void Shop::buyHealthReagent(const string& reagent) {
        cout << endl;
        cout << "Buying " << reagent << "..." << endl;
        cout << "You have successfully bought " << reagent << "!" << endl;
        
        // Deduct coins based on reagent type
        int cost = getHealthReagentCost(reagent);
        coins -= cost;

        cout << "Remaining coins: " << coins << " coins" << endl;
    }

    void Shop::buyEnergyWave(const string& wave) {
        cout << endl;
        cout << "Buying " << wave << "..." << endl;
        cout << "You have successfully bought " << wave << "!" << endl;

        // Deduct coins based on wave type
        int cost = getElixirCost(wave);
        coins -= cost;

        cout << "Remaining coins: " << coins << " coins" << endl;
    }
    
    void Shop::buyElixir(const string& elixir) {
        cout << endl;
        cout << "Buying " << elixir << "..." << endl;
        cout << "You have successfully bought " << elixir << "!" << endl;

        // Deduct coins based on wave type
        int cost = getEnergyWaveCost(elixir);
        coins -= cost;

        cout << "Remaining coins: " << coins << " coins" << endl;
    }

    int Shop::getPokeballCost(const string& pokeball) {
        if (pokeball == "Pokeball") {
            return 5;
        } else if (pokeball == "Great ball") {
            return 10;
        } else if (pokeball == "Ultra ball") {
            return 15;
        }

        return 0;
    }

    int Shop::getHealthReagentCost(const string& reagent) {
        if (reagent == "Super Potion") {
            return 20;
        } else if (reagent == "Hyper Potion") {
            return 50;
        } else if (reagent == "Max Potion") {
            return 100;
        }

        return 0;
    }

    int Shop::getEnergyWaveCost(const string& wave) {
        if (wave == "EnergyWave Spark") {
            return 10;
        } else if (wave == "EnergyWave Surge") {
            return 20;
        } else if (wave == "EnergyWave Blast") {
            return 30;
        }

        return 0;
    }
    
    int Shop::getElixirCost(const string& reagent) {
        if (reagent == "Novice Elixir") {
            return 10;
        } else if (reagent == "Adept Elixir") {
            return 20;
        } else if (reagent == "Elite Elixir") {
            return 30;
        }

        return 0;
    }

//    void Shop::playGacha() {
//    cout << endl;
//    cout << "Welcome to Gacha!" << endl;
//    cout << "Please insert 10 coins to play." << endl;
//
//    if (coins < 10) {
//        cout << "Not enough coins to play Gacha." << endl;
//        return;
//    }
//
//    coins -= 10;
//
//    cout << "Prize Pool:" << endl;
//    cout << "1. Pokeball" << endl;
//    cout << "2. Great Ball" << endl;
//    cout << "3. Ultra Ball" << endl;
//    cout << "4. EnergyWave Spark" << endl;
//    cout << "5. EnergyWave Surge" << endl;
//    cout << "6. EnergyWave Blast" << endl;
//    cout << "7. Mystery Powerful Pokemon" << endl<<endl;
//
//    srand(time(0)); // seed the random number generator
//
//    int randomNumber = rand() % 100 + 1; // generate a random number between 1 and 100
//
//	if (randomNumber >98)
//	{
//		if(name=="Lavaridge Town")
//		{
//			cout<<"Congratulations! You won a Charizard " <<endl;
//			pokemon.appendPokemon("Fire", "Charizard", 780, 200, 84, "Fire Fang", "Wing Attack", "Fire Blast",1, 0);
//		}
//		else if(name=="Eterna City")
//		{
//			cout<<"Congratulations! You won a Venusaur " <<endl;
//			pokemon.appendPokemon("Grass", "Venusaur", 820, 200, 82, "Razor Leaf", "Sludge Bomb", "Solar Beam", 1, 0);
//		}
//		else if(name=="Mossdeep City")
//		{
//			cout<<"Congratulations! You won a Blastoise " <<endl;
//			pokemon.appendPokemon("Water", "Blastoise", 800, 200, 83, "Bite", "Water Pulse", "Hydro Pump", 1,0);
//		}
//		else if(name=="Vermilion City")
//		{
//			cout<<"Congratulations! You won a Raichu " <<endl;
//			pokemon.appendPokemon("Electric", "Raichu", 620, 200, 80, "Spark", "Thunder Shock", "Thunderbolt", 1,0);
//		}
//		else if(name=="Driftveil City")
//		{
//			cout<<"Congratulations! You won a Rhyperior " <<endl;
//			pokemon.appendPokemon("Ground/Rock", "Rhyperior", 1100, 100, 105, "Mud-Slap", "Bulldoze", "Earthquake", 1,0);
//		}
//		else
//		{
//			cout<<"Congratulations! You won a Dragonite " <<endl;
//			pokemon.appendPokemon("Dragon", "Dragonite",  1100, 250, 150, "Dragon Tail", "Dragon Claw", "Hyper Beam",1,0);
//
//		}
		
		
//	}		
//		else if (randomNumber <= 98 && randomNumber >=42) {
//        // Prize is a pokeball
//        int pokeballChoice = rand() % 3 + 1;
//        switch (pokeballChoice) {
//            case 1:
//                cout << "Congratulations! You won a Pokeball!" << endl;
//                inventory.increaseQuantity("Pokeball", 1);
//                break;
//            case 2:
//                cout << "Congratulations! You won a Great Ball!" << endl;
//                inventory.increaseQuantity("Great Ball", 1);
//                break;
//            case 3:
//                cout << "Congratulations! You won an Ultra Ball!" << endl;
//                inventory.increaseQuantity("Ultra Ball", 1);
//                break;
//        }
//    } else {
//        // Prize is an EnergyWave
//        int energyWaveChoice = rand() % 3 + 1;
//        switch (energyWaveChoice) {
//            case 1:
//                cout << "Congratulations! You won an EnergyWave Spark!" << endl;
//                inventory.increaseQuantity("EnergyWave Spark", 1);
//                break;
//            case 2:
//                cout << "Congratulations! You won an EnergyWave Surge!" << endl;
//                inventory.increaseQuantity("EnergyWave Surge", 1);
//                break;
//            case 3:
//                cout << "Congratulations! You won an EnergyWave Blast!" << endl;
//                inventory.increaseQuantity("EnergyWave Blast", 1);
//                break;
//        }
//    }
//
//    cout << "Remaining coins: " << coins << " coins" << endl;
//}



