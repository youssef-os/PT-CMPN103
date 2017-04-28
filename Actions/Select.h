#pragma once
#include "Action.h"
#include "../Figures\CFigure.h"
#include "../Figures\CRectangle.h"
#include "../ApplicationManager.h"

class Select :
	public Action {

public:
	Select(ApplicationManager*);
	bool isSelected(CFigure*,Point);
	float getCircleArea(CFigure*);
	~Select();
};