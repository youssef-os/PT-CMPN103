#include "Output.h"
#include <math.h>

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW_MAIN;
	
	UI.width = 1440;
	UI.height = 720;
	UI.wx = 5;
	UI.wy =5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 85;
	UI.MenuItemWidth = 85;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = MEDIUMPURPLE;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = GRAY;	//Background color
	UI.ToolBarColor = WHITE;
	UI.HighlightColor = DARKBLUE;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 3;	//width of the figures frames

	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateMainToolBar();
	CreateStatusBar();
}
//////////////////////////////////////////////////////////////////////////////////////////

Input* Output::CreateInput(Output*pOut) const
{
	Input* pIn = new Input(pWind, pOut);
	return pIn;
}

//////////////////////////////////////////////////////////////////////////////////////////

//======================================================================================//
//								Interface Functions										//
//======================================================================================//
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearToolBar() const
{
	pWind->SetBrush(UI.ToolBarColor);
	pWind->SetPen(UI.ToolBarColor, 1);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);
}
//////////////////////////////////////////////////////////////////////////////////////////
window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar() const
{
	//Clear Status bar by drawing a filled white rectangle
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateEditToolBar() const
{
	UI.InterfaceMode = MODE_DRAW_EDIT;

	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[EDIT_ITM_COUNT];
	this->ClearToolBar();
	MenuItemImages[ITM_DEL] = "images\\EditMenuItems\\delete.jpg";
	MenuItemImages[ITM_MOVE] = "images\\EditMenuItems\\move.jpg";
	MenuItemImages[ITM_RESIZE] = "images\\EditMenuItems\\resize.jpg";
	MenuItemImages[ITM_ROTATE] = "images\\EditMenuItems\\rotate.jpg";
	MenuItemImages[ITM_SEND_BACK] = "images\\EditMenuItems\\sendback.jpg";
	MenuItemImages[ITM_BRNG_FRNT] = "images\\EditMenuItems\\bringfront.jpg";
	MenuItemImages[ITM_COPY] = "images\\EditMenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\EditMenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\EditMenuItems\\paste.jpg";
	MenuItemImages[ITM_BACKEDIT] = "images\\EditMenuItems\\back.jpg";
	
	//TODO: Prepare images for each menu item and add it to the list

	//Draw menu item one image at a time
	for(int i=0; i<EDIT_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth,0,UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateMainToolBar() const
{
	UI.InterfaceMode = MODE_DRAW_MAIN;
	string MenuItemImages[MAIN_ITM_COUNT];
	this->ClearToolBar();
	MenuItemImages[ITM_ADD] = "images/MainMenuItems/add.jpg";
	MenuItemImages[ITM_EDIT] = "images\\MainMenuItems\\edit.jpg";
	MenuItemImages[ITM_CHNG_DRAW_CLR] = "images\\MainMenuItems\\chngDrawColor.jpg";
	MenuItemImages[ITM_CHNG_FILL_CLR] = "images\\MainMenuItems\\fillCurrentShape.jpg";
	MenuItemImages[ITM_CHNG_BK_CLR] = "images\\MainMenuItems\\background.jpg";
	MenuItemImages[ITM_ZOOM_IN] = "images\\MainMenuItems\\zoom-in.jpg";
	MenuItemImages[ITM_ZOOM_OUT] = "images\\MainMenuItems\\zoom-out.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MainMenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MainMenuItems\\load.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MainMenuItems\\exit.jpg";
	MenuItemImages[ITM_TO_PLAY] = "images\\MainMenuItems\\ToPlay.jpg";
	//Draw menu item one image at a time
	for (int i = 0; i < MAIN_ITM_COUNT; i++)
	{
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);
	}
	//Draw a line under the toolbar
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}

////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawMenuToolBar() const //creates Draw mode menu toolbar
{
	UI.InterfaceMode = MODE_DRAW_DRAW;
	string MenuItemImages[DRAW_ITM_COUNT];
	this->ClearToolBar();
	MenuItemImages[ITM_LINE] = "images\\DrawMenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\DrawMenuItems\\rect.jpg";
	MenuItemImages[ITM_TRI] = "images\\DrawMenuItems\\triangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\DrawMenuItems\\circle.jpg";
	MenuItemImages[ITM_BACKDRAW] = "images\\DrawMenuItems\\back.jpg";


	for (int i = 0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreatePlayToolBar() const
{
	this->ClearToolBar();
	UI.InterfaceMode = MODE_PLAY;
	string MenuItemImages[PLAY_ITM_COUNT];
	MenuItemImages[ITM_PICK_HIDE_MODE] = "images\\PlayMenuItems\\pickandhide.jpg";
	MenuItemImages[ITM_SCRAMBLE_FIND_MODE] = "images\\PlayMenuItems\\scrambleandfind.jpg";
	MenuItemImages[ITM_TO_DRAW] = "images\\PlayMenuItems\\ToDraw.jpg";
	MenuItemImages[ITM_EXITPLAY] = "images\\PlayMenuItems\\exit.jpg";

	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//Draw a line under the toolbar
	pWind->SetPen(WHITE, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);
	
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);
	
}

void Output::DrawLine(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	pWind->DrawLine(P1.x, P1.y, P2.x, P2.y);
}
void Output::DrawTRI(Point P1, Point P2, Point P3, GfxInfo RectGfxInfo, bool selected ) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	pWind->DrawTriangle(P1.x, P1.y, P2.x, P2.y, P3.x, P3.y, style);
}

void Output::DrawCircle(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if (selected)
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else
		DrawingClr = RectGfxInfo.DrawClr;

	pWind->SetPen(DrawingClr, RectGfxInfo.BorderWdth);	//Set Drawing color & width

	drawstyle style;
	if (RectGfxInfo.isFilled)
	{
		style = FILLED;
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else
		style = FRAME;
	double rad = sqrt(pow((P2.x - P1.x), 2) + pow((P2.y - P1.y),2));
	if ((P1.y + rad) > (UI.height - UI.StatusBarHeight)) rad = UI.height - UI.StatusBarHeight - P1.y;
	if ((P1.y - rad) < UI.ToolBarHeight) rad = P1.y - UI.ToolBarHeight;
	pWind->DrawCircle(P1.x, P1.y, rad, style);
}

//////////////////////////////////////////////////////////////////////////////////////////
Output::~Output()
{
	delete pWind;
}

