#include <iostream>
#include <string>
#include <fstream>
#include "filework.h"

using namespace std;

void threeInRow(string startFile, string endFile) {
	string line = "";
	int numbersInRow = 1;
	int totalNumbers = 1;
	bool isFirstString = true;
	while (true)
	{
		try
		{
			if (numbersInRow == 4)
			{
				line += '\n';
				if (isFirstString)
				{
					writeString(endFile, line);
					isFirstString = false;
				}
				else
				{
					addString(endFile, line);
				}
				line = "";
				numbersInRow = 1;
			}
			else
			{

				line += to_string(readNumber(startFile, totalNumbers)) + " ";
				totalNumbers++;
				numbersInRow++;
			}
		}
		catch (const std::invalid_argument& e)
		{
			line += '\n';
			if (isFirstString)
			{
				writeString(endFile, line);
				isFirstString = false;
			}
			else
			{
				addString(endFile, line);
			}
			break;
		}
	}
	
}

int main() {
	string fileName = "numbers.txt";
	string newFile = "formatedNumbers.txt";
	threeInRow(fileName, newFile);
	printFile(newFile);
	return 0;
}