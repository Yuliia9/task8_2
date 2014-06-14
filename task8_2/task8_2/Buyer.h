
/**
*@file		Buyer.h
*@brief		Header file that describes class Buyer that holds information about customers, their purchases
*/

#ifndef BUYER_H_
#define BUYER_H_

#include "Shoe.h"

class Buyer
{
public:
	//life cycle
	Buyer(void);
	~Buyer(void);

	void Buyer::SetPurchase(const Shoe shoe);
	Shoe GetPurchase(unsigned int n);
	unsigned int GetNumPurchase(void);
	void SetNumPurchase(unsigned int n);

private:
	//fields
	std::vector<Shoe> shoes;
	unsigned int purchase;
};

#endif