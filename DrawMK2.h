#pragma once

#include <Windows.h>
#include <string>

#define WIDECHAR
#define COLOR


#ifdef COLOR
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
#endif

//trying to cut down on the repeted code in DrawFunc by making template with overloads 
template <typename T>
class DrawMK2
{
	short m_yMax;
	HANDLE m_hOutput;
	COORD m_coord;

	///////////////////////////
	//sets coord to cursor pos
	///////////////////////////
	void UpdatePos();

public:

	DrawMK2();

	////////////////////////////////////////////////////////////
	//basic print
	//////////////////////////////////////////////////////////

	////////////////////////////////////
	//print at location on screen
	//////////////////////////////////
	/*	template <>
	void operator()(std::string disp, int x, int y);
	
	{
		m_coord = { (short)x, (short)y };
		SetConsoleCursorPosition(m_hOutput, m_coord);
		//draw buff to consol
		WriteConsoleA(m_hOutput, disp.c_str(), disp.length(), NULL, NULL);
	}*/

		/*	void operator()(T disp, int x, int y);

	{
		std::string dsp = std::to_string(disp);
		(*this)(val, x, y);
	}*/


	///////////////////////////////
	//print at last cursor location
	////////////////////////////////
	void operator()(T disp);


	////////////////////////////////////////////////////////////
	//color print
	//////////////////////////////////////////////////////////
#ifdef COLOR
	////////////////////////////////
	//print char with color
	/////////////////////////////////
	void operator()(T disp, int x, int y, int color);
	void operator()(T disp, int color);

#endif // COLOR

	//not sure if this is needed in template

	////////////////////////////////////////////////////////////
	//wide print
	//////////////////////////////////////////////////////////
#ifdef WIDECHAR
	/////////////////////////////
	//print wide char at location
	////////////////////////////////
	void operator()(wchar_t disp, int x, int y);

	//print at last cursor location
	void operator()(wchar_t disp);

	////////////////////////////////////////////////////////////
	//wide print with color
	//////////////////////////////////////////////////////////
#ifdef COLOR
	/////////////////////////////////
	//print wide char with color
	///////////////////////////////
	void operator()(wchar_t disp, int x, int y, int color);
#endif // COLOR

#endif // WIDECHAR
};



