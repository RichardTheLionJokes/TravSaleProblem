//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Loshmanoff.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 active_flag=false;
}
//---------------------------------------------------------------------------

bool __fastcall TForm1::check(int X,int Y)
{
 for (int i=0;i<kol_uzlov;i++)
 {
  if ((abs(X-array_x[i])<=5)&&(abs(Y-array_y[i])<=5)) return false;
 }
 return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::mutation(vector<int> &marshrut)
{

      int gr_otr_mut=random(kol_uzlov-1);
      int dlina_otr_mut=random(4)+3;
      if(dlina_otr_mut>=kol_uzlov-1) dlina_otr_mut=2;
      int temp_mut_1=0;
      int temp_mut_2=dlina_otr_mut;
       mask.resize(kol_uzlov-1);
       fill(mask.begin(),mask.end(),0);
       if(gr_otr_mut+dlina_otr_mut>mask.size())
       {
        temp_mut_1=gr_otr_mut+dlina_otr_mut-mask.size();
        temp_mut_2=mask.size()-gr_otr_mut;
       }
      for(int i=0;i<temp_mut_1;++i) mask.at(i)=1;
      for(int i=0;i<temp_mut_2;++i) mask.at(gr_otr_mut+i)=1;


      for (unsigned int i=0;i<mask.size();i++)
       {
       if (mask.at(i)==1) temp_mut.push_back(marshrut.at(i));
       }

    random_shuffle(temp_mut.begin(),temp_mut.end());

      for (unsigned int i=0;i<mask.size();i++)
       {
       if (mask.at(i)==1)
           {
            marshrut.at(i)=temp_mut.back();
            temp_mut.pop_back();
           }
       }


}
//---------------------------------------------------------------------------

bool __fastcall TForm1::CO(int nomer_marshruta1,int nomer_marshruta2)
{
   int s4et4ik=0;

   if (popul_putei.at(nomer_marshruta1)==popul_putei.at(nomer_marshruta2))
     {
     steps_to_left(popul_putei.at(nomer_marshruta2));
     return false;
     }
   Vibor_2_to4ek_CO:
   s4et4ik++;

    mask_generate(mask);
    vector<int> temp_for_CO_1;
    vector<int> temp_for_CO_2;
   if(s4et4ik>200)
   {
   steps_to_left(popul_putei.at(nomer_marshruta2));
   return false;
   }

     for (int i=0;i<mask.size();i++)
      {
        if (mask.at(i)==1)
            {
            if(popul_putei.at(nomer_marshruta1).at(i)==popul_putei.at(nomer_marshruta2).at(i))
            {
             mask.at(i)=0;
            }
            else
            {
             temp_for_CO_1.push_back(popul_putei.at(nomer_marshruta1).at(i));
             temp_for_CO_2.push_back(popul_putei.at(nomer_marshruta2).at(i));
            }
            }
      }




     if (temp_for_CO_1==temp_for_CO_2) goto Vibor_2_to4ek_CO;

    sort(temp_for_CO_1.begin(),temp_for_CO_1.end());
      sort(temp_for_CO_2.begin(),temp_for_CO_2.end());
     if (!(temp_for_CO_1==temp_for_CO_2)) goto Vibor_2_to4ek_CO;


     for (int i=0;i<mask.size();i++)
      {
        if (mask.at(i)==1)
           {
     swap(popul_putei.at(nomer_marshruta1).at(i),popul_putei.at(nomer_marshruta2).at(i));
           }
      }


    return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
kol_zapuskov=0;
Del=1000000.0;
kol_uzlov=0;
Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
randomize();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (!(active_flag)&&check(X,Y))
{

kol_uzlov++;
StatusBar1->Panels->Items[5]->Text=kol_uzlov-1;
Image1->Canvas->Ellipse(X-4,Y-4,X+4,Y+4);
Image1->Canvas->Brush->Color=clBlack;

array_x.push_back(X);
array_y.push_back(Y);


if(kol_uzlov>3)
 {
 N2->Enabled=true;
 N5->Enabled=true;
 ToolButton1->Enabled=true;
 ToolButton5->Enabled=true;
 }
}
}
//---------------------------------------------------------------------------

  double __fastcall TForm1::target_func(vector<int> &marshrut)
  {
  double length=0;
  length+=array_rast.at(0).at(marshrut.at(0));
    for (unsigned int i=0;i<marshrut.size()-1;i++)
     {
     length+=array_rast.at(marshrut.at(i)).at(marshrut.at(i+1));
     }
   length+=array_rast.at(0).at(marshrut.at(marshrut.size()-1));
   return length;
  }

//---------------------------------------------------------------------------
  int __fastcall TForm1::length(vector<int> marshrut1,vector<int> marshrut2)
  {
  int tux=0;

    for (unsigned int i=0;i<marshrut1.size();i++)
       {
       if (marshrut1.at(i)==marshrut2.at(i)) tux++;
       }

  return tux;
  }
//---------------------------------------------------------------------------

  void __fastcall TForm1::mask_generate(vector<int> &m)
  {
  int number;
  m.clear();
  int temp_m_razm=8;
  if(kol_uzlov<10) temp_m_razm=kol_uzlov-2;
  number=random(temp_m_razm)+2;
  m.resize(kol_uzlov-1);
  fill_n(m.begin(),number,1);
  random_shuffle(m.begin(),m.end());
  }

//---------------------------------------------------------------------------

   void __fastcall TForm1::steps_to_left(vector<int> &marshrut)
   {
    int number;
    vector<int> temp_steps(3);

     for (int i=0;i<temp_steps.size();++i) temp_steps[i]=random(marshrut.size());
     sort(temp_steps.begin(),temp_steps.end());

    rotate(marshrut.begin()+temp_steps[0],marshrut.begin()+temp_steps[1],marshrut.begin()+temp_steps[2]);


   }

//---------------------------------------------------------------------------
void __fastcall TForm1::gnrate_start_popul(vector<vector<int> > &popul)
   {
   multimap<double,int> some;


   popul.resize(razm_popul);

     
for (int i=0;i<kol_uzlov-1;++i)
    {
     popul.at(i).push_back(i+1);
     vector<int> temp_vec;
      temp_vec=popul.at(i);
      for (int j=0;j<kol_uzlov-2;++j)
         {
             for (int k=1;k<kol_uzlov;++k)
               {

        if ((i+1!=k)&&(!(binary_search(temp_vec.begin(),temp_vec.end(),k))))
                         {
         some.insert(make_pair(array_rast.at(popul.at(i).back()).at(k),k));

                         }
                }

       popul.at(i).push_back(some.begin()->second);
            temp_vec.resize(popul.at(i).size());
     partial_sort_copy(popul.at(i).begin(),popul.at(i).end(),temp_vec.begin(),temp_vec.end());
             some.clear();

           }
      }

       }

//---------------------------------------------------------------------------

void _fastcall TForm1::razvert(vector<int> &marshrut)
    {
    vector<int> petux;
    petux=marshrut;
    temp_m.clear();
    temp_m.resize(kol_uzlov+1);
Zannava:
    bool flag=false;
    copy(petux.begin(),petux.end(),temp_m.begin()+1);
    for (int i=0;i<=temp_m.size()-4;++i)
         {
          for (int j=i+2;j<=temp_m.size()-2;++j)
               {
                if ((i==0)&&(j==temp_m.size()-2)) break;

                if (peres_check(i,j))
                  {
                  flag=true;

     reverse(temp_m.begin()+i+1,temp_m.begin()+j+1);
     copy(temp_m.begin()+1,temp_m.end()-1,petux.begin());


                if (flag) goto Zannava;



                  }
               }
         }

      marshrut=petux;
    }
//---------------------------------------------------------------------------
bool _fastcall TForm1::peres_check(int a,int b)
    {

 int x11=array_x.at(temp_m.at(a));
 int x12=array_x.at(temp_m.at(a+1));
 int x21=array_x.at(temp_m.at(b));
 int x22=array_x.at(temp_m.at(b+1));
 int y11=array_y.at(temp_m.at(a));
 int y12=array_y.at(temp_m.at(a+1));
 int y21=array_y.at(temp_m.at(b));
 int y22=array_y.at(temp_m.at(b+1));

int minx1,minx2,miny1,miny2;
int maxx1,maxx2,maxy1,maxy2;
minx1=x11;minx2=x21;miny1=y11;miny2=y21;
maxx1=x12;maxx2=x22;maxy1=y12;maxy2=y22;
if(x11>x12) swap(minx1,maxx1);
if(x21>x22) swap(minx2,maxx2);
if(y11>y12) swap(miny1,maxy1);
if(y21>y22) swap(miny2,maxy2);

 int znamen=(x22-x21)*(y11-y12)-(x12-x11)*(y21-y22);

   if (znamen==0) return false;



  double iks=((x12-x11)*(x21*y22-y21*x22)-(x22-x21)*(x11*y12-y11*x12))/znamen;

  double igrek=((y21-y22)*(x11*y12-y11*x12)-(y11-y12)*(x21*y22-y21*x22))/znamen;


if((iks<=maxx1)&&(iks>=minx1)&&(iks<=maxx2)&&(iks>=minx2))
{
if((igrek<=maxy1)&&(igrek>=miny1)&&(igrek<=maxy2)&&(igrek>=miny2))
{
      return true;

       }
       }

  return false;
    }
//---------------------------------------------------------------------------
void __fastcall TForm1::save_marsh_to_file()
     {
     TStringList *temp_save;
     temp_save=new TStringList;
     temp_save->Add(IntToStr(kol_uzlov));

     for (int i=0; i<kol_uzlov;++i)
          {
           temp_save->Add(FloatToStr(array_x.at(i)));
           temp_save->Add(FloatToStr(array_y.at(i)));
          }
     if (SaveDialog1->Execute())
          {
     temp_save->SaveToFile(SaveDialog1->FileName);
          }
      }
//---------------------------------------------------------------------------
void __fastcall TForm1::open_marsh_from_file()
    {
    N5->Enabled=false;

    array_x.clear();
    array_y.clear();
    array_rast.clear();
    top_popul.clear();
    popul_putei.clear();
   
    kol_uzlov=0;
    kol_zapuskov=0;

    Image1->Canvas->Brush->Color=clWhite;
    Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
    StringGrid4->Visible=false;

    int temp_kol_uzlov;

    bool flag_x_y=true;

    TStringList *temp_open;
    temp_open=new TStringList;

if (OpenDialog1->Execute())
          {
     temp_open->LoadFromFile(OpenDialog1->FileName);

  try
  {
    temp_kol_uzlov = temp_open->Strings[0].ToInt();
  }
  catch(...)
  {
    Application->MessageBox("Файл маршрута имеет неверный формат или поврежден","Ошибка",MB_OK);
    active_flag=false;
    return;
  }
  if (temp_kol_uzlov<4)
     {
     Application->MessageBox("Файл маршрута имеет неверный формат или поврежден","Ошибка",MB_OK);
     active_flag=false;
     return;
     }

kol_uzlov=temp_kol_uzlov;


  if (temp_open->Count<2*kol_uzlov+1)
     {
     Application->MessageBox("Файл маршрута имеет неверный формат или поврежден","Ошибка",MB_OK);
     active_flag=false;
     return;
     }

int str_index=1;
int str_number=0;

while(str_number!=kol_uzlov)
    {
     try
       {
         if (temp_open->Strings[str_index].IsEmpty())
            {
            ++str_index;
            continue;
            }

         if (flag_x_y)
            {
            array_x.push_back(temp_open->Strings[str_index].ToDouble());
            flag_x_y=false;
            ++str_index;
            continue;
            }
         else
            {
            array_y.push_back(temp_open->Strings[str_index].ToDouble());
            flag_x_y=true;
            ++str_index;
            ++str_number;
            }
        }
     catch(...)
       {
       Application->MessageBox("Файл маршрута имеет неверный формат или поврежден","Ошибка",MB_OK);
       array_x.clear();
       array_y.clear();
       active_flag=false;
       return;
       }
    }
    N5->Enabled=true;

        }

    for (int i=0;i<kol_uzlov;++i)
         {
         Image1->Canvas->Ellipse(array_x.at(i)-4,array_y.at(i)-4,array_x.at(i)+4,array_y.at(i)+4);
         Image1->Canvas->Brush->Color=clBlack;
         }
   StatusBar1->Panels->Items[5]->Text=kol_uzlov-1;
    }
//---------------------------------------------------------------------------

void __fastcall TForm1::N2Click(TObject *Sender)
    {
    save_marsh_to_file();
    }
//---------------------------------------------------------------------------


 
void __fastcall TForm1::N3Click(TObject *Sender)
{
open_marsh_from_file();
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
StatusBar1->Panels->Items[1]->Text=X;
StatusBar1->Panels->Items[3]->Text=Y;
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------



void __fastcall TForm1::N5Click(TObject *Sender)
{
 active_flag=true;
 N6->Enabled=true;
 ToolButton6->Enabled=true;
if(kol_zapuskov==1)
{
  for(int i=0;i<razm_popul;i++)
  {
  popul_putei.at(i)=top_popul.at(i);
  }
  int kol_perestanovok=Floor(random(razm_popul*2+1));
  for(int j=0;j<kol_perestanovok;j++)
  {
   Vibor_nomerov_perestanovki_2:
   int nomer1=random(razm_popul);
   int nomer2=random(razm_popul);
   if(nomer1==nomer2) goto Vibor_nomerov_perestanovki_2;

   temp_marsh=popul_putei.at(nomer1);
   popul_putei.at(nomer1)=popul_putei.at(nomer2);
   popul_putei.at(nomer2)=temp_marsh;
  }
}

if(kol_zapuskov==0)
{
razm_popul=kol_uzlov-1;

temp_marsh.resize(kol_uzlov-1);

popul_putei.resize(razm_popul);

top_popul.resize(razm_popul);

  for (int i=0; i<razm_popul;i++)
  {
  top_popul.at(i).resize(kol_uzlov-1);
  }


array_rast.resize(kol_uzlov);

for (int i=0; i<kol_uzlov;i++)
{
array_rast[i].resize(kol_uzlov);
}


for (int i=0;i<kol_uzlov-1;i++)
{
for (int j=i+1;j<kol_uzlov;j++)
{
array_rast.at(i).at(j)=sqrt(pow(array_x.at(i)-array_x.at(j),2)+pow(array_y.at(i)-array_y.at(j),2));
array_rast.at(j).at(i)=array_rast.at(i).at(j);
}
}
kol_zapuskov=1;

  gnrate_start_popul(popul_putei);


for(int i=0;i<razm_popul;i++)
  {
  top_popul.at(i)=popul_putei.at(i);
  }



for(int j=0;j<razm_popul-1;j++)
{
for(int i=j+1;i<razm_popul;i++)
{
   if(target_func(top_popul.at(i))<target_func(top_popul.at(j)))
   {
      temp_marsh=top_popul.at(j);
      top_popul.at(j)=top_popul.at(i);
      top_popul.at(i)=temp_marsh;
   }
}
}
}




  for(int nomer_pokoleniya=0;nomer_pokoleniya<100;nomer_pokoleniya++)
  {
     vector<vector<int> > new_popul_putei;
     new_popul_putei.resize(razm_popul);
     for (int i=0; i<razm_popul;i++)
     {
     new_popul_putei.at(i).resize(kol_uzlov-1);
     }
     vector<int> rand_r;
     for(int i=0;i<razm_popul;i++)
     {
       double r=random(Del+1)/Del;
       if(r<=ver_CO/100.0)
       {
       rand_r.resize(rand_r.size()+1);
       rand_r.at(rand_r.size()-1)=i;
       }
     }

     if (!(rand_r.size()%2==0)) rand_r.resize(rand_r.size()-1);


     int kol_ysp_CO=0;
     for(unsigned int i=0;i<rand_r.size();i+=2)
     {
     CO(rand_r.at(i),rand_r.at(i+1));
     if(CO(rand_r.at(i),rand_r.at(i+1))) kol_ysp_CO++;
     }




     for(int i=0;i<razm_popul;i++)
      {
      double r;
      r=random(Del+1)/Del;
      if(r<=ver_Mut/100.0)
        {
         mutation(popul_putei.at(i));
        }
      }


       for(int i=0;i<razm_popul;i++)
     {
        int otobr_nomer;
        Vibor_nomerov_otbora:
        int n_otb1=random(razm_popul);
        int n_otb2=random(razm_popul);
        if(n_otb1==n_otb2) goto Vibor_nomerov_otbora;
        if(target_func(popul_putei.at(n_otb1))<=target_func(popul_putei.at(n_otb2)))
        {
          otobr_nomer=n_otb1;
        }
        else otobr_nomer=n_otb2;
        new_popul_putei.at(i)=popul_putei.at(otobr_nomer);
     }

     for(int i=0;i<razm_popul;i++)
     {
        popul_putei.at(i)=new_popul_putei.at(i);
     }

     for(int i=0;i<razm_popul;i++)
     {
       int nomer_v_tope=razm_popul;
       for(int j=razm_popul-1;j>=0;j--)
       {
          if(popul_putei.at(i)==top_popul.at(j))
          {
          nomer_v_tope=razm_popul;
          break;
          }
          if(target_func(popul_putei.at(i))>target_func(top_popul.at(j))) break;
          if(target_func(popul_putei.at(i))<target_func(top_popul.at(j))) nomer_v_tope--;
       }
       if(!(nomer_v_tope==razm_popul))
       {
       for(int i=razm_popul-1;i>nomer_v_tope;i--)
       {
          top_popul.at(i)=top_popul.at(i-1);
       }
       top_popul.at(nomer_v_tope)=popul_putei.at(i);
       }
     }
      }
     StringGrid4->RowCount=1;
     StringGrid4->ColCount=kol_uzlov;



    for(int i=0;i<kol_uzlov-1;i++)
     {
        StringGrid4->Cells[i+1][0]=top_popul.at(0).at(i);
     }
     StringGrid4->Cells[0][0]=target_func(top_popul.at(0));
     Image1->Canvas->Brush->Color=clWhite;
     Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
     for(int i=0;i<kol_uzlov;i++)
     {
        Image1->Canvas->Ellipse(array_x.at(i)-4,array_y.at(i)-4,array_x.at(i)+4,array_y.at(i)+4);
        Image1->Canvas->Brush->Color=clBlack;
     }
     Image1->Canvas->MoveTo(array_x.at(0),array_y.at(0));
     for(int i=0;i<kol_uzlov-1;i++)
     {
     Image1->Canvas->LineTo(array_x.at(top_popul.at(0).at(i)),array_y.at(top_popul.at(0).at(i)));
     }
     Image1->Canvas->LineTo(array_x.at(0),array_y.at(0));
     StringGrid4->Visible=true;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::N6Click(TObject *Sender)
{
      for (int i=0;i<top_popul.size();++i) razvert(top_popul.at(i));
      multimap<double,vector<int> > for_sort;
      for (int i=0;i<top_popul.size();++i)
           {
           for_sort.insert(make_pair(target_func(top_popul.at(i)),top_popul.at(i)));
           }
      top_popul.clear();
      for (int i=0;i<razm_popul;++i)
           {
           top_popul.push_back(for_sort.begin()->second);
           ++for_sort.begin();
           }

      for(int i=0;i<kol_uzlov-1;i++)
           {
        StringGrid4->Cells[i+1][0]=top_popul.at(0).at(i);
           }
     StringGrid4->Cells[0][0]=target_func(top_popul.at(0));

     Image1->Canvas->Brush->Color=clWhite;
     Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);

     for(int i=0;i<kol_uzlov;i++)
     {
        Image1->Canvas->Ellipse(array_x.at(i)-4,array_y.at(i)-4,array_x.at(i)+4,array_y.at(i)+4);
        Image1->Canvas->Brush->Color=clBlack;
     }
     Image1->Canvas->MoveTo(array_x.at(0),array_y.at(0));
     for(int i=0;i<kol_uzlov-1;i++)
     {
     Image1->Canvas->LineTo(array_x.at(top_popul.at(0).at(i)),array_y.at(top_popul.at(0).at(i)));
     }
     Image1->Canvas->LineTo(array_x.at(0),array_y.at(0));
      
}

//---------------------------------------------------------------------------



void __fastcall TForm1::N8Click(TObject *Sender)
{
N5->Enabled=false;
N2->Enabled=false;
N6->Enabled=false;
ToolButton1->Enabled=false;
ToolButton5->Enabled=false;
ToolButton6->Enabled=false;
StringGrid4->Visible=false;
kol_uzlov=0;
array_x.clear();
array_y.clear();
array_rast.clear();
top_popul.clear();
popul_putei.clear();
kol_zapuskov=0;
StatusBar1->Panels->Items[5]->Text=0;
Image1->Canvas->Brush->Color=clWhite;
Image1->Canvas->Rectangle(0,0,Image1->Width,Image1->Height);
active_flag=false;
}

//---------------------------------------------------------------------------




