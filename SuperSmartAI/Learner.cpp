#include "Learner.h"
#include <iostream>
#include <fstream>

void Learner::respond(std::string phrase) {
	std::fstream memory;
	memory.open("memory.txt", std::ios::in);
	if (memory.fail()) {
		std::cerr << "File could not be opened." << std::endl;
	}
	while (!memory.eof()) {
		std::string identifier;
		getline(memory, identifier);
		if (identifier == phrase) {
			std::string response;
			getline(memory, response);
			std::cout << response << std::endl;
			return;
		}
	}
	memory.close();

	memory.open("memory.txt", std::ios::out | std::ios::app);
	if (memory.fail()) {
		std::cerr << "File could not be opened." << std::endl;
	}
	memory << phrase << std::endl;
	std::cout << phrase << std::endl;
	std::cout << "YOU: ";
	std::string response;
	getline(std::cin, response);
	memory << response << std::endl;
	memory.close();
}