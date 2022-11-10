#include "Print.h"


#include <iostream>
#include <io.h>//setmode
#include <fcntl.h>//_O_ codes

Draw::Draw()
	:m_yMax(0)
	, m_hOutput(GetStdHandle(STD_OUTPUT_HANDLE))
	, m_coord({ 0,0 })
{
	UpdatePos();
}

void Draw::UpdatePos()
{
	POINT pos;//contains long while COORD uses short
	if (GetCursorPos(&pos))// takes a POINT
	{
		m_coord.X = static_cast<short>(pos.x);
		m_coord.Y = static_cast<short>(pos.y);
	}
}

////////////////////////////////////
//print char at location on screen
//////////////////////////////////
void Draw::operator()(char disp, int x, int y)
{
	m_coord = { (short)x, (short)y };
	SetConsoleCursorPosition(m_hOutput, m_coord);
	char buff[1]{ disp };

	//draw buff to consol
	WriteConsoleA(m_hOutput, buff, 1, NULL, NULL);

	//set cursor position to bottom of output
	/*
	if (y > m_yMax)
	{
	while (m_yMax <= y)
	++m_yMax;

	m_fakeLine = true;
	}

	if (y == m_yMax)
	{
	++m_yMax;
	m_fakeLine = true;
	}


	m_coord = { (short)0, m_yMax };

	SetConsoleCursorPosition(m_hOutput, m_coord);*/
}
///////////////////////////
//loop through and display string starting at location
////////////////////////////
void Draw::operator()(std::string disp, int x, int y)
{
	for (unsigned int i = 0; i < disp.length(); ++i)
	{
		(*this)(disp[i], x + i, y);
	}
}

void Draw::operator()(char disp)
{
	UpdatePos();
	(*this)(disp, m_coord.X, m_coord.Y);
}

void Draw::operator()(std::string disp)
{
	UpdatePos();
	(*this)(disp, m_coord.X, m_coord.Y);
}

////////////////////////////////
//print char with color
/////////////////////////////////
void Draw::operator()(char disp, int x, int y, int color)
{
	SetConsoleTextAttribute(m_hOutput, color);//set color
	(*this)(disp, x, y);
	SetConsoleTextAttribute(m_hOutput, LIGHTGREY);//set back to default color
}


/////////////////////////////
//print wide char at location
////////////////////////////////
void Draw::operator()(wchar_t disp, int x, int y)
{
	_setmode(_fileno(stdout), _O_WTEXT);

	m_coord = { (short)x, (short)y };
	SetConsoleCursorPosition(m_hOutput, m_coord);
	wchar_t buff[1]{ disp };

	WriteConsoleW(m_hOutput, buff, 1, NULL, NULL);
	/*
	if (y > m_yMax)
	{
	while (m_yMax <= y)
	++m_yMax;
	}

	if (y == m_yMax)
	++m_yMax;

	m_coord = { (short)0, m_yMax };

	SetConsoleCursorPosition(m_hOutput, m_coord);*/

	_setmode(_fileno(stdout), _O_TEXT);
}

void Draw::operator()(wchar_t disp)
{
	UpdatePos();
	(*this)(disp, m_coord.X, m_coord.Y);
}

/////////////////////////////////
//print wide char with color
///////////////////////////////
void Draw::operator()(wchar_t disp, int x, int y, int color)
{
	SetConsoleTextAttribute(m_hOutput, color);
	(*this)(disp, x, y);
	SetConsoleTextAttribute(m_hOutput, LIGHTGREY);
}