// ---------------------------------------------------------------------------

#include <fmx.h>
#ifdef _WIN32
#include <tchar.h>
#endif
#pragma hdrstop
#include <System.StartUpCopy.hpp>
// ---------------------------------------------------------------------------
USEFORM("MessageManager.cpp", Form1);
USEFORM("MessageSubscriber.cpp", Form2);
USEFORM("SignaturCapture.cpp", Form4);
USEFORM("THeaderItem.cpp", Form5);
USEFORM("ByteInteger.cpp", Form3);
USEFORM("MainForm.cpp", FormMain);
USEFORM("MobileAPP1Frame2.cpp", ChenYiZheFrame); /* TFrame: File Type */
USEFORM("MobileAPP1Frame1.cpp", SplashFrame); /* TFrame: File Type */
USEFORM("MobileAPP1.cpp", Form6);

// ---------------------------------------------------------------------------
extern "C" int FMXmain() {
	try {
		Application->Initialize();
		Application->FormFactor->Orientations =
			TScreenOrientations() << TScreenOrientation::Portrait;
		Application->CreateForm(__classid(TFormMain), &FormMain);
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm3), &Form3);
		Application->CreateForm(__classid(TForm4), &Form4);
		Application->CreateForm(__classid(TForm5), &Form5);
		Application->CreateForm(__classid(TChenYiZheFrame), &ChenYiZheFrame);
		Application->CreateForm(__classid(TForm6), &Form6);
		Application->Run();
	}
	catch (Exception &exception) {
		Application->ShowException(&exception);
	}
	catch (...) {
		try {
			throw Exception("");
		}
		catch (Exception &exception) {
			Application->ShowException(&exception);
		}
	}
	return 0;
}
// ---------------------------------------------------------------------------
