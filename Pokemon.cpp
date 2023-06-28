#include "pokemon.h"

Pokemon::Pokemon() : head(nullptr), newHead(nullptr)
{
	pokemonSelected = 0;
	damage = 0;
}

void Pokemon::copyPokemon(const Pokemon& other) {
    head = nullptr; // Assuming you have a linked list of pokemon, initialize the head of the copied list to nullptr
    
    // Copy the values from the 'other' object to the current object
    name = other.name;
    level = other.level;
    HP = other.HP;
    energy = other.energy;
    attack = other.attack;
    damage = other.damage;
    EXP = other.EXP;

    // Traverse the linked list in 'other' and copy each node
    pokemonList* otherNode = other.head;
    pokemonList* currentNode = nullptr;
    while (otherNode != nullptr) {
        // Create a new node
        pokemonList* newNode = new pokemonList;
        newNode->name = otherNode->name;
        newNode->type = otherNode->type;
        newNode->level = otherNode->level;
        newNode->HP = otherNode->HP;
        newNode->energy = otherNode->energy;
        newNode->attack = otherNode->attack;
        newNode->normalAttack = otherNode->normalAttack;
        newNode->skill1 = otherNode->skill1;
        newNode->skill2 = otherNode->skill2;
        newNode->EXP = otherNode->EXP;
        newNode->maxEnergy = otherNode->maxEnergy;
        newNode->maxHp = otherNode->maxHp;
        newNode->next = nullptr;

        // Add the new node to the copied list
        if (head == nullptr) {
            head = newNode;
            currentNode = head;
        } else {
            currentNode->next = newNode;
            currentNode = currentNode->next;
        }

        // Move to the next node in the 'other' list
        otherNode = otherNode->next;
    }
}

void Pokemon::startingPokemon()
{
	cout << "Here is your starting pokemon! \n" << endl;
	appendPokemon("Fire", "Charmander", 390, 100, 52, "Scratch", "Ember", "Flamethrower", 3, 50);
	appendPokemon("Grass", "Bulbasaur", 420, 100, 49, "Tackle", "Vine Whip", "Solar Beam", 1, 0);
	appendPokemon("Water", "Squirtle", 380, 100, 48, "Tackle", "Water Gun", "Hydro Pump", 1, 0);
	
}

void Pokemon::appendPokemon(string type, string name, int HP, int energy, int attack, string normalAttack, string skill1, string skill2, int level, int exp)
{
    pokemonList* newPokemon = new pokemonList;
    newPokemon->name = name;
    newPokemon->type = type;
    newPokemon->level = level;
    newPokemon->HP = HP;
    newPokemon->maxHp = HP;
    newPokemon->maxEnergy = energy;
    newPokemon->energy = energy;
    newPokemon->attack = attack;
    newPokemon->normalAttack = normalAttack;
    newPokemon->skill1 = skill1;
    newPokemon->skill2 = skill2;
    newPokemon->EXP = exp;
    newPokemon->next = nullptr;

    if (head == nullptr)
    {
        head = newPokemon;
    }
    else
    {
        pokemonList* ptr = head;
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = newPokemon;
    }
}

void Pokemon::battleStartPokemon()
{
	
    pokemonList* current = head;
    do {
    	
        name = current->name;
        level = current->level;
		EXP = current->EXP;
        HP = current->HP;
        energy = current->energy;
		
    } while (current != nullptr && current != head);
}

void Pokemon::traversePokemonList()
{
    pokemonList* current = head;
	int i=1;
	cout << "-----------------------" << endl;
	cout << "        POKEMON   " << endl;
	cout << "-----------------------" << endl;
    while (current != nullptr)
    {
        // Print or process the data of the current node
        cout << i << ". " << current->name << " Lv" << current->level << endl;
        // Move to the next node
        i++;
        current = current->next;
        
    }
    
	cout << "0. Back" << endl;
	cout << "Which pokemon you want to choose? ";
	int pokemonChosen;
	
	cin >> pokemonChosen;
	
	while (pokemonChosen < 0 || pokemonChosen > i-1) 
	{
	    cout << "Please choose a number between 0 and " << i-1 << ": ";
	    cin >> pokemonChosen;
	}
	
	if(pokemonChosen == 0) return;
	
	pokemonSelected = pokemonChosen-1;
	int initialPokemon = 0;
	
	pokemonList* currentName = head;
	while (currentName != nullptr && initialPokemon <= pokemonSelected)
	{
	    if (initialPokemon == pokemonSelected)
	    {
	        cout << endl << currentName->name << " has been choosen! " << endl;
	        name = currentName->name;
		    level = currentName->level;
		    HP = currentName->HP;
		    energy = currentName->energy;
	    }
	    currentName = currentName->next;
	    initialPokemon++;
	}
}
	

