#include "Inventory.h"

Inventory::Inventory() : CatchingItemsHead(nullptr), head(nullptr) {}

Inventory::Node* Inventory::getCatchingItemsHead() const {
    return CatchingItemsHead;
}

Inventory::Node* Inventory::getHead() const {
    return head;
}

void Inventory::setStr(string s)
{
	str=s;
}
string Inventory::getStr()
{return str;} 


void Inventory::displayCatchingItems() {
    Node* current = CatchingItemsHead;
    if (!current) {
        cout << "Catching Items Inventory is empty!" << endl;
    } else {
        while (current) {
            cout << "Item Name: " << current->itemName << endl;
            cout << "Quantity: " << current->quantity << endl;
            cout << "Description: " << current->description << endl;
            cout << endl;
            current = current->next;
        }
    }
}

void Inventory::display() {
    Node* current = head;
    if (!current) {
        cout << "Normal Inventory is empty!" << endl;
    } else {
    	int i=1;
        while (current) {
        	
            cout << i << ". Item Name: " << current->itemName << endl;
            cout << "   " << "Quantity: " << current->quantity << endl;
            cout << "   " << "Description: " << current->description << endl;
            cout << endl;
            current = current->next;
            i++;
        }
    }
}

void Inventory::useCatchingItem(int itemIndex) {
    Node* current = CatchingItemsHead;
    Node* previous = nullptr;
    int currentIndex = 1;

    while (current) {
        if (currentIndex == itemIndex) {
            cout << "Using Catching Item: " << current->itemName << endl;

            // Decrease the quantity in both catching and normal items
            current->quantity--;
            setStr(current->itemName);
            
            decreaseQuantity(current->itemName, 1);

            if (current->quantity <= 0) {
                // Remove the item from the catching list
                if (previous) {
                    previous->next = current->next;
                } else {
                    CatchingItemsHead = current->next;
                }
                delete current;
            }
            return;
        }

        previous = current;
        current = current->next;
        currentIndex++;
    } 
	
    cout << "Invalid Catching Item index: " << itemIndex << endl;
}

void Inventory::useItem(int itemIndex) {
    Node* currentItem = head;
    Node* previousItem = nullptr;
    int currentIndex = 1;

    while (currentItem) {
        if (currentIndex == itemIndex) {
            cout << "Using Item: " << currentItem->itemName << endl;
            // Perform the action of using the item
            // ...

            // Decrease the quantity in the normal linked list
            currentItem->quantity--;
            setStr(currentItem->itemName);
            if (currentItem->quantity <= 0) {
                // Remove the item from the normal linked list
                if (previousItem) {
                    previousItem->next = currentItem->next;
                } else {
                    head = currentItem->next;
                }
                delete currentItem;
            }

            // Check if the item is also present in the catching linked list
            Node* currentCatchingItem = CatchingItemsHead;
            Node* previousCatchingItem = nullptr;

            while (currentCatchingItem) {
                if (currentCatchingItem->itemName == currentItem->itemName) {
                    // Decrease the quantity in the catching linked list
                    currentCatchingItem->quantity--;
                    if (currentCatchingItem->quantity <= 0) {
                        // Remove the catching item from the list
                        if (previousCatchingItem) {
                            previousCatchingItem->next = currentCatchingItem->next;
                        } else {
                            CatchingItemsHead = currentCatchingItem->next;
                        }
                        delete currentCatchingItem;
                    }
                    break;
                }

                previousCatchingItem = currentCatchingItem;
                currentCatchingItem = currentCatchingItem->next;
            }

            return;
        }

        previousItem = currentItem;
        currentItem = currentItem->next;
        currentIndex++;
    }

    cout << "Invalid Item index: " << itemIndex << endl;
}

