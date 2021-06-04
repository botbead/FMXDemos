// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

// for atan2
#include <math.h>

#include "SlidingStones.h"
#include <FMX.Utils.hpp>
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"

#ifdef _DEBUG
#define DEBUG_PRINT(x) OutputDebugString((x).c_str())
#else
#define DEBUG_PRINT(x)
#endif

TForm9 *Form9;

/*
 *             0,1(270)
 *   -1,0(0)              1,0(180)
 *             0,-1(90)
 */
#define RADDEG(x,y) ((int)(ArcTan2((y),(x))*180/M_PI)+180)%360

enum inAxis {
	AxisX, AxisY, AxisNone
};

// ---------------------------------------------------------------------------
__fastcall TForm9::TForm9(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TForm9::FormCreate(TObject *Sender) {

	ClientWidth = 320;
	ClientHeight = 270;

	// item height/width in gridlayout
	GridLayout1->ItemHeight = 80;
	GridLayout1->ItemWidth = 80;

	Button1->Margins->Left = 5;
	Button1->Margins->Right = 5;
	Button1->Margins->Top = 5;
	Button1->Margins->Bottom = 5;

	Button1->TextSettings->Font->Size = 13;

	FloatAnimation1->AnimationType = TAnimationType::Out;
	FloatAnimation1->Interpolation = TInterpolationType::Back;
	FloatAnimation1->Duration = 0.4;

	StyleBook1->LoadFromFile(Format(_T("%s%s%s"), ARRAYOFCONST((ExtractFilePath(ParamStr(0)),
		_T("Light"), _T(".Style")))));
}
// ---------------------------------------------------------------------------

/*
 * Controls hierarchy:
 * TGridLayout
 *     - Button
 */
void __fastcall TForm9::FormResize(TObject *Sender) {
	new_game();
}

// ---------------------------------------------------------------------------
void __fastcall TForm9::Button1Click(TObject *Sender) {
	bool is_x;
	size_t axis_pos;
	int w, i;
	float xy;
	TButton *b, *hidden;
	IControl *h;
	/*
	 * TPointF
	 * 1. floating-point X and Y coordinates
	 * 2. with the origin in the upper-left corner
	 * 3. primarily used for the coordinates of FireMonkey objects
	 */
	TPointF c3, c1, c2, r;

	if (FloatAnimation1->Running)
		return;

	b = (TButton*)Sender;
	c1 = Button1->BoundsRect.CenterPoint();
	c2 = b->BoundsRect.CenterPoint();

	/*
	 * Button1 as origin
	 */
	r = c2 - c1;

	w = RADDEG(r.X, r.Y);

	DEBUG_PRINT(IntToStr(w));

	c3 = Button1->Position->Point;

	switch (w) {
	case 0:
	case 180:
		FloatAnimation1->PropertyName = _T("Position.X");
		FloatAnimation1->StartValue = b->Position->X;
		axis_pos = AxisX;
		break;
	case 90:
	case 270:
		FloatAnimation1->PropertyName = _T("Position.Y");
		FloatAnimation1->StartValue = b->Position->Y;
		axis_pos = AxisY;
		break;
	default:
		axis_pos = AxisNone;
	}

	if (AxisNone == axis_pos)
		return;
	b->AddObject(FloatAnimation1);
	b->TagString = PointToString(b->Position->Point);

	h = GridLayout1->operator _di_IControl();
	i = (int)(r.Length() / GridLayout1->ItemHeight);

	/*
	 * correct the position of Button1
	 * c2 is the final position of Button1
	 */
	while (i > 1) {
		switch (w) {
		case 0:
			c2 = c1 - PointF(GridLayout1->ItemWidth, 0);
			break;
		case 180:
			c2 = c1 + PointF(GridLayout1->ItemWidth, 0);
			break;
		case 90:
			c2 = c1 - PointF(0, GridLayout1->ItemHeight);
			break;
		case 270:
			c2 = c1 + PointF(0, GridLayout1->ItemHeight);
			break;
		default: ;
		}

		hidden = (TButton*)(h->ObjectAtPoint(h->LocalToScreen(c2)))->GetObjectW();

		xy = (AxisX == axis_pos) ? c3.X : c3.Y;
		c3 = hidden->Position->Point;
		c1 = hidden->BoundsRect.CenterPoint();

		/*
		 * In Delphi, "with" means the following actions use which component
		 */
		TAnimator::AnimateFloat(hidden, FloatAnimation1->PropertyName, xy,
			FloatAnimation1->Duration, FloatAnimation1->AnimationType,
			FloatAnimation1->Interpolation);
		--i;
	}

	if (axis_pos == AxisX)
		FloatAnimation1->StopValue = c3.X;
	else
		FloatAnimation1->StopValue = c3.Y;

	FloatAnimation1->Start();
}
// ---------------------------------------------------------------------------

void __fastcall TForm9::new_game() {
	int i, s, j, r;
	TControl * c;
	TButton * b;

	AddObject(FloatAnimation1);

	srand(time(0));

	/*
	 * Remove all buttons (containingt Button1) and relase resources (excluding Button1) from GridLayout1
	 */
	for (s = GridLayout1->ControlsCount - 1; s > -1; --s) {
		c = GridLayout1->Controls->Items[s];
		GridLayout1->RemoveObject(c);
		if (Button1 == c)
			continue;
		c->DisposeOf();
		// delete c;
	}

	s = (int)(GridLayout1->Width / GridLayout1->ItemWidth);
	r = (int)(GridLayout1->Height / GridLayout1->ItemHeight);
	i = s * r;
	/*
	 * for subsequent buttons Visible
	 */
	Button1->Visible = true;
	/*
	 * 0,[1,i-1]
	 */
	for (s = 1; s < i; ++s) {
		b = (TButton*)(Button1->Clone(0));
		b->Text = IntToStr((int)s);
		b->OnClick = Button1Click;
		/*
		 * Alternative way : GridLayout1->InsertObject(0, b);
		 */
		GridLayout1->AddObject(b);
		b->Position->DefaultValue = b->Position->Point;
	}

	for (j = 0; j < GridLayout1->ControlsCount; ++j) {
		if (GridLayout1->ControlsCount < 3)
			break;
		do {
			s = rand() % GridLayout1->ControlsCount;
			if (GridLayout1->Controls->Items[s]->ClassNameIs(_T("TButton")))
				continue;
			r = rand() % GridLayout1->ControlsCount;
			if (GridLayout1->Controls->Items[r]->ClassNameIs(_T("TButton")))
				continue;
		}
		while (s == r);
		GridLayout1->Exchange(GridLayout1->Controls->Items[s], GridLayout1->Controls->Items[r]);
	}

	/*
	 * Position->DefaultValue is the position after the control be created;
	 * Position->Point is the current position.
	 */
	DEBUG_PRINT(String(_T("-----------------------New Game------------------------------")));
	for (j = 0; j < GridLayout1->ControlsCount; ++j) {
		if (GridLayout1->Controls->Items[j]->ClassNameIs(_T("TButton"))) {
			String degstr;
			b = ((TButton*)(GridLayout1->Controls->Items[j]));
			degstr = b->Text + _T(" : DefaultValue - ");
			degstr += Format(_T("%f, %f"),
				ARRAYOFCONST((GridLayout1->Controls->Items[j]->Position->DefaultValue.X,
				GridLayout1->Controls->Items[j]->Position->DefaultValue.Y)));
			degstr += _T(", Point - ");
			degstr += Format(_T("%f, %f"),
				ARRAYOFCONST((GridLayout1->Controls->Items[j]->Position->Point.X,
				GridLayout1->Controls->Items[j]->Position->Point.Y)));
			degstr += _T(".");
			DEBUG_PRINT(degstr);
		}
	}

	/*
	 * put the Button1 at the end
	 */
	GridLayout1->AddObject(Button1);
	Button1->Text = _T("Origin");
	Button1->Visible = false;
}

void __fastcall TForm9::FloatAnimation1Finish(TObject *Sender) {
	if (((TFmxObject*)Sender)->Parent->ClassNameIs(_T("TButton")))
		Button1->Position->Point = StringToPoint(((TFmxObject*)Sender)->Parent->TagString);
	game_done();
}
// ---------------------------------------------------------------------------

void __fastcall TForm9::FloatAnimation1Process(TObject *Sender) {
	ShadowEffect1->UpdateParentEffects();
}

// ---------------------------------------------------------------------------
void __fastcall TForm9::Button2Click(TObject *Sender) {
	new_game();
}

// ---------------------------------------------------------------------------
/*
 * if the button's DefaultValue position == it's Point position, the game done.
 */
void __fastcall TForm9::game_done() {
	bool ok = true;
    size_t i;
	for (i = 0; i < GridLayout1->ControlsCount; ++i) {
		if (GridLayout1->Controls->Items[i] == Button1)
			continue;
		if (GridLayout1->Controls->Items[i]->ClassNameIs(_T("TButton"))) {
			// if ((GridLayout1->Controls->Items[i]->Position->Point -
			// GridLayout1->Controls->Items[i]->Position->DefaultValue).IsZero()) {
			// ok = false;
			// break;
			// }

			if (GridLayout1->Controls->Items[i]->Position->Point.operator !=
				(GridLayout1->Controls->Items[i]->Position->DefaultValue)) {
				ok = false;
				break;
			}
		}
	}
	if (ok)
		ShowMessage(_T("Done!"));
}
