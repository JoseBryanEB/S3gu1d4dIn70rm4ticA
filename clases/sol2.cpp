#include <iostream>
#include <string.h>
using namespace std; 
char * bill_cipher(char *param_1)

{
  int iVar1;
  int sVar2;
  char *pvVar3;
  int local_18;
  
  sVar2 = strlen(param_1);
  iVar1 = (int)sVar2;
  pvVar3 = new char[iVar1+1] ;
  for (local_18 = 0; local_18 < iVar1; local_18 = local_18 + 1) {
    *(char *)((long)pvVar3 + (long)local_18) = param_1[local_18] ^ 0x32;
  }
  *(char *)((long)pvVar3 + (long)iVar1) = 10;
  return pvVar3;
}
 int main (int argc, char *argv[])
{
  char al[]={0x51,0x46,0x54,0x49, 0x0A,0x5B, 0x03, 0x03, 0x6D , 0x03,0x02,0x6D,0x44,0x01,0x6D,0x46, 0x02, 0x56, 0x02, 0x4F, 0x0A};
  string flag="";
  for (int c =0 ; c<21;i++){
    for (int i = 32; i <126; i++){
      char *sol = bill_cipher(a);
      printf(sol);
    }

  }
  cout<<flag<<endl ;
  return 0;
}
