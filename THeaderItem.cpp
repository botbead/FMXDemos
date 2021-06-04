// ---------------------------------------------------------------------------

#include <fmx.h>
#include <System.IOUtils.hpp>
#pragma hdrstop

#include "THeaderItem.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "DBAccess"
#pragma link "MemDS"
#pragma link "SQLiteUniProvider"
#pragma link "Uni"
#pragma link "UniProvider"
#pragma resource "*.fmx"
TForm5 *Form5;

// ---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm5::StringGrid1ApplyStyleLookup(TObject *Sender) {
	//
	int a;
	THeader *h;
	THeaderItem *i;
	if (StringGrid1->FindStyleResource("header", h)) {
		h->Height = 45;
		for (a = 0; a < h->Count - 1; ++a) {
			/*
			 TStyledSetting   Dependent TTextSettings   Meaning
			 Constant             Properties

			 Family           TFont.Family              Font name.
			 Size             TFont.Size                Font size.
			 Style            TFont.Style               Font style (italic, bold).
			 FontColor        FontColor                 Font color.
			 Other            HorzAlign, VertAlign, Trimming, and WordWrap.     How to align and show the text.
			 */
			i = h->Items[a];
			// clear default style
			i->StyledSettings = i->StyledSettings >> TStyledSetting::FontColor;
			i->StyledSettings = i->StyledSettings >> TStyledSetting::Size;
			i->StyledSettings = i->StyledSettings >> TStyledSetting::Family;
			// or clear all default style
			i->StyledSettings.Clear();
			i->TextSettings->HorzAlign = TTextAlign::Center;
			i->TextSettings->Font->Family = L"Consolas";
			i->TextSettings->Font->Size = 16;
			i->TextSettings->FontColor = TAlphaColors::Orangered;
		}
	}
}

// ---------------------------------------------------------------------------
void __fastcall TForm5::FormCreate(TObject *Sender) {
	/*
	 UnicodeString exePath;
	 UniConnection1->ProviderName = "SQLite";
	 UniConnection1->SpecificOptions->Values["Direct"] = "True";
	 UniConnection1->SpecificOptions->Values["ForceCreateDatabase"] = "True";
	 // ParamStr(0)---exe file path
	 exePath = ExtractFilePath(ParamStr(0));
	 // TDirectory::GetParent() needs header System.IOUtils.hpp
	 // ./../../byou93.db
	 UniConnection1->Database =
	 TDirectory::GetParent
	 (TDirectory::GetParent(ExcludeTrailingPathDelimiter(exePath))) +
	 "//byou93.db";
	 //UniConnection1->Connect();
	 */

	Byou93Connection->Params->Database = ExtractFilePath(ParamStr(0)) + _T("byou93.db");
	// set Property Active as True.
	NanjingTable->Active = true;

	StringGrid1->OnApplyStyleLookup = StringGrid1ApplyStyleLookup;
}
// ---------------------------------------------------------------------------
/*
 * Operation Steps:
 * 1. Data Explorer:
 *    SQLite database->(right click)->Add New Connection:  Specify the Connection name,
 *    Select the database file path;
 *    or Refresh the Connection name and Modify;
 * 2. Drag the BYOU93->Tables->nanjing to the Design Form;
 * 3. Add a TStringGrid to the Form, (right click)->Quick Edit, Align;
 * 4. Find Bind Visually... at the bottom of Object Inspector, open LivesBinding Designer;
 * 5. link(drag and drop) nanjingtable to StringGrid;
 * 6. select nanjingtable, set Property Active as True.
 */
