#ifndef POKEDEX_H
#define POKEDEX_H

#include <iostream>
#include <string>
#include "Battle.h"
using namespace std;

struct PokemonInfo 
{
    string name;
    int HP;
    int energy;
    int attack;
    string normalAttack;
    string skill1;
    string skill2;
    PokemonInfo* next;
    int level;
    int exp;

    PokemonInfo(const string& name) : name(name), next(nullptr) {}
};

struct TypeNode {
    string type;
    PokemonInfo* pokemonList;
    TypeNode* next;

    TypeNode(const string& type) : type(type), pokemonList(nullptr), next(nullptr) {}
};

class Pokedex {
private:
    TypeNode* head;

public:
    Pokedex();
    ~Pokedex();

    TypeNode* findTypeNode(const string& type);
    void addPokemon(string type, string pokemonName, int HP, int energy, int attack, string normalAttack, string skill1, string skill2, int level, int exp);
    void initializePokedex();
    void displayFirePokemons();
    void displayGrassPokemons();
    void displayWaterPokemons();
    void displayElectricPokemons();
    void displayGroundPokemons();
    void displayDragonPokemons();
    void findPokemonByType();
	void generatePokemon(Battle& , string);
	void generateBoss(Battle& , string);
//    void generatePokemon();

};

#endif

