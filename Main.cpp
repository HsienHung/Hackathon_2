#include"GameList.h"
#include"Game.h"
#include<iostream>
using namespace std;

int main()
{
	Game game;
	while(true)
	{
		cout << "*****************************" << endl;
	    cout << "      Welcome to PokeGo     " << endl;
	    cout << "*****************************" << endl;
	                                                      
		cout << "			     _.----.        ____                  ____           "<< endl;
		cout << "			  _,-'       `.     |  |  /`.            /  _ \\       "<< endl;
		cout << "			 \\     __    \\    '-.  | /   `.  ___    /  / \\ \\       "<< endl;
		cout << "			  \\.   \\ \\   |  __  |  |/    ,','_  `. |  /   \\_\\    _ _  "<< endl;
		cout << "			   \\    \\/   /,' _`.|       ,'/ / / /  |  |   ____ , ' _`. "<< endl;
		cout << "			    \\     ,-'/  / \\    ,'  | \\/ / ,`.| |  |  |    |/  / \\ \\ "<< endl;
		cout << "			     \\    \\ |   \\_/ |    `-. \\    `'  /|  |  |_   |   \\_/  |  "<< endl;
		cout << "			      \\    \\ \\      /       `-.`.___,-' \\  \\  /  / \\      /   "<< endl;
		cout << "			       \\    \\ `.__,'|  |`-._    `|       \\  \\/  /   `.__,' "<< endl;
		cout << "			        \\_.-'       |__|    `-._ |        \\____/          "<< endl;
					                                                                                    
	    cout << "*****************************" << endl;
	    cout << "    The Adventure Begins!    " << endl;
	    cout << "*****************************" << endl;
	    cout << "  Welcome to the world of Pokemon! As a " << endl;
	    cout << "  trainer, your journey is about to unfold. " << endl;
	    cout << "  Explore new territories, catch wild Pokemon, " << endl;
	    cout << "  and battle against other trainers to become " << endl;
	    cout << "  the ultimate Pokemon Master!" << endl;
	    cout << endl;
	    
	
	    // Get user input for menu selection
	    int choice;
	    bool validChoice = false;
	    while (!validChoice) 
		{
			cout << "  1. Start New Game" << endl;
	    	cout << "  2. Load Saved Game" << endl;
	    	cout << "  3. Exit" << endl;
	        cout << "Enter your choice: ";
	        cin >> choice;
	
	        // Process the user's choice
	        switch (choice) 
			{
	            case 1:
	                // Start new game
	                cout << "Starting a new game..." << endl;
	                game.StartGame();
	                break;
	            case 2:
//	                // Load saved game
	                cout << "Loading saved game..." << endl;
					break;
	            case 3:
	                // Exit the game
	                cout << "Exiting the game..." << endl;
	                return 0;
	            default:
	                // Invalid choice
	                cout << "Invalid choice. Please select a valid option." << endl;
	                break;
	        }
	    }
	}
	return 0;	
}
