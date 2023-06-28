#include "pokedex.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Pokedex::Pokedex() : head(nullptr) {}

Pokedex::~Pokedex() {
    TypeNode* currentTypeNode = head;
    while (currentTypeNode != nullptr) {
        PokemonInfo* currentPokemon = currentTypeNode->pokemonList;
        while (currentPokemon != nullptr) {
            PokemonInfo* temp = currentPokemon;
            currentPokemon = currentPokemon->next;
            delete temp;
        }
        TypeNode* temp = currentTypeNode;
        currentTypeNode = currentTypeNode->next;
        delete temp;
    }
}

TypeNode* Pokedex::findTypeNode(const string& type) {
    TypeNode* current = head;
    while (current != nullptr) {
        if (current->type == type) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void Pokedex::addPokemon(string type, string pokemonName, int HP, int energy, int attack, string normalAttack, string skill1, string skill2, int level, int exp)
{
    PokemonInfo* newPokemon = new PokemonInfo(pokemonName);
    newPokemon->HP = HP;
    newPokemon->energy = energy;
    newPokemon->attack = attack;
    newPokemon->normalAttack = normalAttack;
    newPokemon->skill1 = skill1;
    newPokemon->skill2 = skill2;
    newPokemon->level = level;
    newPokemon->exp = exp;
    newPokemon->next = nullptr;

    TypeNode* currentTypeNode = findTypeNode(type);
    if (currentTypeNode == nullptr) {
        currentTypeNode = new TypeNode(type);
        currentTypeNode->next = head;
        head = currentTypeNode;
    }

    newPokemon->next = currentTypeNode->pokemonList;
    currentTypeNode->pokemonList = newPokemon;
}

void Pokedex::initializePokedex()
{
	addPokemon("Dragon", "Rayquaza", 1300, 350, 170, "Dragon Tail", "Dragon Pulse", "Outrage",1,0);
	addPokemon("Dragon", "Dragonite", 1100, 250, 150, "Dragon Tail", "Dragon Claw", "Outrage",1,0);
    addPokemon("Dragon", "Dragonair", 800, 200, 100, "Slam", "Dragon Rush", "Outrage",1,0);
    addPokemon("Dragon", "Dratini", 450, 150, 75, "Wrap", "Dragon Tail", "Aqua Tail",1,0);
    addPokemon("Dragon", "Salamence", 950, 200, 135, "Wrap", "Dragon Tail", "Aqua Tail",1,0);
    addPokemon("Dragon", "Bagon", 450, 100, 75, "Wrap", "Dragon Tail", "Aqua Tail",1,0);
    addPokemon("Ground", "Groudon", 1100, 300, 150, "Mud-Shot", "Earth Power", "Earthquake",1,0);
   	addPokemon("Ground", "Rhyperior", 1100, 200, 105, "Mud-Slap", "Bulldoze", "Earthquake",1,0);
   	addPokemon("Ground", "Rhydon", 900, 150, 95, "Mud-Slap", "Bulldoze", "Earthquake",1,0);
   	addPokemon("Ground", "Rhyhorn", 700, 100, 75, "Mud-Slap", "Bulldoze", "Earthquake",1,0);
 	addPokemon("Ground", "Dugtrio", 490, 200, 80, "Sucker Punch", "Earthquake", "Fissure",1,0);
   	addPokemon("Ground", "Diglet", 260, 100, 55, "Scratch", "Mud Slap", "Dig",1,0);
   	addPokemon("Electric", "Zapdos", 1100, 300, 105, "Thunder Wave", "Thunder", "Zap Cannon",1,0);
   	addPokemon("Electric", "Magenezone", 780, 200, 95, "Thunder Shock", "Flash Cannon", "Zap Cannon",1,0);
   	addPokemon("Electric", "Magneton", 550, 150, 85, "Charge Beam", "Discharge", "Zap Cannon",1,0);
   	addPokemon("Electric", "Magnemite", 300, 100, 60, "Spark", "Discharge", "Thunder Bolt",1,0);       
    addPokemon("Electric", "Raichu", 620, 200, 80, "Spark", "Thunder Shock", "Thunderbolt",1,0);
    addPokemon("Electric", "Pikachu", 420, 100, 55, "Quick Attack", "Thunder Shock", "Thunderbolt",1,0);     
	addPokemon("Water", "Kyogre", 1050, 300, 110, "Water Pulse", "Muddy Water", "Water Spout",1,0); 
	addPokemon("Water", "Golduck", 800, 200, 82, "Water Gun", "Liquidation", "Hydro Pump",1,0);
    addPokemon("Water", "Psyduck", 500, 100, 52, "Water Gun", "Aqua Tail", "Water Pulse",1,0);
    addPokemon("Water", "Blastoise", 800, 200, 83, "Bite", "Water Pulse", "Hydro Pump",1,0);
    addPokemon("Water", "Wartortle", 590, 150, 63, "Water Gun", "Bite", "Hydro Pump",1,0);
    addPokemon("Water", "Squirtle", 380, 100, 48, "Tackle", "Water Gun", "Hydro Pump",1,0);  
	addPokemon("Grass", "Cresselia", 1200, 300, 105, "Grass Knot", "Enery Ball", "Solar Beam",1,0);      
	addPokemon("Grass", "Exeggutor", 950, 200, 95, "Bullet Seed", "Seed Bomb", "Solar Beam",1,0);
    addPokemon("Grass", "Exeggcute", 600, 100, 40, "Bullet Seed", "Seed Bomb", "Solar Beam",1,0);        
    addPokemon("Grass", "Venusaur", 820, 200, 82, "Razor Leaf", "Sludge Bomb", "Solar Beam",1,0);
    addPokemon("Grass", "Ivysaur", 610, 150, 62, "Vine Whip", "Razor Leaf", "Solar Beam",1,0);
    addPokemon("Grass", "Bulbasaur", 420, 100, 49, "Tackle", "Vine Whip", "Solar Beam",1,0);
    addPokemon("Fire", "Moltres", 1000, 300, 120, "Ember", "Incinerate", "Overheat",1,0);
	addPokemon("Fire", "Arcanine", 900, 200, 110, "Fire Fang", "Fire Blast", "Flamethrower",1,0);
    addPokemon("Fire", "Growlithe", 550, 100, 70, "Ember", "Flame Wheel", "Flamethrower",1,0);
    addPokemon("Fire", "Charizard", 780, 200, 84, "Fire Fang", "Wing Attack", "Fire Blast",1,0);
    addPokemon("Fire", "Charmeleon", 580, 150, 64, "Ember", "Fire Fang", "Flamethrower",1,0);   	    	
    addPokemon("Fire", "Charmander", 390, 100, 52, "Scratch", "Ember", "Flamethrower",1,0);
}

void Pokedex::displayFirePokemons()
{
    TypeNode* current = findTypeNode("Fire");
    if (current == nullptr) {
        cout << "No Fire type Pokemons found in the Pokedex." << endl;
        return;
    }
    cout << "Fire type Pokemons:" << endl;
    PokemonInfo* currentPokemon = current->pokemonList;
    while (currentPokemon != nullptr) {
        cout << "Name: " << currentPokemon->name << endl;
        cout << "HP: " << currentPokemon->HP << endl;
        cout << "Energy: " << currentPokemon->energy << endl;
        cout << "Attack: " << currentPokemon->attack << endl;
        cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
        cout << "Skill 1: " << currentPokemon->skill1 << endl;
        cout << "Skill 2: " << currentPokemon->skill2 << endl;
        cout << endl;
        currentPokemon = currentPokemon->next;
    }
}

void Pokedex::displayGrassPokemons()
{
     TypeNode* grassTypeNode = findTypeNode("Grass");
        if (grassTypeNode != nullptr) {
            cout << "\nGrass Type Pokemons: " << endl;
            PokemonInfo* currentPokemon = grassTypeNode->pokemonList;
            while (currentPokemon != nullptr) {
                cout << "Name: " << currentPokemon->name << endl;
                cout << "HP: " << currentPokemon->HP << endl;
                cout << "Energy: " << currentPokemon->energy << endl;
                cout << "Attack: " << currentPokemon->attack << endl;
                cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
                cout << "Skill 1: " << currentPokemon->skill1 << endl;
                cout << "Skill 2: " << currentPokemon->skill2 << endl;
                cout << endl;

                currentPokemon = currentPokemon->next;
            }
        } else {
            cout << "No Grass Type Pokemons found." << endl;
        }
}

void Pokedex::displayWaterPokemons()
{
        TypeNode* waterTypeNode = findTypeNode("Water");
        if (waterTypeNode != nullptr) {
            cout << "\nWater Type Pokemons: " << endl;
            PokemonInfo* currentPokemon = waterTypeNode->pokemonList;
            while (currentPokemon != nullptr) {
                cout << "Name: " << currentPokemon->name << endl;
                cout << "HP: " << currentPokemon->HP << endl;
                cout << "Energy: " << currentPokemon->energy << endl;
                cout << "Attack: " << currentPokemon->attack << endl;
                cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
                cout << "Skill 1: " << currentPokemon->skill1 << endl;
                cout << "Skill 2: " << currentPokemon->skill2 << endl;
                cout << endl;

                currentPokemon = currentPokemon->next;
            }
        } else {
            cout << "No Water Type Pokemons found." << endl;
        }
}

void Pokedex::displayElectricPokemons()
{
    TypeNode* electricTypeNode = findTypeNode("Electric");
        if (electricTypeNode != nullptr) {
            cout << "\nElectric Type Pokemons: " << endl;
            PokemonInfo* currentPokemon = electricTypeNode->pokemonList;
            while (currentPokemon != nullptr) {
                cout << "Name: " << currentPokemon->name << endl;
                cout << "HP: " << currentPokemon->HP << endl;
                cout << "Energy: " << currentPokemon->energy << endl;
                cout << "Attack: " << currentPokemon->attack << endl;
                cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
                cout << "Skill 1: " << currentPokemon->skill1 << endl;
                cout << "Skill 2: " << currentPokemon->skill2 << endl;
                cout << endl;

                currentPokemon = currentPokemon->next;
            }
        } else {
            cout << "No Electric Type Pokemons found." << endl;
        }
}

void Pokedex::displayGroundPokemons()
{
   TypeNode* groundTypeNode = findTypeNode("Ground");
        if (groundTypeNode != nullptr) {
            cout << "\nGround Type Pokemons: " << endl;
            PokemonInfo* currentPokemon = groundTypeNode->pokemonList;
            while (currentPokemon != nullptr) {
                cout << "Name: " << currentPokemon->name << endl;
                cout << "HP: " << currentPokemon->HP << endl;
                cout << "Energy: " << currentPokemon->energy << endl;
                cout << "Attack: " << currentPokemon->attack << endl;
                cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
                cout << "Skill 1: " << currentPokemon->skill1 << endl;
                cout << "Skill 2: " << currentPokemon->skill2 << endl;
                cout << endl;

                currentPokemon = currentPokemon->next;
            }
        } else {
            cout << "No Ground Type Pokemons found." << endl;
        }
}

void Pokedex::displayDragonPokemons()
{
    TypeNode* dragonTypeNode = findTypeNode("Dragon");
        if (dragonTypeNode != nullptr) {
            cout << "\nDragon Type Pokemons: " << endl;
            PokemonInfo* currentPokemon = dragonTypeNode->pokemonList;
            while (currentPokemon != nullptr) {
                cout << "Name: " << currentPokemon->name << endl;
                cout << "HP: " << currentPokemon->HP << endl;
                cout << "Energy: " << currentPokemon->energy << endl;
                cout << "Attack: " << currentPokemon->attack << endl;
                cout << "Normal Attack: " << currentPokemon->normalAttack << endl;
                cout << "Skill 1: " << currentPokemon->skill1 << endl;
                cout << "Skill 2: " << currentPokemon->skill2 << endl;
                cout << endl;

                currentPokemon = currentPokemon->next;
            }
        } else {
            cout << "No Dragon Type Pokemons found." << endl;
        }
}

void Pokedex::findPokemonByType()
{
    while (true)
    {
    	cout << "\n-------------"<< endl;
    	cout << "   POKEDEX" << endl;
    	cout << "-------------"<< endl;
        cout << "1. Fire Type" << endl;
        cout << "2. Grass Type" << endl;
        cout << "3. Water Type" << endl;
        cout << "4. Electric Type" << endl;
        cout << "5. Ground Type" << endl;
        cout << "6. Dragon Type" << endl;
        cout << "0. Exit" << endl;
        cout << "Please select the type of Pokemon: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
            case 0:
                return;  // Exit the function and return to the caller

            case 1:
                displayFirePokemons();
                break;
            case 2:
                displayGrassPokemons();
                break;
            case 3:
                displayWaterPokemons();
                break;
            case 4:
                displayElectricPokemons();
                break;
            case 5:
                displayGroundPokemons();
                break;
            case 6:
                displayDragonPokemons();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
        
        cout << "Press any key to go back: ";
        string back;
        cin.ignore();
        getline(cin, back);
    }
}

void Pokedex::generatePokemon(Battle& battle, string cityName)
{	
    static bool initialized = false;
    if (!initialized)
    {
        srand(time(0));
        initialized = true;
    }
	
    int pokemonSelected = rand() % 5;
    int initialPokemon = 0;
	
	string type;
	
	if (cityName == "Lavaridge Town") 
		type = "Fire";
	else if (cityName == "Eterna City") 
	    type = "Grass";
	else if (cityName == "Mossdeep City") 
	    type = "Water";
	else if (cityName == "Vermilion City") 
	    type = "Electric";
	else if (cityName == "Driftveil City") 
	    type = "Ground";
	else if (cityName == "Blackthorn City") 
	    type = "Dragon";
	
    TypeNode* pokemonType = findTypeNode(type);
	
	battle.setType(type);
    PokemonInfo* currentPokemon = pokemonType->pokemonList;
    while (currentPokemon != nullptr && initialPokemon <= pokemonSelected)
    {
        if (initialPokemon == pokemonSelected)
        {
            battle.setName(currentPokemon->name);
            battle.setHP(currentPokemon->HP);
            battle.setEnergy(currentPokemon->energy);
            battle.setAttack(currentPokemon->attack);
            battle.setNormalAttack(currentPokemon->normalAttack);
            battle.setSkill1(currentPokemon->skill1);
            battle.setSkill2(currentPokemon->skill2);
            return;
        }

        currentPokemon = currentPokemon->next;
        initialPokemon++;
    }
}

void Pokedex::generateBoss(Battle& battle, string cityName)
{	

    int pokemonSelected = 5;
    int initialPokemon = 0;
	
	string type;
	
	if (cityName == "Lavaridge Town") 
		type = "Fire";
	else if (cityName == "Eterna City") 
	    type = "Grass";
	else if (cityName == "Mossdeep City") 
	    type = "Water";
	else if (cityName == "Vermilion City") 
	    type = "Electric";
	else if (cityName == "Driftveil City") 
	    type = "Ground";
	else if (cityName == "Blackthorn City") 
	    type = "Dragon";
	
    TypeNode* pokemonType = findTypeNode(type);
	
	battle.setType(type);
    PokemonInfo* currentPokemon = pokemonType->pokemonList;
    while (currentPokemon != nullptr && initialPokemon <= pokemonSelected)
    {
        if (initialPokemon == pokemonSelected)
        {
            battle.setName(currentPokemon->name);
            battle.setHP(currentPokemon->HP);
            battle.setEnergy(currentPokemon->energy);
            battle.setAttack(currentPokemon->attack);
            battle.setNormalAttack(currentPokemon->normalAttack);
            battle.setSkill1(currentPokemon->skill1);
            battle.setSkill2(currentPokemon->skill2);
            return;
        }

        currentPokemon = currentPokemon->next;
        initialPokemon++;
    }
}



