// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <math.h>
#include <System.Math.hpp>
#include <FMX.InertialMovement.hpp>
#include "PathAnimation.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
#pragma resource ("*.Moto360.fmx", _PLAT_ANDROID)
#pragma resource ("*.LgXhdpiPh.fmx", _PLAT_ANDROID)

TForm13 *Form13;

// ---------------------------------------------------------------------------
__fastcall TForm13::TForm13(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm13::FormCreate(TObject *Sender) {
	int a;
	float w;
	TPointF p;
	TCircle *c = 0;
	TAniCalculations *k = 0;

	Button1->Align = TAlignLayout::Left;
	Button1->CanFocus = false;
	Button1->Text = _T("Rec");
	Button1->Margins->Left = 5;
	Button1->Margins->Right = 5;
	Button1->Margins->Top = 5;
	Button1->Margins->Bottom = 5;
	Button1->Anchors =
		TAnchors() >> TAnchorKind::akTop >> TAnchorKind::akLeft >> TAnchorKind::akRight >>
		TAnchorKind::akBottom;
	Button2->Align = TAlignLayout::Left;
	Button2->CanFocus = false;
	Button2->Text = _T("Play");
	Button2->Margins->Left = 5;
	Button2->Margins->Right = 5;
	Button2->Margins->Top = 5;
	Button2->Margins->Bottom = 5;
	Button2->Anchors =
		TAnchors() >> TAnchorKind::akTop >> TAnchorKind::akLeft >> TAnchorKind::akRight >>
		TAnchorKind::akBottom;
	Button3->Align = TAlignLayout::Left;
	Button3->CanFocus = false;
	Button3->Text = _T("Del");
	Button3->Margins->Left = 5;
	Button3->Margins->Right = 5;
	Button3->Margins->Top = 5;
	Button3->Margins->Bottom = 5;
	Button3->Anchors =
		TAnchors() >> TAnchorKind::akTop >> TAnchorKind::akLeft >> TAnchorKind::akRight >>
		TAnchorKind::akBottom;

	ScrollBox1->Align = TAlignLayout::Client;

	Circle1->Height = 35;
	Circle1->Width = 35;
	Circle1->Stroke->Thickness = 3;
	Circle1->Parent = Layout1;
	// Used for scrolling; requires just one finger.
	Circle1->Touch->InteractiveGestures = TInteractiveGestures() << TInteractiveGesture::Pan;

	PathAnimation1->Parent = Circle1;
	BevelEffect1->Size = 20;
	BevelEffect1->Direction = 30;
	BevelEffect1->Parent = Circle1;

	Layout1->Parent = ScrollBox1;
	PathAnimation1->Duration = 5;

	/*
	 *TAniCalculations provides support for displaying content
	 *that is larger than the size of the viewport window.
	 *
	 *TAniCalculations enables the user to scroll the origin of the viewport window within the content view
	 *using the mouse or finger.
	 *
	 *The user, using the mouse or finger, can initialize scrolling and define moving parameters,
	 *then the viewport window can move inertially providing animation of scrolling.
	 */
	k = new TAniCalculations(0);
	k->Animation = 1;
	k->AutoShowing = 1;
	k->Averaging = 1;
	// enable scrolling
	ScrollBox1->AniCalculations->Assign(k);
	delete k;

	Layout1->SetBounds(0, 0, this->Width, this->Height);
	for (a = 0; a < 8; ++a) {
		c = (TCircle*)Circle1->Clone(0);
		Layout1->AddObject(c);
		c->OnMouseMove = Circle1MouseMove;
		c->OnMouseUp = Circle1MouseUp;
		c->OnGesture = Circle1Gesture;
		// Specifies whether the control captures mouse events.
		c->AutoCapture = 1;
		c->CanFocus = 1;
		// Occurs when the control is redrawn
		c->OnPaint = Circle1Paint;
		switch (a) {
		case 0:
			c->Fill->Color = TAlphaColors::Yellow;
			break;
		case 1:
		case 2:
		case 3:
			c->Fill->Color = TAlphaColors::Cornflowerblue;
			break;
		case 4:
		case 5:
		case 6:
		case 7:
			c->Fill->Color = TAlphaColors::Darkorange;
			break;
		default: ;
		}
		w = 8 + (c->Width + 8) * a;
		p = TPointF(w, 8);
		c->Position->Point = p;
		if (Layout1->Width < w)
			Layout1->Width = w + c->Width + 8;
		c->Visible = 1;
	}
	Circle1->Visible = 0;

	StyleBook1->LoadFromFile(Format(_T("%s%s%s"), ARRAYOFCONST((ExtractFilePath(ParamStr(0)),
		_T("RubyGraphite"), _T(".Style")))));
	StyleBook = StyleBook1;
}

// ---------------------------------------------------------------------------
void __fastcall TForm13::PathAnimation1Process(TObject *Sender) {
	TPathAnimation * a = 0;
	TCircle * c = 0;
	if (__classid(TPathAnimation) == Sender->ClassType()) {
		a = (TPathAnimation*)Sender;
		c = (TCircle*)(a->Parent);
		c->Position->Point = c->Position->Point - TPointF(c->Width, c->Height) * 0.5;

	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm13::Circle1Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
	bool &Handled) {
	Handled = 1;
}

// ---------------------------------------------------------------------------
void __fastcall TForm13::Circle1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y) {
	TPointF p;
	TCircle *c = 0;
	TPathAnimation *j = 0;

	if (Shift.Contains(ssLeft)) {
		c = (TCircle*)Sender;
		// The absolute context for a control is the parent form area, and the local context is the control area.
		p = c->LocalToAbsolute(TPointF(X, Y));

		if (!(c->ShowHint)) {
			c->Position->DefaultValue = c->Position->Point - p;
			c->ShowHint = 1;

			if (TAlphaColors::Black != c->Stroke->Color) {
				for (size_t i = 0; i < c->ChildrenCount; ++i) {
					if (c->Children->Items[i]->ClassNameIs(_T("TPathAnimation"))) {
						j = (TPathAnimation*)(c->Children->Items[i]);
						j->Path->MoveTo(c->Position->Point + 0.5 * TPointF(c->Width, c->Height));
						Layout1->Repaint();
					}
				}
			}

		}

		c->Position->Point = c->Position->DefaultValue + p;
		if (TAlphaColors::Black != c->Stroke->Color) {
			for (size_t i = 0; i < c->ChildrenCount; ++i) {

				if (c->Children->Items[i]->ClassNameIs(_T("TPathAnimation"))) {
					p = c->Position->Point + 0.5 * TPointF(c->Width, c->Height);
					j = (TPathAnimation*)(c->Children->Items[i]);
					if (j->Path->LastPoint().Distance(p) > 8)
						j->Path->LineTo(p);
					Layout1->Repaint();
				}
			}
		}

	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm13::Circle1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
	float X, float Y) {
	((TCircle *)(Sender))->ShowHint = 0;
}
// ---------------------------------------------------------------------------

void __fastcall TForm13::Circle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect) {
	TRectF a;
	if (this->Focused && this->Focused->GetObjectW()->ClassNameIs(_T("TCircle"))) {
		a = ARect;
		InflateRect(a, -0.5, -0.5);
		Canvas->DrawEllipse(a, 0.5);

	}
}

// ---------------------------------------------------------------------------
// Occurs when the control is painted.
void __fastcall TForm13::Layout1Painting(TObject *Sender, TCanvas *Canvas, const TRectF &ARect) {

	int a;
	float w, s, l;
	TCircle *c = 0;
	TPathAnimation *j = 0;
	TPathData *d = 0;
	TStrokeBrush *g = 0;
	TPointF p1, p2, p3, p4;

	Canvas->Fill->Color = TAlphaColors::Gainsboro; // TAlphaColors::Brown;
	Canvas->FillRect(ARect, (float)0, (float)0, TCorners(), (float)1);
	g = new TStrokeBrush(TBrushKind::Solid, TAlphaColors::Deepskyblue);
	g->Thickness = 2;
	s = 0.85;
	l = 20;
	for (a = 0; a < Layout1->Children->Count; ++a) {
		if (!(Layout1->Children->operator[](a)))
			continue;
		if (__classid(TCircle) != Layout1->Children->operator[](a)->ClassType())
			continue;
		c = (TCircle *)(Layout1->Children->operator[](a));
		for (size_t i = 0; i < c->ChildrenCount; ++i) {
			if (__classid(TPathAnimation) == c->Children->operator[](i)->ClassType()) {
				j = (TPathAnimation *)(c->Children->operator[](i));
				if (j->Path->IsEmpty());
				else {
					d = new TPathData;
					// Assign copies properties and other attributes of the specified Source object to the current object.
					// The standard form of a call to Assign is:
					// Destination->Assign(Source);
					d->Assign(j->Path);
					g->Color = c->Fill->Color;

					if (d->Count - 1 > 1) {
						// next to last
						p1 = d->Points[d->Count - 2].Point;
						// the last
						p2 = d->Points[d->Count - 1].Point;
						// arrow
						p3 = p2 - p1;
						w = ArcTan2(p3.Y, p3.X);
						p3 = p2 + TPointF(Cos(w - M_PI * s), Sin(w - M_PI * s)) * l;
						p4 = p2 + TPointF(Cos(w + M_PI * s), Sin(w + M_PI * s)) * l;
						d->MoveTo(p2);
						d->LineTo(p3);
						d->MoveTo(p2);
						d->LineTo(p4);
					}

					Canvas->DrawPath(d, 1, g);
					delete d;
				}
			}
		}
	}
	delete g;

}
// ---------------------------------------------------------------------------

void __fastcall TForm13::Button1Click(TObject *Sender) {
	TCircle *c = 0;
	if (this->Focused && this->Focused->GetObjectW()->ClassNameIs(_T("TCircle"))) {
		c = (TCircle*)(this->Focused->GetObjectW());
		if (TAlphaColors::Black != c->Stroke->Color)
			c->Stroke->Color = TAlphaColors::Black;
		else
			c->Stroke->Color = TAlphaColors::Chartreuse;
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm13::Button2Click(TObject *Sender) {
	bool b;
	int a;
	TCircle * c = 0;
	TPathAnimation* j = 0;

	b = false;
	for (a = 0; a < Layout1->ChildrenCount; ++a) {
		if (!(Layout1->Children->operator[](a)))
			continue;
		if (__classid(TCircle) != Layout1->Children->operator[](a)->ClassType())
			continue;
		c = (TCircle *)(Layout1->Children->operator[](a));
		for (size_t i = 0; i < c->ChildrenCount; ++i) {
			if (__classid(TPathAnimation) == c->Children->operator[](i)->ClassType()) {
				j = (TPathAnimation *)(c->Children->operator[](i));
				if (!(j->Path->IsEmpty())) {
					j->Stop();
					c->Position->Point = TPointF(0, 0) - TPointF(c->Width, c->Height) * 0.5;
					j->Start();
					b = 1;
					break;
				}
			}
		}
	}
	if (b) {
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm13::Button3Click(TObject *Sender) {
	TCircle * c = 0;
	TPathAnimation* j = 0;
	if (this->Focused && this->Focused->GetObjectW()->ClassNameIs(_T("TCircle"))) {
		c = (TCircle*)(this->Focused->GetObjectW());
		c->Stroke->Color = TAlphaColors::Black;
		for (size_t i = 0; i < c->ChildrenCount; ++i) {
			if (__classid(TPathAnimation) == c->Children->operator[](i)->ClassType()) {
				j = (TPathAnimation *)(c->Children->operator[](i));
				if (j->Path) {
					j->Stop();
					j->Path->Clear();
					Layout1->Repaint();
					break;
				}
			}
		}
	}
}
// ---------------------------------------------------------------------------
