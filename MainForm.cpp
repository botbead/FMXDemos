// ---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "MessageManager.h"
#include "ByteInteger.h"
#include "SignaturCapture.h"
#include "THeaderItem.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TFormMain *FormMain;

// ---------------------------------------------------------------------------
__fastcall TFormMain::TFormMain(TComponent* Owner) : TForm(Owner) {
}
// ---------------------------------------------------------------------------

void __fastcall TFormMain::Button1Click(TObject *Sender) {
	Form1->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TFormMain::Button2Click(TObject *Sender) {
	Form3->ShowModal();
}
// ---------------------------------------------------------------------------

void __fastcall TFormMain::Button3Click(TObject *Sender) {
	Form4->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button4Click(TObject *Sender) {
	Form5->ShowModal();
}
// ---------------------------------------------------------------------------
