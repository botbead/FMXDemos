// ---------------------------------------------------------------------------

#ifndef CheckBoxStyleH
#define CheckBoxStyleH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>

// ---------------------------------------------------------------------------
class TForm8 : public TForm {
__published: // IDE-managed Components
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TCheckBox *CheckBox3;
	TCheckBox *CheckBox4;
	TCheckBox *CheckBox5;
	TCheckBox *CheckBox6;
	TCheckBox *CheckBox7;
	TCheckBox *CheckBox8;
	TCheckBox *CheckBox9;
	TCheckBox *CheckBox10;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm8(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
// ---------------------------------------------------------------------------
#endif
