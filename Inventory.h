#ifndef INVENTORY_H
#define INVENTORY_H
#include <fstream>
#include <sstream>

#include <iostream>
#include <string>

using namespace std;

class Inventory {
private:
    struct Node {
        string itemName;
        int quantity;
        string description;
        Node* next;

        Node(const string& name, int qty, const string& desc, Node* n = nullptr)
            : itemName(name), quantity(qty), description(desc), next(n) {}
    };
    Node* CatchingItemsHead;     // Head of the catching items list
    Node* head;   // Head of the items list
    string str;

public:
    Inventory();
    ~Inventory();
    Node* getCatchingItemsHead() const;
    Node* getHead() const;
    
    void setStr(string );
    string getStr();
    void displayCatchingItems();
    void display();
    void useCatchingItem(int itemIndex);
    void useItem(int itemIndex);
    void addCatchingItem(const string& itemName);
    void addItem(const string& itemName);
    void addItem(const string& itemName, int);
    void copyInventory(const Inventory& otherInventory);

    void increaseQuantity(const string& name, int qty);
	void decreaseQuantity(const string& name, int qty);
	
	void saveData(const string& filename);
    void loadData(const string& filename);
    void saveInventoryData(ofstream& file, Node* inventory);
    void loadInventoryData(ifstream& file);
    void writeToFile(const std::string& filename);

};

#endif
