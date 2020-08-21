// ---------------------------------------------------------------------------

#ifndef SignaturCaptureH
#define SignaturCaptureH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>

// ---------------------------------------------------------------------------
class TForm4 : public TForm {
__published: // IDE-managed Components
	TToolBar *ToolBar1;
	TButton *Button1;
	TButton *Button2;
	TLayout *Layout1;
	TRoundRect *RoundRect1;
	TPath *Path1;
	TRectangle *Rectangle1;

	void __fastcall RoundRect1MouseDown(TObject *Sender, TMouseButton Button,
		TShiftState Shift, float X, float Y);
	void __fastcall RoundRect1MouseMove(TObject *Sender, TShiftState Shift,
		float X, float Y);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall RoundRect1MouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          float X, float Y);

private: // User declarations
public: // User declarations
	__fastcall TForm4(TComponent* Owner);
	bool beMouseDown;
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
// ---------------------------------------------------------------------------
#endif
