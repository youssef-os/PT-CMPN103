#pragma once
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Actions\Action.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Figures\CFigure.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Figures\CRectangle.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\ApplicationManager.h"


class CRectangle;
class CFigure;

class Cut :
	public Action
{
	int MaxSelSize;
	Point P1, P2;
	int SelFigCount;
	CFigure**SelFigList;
public:
	Cut(ApplicationManager *pApp);
	void FindSelectedFig();
	virtual void ReadActionParameters();
	virtual void Execute();
	~Cut();
};

