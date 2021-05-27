// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MobileAPP1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "MobileAPP1Frame1"
#pragma link "MobileAPP1Frame2"
#pragma resource "*.fmx"
TForm6 *Form6;

// ---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm6::SplashFrame1Rectangle3Click(TObject *Sender) {
	TabControl1->SetActiveTabWithTransition(TabItem2, TTabTransition::Slide);
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::ChenYiZheFrame1ToolBarClick(TObject *Sender) {
	TabControl1->SetActiveTabWithTransition(TabItem1, TTabTransition::Slide,
		TTabTransitionDirection::Reversed);
}
// ---------------------------------------------------------------------------

void __fastcall TForm6::FormCreate(TObject *Sender) {
	TScrollCalculations *a = new TScrollCalculations(ChenYiZheFrame->VertScrollBox1);
	a->Animation = true;
	a->AutoShowing = true;
	a->Averaging = true;
	a->BoundsAnimation = true;
	ChenYiZheFrame->VertScrollBox1->AniCalculations->Assign(a);
	delete a;
}
// ---------------------------------------------------------------------------
