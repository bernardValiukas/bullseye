/*
Jackson Valiukas
Bullseye
Last Updated 
14/03/15
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

using namespace std;

void itemsTable();

int main(int argc, char** argv) 
{
	double goodsPriceArray[5] = {1.1, 2.2, 3.9, 5.6, 10.2};
	string goodsNameArray[5] = {"Milk", "Lollies", "Tomato Paste", "Butter", "Chips"};
	string attempName[3] = {"first", "second", "last"};
	
	bool itemCheck[5] = {false, false, false, false, false};
	bool hiddenBullseyeFlag = false;
	
	int playerAttemts;
	int goodsSelection;
	int goodsGuess;
	
	double totalPrice;
	
	srand(time(NULL)); 
	int hiddenBullseye = rand() % 5 + 1 ;
	
	cout << hiddenBullseye << endl;
	cout << "-------------------------------------------------------------------------------|" << endl;
	cout << "|                                                                              |" << endl;
	cout << "\n" << endl;
	cout << "|                           ~ Welcome to Bullseye ~                            |" << endl;
	cout << "\n" << endl;
	cout << "|                                                                              |" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	
	
	cout << "Choose an item. \nGuess how many of that item will have a total between $10 and $12. " 
	     << "If you get it correct you win. \nYou have 3 chances." << endl;
	cout << "Any total value between $2-12 is lands on the board." << endl;
	
	system("pause");
	
	for(int i = 0 ; i <3 ; i++)
	{	
		system("cls");
		
		itemsTable();
		cout << "---------------------\n" << endl;
		cout << "Select " << attempName[i] << " item." << endl;
		
		cin >> goodsSelection;
		
		while(goodsSelection > 5 || goodsSelection < 1 || itemCheck[goodsSelection -1] == true)
		{
			if(goodsSelection > 5 || goodsSelection < 1)
			{
				cout << "Invalid item selected. Please choose another item." << endl;
				cin >> goodsSelection;
			}
			else
			{
				cout << "Item already chosen. Please choose another item." << endl;
				cin >> goodsSelection;
			}
		}
		
		itemCheck[goodsSelection -1] = true;
		
		if(goodsSelection == hiddenBullseye)
		{
			hiddenBullseyeFlag = true;
		}
		
		cout << "How many of that item do you want to guess?" << endl;
		cin >> goodsGuess;
		
		totalPrice = goodsGuess * goodsPriceArray[goodsSelection -1];
		
		cout << goodsNameArray[goodsSelection -1] << " costs $" << goodsPriceArray[goodsSelection -1] << endl;
		system("pause");
		cout << "Total cost is $" << totalPrice << endl;
		
		if( totalPrice >= 10 && totalPrice <= 12 )
		{
			cout << "YOU WIN!" << endl;
			break;
		}

		else
		{
			cout << "You guessed incorrectly!" << endl;
		}
		
		if(i == 2)
		{
			cout << "Incorrectly guessed three times. YOU LOSE!" << endl;
			system("pause");
			system("cls");
			cout << "Second Chance" << endl;
			cout << "If one of the items you landed on the board is the hidden bullseye you win." << endl;
			system("pause");
			
			cout << "Hidden Bullseye was behind the " << goodsNameArray[hiddenBullseye -1] << endl;	
			if(hiddenBullseyeFlag == true)
			{
				cout << "YOU WIN!" << endl;
			}
			else
			{
				cout << "YOU LOSE!" << endl;
			}
				
		}
		
		system("pause");	
	}

	
	return 0;
}

void itemsTable()
{
	cout << "1 | Milk\n"
	 << "2 | Lollies\n"
	 << "3 | Tomato Paste\n"
	 << "4 | Butter\n"
	 << "5 | Chips\n";
}
