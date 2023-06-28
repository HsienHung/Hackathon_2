#include "Map.h"

Map::Map() : head(nullptr), currentCity(nullptr) {
    appendNode("Lavaridge Town");
}

Map::~Map() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

void Map::appendNode(const string cityName) {
    Node* newNode = new Node(cityName);

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void Map::display() const {
    if (head == nullptr) {
        cout << "Map is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << "City Name: " << current->city.getName() << endl;
        cout << endl;
        current = current->next;
    }
}

void Map::chooseCity() {
    cout << "Cities Unlocked: " << endl;
    cout << "-----------------" << endl;
    int cityIndex = 1;
    Node* current = head;
    while (current != nullptr) {
        cout << cityIndex << ". " << current->city.getName() << endl;
        current = current->next;
        cityIndex++;
    }

    int choice;
    bool validChoice = false;
    do {
        cout << "Choose a city to visit: ";
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else if (choice < 1 || choice >= cityIndex) {
            cout << "Invalid choice. Please try again." << endl;
        } else {
            validChoice = true;
        }
    } while (!validChoice);

    current = head;
    for (int i = 1; i < choice && current != nullptr; i++) {
        current = current->next;
    }

    cout << "Visiting " << current->city.getName() << "!" << endl;
    
	current->city.visitCity();
    
	if(current->city.getWin() == true)
	{
		if (current->city.getName() == "Lavaridge Town") 
			appendNode("Eterna City");
		else if (current->city.getName() == "Eterna City") 
		   appendNode("Mossdeep City");
		else if (current->city.getName() == "Mossdeep City") 
		    appendNode("Vermilion Cit");
		else if (current->city.getName() == "Vermilion City") 
		    appendNode("Driftveil City");
		else if (current->city.getName() == "Driftveil City") 
		    appendNode("Blackthorn City");
		else
			cout << "You have complete the journey !!!";
	}
    currentCity = &current->city;
}

void Map::copyMap(const Map& otherMap) {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;

    Node* otherCurrent = otherMap.head;
    while (otherCurrent) {
        appendNode(otherCurrent->city.getName());
        otherCurrent = otherCurrent->next;
    }

    if (otherMap.currentCity) {
        Node* mapCurrent = head;
        while (mapCurrent) {
            if (mapCurrent->city.getName() == otherMap.currentCity->getName()) {
                currentCity = &mapCurrent->city;
                break;
            }
            mapCurrent = mapCurrent->next;
        }
    }
}

const City* Map::getCurrentCity() const {
    return currentCity;
}

