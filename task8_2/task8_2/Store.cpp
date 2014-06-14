
/**
*@file		Store.cpp
*@brief		Implements methods for class Store for modeling the shopping in store
*/

#include "stdafx.h"
#include "Store.h"

using namespace std;

#define POSSIBLY_NUM_PURCHASE 2

/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
Store::Store(void)
{
}


/**
* @brief					Constructor for creating object of class with defined number of customers in shop
* @param	[unsigned int]  num - number of customers in store
*/
Store::Store(unsigned int num) : buyers(num)
{

}

/**
* @brief				Destructor
* @param	void
*/
Store::~Store(void)
{
}

/**
* @brief					Method for modeling shopping in store 
* @param	[vector<Shoe>&] storage - information about shoes that sails in store
			[unsigned int]  n - number of customers in store
*
*@return	void
*/
void Store::Shopping(vector<Shoe>& storage, unsigned int n)
{
	unsigned int customer;
	unsigned int item;
	while (true)
	{
		customer = rand() % n;
		srand(n);
		if (buyers[customer].GetNumPurchase() < POSSIBLY_NUM_PURCHASE)
		{
			cout << "Buyer " << customer << "\t";

			item = rand() % storage.size();
			srand(storage.size());
			cout << "bought " << storage[item].GetModel() << " size " << storage[item].GetSize() << "\n";

			buyers[customer].SetPurchase(storage[item]);
			storage.erase(storage.begin() + item);

			break;
		}
		else
		{
			buyers[customer].SetNumPurchase(0);
			for (unsigned int i = 0; i < POSSIBLY_NUM_PURCHASE; ++i)
			{
				storage.push_back(buyers[customer].GetPurchase(i));
			}
		}
	}
}


/**
* @brief					Method for showing information about purchase of customers
* @param	void
*
*@return	bool			returns true if there is no purchase 
							otherwise returns false
*/
bool Store::ShowCustomers(void)
{
	bool isEmpty = true;
	Shoe temp;

	for (unsigned int i = 0; i < buyers.size(); ++i)
	{
		unsigned int num = buyers[i].GetNumPurchase();
		if (num != 0 )
		{
			for (unsigned int j = 0; j < num; ++j)
			{
				string res = buyers[i].GetPurchase(j).GetModel();
				isEmpty = false;
				temp = buyers[i].GetPurchase(j);
				cout << "Purchase of customer " << i << "\t";
				cout << "model: " << buyers[i].GetPurchase(j).GetModel() << "size " << temp.GetSize();
			}

		}
	}
	return isEmpty;
}

