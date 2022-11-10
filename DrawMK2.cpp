#include "DrawMK2.h"


#include <iostream>
#include <io.h>//setmode
#include <fcntl.h>//_O_ codes

template <typename T>
DrawMK2<T>::DrawMK2()
	:m_yMax(0)
	, m_hOutput(GetStdHandle(STD_OUTPUT_HANDLE))
	, m_coord({ 0,0 })
{
	UpdatePos();
}

template <typename T>
void DrawMK2<T>::UpdatePos()
{
	POINT pos;
	if (GetCursorPos(&pos))
	{
		m_coord.X = static_cast<short>(pos.x);
		m_coord.Y = static_cast<short>(pos.y);
	}
}

////////////////////////////////////////////////////////////
//basic print
//////////////////////////////////////////////////////////

////////////////////////////////////
//print at location on screen
//////////////////////////////////
/*
template <>
void DrawMK2<std::string>::operator()(std::string disp, int x, int y)
{
	m_coord = { (short)x, (short)y };
	SetConsoleCursorPosition(m_hOutput, m_coord);
	//draw buff to consol
	WriteConsoleA(m_hOutput, disp.c_str(), disp.length(), NULL, NULL);
}
//need to make sure type is not string befor converrting
//trying to overload to speialize for string
template <class T>
void DrawMK2<T>::operator()(T disp, int x, int y)
{
	std::string dsp = std::to_string(disp);
	(*this)(val, x, y);
}*/

///////////////////////////////
//print at last cursor location
////////////////////////////////
template <typename T>
void DrawMK2<T>::operator()(T disp)
{

}


////////////////////////////////////////////////////////////
//color print
//////////////////////////////////////////////////////////
#ifdef COLOR
////////////////////////////////
//print char with color
/////////////////////////////////
template <typename T>
void DrawMK2<T>::operator()(T disp, int x, int y, int color)
{

}
template <typename T>
void DrawMK2<T>::operator()(T disp, int color)
{

}

#endif // COLOR
