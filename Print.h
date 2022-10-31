#pragma once

#include <Windows.h>
#include <string>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6

#define LIGHTGREY 7 //default
#define DARKGREY 8

#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14

#define WHITE 15


class Draw
{
	short m_yMax;
	HANDLE m_hOutput;
	COORD m_coord;


	void UpdatePos();

public:

	Draw();

	////////////////////////////////////
	//print char at location on screen
	//////////////////////////////////
	void operator()(char disp, int x, int y);///////////////
											 //print string
	void operator()(std::string disp, int x, int y);
	//print at last cursor location
	void operator()(char disp);///////////////////
	void operator()(std::string disp);///////////////////

									  ////////////////////////////////
									  //print char with color
									  /////////////////////////////////
	void operator()(char disp, int x, int y, int color);


	/////////////////////////////
	//print wide char at location
	////////////////////////////////
	void operator()(wchar_t disp, int x, int y);
	//print at last cursor location
	void operator()(wchar_t disp);

	/////////////////////////////////
	//print wide char with color
	///////////////////////////////
	void operator()(wchar_t disp, int x, int y, int color);
};



