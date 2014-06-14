
/**
*@file		Shoe.cpp
*@brief		Implements methods for class Shoe that holds information about one pair of shoes
*/
#include "stdafx.h"
#include "Shoe.h"

using namespace std;

/**
* @brief			Constructor without parameters for setting fields in class to their default values
* @param	void
*/
Shoe::Shoe(void) : model("\0"), size(0)
{

}

/**
* @brief				Destructor
* @param	void
*/
Shoe::~Shoe(void)
{
}

/**
* @brief					Method for setting the model of shoe
* @param	[const string&] _model - the model of shoes
*
*@return	void
*/
void Shoe::SetModel(const string& _model)
{
	model = _model;
}

/**
* @brief					Method for setting the size of shoe
* @param	[unsigned int] _size - the size of shoes
*
*@return	void
*/
void Shoe::SetSize(unsigned int _size)
{
	size = _size;
}


/**
* @brief					Method for getting the model of shoe
* @param	void
*@return	string			the model of shoe
*/
string Shoe::GetModel(void)
{
	return model;
}

/**
* @brief					Method for getting the size of shoe
* @param	void
*@return	unsigned int	the size of shoe
*/
unsigned int Shoe::GetSize(void)
{
	return size;
}
