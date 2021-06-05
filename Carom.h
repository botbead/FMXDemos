// ---------------------------------------------------------------------------

#ifndef CaromH
#define CaromH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Ani.hpp>

// ---------------------------------------------------------------------------
class TForm10 : public TForm {
__published: // IDE-managed Components
	TToolBar *ToolBar1;
	TButton *Button1;
	TTrackBar *TrackBar1;
	TRectangle *Rectangle1;
	TFloatAnimation *FloatAnimation1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall TrackBar1Tracking(TObject *Sender);
	void __fastcall Rectangle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FloatAnimation1Process(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm10(TComponent* Owner);

	float ball_size;
	DynamicArray<TPointF>p;
	DynamicArray<TPointF>v;
	DynamicArray<unsigned>colors;
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm10 *Form10;
// ---------------------------------------------------------------------------
#endif
