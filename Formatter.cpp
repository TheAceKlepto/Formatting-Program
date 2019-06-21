


/*
		User can enter a list of words seperated by a space to input into the program.
		The user MUST end their entry with a -1 in order for it to continue.

		This program will format the list into a file called words.txt and also output to the console
		the words in quotation marks seperated by a comma. This part will make it extremley easy to copy
		and paste the output into an array.
	*/


#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void usingCommas(std::vector<std::string>& v);
void createFile(std::vector<std::string>& v);

int main()
{
	std::string userInput = "";
	std::vector<std::string> stringVector; 
	
	std::cout << "Enter list of words here: ";
	std::cin >> userInput;

	while (userInput != "-1")
	{
		stringVector.push_back(userInput);
		std::cin >> userInput;
	}

	std::cout << "\n";

	usingCommas(stringVector);

	createFile(stringVector);

	std::cout << "\n\nAll operations complete...\n";
	
	system("Pause...");
	return 0;
}

void usingCommas(std::vector<std::string> &v)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (i == v.size() - 1)
			std::cout << "\"" << v[i] << "\"";
		else
			std::cout << "\"" << v[i] << "\"" << ", ";
	}
}

void createFile(std::vector<std::string>& v)
{
	std::ofstream myWordFile;

	myWordFile.open("words.txt");

	for (int i = 0; i < v.size(); i++)
		myWordFile << v[i] << " ";

	myWordFile.close();
}