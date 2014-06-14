
/**
*@file		Shoe.h
*@brief		Header file that holds information about one pair of shoes
*/

#ifndef SHOE_H_
#define SHOE_H_

class Shoe
{
public:
	//life cycle
	Shoe(void);
	~Shoe(void);

	void SetModel(const std::string&  _model);
	void SetSize(unsigned int _size);
	std::string GetModel(void);
	unsigned int GetSize(void);


private:
	//fields
	std::string model;
	unsigned int size;
};

#endif