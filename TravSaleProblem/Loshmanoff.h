//---------------------------------------------------------------------------

#ifndef LoshmanoffH
#define LoshmanoffH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <jpeg.hpp>
#include <Vector.h>
#include <math.h>
#include <Math.hpp>
#include <Grids.hpp>
#include <Algorithm.h>
#include <map.h>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <SysUtils.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TImage *Image1;
        TStringGrid *StringGrid4;
        TSaveDialog *SaveDialog1;
        TMainMenu *MainMenu1;
        TMenuItem *N1;
        TMenuItem *N2;
        TOpenDialog *OpenDialog1;
        TMenuItem *N3;
        TStatusBar *StatusBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TMenuItem *N4;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *N8;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TImageList *ImageList1;
        TImage *Image2;
        TToolButton *ToolButton3;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Image1MouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall N2Click(TObject *Sender);
        void __fastcall N3Click(TObject *Sender);
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall N5Click(TObject *Sender);
        void __fastcall N6Click(TObject *Sender);
        void __fastcall N8Click(TObject *Sender);




private:	// User declarations
        typedef vector<int>::iterator iterator;
        bool active_flag;
        int kol_uzlov;
        vector<int> temp_marsh;
        vector<vector<int> > top_popul;
        vector<double> array_x;
        vector<double> array_y;
        vector<vector<double> > array_rast;
        vector<vector<int> > popul_putei;
        vector<int> temp_mut;

        bool __fastcall TForm1::check(int X,int Y);
        void __fastcall TForm1::mutation(vector<int> &);
        bool __fastcall TForm1::CO(int nomer_marshruta1,int nomer_marshruta2);
        int __fastcall TForm1::length(vector<int> marshrut1,vector<int> marshrut2);
        void __fastcall TForm1::mask_generate(vector<int> &);
        double __fastcall TForm1::target_func(vector<int> &);
        void __fastcall TForm1::steps_to_left(vector<int> &);
        void __fastcall TForm1::gnrate_start_popul(vector<vector<int> > &);
        void __fastcall TForm1::razvert(vector<int> &);
        bool __fastcall TForm1::peres_check(int,int);
        void __fastcall TForm1::save_marsh_to_file();
        void __fastcall TForm1::open_marsh_from_file();
        double Del;
        int razm_popul;
        short kol_zapuskov;
        static const int ver_Mut=20;
        static const int ver_CO=40;
        long int temp;
public:		// User declarations
      vector<int> mask;
      vector<int> temp_m;
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