void Inventory::addCatchingItem(const string& itemName) {
    string description;

    if (itemName == "Pokeball") {
        description = "A tool used for capturing Pokemon with low success probability.";
    } else if (itemName == "Great ball") {
        description = "A tool used for capturing Pokemon with medium success probability.";
    } else if (itemName == "Ultra ball") {
        description = "A tool used for capturing Pokemon with high success probability.";
    } else {
        cout << "Invalid Catching Item: " << itemName << endl;
        return;
    }

    Node* newNodeCatching = new Node(itemName, 1, description); // Create a new Node for catching items
    Node* newNodeNormal = new Node(itemName, 1, description);   // Create a new Node for normal items

    // Add into catching linked list
    if (!CatchingItemsHead) {
        CatchingItemsHead = newNodeCatching;
    } else {
        Node* current = CatchingItemsHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newNodeCatching;
    }

    // Add into normal linked list
    if (!head) {
        head = newNodeNormal;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNodeNormal;
    }
}


void Inventory::addItem(const string& itemName, int quantity) {
    string description;

    if (itemName == "Pokeball") {
        description = "A tool used for capturing Pokemon with low success probability.";
    } else if (itemName == "Great ball") {
        description = "A tool used for capturing Pokemon with medium success probability.";
    } else if (itemName == "Ultra ball") {
        description = "A tool used for capturing Pokemon with high success probability.";
    } else if (itemName == "Super Potion") {
        description = "Restores a Pokemon's HP by 100 points.";
    } else if (itemName == "Hyper Potion") {
        description = "Restores a Pokemon's HP by 300 points.";
    } else if (itemName == "Max Potion") {
        description = "Restores a Pokemon's HP by 500 points.";
    } else if (itemName == "EnergyWave Spark") {
        description = "Restores a Pokemon's Energy by 10 points.";
    } else if (itemName == "EnergyWave Surge") {
        description = "Restores a Pokemon's Energy by 20 points.";
    } else if (itemName == "EnergyWave Blast") {
        description = "Restores a Pokemon's Energy by 50 points.";
    } else if (itemName == "Novice Elixir") {
        description = "Increase a Pokemon's EXP by 20 points.";
    } else if (itemName == "Adept Elixir") {
        description = "Increase a Pokemon's EXP by 50 points.";
    } else if (itemName == "Elite Elixir") {
        description = "Increase a Pokemon's EXP by 100 points.";
    } else {
        cout << "Invalid Item: " << itemName << endl;
        return;
    }

    Node* newNode = new Node(itemName, quantity, description);

	//add into normal linked list
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    //add into catching linked list
    if(itemName=="Pokeball"||itemName=="Great Ball"||itemName=="Great Ball")
    {
    	if (!CatchingItemsHead) {
        CatchingItemsHead = newNode;
    } else {
        Node* current = CatchingItemsHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
	}
    
}
void Inventory::addItem(const string& itemName) {
    string description;

    if (itemName == "Pokeball") {
        description = "A tool used for capturing Pokemon with low success probability.";
    } else if (itemName == "Great ball") {
        description = "A tool used for capturing Pokemon with medium success probability.";
    } else if (itemName == "Ultra ball") {
        description = "A tool used for capturing Pokemon with high success probability.";
    } else if (itemName == "Super Potion") {
        description = "Restores a Pokemon's HP by 100 points.";
    } else if (itemName == "Hyper Potion") {
        description = "Restores a Pokemon's HP by 300 points.";
    } else if (itemName == "Max Potion") {
        description = "Restores a Pokemon's HP by 500 points.";
    } else if (itemName == "EnergyWave Spark") {
        description = "Restores a Pokemon's Energy by 10 points.";
    } else if (itemName == "EnergyWave Surge") {
        description = "Restores a Pokemon's Energy by 20 points.";
    } else if (itemName == "EnergyWave Blast") {
        description = "Restores a Pokemon's Energy by 50 points.";
    } else if (itemName == "Novice Elixir") {
        description = "Increase a Pokemon's EXP by 20 points.";
    } else if (itemName == "Adept Elixir") {
        description = "Increase a Pokemon's EXP by 50 points.";
    } else if (itemName == "Elite Elixir") {
        description = "Increase a Pokemon's EXP by 100 points.";
    } else {
        cout << "Invalid Item: " << itemName << endl;
        return;
    }

    Node* newNode = new Node(itemName, 1, description);

	//add into normal linked list
    if (!head) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    //add into catching linked list
    if(itemName=="Pokeball"||itemName=="Great Ball"||itemName=="Great Ball")
    {
    	if (!CatchingItemsHead) {
        CatchingItemsHead = newNode;
    } else {
        Node* current = CatchingItemsHead;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
	}
    
}

void Inventory::copyInventory(const Inventory& otherInventory) {
    // Clear the current inventory
    Node* current = CatchingItemsHead;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    CatchingItemsHead = nullptr;

    current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    // Copy the catching items from the other inventory
    Node* otherCurrent = otherInventory.CatchingItemsHead;
    while (otherCurrent) {
        addCatchingItem(otherCurrent->itemName);
        otherCurrent = otherCurrent->next;
    }

    // Copy the normal items from the other inventory
    otherCurrent = otherInventory.head;
    while (otherCurrent) {
        addItem(otherCurrent->itemName);
        otherCurrent = otherCurrent->next;
    }
}

void Inventory::increaseQuantity(const string& name, int qty) {
    Node* current = head;
    bool found = false;
    
    while (current) {
        if (current->itemName == name) {
            current->quantity += qty;
            found = true;
            break;
        }
        
        current = current->next;
    }	if(found==false)
    {
    	addItem(name);
	}
}
void Inventory::decreaseQuantity(const string& itemName, int qty) {
    Node* current = head;

    while (current) {
        if (current->itemName == itemName) {
            current->quantity -= qty;
            if (current->quantity <= 0) {
                // Remove the item from the normal linked list
                if (current == head) {
                    head = current->next;
                } else {
                    Node* previous = head;
                    while (previous->next != current) {
                        previous = previous->next;
                    }
                    previous->next = current->next;
                }
                delete current;
            }
            return;
        }

        current = current->next;
    }

    cout << "Item not found: " << itemName << endl;
}


Inventory::~Inventory() {
    Node* current = CatchingItemsHead;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }

    current = head;
    while (current) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void Inventory::saveData(const string& filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        saveInventoryData(file, CatchingItemsHead);
        saveInventoryData(file, head);
        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void Inventory::loadData(const string& filename)
{
    ifstream file(filename);
    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            if (line == "CatchingItems")
            {
                loadInventoryData(file);
            }
        }
        file.close();
    }
    else
    {
        cout << "Unable to open the file." << endl;
    }
}

void Inventory::saveInventoryData(ofstream& file, Node* inventory)
{
    while (inventory != nullptr)
    {
        file << "Item Name: " << inventory->itemName << endl;
        file << "Quantity: " << inventory->quantity << endl;
        file << "Description: " << inventory->description << endl;
        file << endl;

        inventory = inventory->next;
    }
}
void Inventory::writeToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (!file.is_open()) {
            std::cout << "Error opening file!" << std::endl;
            return;
        }

        file << "Inventory Linked List:" << std::endl;
        Node* temp = head;
        int itemCount = 1;
        while (temp != nullptr) {
            file << "Item " << itemCount << ":" << std::endl;
            file << "Name: " << temp->itemName << std::endl;
            file << "Quantity: " << temp->quantity << std::endl;
            file << "Description: " << temp->description << std::endl;
            file << std::endl;

            temp = temp->next;
            itemCount++;
        }
        
}
void Inventory::loadInventoryData(ifstream& file)
{
    string line;
    getline(file, line); // Read the empty line

    string itemName, description;
    int quantity;

    // Read and parse each line
    while (getline(file, line))
    {
        if (line == "")
            break;

        stringstream ss(line);
        string key, value;
        getline(ss, key, ':');
        getline(ss, value);

        if (key == "Item Name")
            itemName = value;
        else if (key == "Quantity")
            quantity = stoi(value);
        else if (key == "Description")
            description = value;
    }

    // Create a new inventory node and assign the values
    Node* newItem = new Node(itemName, quantity, description);
    newItem->next = nullptr;

    // Attach the new inventory node to the inventory list
    if (head == nullptr)
        head = newItem;
    else
    {
        Node* current = head;
        while (current->next != nullptr)
            current = current->next;
        current->next = newItem;
    }
}


