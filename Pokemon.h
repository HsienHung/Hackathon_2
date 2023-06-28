#ifndef POKEMON_H
#define POKEMON_H
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

class Pokemon
{
private:
	struct pokemonList
	{
		string name;
		string type;
		int level;
		int HP;
		int energy;
		int attack;
		string normalAttack;
		string skill1;
		string skill2;
		int EXP;
		int maxEnergy;
		int maxHp;
		
		pokemonList* next;
	};
	
	pokemonList* head;
	int pokemonSelected;
	string name;
	int level;
	int HP;
	int energy;
	int attack;
	int damage;
	int EXP;
//	int MAX_HP;
//	int MAX_Energy;
    pokemonList* newHead;

	
public:
	Pokemon(); // Constructor
	void copyPokemon(const Pokemon& other);
	void startingPokemon();
	void setMaxHP(int);
	void appendPokemon(string name, string type, int HP, int energy, int attack, string normalAttack, string skill1, string skill2, int level, int exp);
	void displayPokemon();
	void battleStartPokemon();
	void traversePokemonList();
	void pokemonFight();
	void setHP(int newHP);
	void setEXP(int exp);
	string getName();
	int getLevel();
	int getHP();
	int getEnergy();
	int getDamage();
	int getEXP();
	void setEnergy(int );
	void setMaxEnergy(int );
	
	void saveData(const string& filename);
    void loadData(const string& filename);
   void savePokemonData(std::ofstream& file, pokemonList* pokemon);
    void loadPokemonData(std::ifstream& file, pokemonList* pokemon);
    void writeToFile(const std::string& filename);

	
};

#endif // POKEMON_H
