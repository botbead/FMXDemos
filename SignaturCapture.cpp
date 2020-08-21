// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "SignaturCapture.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm4 *Form4;

// ---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::RoundRect1MouseDown(TObject *Sender,
	TMouseButton Button, TShiftState Shift, float X, float Y) {
	beMouseDown = true;
	TPointF pt(X, Y);
    // Shift is a set
	// if (Shift.Contains(ssShift)) {
	if (beMouseDown)
		Path1->Data->MoveTo(pt);
	// }

}

// ---------------------------------------------------------------------------
void __fastcall TForm4::RoundRect1MouseMove(TObject *Sender, TShiftState Shift,
	float X, float Y) {
	TPointF pt(X, Y);
	// if (Shift.Contains(ssShift)) {
	if (beMouseDown) {
		Path1->Data->LineTo(pt);
		RoundRect1->Repaint();
	}
	// }
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::Button2Click(TObject *Sender) {
	TBrushBitmap *bmp = new TBrushBitmap;
	bmp->Bitmap->Assign(Path1->MakeScreenshot());
	bmp->Bitmap->Resize(Path1->Width, Path1->Height);
	Rectangle1->Fill->Kind = TBrushKind::Bitmap;
	Rectangle1->Fill->Bitmap->Assign(bmp);
	Path1->Data->Clear();

}
// ---------------------------------------------------------------------------

void __fastcall TForm4::Button1Click(TObject *Sender) {
	Rectangle1->Fill->Kind = TBrushKind::None;
	Path1->Data->Clear();
	Layout1->Repaint();
}
// ---------------------------------------------------------------------------

void __fastcall TForm4::FormCreate(TObject *Sender) {
	RoundRect1->AutoCapture = true;
	beMouseDown = false;
}

// ---------------------------------------------------------------------------
void __fastcall TForm4::RoundRect1MouseUp(TObject *Sender, TMouseButton Button,
	TShiftState Shift, float X, float Y) {
	beMouseDown = false;
}
// ---------------------------------------------------------------------------
