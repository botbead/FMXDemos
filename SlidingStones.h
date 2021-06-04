//---------------------------------------------------------------------------

#ifndef SlidingStonesH
#define SlidingStonesH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Ani.hpp>
#include <FMX.Effects.hpp>
//---------------------------------------------------------------------------
class TForm9 : public TForm
{
__published:	// IDE-managed Components
	TGridLayout *GridLayout1;
	TButton *Button1;
	TFloatAnimation *FloatAnimation1;
	TToolBar *ToolBar1;
	TButton *Button2;
	TShadowEffect *ShadowEffect1;
	TStyleBook *StyleBook1;
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FloatAnimation1Finish(TObject *Sender);
	void __fastcall FloatAnimation1Process(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm9(TComponent* Owner);
	void __fastcall new_game();
    void __fastcall game_done();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm9 *Form9;
//---------------------------------------------------------------------------
#endif
