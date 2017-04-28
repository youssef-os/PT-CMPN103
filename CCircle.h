#pragma once
#include "e:\cce sophomore\pt-cmpn103\figures\cfigure.h"
class CCircle :
	public CFigure
{

private:
	Point Center;	
	Point Distance;
public:
	CCircle(Point , Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;
	virtual void GetFigureParameters(Point&P1, Point&P2, Point&P3, GfxInfo&Gfx);
	//virtual void Save(ofstream &OutFile);
	//yala asht3'l
};

