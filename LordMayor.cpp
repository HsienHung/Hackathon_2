#include<iostream>
#include"LordMayor.h"


void LordMayor::beforeBattle(string cityname,Inventory& inventory, Pokemon& pokemon, bool& win)
{
	
	cout << "You have enter Lord Mayer house..." << endl << endl;
	cout << "Lord Mayor: \nAh, brave adventurer! You have conquered the dungeon and tamed mighty Pokémon. Now, it's time to test your" << endl;
	cout << "mettle against me. Are you ready to face the ultimate challenge?" << endl << endl;
	cout << "You: " << endl;
	cout << "1. Yes, I am prepared to face you!" <<endl;
	cout << "2. No, I need more time to train." << endl;
	cout << "\nYour choice: ";
	
	int choice;
	cin >> choice;
	while (choice != 1 && choice != 2) 
	{
		cout << "Please choose 1 or 2 : ";
		cin >> choice;
	}
	
	if(choice == 2)
	{
		cout << "\nLord Mayor: " << endl;
		cout << "I understand your hesitation. True strength comes from rigorous training. Take the time you need, but " <<endl;
		cout << "remember, the path forward lies in defeating me. Return when you feel ready to face this ultimate challenge." << endl;
		cout << "May your training be fruitful!" << endl << endl;
		return;
	}
	
	else
	{
		cout << "\nYou: " << endl;
		cout << "I am ready to face any challenge you throw my way, Lord Mayor! " << endl;
		
		cout << "\nLord Mayor: " << endl;
		cout << "Very well, brave adventurer. But remember, I am no ordinary opponent. I have honed my skills and trained my" << endl;
		cout << "Pokémon to perfection. Are you truly prepared to face the full extent of my power?" << endl;
		
		cout << "\nYou: " << endl;
		cout << "I am confident in my abilities and the strength of my Pokémon. I believe we can overcome any challenge!"<< endl;
		
		cout << "\nLord Mayor: " << endl;
		cout << "Admirable confidence, indeed. Let our battle begin, and may the best warrior emerge victorious!" << endl << endl;
		
		cout << "------------------------------------------------------" << endl;
		cout << "               !!! BATTLE START !!!" << endl;
		cout << "------------------------------------------------------" << endl;
		mayorBattle(cityname, inventory, pokemon, win);
		
	}

}

void LordMayor::mayorBattle(string cityname, Inventory& inventory, Pokemon& pokemon,bool& WIN)
{
	pokedex.initializePokedex();
	pokedex.generateBoss(battle, cityname);
	battle.bossStatus();
    battle.battleStart(pokemon, inventory);
    
}

void LordMayor::afterBattle(string name)
{
	
	cout << "\nLord Mayor: " << endl;
	cout << "Impressive! Your skills are beyond what I anticipated. It seems I have underestimated you, young adventurer. " <<endl;
	
	cout << "\nYou: " << endl;
	cout << "Thank you, Lord Mayor. Your strength pushed me to my limits, but I prevailed. " << endl;

	cout << "\nLord Mayor: " << endl;
	cout << "Indeed, you have proven yourself worthy. As promised, I shall grant you passage to the next city. But remember, ";
	cout << "even greater challenges lie ahead. Prepare yourself for what awaits." << endl;

	cout << "\nYou: " << endl;
	cout << "I shall remain vigilant and continue to grow stronger. Thank you, Lord Mayor, for this opportunity. " << endl;

	cout << "\nLord Mayor: " << endl;
	cout << "Lord Mayor: Farewell, brave adventurer. May your journey be filled with triumph and glory. ";
	
	
	

}

