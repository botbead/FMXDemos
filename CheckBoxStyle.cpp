// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "CheckBoxStyle.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm8 *Form8;

// ---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender) {
	TButton *btn;
	if (StyleBook)
		StyleBook = 0;
	btn = (TButton*)Sender;
	TStyleManager::SetStyle(TStyleStreaming::LoadFromFile
		(L"E:\\RadStudio10_3_3_Rio\\Redist\\styles\\Fmx\\" + btn->Text +
		L".Style"));
}

// ---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender) {
	if (StyleBook)
		StyleBook = 0;
	TStyleManager::SetStyle(0);
}
// ---------------------------------------------------------------------------
