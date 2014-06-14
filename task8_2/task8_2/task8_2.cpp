/**
* @file			task8_2.cpp
* @brief		Program simulates the work of popular shoe's store

* Copyright 2014 by Yuliia Lyubchik Inc.,
*
* This software is the confidential and proprietary information
* of Yuliia Lyubchik. ("Confidential Information").  You
* shall not disclose such Confidential Information and shall use
* it only with permission from Yuliia.
*
*/

#include "stdafx.h"
#include "Serialize.h"
#include "Shoe.h"
#include "task8_2.h"
#include "Store.h"

#define ERROR 0
#define SUCCESS 1

using std::cout;
using std::cin;

int main(void)
{
	Interface();

	Serialize db;
	unsigned int retCode;
	unsigned int num;

	db.Read("shoes.txt");
	std::vector <Shoe> storage;
	retCode = db.Parse(storage);

	if (retCode = ERROR)
	{
		cout << "Sorry, error occurs while trying to get information about shoes in storage";
		return 0;
	}
	do
	{
		char str[10];
		unsigned char command;
		do
		{
			cout << "Enter how buyers will be in store: ";
			cin >> str;
			retCode = Is_posit_digit(str);
			if (!retCode)
			{
				puts("Please check if you entered positive digit number.");
			}
		} 
		while (!retCode);
		num = atoi(str);

		Store shop(num);

		while (true)
		{
			do
			{
				cout << "\nEnter next command \ne - exit program, b - sent buyers to shopping,";
				cout << "\nd - show information in store, s - show customer's purchases \n : ";
				cin >> command;
			}
			while (command != 'e' && command != 'b' && command != 's' && command != 'd');

			if (command == 'e')
			{
				getchar();
				return 0;
			}

			else if (command == 'b')
			{
				shop.Shopping(storage, num);
				if (storage.empty())
				{
					cout << "There is no shoes in store. Please come next time;)";
					getchar();
					getchar();
					return 0;
				}
			}
			else if (command == 'd')
			{
				for (unsigned int n = 0; n < storage.size(); ++n)
				{
					cout << "model: " << storage[n].GetModel() << "\t";
					cout << "size: " << storage[n].GetSize() << "\n";
				}
			}
			else if (command == 's')
			{
				retCode = shop.ShowCustomers();
				if (retCode)
				{
					cout << "On the moment there is no purchase in the store." << "\n";
				}
			}
		}

	} 
	while (true);
	getchar();
	return 0;
}


void Interface(void)
{
	puts("------------------------------------------------------------------------");
	puts("Welcome to the first console store! ");
	puts("Let shopping begin!");
	puts("Program made by Yuliia Lyubchik.");
	puts("------------------------------------------------------------------------\n");
}


bool Is_posit_digit(char* str)
{
	if (str == NULL)
	{
		return ERROR;
	}
	char* psubstr;
	char key[] = "0123456789";
	psubstr = strpbrk(str, key);
	if (psubstr == NULL)
	{
		return ERROR;
	}
	int shift = 0;
	while (psubstr != NULL)
	{
		if (psubstr != (str + shift))
		{
			return ERROR;
		}
		psubstr = strpbrk(psubstr + 1, key);
		shift++;
	}
	return SUCCESS;
}
