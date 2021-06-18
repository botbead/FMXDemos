// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <iso646.h>
#include <System.Math.hpp>
#include <System.Math.Vectors.hpp>
#include "ArrowsDraw.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm12 *Form12;

// ---------------------------------------------------------------------------
__fastcall TForm12::TForm12(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm12::FormCreate(TObject *Sender) {
	Rectangle1->Align = TAlignLayout::Client;
	// Rectangle1->Align = TAlignLayout::None;
	Rectangle1->Stroke->Thickness = 3;
	SelectionPoint1->Scale->X = 2;
	SelectionPoint1->Scale->Y = 2;

	SelectionPoint2->Scale->X = 2;
	SelectionPoint2->Scale->Y = 2;
}

// ---------------------------------------------------------------------------
void __fastcall TForm12::Rectangle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect) {

	bool show;
	float e, fl, fr, l, s, w;
	TPointF p1, p2, p3, p4;
	TPolygon poly;

	p1 = SelectionPoint1->Position->Point;
	p2 = SelectionPoint2->Position->Point;

	Canvas->Stroke->Assign(Rectangle1->Stroke);

	Canvas->DrawLine(p1, p2, 1);

	l = 50; // length
	s = 0.9; // 90
	show = true;
	do {
		show = !show;

		p3 = p2;
		p2 = p1;
		p1 = p3;

		p3 = p2 - p1;
		w = ArcTan2(p3.Y, p3.X);

		// the param of Cos/Sin functions is an angle in radians.
		// TPointF(this->x * f, this->y * f);
		/*
		 p3 = p2 + TPointF(Cos(w), Sin(w)) * l;
		 Canvas->DrawLine(p2, p3, 1);
		 */

		fl = w - M_PI * s;
		p3 = p2 + TPointF(Cos(fl), Sin(fl)) * l;
		// Canvas->DrawLine(p2, p3, 1);

		fr = w + M_PI * s;
		p4 = p2 + TPointF(Cos(fr), Sin(fr)) * l;
		// Canvas->DrawLine(p2, p4, 1);

		// Canvas->DrawLine(p3, p4, 1);

		poly.set_length(4);
		poly[0] = p2;
		poly[1] = p3;
		poly[2] = p4;
		poly[3] = p2;

		Canvas->FillPolygon(poly, 1);
		Canvas->DrawPolygon(poly, 1);
	}
	while (!show);

}

// ---------------------------------------------------------------------------
void __fastcall TForm12::SelectionPoint2Track(TObject *Sender, float &X, float &Y) {
	Rectangle1->Repaint();
}
// ---------------------------------------------------------------------------

void __fastcall TForm12::SelectionPoint1Track(TObject *Sender, float &X, float &Y) {
	Rectangle1->Repaint();
}
// ---------------------------------------------------------------------------
