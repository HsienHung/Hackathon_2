#include "Battle.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Battle::Battle() {
    name = "";
    HP = 0;
    energy = 0;
    attack = 0;
    normalAttack = " ";
    skill1 = "";
    skill2 = "";
    level = 0;
    exp = 0;
    faitedPokemon = 0;
}

void Battle::setType(const string& t) {
    type = t;
}

void Battle::setName(const string& n) {
    name = n;
}

void Battle::setHP(int hp) {
    HP = hp;
}

void Battle::setEnergy(int e) {
    energy = e;
}

void Battle::setAttack(int a) {
    attack = a;
}

void Battle::setNormalAttack(const string& na) {
    normalAttack = na;
}

void Battle::setSkill1(const string& s1) {
    skill1 = s1;
}

void Battle::setSkill2(const string& s2) {
    skill2 = s2;
}

void Battle::enemyStatus()
{
	static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }
    
    int lvl = rand() % 3 + 1;
    level = lvl;
    cout << "Wild " << name << " appeared!" << endl;
    cout << "-----------------------" << endl;
	cout << "      Enemy Status" << endl;
	cout << "-----------------------" << endl;
    cout << name << " Lv" << level << endl;
    HP = HP+((level-1)*40);
    cout << "HP: " << HP << endl;
    attack = attack + ((level-1)*3);
    energy = energy + ((level-1)*10);
}

void Battle::enemyDamage(Pokemon& pokemon)
{
	static bool initialized = false;
    if (!initialized) {
        srand(time(0));
        initialized = true;
    }
    
    int enemyChoose = rand() % 10 + 1;
    
    if(enemyChoose <=5)
    {
    	cout << name << " used " << normalAttack << " !" << endl;
		cout << "Deals " << attack << " damages to you!" << endl;
    	damage = attack;
	}
    	
    else if(enemyChoose >=6 && enemyChoose <=8)
    {
    	cout << name << " used " << skill1 << " !" << endl;
		cout << "Deals " << attack*1.3 << " damages to you!" << endl;
    	damage = attack*1.3;
	}
	else
	{
		cout << name << " used " << skill2 << " !" << endl;
		cout <<  "Deals " << attack*1.4 << " damages to you!" << endl;
    	damage = attack*1.4;
	}
	pokemon.setHP(pokemon.getHP() - damage);
}

