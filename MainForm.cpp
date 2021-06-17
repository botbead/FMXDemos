// ---------------------------------------------------------------------------
#include <fmx.h>
#pragma hdrstop

#include "MainForm.h"
#include "MessageManager.h"
#include "ByteInteger.h"
#include "SignaturCapture.h"
#include "THeaderItem.h"
#include "MobileAPP1.h"
#include "HeaderAndFooter.h"
#include "CheckBoxStyle.h"
#include "SlidingStones.h"
#include "Carom.h"
#include "SelectionDrawHandle.h"
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
void __fastcall TFormMain::Button5Click(TObject *Sender) {
	Form6->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button6Click(TObject *Sender) {
	Form7->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button7Click(TObject *Sender) {
	Form8->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button8Click(TObject *Sender) {
	Form9->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button9Click(TObject *Sender) {
	Form10->ShowModal();
}

// ---------------------------------------------------------------------------
void __fastcall TFormMain::Button10Click(TObject *Sender) {
	Form11->ShowModal();
}
// ---------------------------------------------------------------------------
