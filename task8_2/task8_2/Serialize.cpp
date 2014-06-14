
/**
*@file		SErialize.cpp
*@brief		Implements methods for serialize class that gets information about shoes from file
*/

#include "stdafx.h"
#include "Serialize.h"

#define ERROR 0
#define SUCCESS 1
#define NEXT_MODEL 11
#define SHOE_BEG "<shoe>"
#define SHOE_END "<shoe/>"
#define MODEL_NAME_BEG "<model>"
#define MODEL_NAME_END "<model/>"
#define SIZE_BEG "<size>"
#define SIZE_END "<size/>"
#define QUANTITY_BEG "<quantity>"
#define QUANTITY_END "<quantity/>"


using namespace std;

/**
* @brief			Constructor without parameters to set fields in class to their default values
* @param	void
*/
Serialize::Serialize(void) : content()
{
}

/**
* @brief				Destructor
* @param	void
*/
Serialize::~Serialize(void)
{
}


/**
* @brief					Function for reading all information from file into vector of strings
* @param	[const string&]	fileName - name of file which saves information about shoes
*
*@return	unsigned int	returns Error if file can't be opened
							otherwise if file was opened and information was read
*/
unsigned int Serialize::Read(const string& fileName)
{

	ifstream file;
	string line;
	file.open(fileName);
	if (file.is_open())
	{
		while (!file.eof())
		{

			file >> line;
			content.push_back(line);
		}
		if (!content.empty())
		{
			return SUCCESS;
		}
	}
	else
	{
		return ERROR;
	}
	file.close();
	return SUCCESS;
}


/**
* @brief					Function for parsing lines from file on shoe's model,size and quantity
* @param	[vector<Shoe>&]	shoes - vector that contains information about shoes
*
*@return	unsigned int	returns Error if there is no data in file
							otherwise if file was opened and information was found returns success
*/
unsigned int Serialize::Parse(vector<Shoe>& shoes)
{
	unsigned int num = 0;
	vector<string> data;
	Shoe temp;
	Trim(content, NEXT_MODEL*num, SHOE_BEG, SHOE_END, data);
	if (data.empty())
	{
		return ERROR;
	}
	
	while (!data.empty())
	{
		Trim(content, (NEXT_MODEL*num) + 1, MODEL_NAME_BEG, MODEL_NAME_END, data);
		if (!data.empty())
		{
			string model;
			for (unsigned int n = 0; n < data.size(); ++n)
			{
				model.append(data[n] + " ");
			}

			unsigned int size;
			Trim(content, (NEXT_MODEL*num) + 1, SIZE_BEG, SIZE_END, data);
			if (!data.empty())
			{
				size = atoi(data[0].c_str());
			}

			unsigned int quantity;
			Trim(content, (NEXT_MODEL*num) + 1, QUANTITY_BEG, QUANTITY_END, data);
			if (!data.empty())
			{
				quantity = atoi(data[0].c_str());
			}
			temp.SetModel(model);
			temp.SetSize(size);
			for (unsigned int n = 0; n < quantity; ++n)
			{
				shoes.push_back(temp);
			}
			++num;
		}
		else
		{
			return ERROR;
		}
		Trim(content, num*NEXT_MODEL, SHOE_BEG, SHOE_END, data);
	}
	return SUCCESS;
}


/**
* @brief							Function that trims defined information from vector of strings
* @param	[const vector<string>&]	toTrim - vector of strings
			[size_t]				startIndex - index of needed information from begging of vector toTrim
			[const string&]			opener - string that marks the beginning of needed information
			[const string&]			closer - string that marks the end of needed information
			[vector<string>&]		result - vector that contains needed information

*
*@return	void				
*/
void Serialize::Trim(const vector<string>& toTrim, size_t startIndex, const string& opener, const string& closer, vector<string>& result)
{
	result.clear();
	vector<string>::const_iterator itr;
	vector<string>::const_iterator itr2;
	
	itr = find(toTrim.begin()+startIndex, toTrim.end(), opener);
	if (itr != toTrim.end())
	{
		itr2 = find(itr, toTrim.end(), closer);
		if (itr2 != toTrim.end())
		{
			for (++itr; itr != itr2; ++itr)
			{
				result.push_back(*itr);
			}
		}
	}
}
