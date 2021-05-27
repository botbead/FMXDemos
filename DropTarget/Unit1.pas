unit Unit1;

interface

uses
  System.SysUtils, System.Types, System.UITypes, System.Classes,
  System.Variants,
  FMX.Types, FMX.Controls, FMX.Forms, FMX.Graphics, FMX.Dialogs, FMX.ScrollBox,
  FMX.Memo, FMX.ExtCtrls, FMX.StdCtrls, FMX.Controls.Presentation;

type
  TForm1 = class(TForm)
    ToolBar1: TToolBar;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    DropTarget1: TDropTarget;
    Memo1: TMemo;
    StyleBook1: TStyleBook;
    procedure DropTarget1DragOver(Sender: TObject; const Data: TDragObject;
      const Point: TPointF; var Operation: TDragOperation);
    procedure DropTarget1Dropped(Sender: TObject; const Data: TDragObject;
      const Point: TPointF);
    procedure Button1Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

Uses FMX.Platform;

{$R *.fmx}

// Clear
procedure TForm1.Button1Click(Sender: TObject);
begin
  Memo1.Lines.Clear;
end;

// Clipboard
procedure TForm1.Button2Click(Sender: TObject);
var
  ClipService: IFMXClipboardService;
  K: String;
begin
  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService,
    ClipService) then
  begin
    K := Memo1.Text;
    ClipService.SetClipboard(K);
  end;
end;

procedure TForm1.Button3Click(Sender: TObject);
var
  A: Integer;
  ClipService: IFMXClipboardService;
  K: String;
  S: String;
begin
  K := '';

  for A := 0 to Memo1.Lines.Count - 1 do
  begin
    S := Memo1.Lines[A];
    if Trim(S).IsEmpty then
      Continue;
    K := K + S + #9; // Tab
  end;

  if TPlatformServices.Current.SupportsPlatformService(IFMXClipboardService,
    ClipService) then
  begin
    ClipService.SetClipboard(K);
  end;
end;

// DragOver
procedure TForm1.DropTarget1DragOver(Sender: TObject; const Data: TDragObject;
  const Point: TPointF; var Operation: TDragOperation);
begin
  Operation := TDragOperation.Copy;
end;

// Drop
procedure TForm1.DropTarget1Dropped(Sender: TObject; const Data: TDragObject;
  const Point: TPointF);
var
  D: String;
  U: TStringList;
begin
  U := TStringList.Create;
  U.Sorted := True;

  for D in Data.Files do
  begin
    U.Add(ExtractFileName(D));
  end;

  Memo1.Lines.AddStrings(U);
  U.Free;
end;

end.
