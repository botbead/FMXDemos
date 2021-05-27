// ---------------------------------------------------------------------------

#ifndef MobileAPP1H
#define MobileAPP1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.TabControl.hpp>
#include <FMX.Types.hpp>
#include "MobileAPP1Frame1.h"
#include "MobileAPP1Frame2.h"

// ---------------------------------------------------------------------------
class TForm6 : public TForm {
__published: // IDE-managed Components
	TTabControl *TabControl1;
	TTabItem *TabItem1;
	TTabItem *TabItem2;
	TSplashFrame *SplashFrame1;
	TChenYiZheFrame *ChenYiZheFrame1;

	void __fastcall SplashFrame1Rectangle3Click(TObject *Sender);
	void __fastcall ChenYiZheFrame1ToolBarClick(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm6(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
// ---------------------------------------------------------------------------
#endif
