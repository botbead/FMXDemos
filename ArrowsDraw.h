// ---------------------------------------------------------------------------

#ifndef ArrowsDrawH
#define ArrowsDrawH
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>

// ---------------------------------------------------------------------------
class TForm12 : public TForm {
__published: // IDE-managed Components
	TRectangle *Rectangle1;
	TSelectionPoint *SelectionPoint1;
	TSelectionPoint *SelectionPoint2;

	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Rectangle1Paint(TObject *Sender, TCanvas *Canvas, const TRectF &ARect);
	void __fastcall SelectionPoint2Track(TObject *Sender, float &X, float &Y);
	void __fastcall SelectionPoint1Track(TObject *Sender, float &X, float &Y);

private: // User declarations
public: // User declarations
	__fastcall TForm12(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm12 *Form12;
// ---------------------------------------------------------------------------
#endif
