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
	String path;
	if (StyleBook)
		StyleBook = 0;
	btn = (TButton*)Sender;
	path = ExtractFilePath(ParamStr(0));
	path = Format(_T("%s%s%s"), ARRAYOFCONST((path, btn->Text, _T(".Style"))));
	TStyleManager::SetStyle(TStyleStreaming::LoadFromFile(path));
}

// ---------------------------------------------------------------------------
void __fastcall TForm8::Button3Click(TObject *Sender) {
	if (StyleBook)
		StyleBook = 0;
	TStyleManager::SetStyle(0);
}
// ---------------------------------------------------------------------------
