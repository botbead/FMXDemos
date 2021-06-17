// ---------------------------------------------------------------------------

#ifndef SelectionDrawHandleH
#define SelectionDrawHandleH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Types.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>

// ---------------------------------------------------------------------------

class TMySelection : public Fmx::Objects::TSelection {
protected:
	void __fastcall DrawHandle(Fmx::Graphics::TCanvas* const Canvas,
		const Fmx::Objects::TSelection::TGrabHandle Handle, const System::Types::TRectF &Rect);

public:
	__fastcall TMySelection(System::Classes::TComponent* AOwner);
	__fastcall ~TMySelection();
};

class TForm11 : public TForm {
__published: // IDE-managed Components
	TLayout *Layout1;
	TLayout *Layout2;
	TRectangle *Rectangle1;
	TArcDial *ArcDial1;
	TSelection *Selection1;
	TArcDial *ArcDial2;
	TCheckBox *CheckBox1;
	TCheckBox *CheckBox2;
	TTrackBar *TrackBar1;
	TCheckBox *CheckBox3;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ArcDial1Change(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall ArcDial2Change(TObject *Sender);
	void __fastcall CheckBox1Change(TObject *Sender);
	void __fastcall CheckBox2Change(TObject *Sender);
	void __fastcall TrackBar1Tracking(TObject *Sender);
	void __fastcall CheckBox3Change(TObject *Sender);
	void __fastcall Selection1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);

private: // User declarations
public: // User declarations
	__fastcall TForm11(TComponent* Owner);
	__fastcall ~TForm11();

	TMySelection *Selection2;
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm11 *Form11;
// ---------------------------------------------------------------------------
#endif
