// ---------------------------------------------------------------------------

#ifndef MobileAPP1Frame1H
#define MobileAPP1Frame1H
// ---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>

// ---------------------------------------------------------------------------
class TSplashFrame : public TFrame {
__published: // IDE-managed Components
	TLayout *Layout1;
	TRectangle *Rectangle1;
	TRectangle *Rectangle2;
	TRectangle *Rectangle3;
	TText *Text1;
	TText *Text2;
	TCircle *Circle1;
	TText *Text3;

private: // User declarations
public: // User declarations
	__fastcall TSplashFrame(TComponent* Owner);
};

// ---------------------------------------------------------------------------
extern PACKAGE TSplashFrame *SplashFrame;
// ---------------------------------------------------------------------------
#endif
