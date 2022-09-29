#include <iostream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <vector>
#include<fstream>
#include<stdio.h>
using namespace std;



using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

struct duom{
  string var;
  string pav;
  int paz[5];
  int egz;
};
duom ivedimas(int &n);
void isvedimas(duom temp, int n);


int main()
//doumenu pvzd.
{
    char fileName[30], ch;
    fstream fp;
    cout<<"Iveskite txt failo pavadinima: ";
    gets(fileName);
    fp.open(fileName, fstream::in);
    if(!fp)
    {
        cout<<"\Klaida, neteisingas failo pavadinimas ar jo isvis nera!";
        return 0;
    }
    cout<<"\Textinis dokumentas-"<<fileName<<":-\n";
    while(fp>>noskipws>>ch)
        cout<<ch;
    fp.close();
    cout<<endl;
//---------------------------------------------------------

//pats kodas kuris skaiciuoja
  duom asmuo1;
  duom *mas,*tempas;
  int n =1, m,i=0;
  //cout<<"Iveskite studentu kieki: "; cin>>n;
  mas = new duom [n];
  char uzklk='1';
  while (uzklk!='T') {
       mas[i]=ivedimas(m);
       i++;n++;
       tempas = new duom [n];
       for (int j=0;j<n-1;j++)
         tempas[j]=mas[j];
       mas=new duom [n];
      mas=tempas;
      delete [] tempas;
    cout<<"Ar norite baigti ivedima? T/N";
    cin>>uzklk;
    }
  for (int b=0;b<n;b++)
    isvedimas (mas[b], 5);
  delete [] mas;
}


duom ivedimas(int &n){
  duom asmuo;
  cout<<"Iveskite varda: "; cin>>asmuo.var;
  cout<<"Iveskite pavarde: "; cin>>asmuo.pav;
  cout<<"Iveskite egzamino paz.: "; cin>>asmuo.egz;

  n=5;
  for (int kint=0;kint<n; kint++)
    {
      cout<<"Iveskite "<<kint+1<<" pazymi: ";
      cin>>asmuo.paz[kint];
    }
  return asmuo;
}

void isvedimas(duom temp, int n){
  cout<<std::left<<std::setw(20)<<temp.var<<std::left<<std::setw(20)<<temp.pav;
  for (int a=0;a<n;a++) cout<<std::right<<std::setw(5)<<temp.paz[a];
  cout<<std::right<<std::setw(5)<<temp.egz<<endl;


  printf("|%-20s|%-20s|", temp.var.c_str(), temp.pav.c_str());
  for (int a=0;a<n;a++) printf("%5d|",temp.paz[a]);
  printf("%*d|\n",5,temp.egz);
}


