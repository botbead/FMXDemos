// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "MessageSubscriber.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender) {
	(new TForm2(Application))->Show();
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action) {
	/*
	 The __classid keyword allows you to specify a metaclass.
	 A metaclass is a way of treating a class as an an object.
	 Using a metaclass allows us to retrieve information about that class
	 without having to refer to a specific instance.
	 Several VCL functions require a metaclass as a parameter.
	 */
	TMessageManager::DefaultManager->Unsubscribe(__classid(TMessage__1<UnicodeString>),
		subscriber_id);
	Action = TCloseAction::caFree;
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject * Sender) {
	subscriber_id = TMessageManager::DefaultManager->SubscribeToMessage
		(__classid(TMessage__1<UnicodeString>), &(this->msg_react));
	Caption = _T("Subscriber No.: ") + IntToStr((int)subscriber_id);
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::msg_react(TObject* const sender, TMessageBase* const msg) {
	Label1->Text = ((TMessage__1<UnicodeString> *)msg)->Value;
}
// ---------------------------------------------------------------------------
