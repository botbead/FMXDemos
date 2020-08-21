//---------------------------------------------------------------------------

#ifndef ByteIntegerH
#define ByteIntegerH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TLayout *Layout1;
	TSwitch *Switch1;
	TSwitch *Switch2;
	TSwitch *Switch3;
	TSwitch *Switch4;
	TSwitch *Switch5;
	TSwitch *Switch6;
	TSwitch *Switch7;
	TSwitch *Switch8;
	TLayout *Layout2;
	TButton *Button1;
	TButton *Button2;
	TLabel *Label1;
	TButton *Button3;
	TLayout *Layout3;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	void __fastcall Switch1Switch(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
    TIntegerSet s;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
