#include <iostream>

//#include <io.h>//setmode
//#include <fcntl.h>//_O_ codes

//#include <Windows.h>//SetConsoleTextAttribute/ color

#include "DrawFunc.h"

//#define TEST
#include <string>
int main()
{
#ifdef TEST



	Draw print;

	print(L'\u2588', 0, 0, BLUE);
	print(L'\u2591');
	print(L'\u2592', 0, 1, LIGHTMAGENTA);
	print(L'\u2593');

	print("hello world", 0, 2);

	getchar();
	print("hi", 2, 2);

	getchar();

#else
	std::string foo = "hello";
	int bar = 105;

	Draw print;


	std::cout << foo;
	getchar();

	print(foo, 0, 1);



	getchar();
#endif // TEST
	return 0;
}