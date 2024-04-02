#include <iostream>
#include "String.h"


int main()
{
	String s1("First");
	String s2("Second");

	String s3 = s1 + s2;
	std::cout << s3 << std::endl;

	std::cout << "Length of s3: " << s3.length() << std::endl;

	s3.clear();
	std::cout << "Is s3 empty: " << s3.empty() << std::endl;

	String s4;
	std::cin >> s4;
	std::cout << "You entered: " << s4;
	
	return 0;
}