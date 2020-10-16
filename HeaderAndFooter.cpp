// ---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include <System.Win.Registry.hpp>
#include "HeaderAndFooter.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm7 *Form7;

// ---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm7::SetPermissions() {
#ifdef _Windows
	UnicodeString cHomePath = "SOFTWARE";
	UnicodeString cFeatureBrowserEmulation =
		"Microsoft\\Internet Explorer\\Main\\FeatureControl\\FEATURE_BROWSER_EMULATION\\";
	int cIE11 = 11001;
	UnicodeString sKey = ExtractFileName(ParamStr(0));
	TRegIniFile *Reg = new TRegIniFile(cHomePath);
	__try {
		TRegistry *reg1 = dynamic_cast<TRegistry*>(Reg);
		if (Reg->OpenKey(cFeatureBrowserEmulation,
			true) && !(reg1->KeyExists(sKey) && reg1->ReadInteger(sKey)
			== cIE11)) {
			reg1->WriteInteger(sKey, cIE11);
		}
	}
	__finally {
		Reg->Free();
	}
#endif
}

void __fastcall TForm7::FormCreate(TObject *Sender) {
	SetPermissions();
	WebBrowser1->URL = L"https://www.digislug.com";
    WebBrowser1->Navigate();
}
// ---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
	if(WebBrowser1->CanGoBack)
		WebBrowser1->GoBack();
	else
		WebBrowser1->Navigate();
}
//---------------------------------------------------------------------------

