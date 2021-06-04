// ---------------------------------------------------------------------------

#ifndef HeaderAndFooterH
#define HeaderAndFooterH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.WebBrowser.hpp>

// ---------------------------------------------------------------------------
class TForm7 : public TForm {
__published: // IDE-managed Components
	TToolBar *ToolBar1;
	TToolBar *ToolBar2;
	TLabel *Label1;
	TButton *Button1;
	TWebBrowser *WebBrowser1;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

private: // User declarations
public: // User declarations
	__fastcall TForm7(TComponent* Owner);
	void __fastcall SetPermissions();
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
// ---------------------------------------------------------------------------
#endif
