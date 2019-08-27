#include <iostream>
#include "Learner.h"

int main() {
	Learner AI;
	for (;;) {
		std::cout << "\nYOU: ";
		std::string phrase;
		getline(std::cin, phrase);
		std::cout << "COMPUTER: ";
		AI.respond(phrase);
	}

	system("pause");
	return 0;
}