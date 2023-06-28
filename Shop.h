#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Inventory.h"
#include "Pokemon.h"

using namespace std;

class Shop {
private:
    int coins;
    Inventory inventory;
   

public:
 

  	Shop(Inventory& inventory);
//  	Shop(const Inventory& inventory, const string& cityname, Pokemon& pokemon);
    Shop();
    void setCoins(int);
    void visitShop(Inventory& );

    void buyPokeball(const string&);
    void buyHealthReagent(const string&);
    void buyEnergyWave(const string&);
    void buyElixir(const string&);
    int getCoins() const;
    int getPokeballCost(const string&);
    int getHealthReagentCost(const string&);
    int getEnergyWaveCost(const string&);
    int getElixirCost(const string&);
    void buyItems(Inventory& );
//    void playGacha();
};

#endif

