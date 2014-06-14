
/**
*@file		Store.h
*@brief		Header file that describes class Store for modeling the shopping in store
*/

#ifndef STORE_H_
#define STORE_H_

#include "Buyer.h"
#include "Shoe.h"

class Store
{
public:
	//life cycle
	~Store(void);
	Store(unsigned int num);

	void Shopping(std::vector<Shoe>& storage, unsigned int n);
	bool ShowCustomers(void);

private:
	//prohibit
	Store(void);

	//fields
	std::vector <Buyer> buyers;
	
};

#endif