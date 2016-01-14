/* Name: Ryan Ang
The program is written on MS Visual Studio C++ platform, Windows x64
*/

//Checks for memory leaks
#ifdef _WIN32 //WIN32 is defined on windows: source http://stackoverflow.com/questions/8666378/detect-windows-or-linux-in-c-c
#if defined(_MSC_VER) 
//http://stackoverflow.com/questions/28166565/detect-gcc-as-opposed-to-msvc-clang-with-macro
//gcc does not have crtdbg, visual c++ does. 
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif
#endif
//Checks for memory leaks

#include <cstring>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <math.h>
#include <stdlib.h>

#include <string>
#include <string.h>
#include <sstream>
#include <vector>

std::string encrypt(std::string &iostr, int key);//http://www.cplusplus.com/forum/beginner/115317/ 
std::string decrypt(std::string &iostr, int key);
void test();//test some functions
void main2();// actual main
void bruteForce();// brute force a message
void printMenu();

int main()
{
	//_CrtSetBreakAlloc(307); //memory leak reported ith memory allocation. This will break at ith.
	main2();
#ifdef _WIN32 
#if defined(_MSC_VER) 

	_CrtDumpMemoryLeaks();//checks for memory leak. MUST USE DEBUGGER
#endif
#endif
	return 0;
}
void test()
{
	std::string source;
	std::cout << "Enter a message" << std::endl;
	std::getline(std::cin, source);//flush new line char
	std::getline(std::cin, source);
	//std::cin >> source;

	int key;
	std::cout << "Enter an integer" << std::endl;
	std::cin >> key;


	std::string en = encrypt(source, key);

	std::cout << "encrypted: " << en << std::endl;

	std::string de = decrypt(en, key);

	std::cout << "decrypted: " << de << std::endl;
}
void main2()
{
	std::string choice = "";
	printMenu();
	do {
		std::cin >> choice;
		if (choice == "1")
		{
			test();
		}
		else if (choice == "2")
		{
			bruteForce();
		}
		else if (choice == "h")
		{
			printMenu();
		}
		else if (choice == "q")
		{
			std::cout << "Exiting. " << std::endl;
		}
		else
		{
			std::cout << "Invalid command. " << std::endl;
		}
		
	} while (choice != "q");

}
void bruteForce()
{
	std::string source;
	std::cout << "Enter an encrypted message" << std::endl;
	std::getline(std::cin, source);//flush new line char
	std::getline(std::cin, source);
	//std::cin >> source;

	std::cout << "Attempting to decrypt: " << source << std::endl;
	std::string de;
	for (int i = -27; i <= 26; i++)
	{
		de = decrypt(source, i);
		std::cout << de << "  Key: " << i;
		if (i % 2 != 0)
		{
			if (i > 0 && i < 10 )
				std::cout << "\t\t";
			else
				std::cout << "\t";
		}
			
		if (i % 2 == 0)//keep two columns
			std::cout << "\n\n";
	}
}
void printMenu()
{
	std::cout << "Enter (1) for encrypting a message" << std::endl;
	std::cout << "Enter (2) for brute forcing an encrypted message" << std::endl;
	std::cout << "Enter (h) for help menu" << std::endl;
	std::cout << "Enter (q) to quit" << std::endl;
}

std::string encrypt(std::string &iostr, int key)
{
	key %= 26;//take key and divide by 26 and take remainder
	int ch;
	std::string result = iostr;

	for (auto &it : result)
	{
		ch = tolower(it) + key;

		if (key < 0 && ch < 'a')
			ch += 26;

		if (ch > 'z')
			ch -= 26;
		it = ch;
	}
	return result;

}

std::string decrypt(std::string &iostr, int key)
{
	key %= 26;//take key and divide by 26 and take remainder
	int ch;
	std::string result = iostr;

	for (auto &it : result)
	{
		ch = tolower(it) - key;

		if (key < 0 && ch > 'z')
			ch -= 26;

		if (ch < 'a')
			ch += 26;
		it = ch;
	}
	return result;
}
