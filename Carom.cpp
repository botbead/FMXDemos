// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Carom.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm10 *Form10;

// ---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm10::FormCreate(TObject *Sender) {
	Rectangle1->Fill->Color = TAlphaColorRec::Cornsilk;
	TrackBar1->Min = 1;
	TrackBar1->Max = 100;
	TrackBar1->Value = 23;

	ball_size = TrackBar1->Value;

	// RandSeed = 382763;
	RandSeed = 95279527;

	FloatAnimation1->Loop = true;
	FloatAnimation1->StartValue = 0;
	FloatAnimation1->StopValue = 1;
	FloatAnimation1->PropertyName = _T("TagFloat");
	// the Enabled should be in the end
	FloatAnimation1->Enabled = true;
}

// ---------------------------------------------------------------------------
void __fastcall TForm10::TrackBar1Tracking(TObject *Sender) {
	ball_size = TrackBar1->Value;
	Rectangle1->Repaint();
}

// ---------------------------------------------------------------------------
void __fastcall TForm10::Rectangle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect) {
	size_t len, i;
	TBrush *bs;
	TRectF r;
	TPointF tpE;

	// the max point coordinate
	tpE = TPointF(Rectangle1->Width - ball_size, Rectangle1->Height - ball_size);
	bs = new TBrush(TBrushKind::Solid, TAlphaColorRec::Yellow);

	for (i = 0; i < p.Length; ++i) {
		/*
		 *creates an empty TRectF object,
		 *with the upper-left corner and the lower-right corner both in the point (0, 0).
		 */
		r = TRectF::Empty();

		r.Offset((TPointF(ball_size, ball_size) *0.5 + p[i] *tpE).X,
			(TPointF(ball_size, ball_size) *0.5 + p[i] *tpE).Y);
		/*
		 * inflate ---
		 * to fill something such as a ball, mattress, tire, or boat with air or gas to bring it to the proper size,
		 * shape, and firmness for use, or to become filled with air or gas
		 */
		r.Inflate(ball_size / 2, ball_size / 2);
		bs->Color = colors[i];
		Canvas->FillEllipse(r, 1, bs);
	}
	delete bs;
}

// ---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject *Sender) {
	size_t l, i;
	float x, y;
	l = p.Length;
	p.set_length(l + 1);
	v.set_length(l + 1);
	colors.set_length(l + 1);

	p[l] = TPointF(Random(), Random());
	// cosine ? adj / hypot
	/*
	 * 1 = coefficient, e = 10 to the power of, -2 = exponent
	 * 1e-2 == 0.01
	 */
	v[l] = TPointF(0.5 - Random(), 0.5 - Random()).Normalize() * 1E-2;
	colors[l] = HSLtoRGB(Random() * 0.2, Random(), 0.5);
	Rectangle1->Repaint();
}

// ---------------------------------------------------------------------------
void __fastcall TForm10::FloatAnimation1Process(TObject *Sender) {
	int i, j, k;
	float n;
	TPointF p1;
	TPointF tpE;
	TPointF p2;
	TPointF p3;

	Rectangle1->Repaint();
	j = p.Length;
	tpE = TPointF(Rectangle1->Width - ball_size, Rectangle1->Height - ball_size);

	for (i = 0; i < j - 1; ++i) {
		for (k = i + 1; k < j; ++k) {
			p1 = tpE * (p[i] + v[i]);
			p2 = tpE * (p[k] + v[k]);

			if ((p1 - p2).Length() < ball_size) {
				p3 = p[k] - p[i];
				n = p3.DotProduct(p3);
				p1.X = v[i].DotProduct(p3);
				p1.Y = v[k].DotProduct(p3);

				v[k] = v[k] - p3 * (p1.Y - p1.X) / n;
				v[i] = v[i] - p3 * (p1.X - p1.Y) / n;
			}
		}
	}

	for (i = 0; i < j; ++i) {
		p1 = p[i] + v[i];

		if ((p1.X < 0) || (p1.X > 1))
			v[i].X = -v[i].X;
		if ((p1.Y < 0) || (p1.Y > 1))
			v[i].Y = -v[i].Y;

		p1 = p[i] + v[i];
		p[i] = p1;
	}
}
// ---------------------------------------------------------------------------
