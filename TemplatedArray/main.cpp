#include <iostream>
#include <string>
#include "TArray.h"

int main()
{
	TArray<int> myArray{ 3 };
	myArray.setValue(0, 1);
	myArray.setValue(1, 10);
	myArray.setValue(2, 100);
	std::cout << myArray << std::endl;

	TArray<std::string> strArray{ 2 };
	strArray.setValue(0, "Hello");
	strArray.setValue(1, "World");
	std::cout << strArray << std::endl;

	return 0;
}