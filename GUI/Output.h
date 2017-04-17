#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window

	// ----- Bars Drawing functions
	void CreateDrawMenuToolBar() const;	//creates Draw mode toolbar & menu
	void CreateMainToolBar() const;     //Creates Main Tool Bar
	void CreateEditToolBar() const;     //Creates Edit Tool bar
	void CreatePlayToolBar() const;	//creates Play mode toolbar & menu
	void CreateStatusBar() const;	//create the status bar
	void Output::ClearToolBar() const;

	
	Input* CreateInput(Output*pOut) const; //creates a pointer to the Input object	
	
	//---- Clearing functions
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	
	// -- Figures Drawing functions
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;  //Draw a rectangle
	void DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawTRI(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected = false) const;
	void DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected = false) const;
	///Make similar functions for drawing all other figures.
	
	void PrintMessage(string msg) const;	//Print a message on Status bar

	color getCrntDrawColor() const;	//get current drwawing color
	color getCrntFillColor() const;	//get current filling color
	int getCrntPenWidth() const;		//get current pen width

	
	~Output();
};

#endif