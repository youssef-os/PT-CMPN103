#include "Copy.h"



Copy::Copy(ApplicationManager *pApp): Action(pApp)
{
	
	pApp->GetFigCount(MaxSelSize);
	SelFigList = new CFigure*[MaxSelSize];
	SelFigCount = 0;
}

void Copy::FindSelectedFig()
{
	CFigure**List;
	List = pManager->GetFigList();
	for (int i = 0; i < MaxSelSize; i++)
	{
		if (List[i]->IsSelected())
			SelFigList[SelFigCount++] = List[i];
	}
}

void Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Copying Selected Figures: Click The Reference Point");

	pIn->GetPointClicked(P1.x, P1.y);

	pOut->PrintMessage("Copying Selected Figures: Click The Target Point");

	pIn->GetPointClicked(P2.x, P2.y);

}

void Copy::Execute()
{
	FindSelectedFig();
	Point P1o, P2o, P3o;
	
	for (int i = 0; i < SelFigCount; i++)
	{
		if (dynamic_cast<CRectangle*>(SelFigList[i]) != NULL)
		{
			GfxInfo RectGfx;

			SelFigList[i]->GetFigureParameters(P1o, P2o, P3o, RectGfx);
			Point Pa;
			Pa.x = P1o.x + P1.x; Pa.y = P1o.y + P1.y;
			Point Pb;
			Pb.x = P2o.x + P2.x; Pb.y = P2o.y + P2o.y;
			CRectangle*R = new CRectangle(Pa, Pb, RectGfx);

			pManager->AddFigure(R);
		}
			
	}
}

Copy::~Copy()
{
	delete SelFigList;
}