void Battle::battleStart(Pokemon& pokemon, Inventory& inventory)
{	
	pokemon.battleStartPokemon();
	int choice;
	while(choice !=4 )
	{
		cout << "-----------------------" << endl;
	    cout << "      Your Status" << endl;
	    cout << "-----------------------" << endl;
	    
	    cout << pokemon.getName() << " Lv";
		cout << pokemon.getLevel() << endl;
		
		
		if(pokemon.getHP()<=0)
		{
			
			pokemon.setHP(0);
			cout << "HP: " << pokemon.getHP() << endl;
			cout << "Energy: " << pokemon.getEnergy() << endl;
			if(faitedPokemon >=2)
			{
				cout << "------------------------------------------------------" << endl;
				cout << "        DEFEAT!!! All your Pokemon has faited" << endl;
				cout << "------------------------------------------------------" << endl;
				break;
			}
			else
			{
				cout << "This pokemon has faited. " << endl;
		    	cout << "Please choose another pokemon. " << endl;
		    	choice =3;
		    	faitedPokemon++;
			}
			
		}
				
		else
		{
			cout << "HP: " << pokemon.getHP() << endl;
			cout << "Energy: " << pokemon.getEnergy() << endl;
			cout << "-----------------------" << endl;
			cout << "        ACTION   " << endl;
			cout << "-----------------------" << endl;
			cout << "1. FIGHT" << endl;
			cout << "2. BAG" << endl;
			cout << "3. POKEMON" << endl;
			cout << "4. RUN" << endl;
			cout << "Enter your choice: ";
	    	cin >> choice;
		}
	   
	    bool exitBattle = false;
		//Handle the user's choice and perform the corresponding actions
		int catchPercentage;
		
	    switch (choice)
	    {
	        case 1:
	            pokemon.pokemonFight();
	            if(pokemon.getDamage() == 0)
	            	break;
	            else
	            {
	            	cout << "You have deal " << pokemon.getDamage() << " damages !!!\n";
					HP = HP-pokemon.getDamage();
				}         	
	            break;
	        case 2: 
				inventory.display();
				int items;
				cout << "0. Back" << endl;
	        	cout << "Select the items you want to use: ";
				cin >> items;
				inventory.useItem(items);       	
        		        		       	
	        	if (items == 0) break;
				
				else
				{  	
		        	static bool initialized = false;
					if (!initialized) 
					{
					    srand(time(0));
					    initialized = true;
					}
					catchPercentage = rand() % 10 + 1;
					
					if(inventory.getStr()== "Pokeball"||inventory.getStr()== "Great ball"||inventory.getStr()== "Ultra ball")
					{
						if(inventory.getStr()== "Pokeball")
			            {
			            	if(catchPercentage>=1 && catchPercentage<=5)
						    {
						    	cout << "Congratualations, You have caught the " << name << " !!!" << endl;
			            		pokemon.appendPokemon(type, name, HP, energy, attack, normalAttack, skill1, skill2, level, exp);
							}
						    else
						    	cout << name << "has run away" << endl;			    
						}
						else if(inventory.getStr()== "Great ball")
						{
							if(catchPercentage>=1 && catchPercentage<=7)
						    {
						    	cout << "Congratualations, You have caught the " << name << " !!!" << endl;
			            		pokemon.appendPokemon(type, name, HP, energy, attack, normalAttack, skill1, skill2, level, exp);
							}
						    else
						    	cout << name << "has run away" << endl;		
						}
						else if(inventory.getStr()== "Ultra ball")
						{
							cout << "Congratualations, You have caught the " << name << " !!!" << endl;
			            	pokemon.appendPokemon(type, name, HP, energy, attack, normalAttack, skill1, skill2, level, exp);	
						}
			            exitBattle = true; // Set the flag to exit the switch statement
		        		break;
					}
					
					else
					{
						if(inventory.getStr()=="Super Potion")   
						{
							cout << "------------------------------------" << endl;
							cout << "   " << pokemon.getName() << " has recovery 100 HP   " << endl;
							cout << "------------------------------------" << endl;
							pokemon.setHP(pokemon.getHP()+100);
						}   
						
						else if(inventory.getStr()=="Hyper Potion")   
						{
							cout << "------------------------------------" << endl;;
							cout << "   " << pokemon.getName() << " has recovery 300 HP" << endl;
							cout << "------------------------------------" << endl;
							pokemon.setHP(pokemon.getHP()+300);	
						} 
						
						else if(inventory.getStr()=="Max Potion")   
						{
							cout << "------------------------------------" << endl;
							cout << "   " << pokemon.getName() << " has recovery 500 HP" << endl;
							cout << "------------------------------------" << endl;
							pokemon.setHP(pokemon.getHP()+500);	
						} 
						
						else if(inventory.getStr()=="Novice Elixir")   
						{
								int oriLevel= pokemon.getLevel();
								cout << "----------------------------------------------------" << endl;		
								cout << "          " <<  pokemon.getName() << " has increase 20 EXP" << endl;
								cout << "----------------------------------------------------" << endl;		
								pokemon.setEXP(pokemon.getEXP()+20);
									if(pokemon.getLevel() == oriLevel+1 && pokemon.getLevel()<=4)
						    	{
						    		if( pokemon.getLevel()==4)
						    		{
						    			cout << "Congratualations !!! Evolved to " << pokemon.getName() << " !!!" << endl;
										cout << "----------------------------------------------------" << endl;		
									}
						    			
						    		else
						    		{															    			
						    			cout << "          " << pokemon.getName() << " level up to lv" << pokemon.getLevel() << " !!!" << endl;
						    			cout << "----------------------------------------------------" << endl;							    			
									}
						    			
								}

						}
						
						else if(inventory.getStr()=="Adept Elixir")   
						{
								int oriLevel= pokemon.getLevel();
								cout << "----------------------------------------------------" << endl;		
								cout << "          " <<  pokemon.getName() << " has increase 50 EXP" << endl;
								cout << "----------------------------------------------------" << endl;	
								pokemon.setEXP(pokemon.getEXP()+50);
									if(pokemon.getLevel() == oriLevel+1 && pokemon.getLevel()<=4)
						    	{
						    		if( pokemon.getLevel()==4)
						    		{
						    			cout << "Congratualations !!! Evolved to " << pokemon.getName() << " !!!" << endl;
										cout << "----------------------------------------------------" << endl;		
									}
						    			
						    		else
						    		{															    			
						    			cout << "          " << pokemon.getName() << " level up to lv" << pokemon.getLevel() << " !!!" << endl;
						    			cout << "----------------------------------------------------" << endl;							    			
									}
						    			
								}
						}
						
						else if(inventory.getStr()=="Elite Elixir")   
						{
								int oriLevel= pokemon.getLevel();
								cout << "----------------------------------------------------" << endl;
								cout << "          " <<  pokemon.getName() << " has increase 100 EXP" << endl;
								cout << "----------------------------------------------------" << endl;
								pokemon.setEXP(pokemon.getEXP()+100);
									if(pokemon.getLevel() == oriLevel+1 && pokemon.getLevel()<=4)
						    	{
						    		if( pokemon.getLevel()==4)
						    		{
						    			cout << "   " << "Congratualations !!! Evolved to " << pokemon.getName() << " !!!" << endl;
										cout << "----------------------------------------------------" << endl;		
									}
						    			
						    		else
						    		{															    			
						    			cout << "          " << pokemon.getName() << " level up to lv" << pokemon.getLevel() << " !!!" << endl;
						    			cout << "----------------------------------------------------" << endl;							    			
									}
						    			
								}
						}
						
						else if(inventory.getStr()=="EnergyWave Spark")   
						{
							cout << "---------------------------------------" << endl;
							cout << "   " << pokemon.getName() << " has recovery 10 Energy" << endl;	
							cout << "---------------------------------------" << endl;
							pokemon.setEnergy(pokemon.getEnergy()+10);
						} 
						
						else if(inventory.getStr()=="EnergyWave Surge")   
						{
							cout << "---------------------------------------" << endl;
							cout << "   " << pokemon.getName() << " has recovery 20 Energy" << endl;	
							cout << "---------------------------------------" << endl;
						} 
						
						else if(inventory.getStr()=="EnergyWave Blast")   
						{
							cout << "---------------------------------------" << endl;
							cout << "   " << pokemon.getName() << " has recovery 50 Energy" << endl;	
							cout << "---------------------------------------" << endl;
						} 
						cout << "-----------------------" << endl;
					    cout << "      Your Status" << endl;
					    cout << "-----------------------" << endl;
					    
					    cout << pokemon.getName() << " Lv";
						cout << pokemon.getLevel() << endl;
						cout << "HP: " << pokemon.getHP() << endl;
						cout << "Energy: " << pokemon.getEnergy() << endl;
						
						cout << "-----------------------" << endl;
					    cout << "      Enemy Status" << endl;
					    cout << "-----------------------" << endl;
					    cout << name << " Lv" << level << endl;
					    cout << "Remaining HP: " << HP << endl;
						enemyDamage(pokemon);
					} 					
					break;
  
				}
	        	
	            
	        case 3:
	            pokemon.traversePokemonList();
	            while(pokemon.getHP()<=0)
	            {
	            	cout << "This pokemon has faited. " << endl;
	            	cout << "Please choose another pokemon. " << endl;
	            	pokemon.traversePokemonList();
				}
	            
	            break;
	        case 4:
	            cout << "You have left the battle. " << endl;
	            return;
	        default:
	            cout << "Invalid choice!" << endl;
	            break;
	    }
	    
	    if (exitBattle) 
		{
		    return; // Return outside the switch statement
		}
        
	    if(choice == 1 && pokemon.getDamage() != 0)
	    {
	    	cout << "-----------------------" << endl;
		    cout << "      Enemy Status" << endl;
		    cout << "-----------------------" << endl;
		    cout << name << " Lv" << level << endl;
		    cout << "Remaining HP: " << HP << endl;
		    
		    if( HP <= 0)
		    {
		    	cout << "Enemy has faited" << endl;
		    	cout << "------------------------------------------------------" << endl;
		    	cout << "   Congratualations !!! You have won the battle !!!" << endl;
		    	cout << "------------------------------------------------------" << endl;
		    	int oriLevel= pokemon.getLevel();
		    	cout << pokemon.getName();
		    	pokemon.setEXP(pokemon.getEXP()+50);		    	
		    	cout << " gained 50 EXP!" << endl;
		    	if(pokemon.getLevel() == oriLevel+1 && pokemon.getLevel()<=4)
		    	{
		    		if( pokemon.getLevel()==4)
		    		{
		    			cout << "Congratualations !!! Evolved to " << pokemon.getName() << " !!!" << endl;
						cout << "------------------------------------------------------" << endl;	
					}
		    			
		    		else
		    		{
		    			cout << pokemon.getName() << " level up to lv" << pokemon.getLevel() << " !!!" << endl;
		    			cout << "------------------------------------------------------" << endl;
					}
		    			
				}
			
				break;
			}
	    	enemyDamage(pokemon);
		    
		}
	    
	}
}

void Battle::bossStatus()
{
    int lvl = 3;
    level = lvl;
    cout << "-----------------------" << endl;
	cout << "      Enemy Status" << endl;
	cout << "-----------------------" << endl;
    cout << name << " Lv" << level << endl;
    HP = HP+((level-1)*40);
    cout << "HP: " << HP << endl;
    attack = attack + ((level-1)*3);
    energy = energy + ((level-1)*10);
}

int Battle::getHP()
{
	return HP;
}
