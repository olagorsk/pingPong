//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x, y;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP) rightPaddleUp->Enabled = true;
    if (Key == VK_DOWN) rightPaddleDown->Enabled = true;

   if (Key == 'A') leftPaddleUp->Enabled = true;
    if (Key == 'Z') leftPaddleDown->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
       if (Key == VK_UP) rightPaddleUp->Enabled = false;
   if (Key == VK_DOWN) rightPaddleDown->Enabled = false;

   if (Key == 'A') leftPaddleUp->Enabled = false;
    if (Key == 'Z') leftPaddleDown->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleUpTimer(TObject *Sender)
{
if (rightPaddle->Top > table -> Top+10) rightPaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
 if (rightPaddle->Top+rightPaddle->Height < table -> Height) rightPaddle->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
 if (leftPaddle->Top > table -> Top+10) leftPaddle->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
  if (leftPaddle->Top+leftPaddle->Height < table -> Height) leftPaddle->Top += 10;
}
//---------------------------------------------------------------------------

