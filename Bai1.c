//Ma de 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX_SIZE 100
typedef struct 
{
    int a,b,c;
}HS;


HS nhapHS(HS m)
{
   printf("Nhap 3 thong so cua hon so: ");
   scanf("%d%d%d",&m.a,&m.b,&m.c);
   return m;
}
//Chuyen sang phan so
typedef struct 
{
    int tu,mau;
}PS;

PS chuyenPS(HS hs)
{
    PS ps;
    ps.tu = hs.a*hs.c+hs.b;
    ps.mau = hs.c;
    return ps; 
}

void inPhanSo (PS a)
{
    printf("%d/%d\n",a.tu,a.mau);
}

void inHS(HS hs)
{
    printf("Phan nguyen cua hon so: %d\n",hs.a);
    printf("Phan phan so cua hon so: %d/%d\n",hs.b,hs.c);
}
//rut gon phan so
int ucln(int a,int b)
{
    if(b==0) return a;
    return ucln(b,a%b);
}

PS simplify(PS a)
{
  int i = ucln(a.tu,a.mau);
  a.tu = a.tu / i;
  a.mau = a.mau /i;
  return a;
}
PS tongPS(PS a, PS b)
{
    PS c;
    c.tu = a.mau * b.tu + b.mau* a.tu;
    c.mau = a.mau*b.mau;
    return simplify(c);
}

PS hieuPS(PS a, PS b)
{
    PS c;
    c.tu = a.tu * b.mau - b.tu* a.mau;
    c.mau = a.mau*b.mau;
    return simplify(c);
}

PS tichPS( PS a,PS b)
{
    PS c;
    c.tu = a.tu * b.tu;
    c.mau = a.mau * b.mau;
    return simplify(c);
}

int main()
{
  printf("Bai 1a: \n");
  //a
  HS honso;
  honso = nhapHS(honso);
  inHS(honso);
  //b
  printf("Bai 1b: \n");
  
  HS hs1;
  hs1 = nhapHS(hs1);
  HS hs2;
  hs2 = nhapHS(hs2);

   PS ps1 = chuyenPS(hs1);
   PS ps2 = chuyenPS(hs2);

  printf("Dang phan so cua hon so 1: ");inPhanSo(ps1);
  printf("Dang phan so cua hon so 2: ");inPhanSo(ps2);

  PS tong = tongPS(ps1,ps2);
  printf("Tong hai hon so: ");inPhanSo(tong);
  PS hieu = hieuPS(ps1,ps2);
  printf("Hieu hai hon so: ");inPhanSo(hieu);
  PS tich = tichPS(ps1,ps2);
  printf("Tich hai hon so: ");inPhanSo(tich);
}
