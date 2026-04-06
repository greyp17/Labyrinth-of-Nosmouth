#include <iostream>

int TestFunctions() {

	//Prompt user for specific tests...
	int userAnswer{0};
	std::cout << "Would you like to test (testname)? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {
		
		//function call here
		std::cout << "First test function call\n";

	}
	std::cout << "Would you like to test (testname)? (0(no)/1(yes))\n";
	std::cin >> userAnswer;
	if (userAnswer == 1) {

		//function call here
		std::cout << "Second test function call\n";

	}

	std::cout << "End of test.\n";

	return 0;

}