/* Name: Ryan Ang
The program is written on MS Visual Studio C++ platform, Windows x64
*/

//Checks for memory leaks
#ifdef _WIN32 //WIN32 is defined on windows: source http://stackoverflow.com/questions/8666378/detect-windows-or-linux-in-c-c
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
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
void doIt();//actual main

int main()
{
	//_CrtSetBreakAlloc(307); //memory leak reported ith memory allocation. This will break at ith.
	doIt();
#ifdef _WIN32 
	_CrtDumpMemoryLeaks();//checks for memory leak. MUST USE DEBUGGER
#endif
	return 0;
}
void doIt()
{
	std::string source;
	std::cout << "Enter a message" << std::endl;
	std::cin >> source;

	int key;//move by 15
	std::cout << "Enter an integer" << std::endl;
	std::cin >> key;


	std::string en = encrypt(source, key);

	std::cout << "encrypted: " << en << std::endl;

	std::string de = decrypt(en, key);

	std::cout << "decrypted: " << de << std::endl;
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
