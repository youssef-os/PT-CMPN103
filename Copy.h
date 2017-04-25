#pragma once
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Actions\Action.h"
#include "Figures\CFigure.h"
#include "Figures\CRectangle.h"
#include "ApplicationManager.h"

class CRectangle;
class CFigure;

class Copy :
	public Action
{
	int MaxSelSize;
	Point P1, P2;
	int SelFigCount;
	CFigure**SelFigList;
public:
	Copy(ApplicationManager *pApp);
	void FindSelectedFig();
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};

