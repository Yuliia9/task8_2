
/**
*@file		Serialize.h
*@brief		Header file that describes class Serialize that gets information about shoes from file
*/


#ifndef SERIALIZE_H_
#define SERIALIZE_H_

#include "Shoe.h"

class Serialize
{
public:
	//life cycle
	Serialize(void);
	~Serialize(void);

	unsigned int Read(const std::string& fileName);
	unsigned int Parse(std::vector<Shoe>& shoes);
	void Trim(const std::vector<std::string>& toTrim, size_t startIndex, const std::string& opener, const std::string& closer, std::vector<std::string>& result);


private:
	//fields
	std::vector <std::string> content;
};

#endif