// ---------------------------------------------------------------------------

#ifndef MessageSubscriberH
#define MessageSubscriberH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <System.Messaging.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Memo.hpp>
#include <FMX.ScrollBox.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>

// ---------------------------------------------------------------------------
class TForm2 : public TForm {
__published: // IDE-managed Components
	TToolBar *ToolBar1;
	TButton *Button1;
	TLabel *Label1;

	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm2(TComponent* Owner);

	int subscriber_id;

	void __fastcall msg_react(TObject * const sender, TMessageBase * const msg);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
// ---------------------------------------------------------------------------
#endif
