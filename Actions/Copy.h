#pragma once
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Actions\Action.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Figures\CFigure.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\Figures\CRectangle.h"
#include "E:\College\Sophomore\Spring 2017\Programming Techniques\PT-CMPN103\PT-CMPN103\ApplicationManager.h"

class CRectangle;
class CFigure;
class Action;

class Copy :
	public Action
{
	Point P1, P2;
	//queue<Action**> CopiedFigAct;
public:
	Copy(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Copy();
};

