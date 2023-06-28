//#ifndef GAMELIST_H
//#define GAMELIST_H
//#include"Inventory.h"
//#include"Pokemon.h"
//#include"Map.h"
//#include <string>
//
//#include <iostream>
//#include <string>
//#include "Shop.h"
//
//using namespace std;
//
//class GameState {
//private:
//    string gameName;
//    //Shop shop;
//    Inventory inventory;
//    Pokemon pokemon;
//    Map gameMap;
//
//public:
////	Shop& getShop() {
////        return shop;
////    }
//    const Inventory& getInventory() const {
//        return inventory;
//    GameState() = default; // Default constructor
//    
//    GameState(const string& name, int startingCoins)
//        : gameName(name), inventory(), pokemon(), gameMap() {}
//
//    GameState& operator=(const GameState& other) {
//        if (this == &other) {
//            return *this; // Check for self-assignment
//        }
//
//        gameName = other.gameName;
//        //shop.setCoins(other.shop.getCoins()) ;
//        //shop = other.shop;
//        inventory = other.inventory;
//        pokemon = other.pokemon;
//        gameMap = other.gameMap;
//
//        return *this;
//    }
//
//    void setGameName(const string& name) {
//        gameName = name;
//    }
//
//    // Add getter and setter functions for other members as needed
//    
//    void displayGameState() {
//        // Implement the display logic for the game state
//    }
//};
//
//
//struct GameNode {
//    GameState state;
//    GameNode* next;
//
//    GameNode(const GameState& gameState, const string& name)
//        : state(gameState), next(nullptr) {
//        // Set the state and next pointer
//    }
//};
//
//
//class GameList {
//private:
//    GameNode* head;
//    GameNode* tail;
//
//public:
//    GameList();
//    void appendNode(const GameState&)const;
//    GameNode* getHead() const;
//    bool isEmpty() const;
//    bool exists(const string& gameName) const;
//    void updateGame(const GameState& gameState)const;
//    void display() const;
//};
//
//#endif  // GAMELIST_H

