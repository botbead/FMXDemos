// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <System.UIConsts.hpp>
#include "SelectionDrawHandle.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm11 *Form11;

// ---------------------------------------------------------------------------
__fastcall TForm11::TForm11(TComponent* Owner) : TForm(Owner) {
	Selection2 = new TMySelection(Owner);

}

// ---------------------------------------------------------------------------
void __fastcall TForm11::FormCreate(TObject *Sender) {
	Rectangle1->Size->Width = 400;
	Rectangle1->Size->Height = 400;
	Rectangle1->Align = TAlignLayout::Center;
	Selection1->GripSize = 8;
	ArcDial1->ShowValue = true;
	ArcDial2->ShowValue = true;
	Selection1->ShowHandles = true;
	CheckBox1->IsChecked = true;
	CheckBox2->IsChecked = true;
	Selection1->Parent = Rectangle1;
	Selection1->ParentBounds = true;
	TrackBar1->Max = 25;
	TrackBar1->Value = 8;
	CheckBox3->IsChecked = true;

	Selection1->Visible = false;

	Selection1->GripSize = 8;
	Selection2->ShowHandles = true;
	Selection2->Parent = Rectangle1;
	Selection2->ParentBounds = true;
	Selection2->Align = TAlignLayout::Center;
	Selection2->Size->Width = 150;
	Selection2->Size->Height = 150;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::ArcDial1Change(TObject *Sender) {
	Rectangle1->RotationAngle = ArcDial1->Value;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::FormShow(TObject *Sender) {
	Rectangle1->Position->Point.Y = Layout2->Position->Point.y;
	long double x = hypot(Rectangle1->Size->Height, Rectangle1->Size->Width);
	x += Layout1->Size->Height;
	x += 100;
	this->Height = x;
	this->Position = TFormPosition::DesktopCenter;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::ArcDial2Change(TObject *Sender) {
	Selection1->RotationAngle = ArcDial2->Value;
	Selection2->RotationAngle = ArcDial2->Value;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::CheckBox1Change(TObject *Sender) {
	Selection1->ShowHandles = CheckBox1->IsChecked;
	Selection2->ShowHandles = CheckBox1->IsChecked;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::CheckBox2Change(TObject *Sender) {
	Selection1->ParentBounds = CheckBox2->IsChecked;
	Selection2->ParentBounds = CheckBox2->IsChecked;
}
// ---------------------------------------------------------------------------

void __fastcall TForm11::TrackBar1Tracking(TObject *Sender) {
	Selection1->GripSize = TrackBar1->Value;
	Selection2->GripSize = TrackBar1->Value;
}

// ---------------------------------------------------------------------------
void __fastcall TMySelection::DrawHandle(Fmx::Graphics::TCanvas* const Canvas,
	const Fmx::Objects::TSelection::TGrabHandle Handle, const System::Types::TRectF &Rect) {
	TBrush *Fill = 0;
	TStrokeBrush *Stroke = 0;

	Fill = new TBrush(TBrushKind::Solid, claWhite); // System.UIConsts.hpp
	Stroke = new TStrokeBrush(TBrushKind::Solid, Color);
	try {
		if (Enabled)
			Fill->Color = (Handle == HotHandle) ? claRed : claWhite;
		else
			Fill->Color = claGrey;
		Canvas->FillEllipse(Rect, AbsoluteOpacity, Fill);
		Canvas->DrawEllipse(Rect, AbsoluteOpacity, Stroke);
	}
	catch (...) {
	}
	delete Fill;
	delete Stroke;
}

// ---------------------------------------------------------------------------
void __fastcall TForm11::CheckBox3Change(TObject *Sender) {
	Selection1->Enabled = CheckBox3->IsChecked;
	Selection2->Enabled = CheckBox3->IsChecked;
}

// ---------------------------------------------------------------------------
__fastcall TForm11::~TForm11() {
	// delete Selection2;
	// Selection2->DisposeOf();
}

void __fastcall TForm11::Selection1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect) {

	TSelection * s = (TSelection*)Sender;

	TBrush *Fill = 0;
	TStrokeBrush *Stroke = 0;

	Fill = new TBrush(TBrushKind::Solid, claWhite); // System.UIConsts.hpp
	Stroke = new TStrokeBrush(TBrushKind::Solid, s->Color);
	try {
		if (s->Enabled)
			switch (s->HotHandle) {
			case Fmx::Objects::TSelection::TGrabHandle::LeftTop:
				Fill->Color = claRed;
				break;
			case Fmx::Objects::TSelection::TGrabHandle::RightTop:
				Fill->Color = claRed;
				break;
			case Fmx::Objects::TSelection::TGrabHandle::LeftBottom:
				Fill->Color = claRed;
				break;
			case Fmx::Objects::TSelection::TGrabHandle::RightBottom:
				Fill->Color = claRed;
				break;
			default:
				Fill->Color = claWhite;
			}
		else
			Fill->Color = claGrey;
		Canvas->FillEllipse(ARect, s->AbsoluteOpacity, Fill);
		Canvas->DrawEllipse(ARect, s->AbsoluteOpacity, Stroke);
	}
	catch (...) {
	}
	delete Fill;
	delete Stroke;

}

// ---------------------------------------------------------------------------
__fastcall TMySelection::TMySelection(System::Classes::TComponent* AOwner) : TSelection(AOwner) {

}

// ---------------------------------------------------------------------------
__fastcall TMySelection::~TMySelection() {

}

// ---------------------------------------------------------------------------
void __fastcall TForm11::FormClose(TObject *Sender, TCloseAction &Action) {
	Selection2->DisposeOf();
}
// ---------------------------------------------------------------------------