void Pokemon::pokemonFight()
{
    int initialPokemon = 0;
	int choice;
	pokemonList* current = head;
    while (current != nullptr && initialPokemon <= pokemonSelected)
    {
    	if (initialPokemon == pokemonSelected)
        {
        	cout << "-----------------------" << endl;
			cout << "         FIGHT   " << endl;
			cout << "-----------------------" << endl;
        	cout << "1. " << current->normalAttack << " (0 Energy)" << endl;
        	cout << "2. " << current->skill1 << " (30 Energy)" << endl;
        	cout << "3. " << current->skill2 << " (40 Energy)" << endl;
        	cout << "0. BACK" << endl;
        	cout << "Enter your choice: ";
	    	cin >> choice;
	    
	    	if((current->energy) - 30 <0 && choice == 2)
	    	{
	    		damage = 0;
	    		cout << "Not enough energy. Please choose other move." << endl;
	    		break;
			}
			
			else if((current->energy) - 40 <0 && choice == 3)
	    	{
	    		damage = 0;
	    		cout << "Not enough energy. Please choose other move." << endl;
	    		break;
			}
					
	    	switch(choice)
	    	{
	    		case 0:
	    			return;
	    		case 1:
	    			damage = current->attack;
	    			break;
	    		case 2:
					damage = (current->attack)*1.3;
					current->energy = (current->energy) - 30;
	    			energy = current->energy;
	    			break;	
	    			
	    		case 3:
	    			damage = (current->attack)*1.4;
	    			current->energy = (current->energy) - 40;
	    			energy = current->energy;
	    			break;
			}
			
            return;
        }
        current = current->next;
        initialPokemon++;
    }
}

void Pokemon::setHP(int hp)
{
    pokemonList* current = head;
    int count = 0;
	
    while (current != nullptr && count < pokemonSelected)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr)
    {
    	if(hp>current->maxHp)
    	{
    		current->HP =current->maxHp;
    		HP=current->HP;
		}
		else
		{
			current->HP = hp;
        	HP = current->HP;
		}
    }
}
void Pokemon::setEnergy(int newEnergy)
{
    pokemonList* current = head;
    int count = 0;
	
    while (current != nullptr && count < pokemonSelected)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr)
    {
    	if(newEnergy>current->maxEnergy)
    	{
    		current->energy = current->maxEnergy;
        	energy = current->energy;
		}
		else
		{
			current->energy = newEnergy;
        	energy = current->energy;
		}
        
    }
}
void Pokemon::setMaxEnergy(int newEnergy)
{
    pokemonList* current = head;
    int count = 0;
	
    while (current != nullptr && count < pokemonSelected)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr)
    {
    	int EnergyGained=newEnergy-(current->energy);
    	current->maxEnergy=current->maxEnergy+EnergyGained;
    }
}

void Pokemon::setMaxHP(int hp)
{
    pokemonList* current = head;
    int count = 0;
	
    while (current != nullptr && count < pokemonSelected)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr)
    {
    	int hpGained=hp-(current->HP);
    	current->maxHp=current->maxHp+hpGained;
    }
}

