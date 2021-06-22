// ---------------------------------------------------------------------------

#ifndef PathAnimationH
#define PathAnimationH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Effects.hpp>

// ---------------------------------------------------------------------------
class TForm13 : public TForm {
__published: // IDE-managed Components
	TToolBar *ToolBar1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TScrollBox *ScrollBox1;
	TLayout *Layout1;
	TCircle *Circle1;
	TPathAnimation *PathAnimation1;
	TBevelEffect *BevelEffect1;
	TStyleBook *StyleBook1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall PathAnimation1Process(TObject *Sender);
	void __fastcall Circle1Gesture(TObject *Sender, const TGestureEventInfo &EventInfo,
		bool &Handled);
	void __fastcall Circle1MouseMove(TObject *Sender, TShiftState Shift, float X, float Y);
	void __fastcall Circle1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift, float X,
		float Y);
	void __fastcall Circle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall Layout1Painting(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm13(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm13 *Form13;
// ---------------------------------------------------------------------------
#endif
