//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=10, y=10;
char who;
int leftPoints=0, rightPoints=0;
int bounces=0;

void endGame(char who)
{
char * pointsMessage;
AnsiString leftPointsText, rightPointsText, bouncesText;
 Form1->ball_timer->Enabled = false;
 Form1->ball->Visible = false;
         if (who =='r')
         {
         rightPoints++;
         pointsMessage = " Punkt dla gracza prawego >";
         }
         else
         {
         leftPoints++;
         pointsMessage = " < Punkt dla gracza lewego";
         }

   Form1->PointsMessage->Visible=true;
   Form1->PointsMessage->Caption=pointsMessage;

   leftPointsText = IntToStr(leftPoints);
   rightPointsText= IntToStr(rightPoints);

   Form1->Points->Visible=true;
   Form1->Points->Caption=leftPointsText + " : " + rightPointsText;

   bouncesText = IntToStr(bounces);
   Form1->Bounces->Visible=true;
   Form1->Bounces->Caption=" Liczba odbi� wynosi " + bouncesText;

   Form1->NextRound->Visible=true;
   Form1->NewGame->Visible=true;

}

void newRound()
{
 Form1->ball->Visible = true;
   Form1-> PointsMessage->Visible=false;
   Form1-> Points->Visible=false;
   Form1-> Bounces->Visible=false;
   Form1-> NextRound->Visible=false;
   Form1->NewGame->Visible=false;
   bounces=0;
   x=10, y=10;
   Form1->ball->Left=400;
   Form1->ball->Top=180;
      Form1->ball_timer->Enabled = true;
}
//---------------------------------------------------------------------------
  void __fastcall TForm1::pingPongOlaClick(TObject *Sender)
{
AnsiString strMessage = "Your record has been registered";
	AnsiString strCountry = "Country Name: Australia";
	AnsiString strCity = "City to visit: Melbourne";
	AnsiString strFinal = "Have a nice strip.";

	ShowMessage(strMessage + sLineBreak + strCountry + sLineBreak +
			strCity + sLineBreak + strFinal);
}
 //---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if (Key == VK_UP)
    {
    rightPaddleUp->Enabled = true;
     rightPaddle->Picture->LoadFromFile("img/palette_right_up.bmp");
    }
    if (Key == VK_DOWN)
    {
    rightPaddle->Picture->LoadFromFile("img/palette_right_down.bmp");
    rightPaddleDown->Enabled = true;
    }

   if (Key == 'A')
   {
   leftPaddleUp->Enabled = true;
     leftPaddle->Picture->LoadFromFile("img/palette_left_up.bmp");
     }
    if (Key == 'Z')
    {
     leftPaddle->Picture->LoadFromFile("img/palette_left_down.bmp");
    leftPaddleDown->Enabled = true;
    }
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
if (rightPaddle->Top > table -> Top-6) rightPaddle->Top -= 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::rightPaddleDownTimer(TObject *Sender)
{
 if (rightPaddle->Top+rightPaddle->Height-10 < table -> Height) rightPaddle->Top += 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleUpTimer(TObject *Sender)
{
 if (leftPaddle->Top > table -> Top-6) leftPaddle->Top -= 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::leftPaddleDownTimer(TObject *Sender)
{
  if (leftPaddle->Top+leftPaddle->Height-10 < table -> Height) leftPaddle->Top += 20;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ball_timerTimer(TObject *Sender)
{
ball->Left += x;
ball->Top += y;

if(ball->Top-5 <= table->Top) y=-y;   //bounce top

if(ball->Top+ball->Height >= table->Height) y=-y;    //bounce bottom


if       (ball->Top-ball->Height/2 >= leftPaddle->Top-60  &&
        ball->Top-ball->Height/2 <= leftPaddle->Top+leftPaddle->Height-60 &&
        ball->Left <= leftPaddle->Left+leftPaddle->Width-10)
        {
        x=-x*1.2;
        bounces++;
        }
        else if
        (ball->Top-ball->Height/2 >= leftPaddle->Top-20  &&
        ball->Top-ball->Height/2 <= leftPaddle->Top+leftPaddle->Height-20 &&
        ball->Left <= leftPaddle->Left+leftPaddle->Width-10)
        {
        x=-x;
         bounces++;
        }    //left bounce
       else if (ball->Left < leftPaddle->Left+leftPaddle->Width-10)
        {
         who='r';
         endGame(who);
        }
if       (ball->Top-ball->Height/2 >= rightPaddle->Top-60 &&
        ball->Top-ball->Height/2 <= rightPaddle->Top+rightPaddle->Height-60 &&
        ball->Left+ball->Width >= rightPaddle->Left+10)
        {
        x=-x*1.2;
        bounces++;
        }
        else if(ball->Top-ball->Height/2 >= rightPaddle->Top-20 &&
        ball->Top-ball->Height/2 <= rightPaddle->Top+rightPaddle->Height-20 &&
        ball->Left+ball->Width >= rightPaddle->Left+10)
        {
        x=-x;
        bounces++;
        }    //right bounce
       else if (ball->Left+ball->Width >= rightPaddle->Left+10)
        {
         who='l';
         endGame(who);
        }

}


void __fastcall TForm1::NextRoundClick(TObject *Sender)
{
newRound();
}

void __fastcall TForm1::NewGameClick(TObject *Sender)
{

 if (Application->MessageBox("Czy na pewno chcesz zacz�� od nowa?", "Potwierd�",
MB_YESNO | MB_ICONQUESTION)==IDYES)
{
newRound();
leftPoints=0, rightPoints=0;
}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


