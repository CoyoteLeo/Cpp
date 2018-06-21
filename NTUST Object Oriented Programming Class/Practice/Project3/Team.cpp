#include "Team.h"
#include <string>

void Team::fetchCommand(std::string input)
{
	std::string temp;

	std::cout << "Input : \n" << input << std::endl << std::endl;
	while (input.find('\r') != std::string::npos)
	{
		temp = temp.assign(input, 0, input.find('\r'));
		input.erase(0, input.find('\r') + 2);
		commands.push_back(temp);
	}
	commands.push_back(input);
}
