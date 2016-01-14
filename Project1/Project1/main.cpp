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

int main()
{
	//_CrtSetBreakAlloc(307); //memory leak reported ith memory allocation. This will break at ith.
	//appStore();
#ifdef _WIN32 
	_CrtDumpMemoryLeaks();//checks for memory leak. MUST USE DEBUGGER
#endif
	return 0;
}