//#include "GameList.h"
//#include <iostream>
//
//using namespace std;
//
////GameNode::GameNode(const GameState& gameState, const string& name)
////    : state(gameState), next(nullptr) {
////    state.gameName = name;
////}
//
////GameList::GameList() : head(nullptr), tail(nullptr) {}
////
////void GameList::appendNode(const GameState& gamestate)const {
////	GameNode* newNode=new GameNode;
////	newNode->state=gamestate;
////    if (head == nullptr) {
////        head = newNode;
////        tail = newNode;
////    } else {
////        tail->next = newNode;
////        tail = newNode;
////    }
////}
//
//GameNode* GameList::getHead() const {
//    return head;
//}
//
//bool GameList::isEmpty() const {
//    return head == nullptr;
//}
//
//bool GameList::exists(const string& gameName) const {
//    GameNode* currentNode = head;
//    while (currentNode != nullptr) {
//        if (currentNode->state.gameName == gameName) {
//            return true;
//        }
//        currentNode = currentNode->next;
//    }
//    return false;
//}
//
//void GameList::updateGame(const GameState& gameState) const{
//    GameNode* currentNode = head;
//    while (currentNode != nullptr) {
//        if (currentNode->state.gameName == gameState.gameName) {
//            currentNode->state = gameState;
//            return;
//        }
//        currentNode = currentNode->next;
//    }
//}
//
//void GameList::display() const {
//    GameNode* node = head;
//    while (node != nullptr) {
//        cout << "**********************************************" << endl;
//        cout << "*  Game Name: " << node->state.gameName << " *" << endl;
//        // Display other game state variables
//        // ...
//
//        node = node->next;
//    }
//}

