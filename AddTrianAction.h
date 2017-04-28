#pragma once
#include "e:\cce sophomore\pt-cmpn103\actions\action.h"
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
