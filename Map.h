#ifndef MAP_H
#define MAP_H
#include"Shop.h"
#include"City.h"

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Map {
private:
    struct Node {
        City city;
        Node* next;

        Node(const City& city) : city(city), next(nullptr) {}
    };
    Node* head;
    City* currentCity;
    //Shop shop;

public:
    Map();
    ~Map();

    void appendNode(const string cityName);
    void display() const;
    void chooseCity( );
    void copyMap(const Map& otherMap);
    const City* getCurrentCity() const;
};

#endif

