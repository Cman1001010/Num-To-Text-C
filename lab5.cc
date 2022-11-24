//Lab5
//Charles Engle
//11/4/2022
//Programming with C

#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

void error()
{
	string errStr = "Error: digit in 10s position cannot be one";
	throw runtime_error(errStr);
}

//Vector manipulation methods
void vAdd(vector<char>* dest, string in)
{
	for(char c: in)
	{
		dest->push_back(c);
	}
}
void vPrint(vector<char>* read)
{
	int rSize = read->size();
	vector<char> temp = *read;
	for(int i = 0; i < rSize; i++)
	{
		cout << temp[i];
	}
	cout << "\n";
}

//Translates nums to words
void numt(vector<char>* dest, int num)
{
	switch(num)
	{
		case 1:
			vAdd(dest, "one ");
			break;
		case 2:
			vAdd(dest, "two ");
			break;
		case 3:
			vAdd(dest, "three ");
			break;
		case 4:
			vAdd(dest, "four ");
			break;
		case 5:
			vAdd(dest, "five ");
			break;
		case 6:
			vAdd(dest, "six ");
			break;
		case 7:
			vAdd(dest, "seven ");
			break;
		case 8:
			vAdd(dest, "eight ");
			break;
		case 9:
			vAdd(dest, "nine ");
			break;
	}
}

//Adds hundred or thousand
void position(vector<char>* dest, int pos)
{

	switch(pos)
	{
		case 2:
			vAdd(dest, "hundred ");
			break;
		case 3:
			
			vAdd(dest, "thousand ");
			break;
	}
}

//Translate tens positions
void tens(vector<char>* dest, int in)
{
	switch(in)
	{
		case 1:
			error();
			break;
		case 2:
			vAdd(dest, "twenty ");
			break;
		case 3:
			vAdd(dest, "thirty ");
			break;
		case 4:
			vAdd(dest, "forty ");
			break;
		case 5:
			vAdd(dest, "fifty ");
			break;
		case 6:
			vAdd(dest, "sixty ");
			break;
		case 7:
			vAdd(dest, "seventy ");
			break;
		case 8:
			vAdd(dest, "eighty ");
			break;
		case 9:
			vAdd(dest, "ninety ");
			break;
	}
}

//Final translate function
void translate(vector<char>* fin, int num)
{
	int size = log10(num);
	int temp;
	int use = num;
	vector<int> nums;

	//i = position
	//temp = number in pos
	//use = num - each read position
	for(int i = size; i > -1; i--)
	{
		temp = use/pow(10, i);
		use = use-(temp * pow(10, i));
		
		//test
		//cout << "Test1: " << temp << ", " << use;

		if(i < 1)
		{
			numt(fin, temp);
		}
		else if (i == 1)
		{
			tens(fin,temp);
		}
		else
		{
			numt(fin, temp);
			position(fin, i);
		}
	}
}

int main(int argc, char* argv[])
{
	string snum = argv[1];
	int num = stoi(snum);

	vector<char> out;
	vAdd(&out, "Number "); vAdd(&out, snum); vAdd(&out, " is written as ");
        translate(&out, num);

	vPrint(&out);

	return 0;
}