void Pokemon::setEXP(int exp)
{
	
	
    pokemonList* current = head;
    pokemonList* previous = nullptr;
    int count = 0;
	
    while (current != nullptr && count < pokemonSelected)
    {
        previous = current;
        current = current->next;
        count++;
    }

    if (current != nullptr)
    {
        current->EXP = exp;
        EXP = current->EXP;

        if (current->EXP >= 100)
        {
            current->level = (current->level) + 1;
            level = current->level;

            if (level == 4 && current->name == "Charmander")
            {
                appendPokemon("Fire", "Charmeleon", 580, 150, 64, "Ember", "Fire Fang", "Flamethrower", 1, 0);
                name = "Charmeleon";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Charmeleon")
            {
                appendPokemon("Fire", "Charizard", 780, 200, 84, "Fire Fang", "Wing Attack", "Fire Blast", 1, 0);
                name = "Charizard";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Growlithe")
            {
                appendPokemon("Fire", "Arcanine", 900, 200, 110, "Fire Fang", "Fire Blast", "Flamethrower", 1, 0);
                name = "Arcanine";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Bulbasaur")
            {
                appendPokemon("Grass", "Ivysaur", 610, 150, 62, "Vine Whip", "Razor Leaf", "Solar Beam", 1, 0);
                name = "Ivysaur";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Ivysaur")
            {
                appendPokemon("Grass", "Venusaur", 820, 200, 82, "Razor Leaf", "Sludge Bomb", "Solar Beam", 1, 0);
                name = "Venusaur";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Exeggcute")
            {
                appendPokemon("Grass", "Exeggutor", 950, 200, 95, "Bullet Seed", "Seed Bomb", "Solar Beam", 1, 0);
                name = "Exeggutor";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Squirtle")
            {
                appendPokemon("Water", "Wartortle", 590, 150, 63, "Water Gun", "Bite", "Hydro Pump", 1, 0);
                name = "Wartortle";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Wartortle")
            {
                appendPokemon("Water", "Blastoise", 800, 200, 83, "Bite", "Water Pulse", "Hydro Pump", 1, 0);
                name = "Blastoise";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Psyduck")
            {
                appendPokemon("Water", "Golduck", 800, 200, 82, "Water Gun", "Liquidation", "Hydro Pump", 1, 0);
                name = "Golduck";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Pikachu")
            {
                appendPokemon("Electric", "Raichu", 620, 200, 80, "Spark", "Thunder Shock", "Thunderbolt", 1, 0);
                name = "Raichu";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Magnemite")
            {
                appendPokemon("Electric", "Magneton", 550, 150, 85, "Charge Beam", "Discharge", "Zap Cannon", 1, 0);
                name = "Magneton";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }

			else if (level == 4 && current->name == "Magneton")
            {
                appendPokemon("Electric", "Magenezone", 780, 200, 95, "Thunder Shock", "Flash Cannon", "Zap Cannon", 1, 0);
                name = "Magenezone";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Diglet")
            {
                appendPokemon("Ground", "Dugtrio", 490, 200, 80, "Sucker Punch", "Earthquake", "Fissure", 1, 0);
                name = "Dugtrio";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Rhyhorn")
            {
                appendPokemon("Ground", "Rhydon", 900, 100, 95, "Mud-Slap", "Bulldoze", "Earthquake", 1, 0);
                name = "Rhydon";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Rhydon")
            {
                appendPokemon("Ground", "Rhyperior", 1100, 100, 105, "Mud-Slap", "Bulldoze", "Earthquake", 1, 0);
                name = "Rhyperior";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Bagon")
            {
                appendPokemon("Dragon", "Salamence", 950, 200, 135, "Wrap", "Dragon Tail", "Aqua Tail", 1, 0);
                name = "Salamence";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Dratini")
            {
                appendPokemon("Dragon", "Dragonair", 800, 200, 100, "Slam", "Dragon Rush", "Outrage", 1, 0);
                name = "Dragonair";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            else if (level == 4 && current->name == "Dragonair")
            {
                appendPokemon("Dragon", "Dragonite", 1100, 250, 150, "Dragon Tail", "Dragon Claw", "Hyper Beam", 1, 0);
                name = "Dragonite";
                if (previous != nullptr)
                    previous->next = current->next;
                else
                    head = current->next;
                delete current;
                current = nullptr;
            }
            
            if (current != nullptr)
            {
                current->EXP = current->EXP-100;
                EXP = current->EXP;
                current->attack = (current->attack) + 3;
                current->HP = (current->HP) + 40;
                current->energy = (current->energy) + 10;
            }
        }
    }
}


string Pokemon::getName()
{
	return name;
}

int Pokemon::getLevel()
{
	return level;
}

int Pokemon::getHP()
{
	return HP;
}

int Pokemon::getEnergy()
{
	return energy;
}
	
int Pokemon::getDamage()
{
	return damage;
}

int Pokemon::getEXP()
{
	return EXP;
}

void Pokemon::displayPokemon()
{
	pokemonList* ptr = head;
	while (ptr)
	{
		
		cout << ptr->name << " Lv";
		cout << ptr->level << endl;
		cout << "EXP: " << ptr->EXP << endl;
		cout << "HP: " << ptr->HP << endl;
		cout << "Energy: " << ptr->energy << endl;
		cout << "Attack: " << ptr->attack << endl;
		cout << "Normal Attack: " << ptr->normalAttack << " (" << ptr->attack << " damages)" << endl;
		cout << "Skill 1: " << ptr->skill1 << " (" << static_cast<int>((ptr->attack)*1.3) << " damages)" << endl;
		cout << "Skill 2: " << ptr->skill2 << " (" << static_cast<int>((ptr->attack)*1.4) << " damages)" << endl<< endl;
		ptr = ptr->next;
	}
	
	
}

void Pokemon::saveData(const string& filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        pokemonList* current = head;
        while (current != nullptr)
        {
            savePokemonData(file, current);
            current = current->next;
        }
        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void Pokemon::loadData(const string& filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line == "Pokemon")
            {
                pokemonList* pokemon = nullptr;  // Create a pointer to a pokemonList object
                loadPokemonData(file, pokemon);  // Pass the file object as the argument
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}




void Pokemon::savePokemonData(ofstream& file,  pokemonList* pokemon)
{
    if (pokemon != nullptr)
    {
        file << "Name: " << pokemon->name << endl;
        file << "Type: " << pokemon->type << endl;
        file << "Level: " << pokemon->level << endl;
        file << "HP: " << pokemon->HP << endl;
        file << "Energy: " << pokemon->energy << endl;
        file << "Attack: " << pokemon->attack << endl;
        file << "Normal Attack: " << pokemon->normalAttack << endl;
        file << "Skill 1: " << pokemon->skill1 << endl;
        file << "Skill 2: " << pokemon->skill2 << endl;
        file << "EXP: " << pokemon->EXP << endl;
        file << "Max Energy: " << pokemon->maxEnergy << endl;
        file << "Max HP: " << pokemon->maxHp << endl;
        file << endl;
    }
}

void Pokemon::loadPokemonData(ifstream& file,  pokemonList* pokemon)
{
    string line;
    getline(file, line); // Read the empty line

    string name, type, normalAttack, skill1, skill2;
    int level, HP, energy, attack, EXP, maxEnergy, maxHP;

    // Read and parse each line
    while (getline(file, line))
    {
        if (line == "")
            break;

        stringstream ss(line);
        string key, value;
        getline(ss, key, ':');
        getline(ss, value);

        if (key == "Name")
            name = value;
        else if (key == "Type")
            type = value;
        else if (key == "Level")
            level = stoi(value);
        else if (key == "HP")
            HP = stoi(value);
        else if (key == "Energy")
            energy = stoi(value);
        else if (key == "Attack")
            attack = stoi(value);
        else if (key == "Normal Attack")
            normalAttack = value;
        else if (key == "Skill 1")
            skill1 = value;
        else if (key == "Skill 2")
            skill2 = value;
        else if (key == "EXP")
            EXP = stoi(value);
        else if (key == "Max Energy")
            maxEnergy = stoi(value);
        else if (key == "Max HP")
            maxHP = stoi(value);
    }

    // Create a new Pokemon node and assign the values
    pokemonList* newPokemon = new pokemonList();
    newPokemon->name = name;
    newPokemon->type = type;
    newPokemon->level = level;
    newPokemon->HP = HP;
    newPokemon->energy = energy;
    newPokemon->attack = attack;
    newPokemon->normalAttack = normalAttack;
    newPokemon->skill1 = skill1;
    newPokemon->skill2 = skill2;
    newPokemon->EXP = EXP;
    newPokemon->maxEnergy = maxEnergy;
    newPokemon->maxHp = maxHP;
    newPokemon->next = nullptr;

    // Attach the new Pokemon node to the Pokemon list
    if (head == nullptr)
        head = newPokemon;
    else
    {
        pokemonList* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newPokemon;
    }
}
// Function to write the Pokemon linked list to a file
    void Pokemon::writeToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file!" << std::endl;
            return;
        }

        file << "Pokemon Linked List:" << std::endl;
        pokemonList* temp = head;
        int pokemonCount = 1;
        while (temp != nullptr) {
            file << "Pokemon " << pokemonCount << ":" << std::endl;
            file << "Name: " << temp->name << std::endl;
            file << "Type: " << temp->type << std::endl;
            file << "Level: " << temp->level << std::endl;
            file << "HP: " << temp->HP << std::endl;
            file << "Energy: " << temp->energy << std::endl;
            file << "Attack: " << temp->attack << std::endl;
            file << "Normal Attack: " << temp->normalAttack << std::endl;
            file << "Skill 1: " << temp->skill1 << std::endl;
            file << "Skill 2: " << temp->skill2 << std::endl;
            file << "EXP: " << temp->EXP << std::endl;
            file << "Max Energy: " << temp->maxEnergy << std::endl;
            file << "Max HP: " << temp->maxHp << std::endl;
            file << std::endl;

            temp = temp->next;
            pokemonCount++;
        }
}

