
/**
*@file		Buyer.cpp
*@brief		Implements methods for Buyer class that holds information about customers, their purchases
*/

#include "stdafx.h"
#include "Buyer.h"

unsigned int ERROR = 0;
unsigned int SUCCESS = 1;

using std::string;


/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
Buyer::Buyer(void) : shoes(), purchase(0)
{

}


/**
* @brief				Destructor
* @param	void
*/
Buyer::~Buyer(void)
{
}

/**
* @brief					Method for setting purchase of customer
* @param	[const Shoe]	shoe - the purchase of customer
*
*@return	void
*/
void Buyer::SetPurchase(const Shoe shoe)
{
	shoes.push_back(shoe);
	++purchase;
}


/**
* @brief					Method for getting the number of customers of customers
* @param	void
*
*@return	unsigned int	the number of customers purchase
*/
unsigned int Buyer::GetNumPurchase(void)
{
	return purchase;
}


/**
* @brief					Method for setting the number of purchases for customer
* @param	[unsigned int]  n - the number of purchase of customer
*
*@return	void
*/
void Buyer::SetNumPurchase(unsigned int n)
{
	purchase = n;
}


/**
* @brief					Method for getting the information about purchase of customer
* @param	[unsigned int]  n - the index of purchase of customer
*
*@return	Shoe			Returns the object of Shoe class that holds information about purchase
*/
Shoe Buyer::GetPurchase(unsigned int n)
{
	return shoes.at(n);
}

