#pragma once
#include "Action.h"
class AddTrianAction :
	public Action
{
private:
	Point P1, P2,P3; //Triangle Corners
	GfxInfo TrianGfxInfo;
public:
	AddTrianAction(ApplicationManager *pApp);
	
	//Reads Triangle parameters
	virtual void ReadActionParameters();
	
	//Add triangle to the ApplicationManager
	virtual void Execute() ;
	
};
