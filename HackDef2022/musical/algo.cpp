#include<bits/stdc++.h>

int main(int _Argc,char **_Argv,char **_Env)

{
  int iVar1;
  int iVar2;
  char *local_160;
  char local_155 [61];
  int local_118 [32];
  int local_98 [4];
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int aiStack104 [16];
  char *local_28;
  int local_1c;
  
  local_98[0] = 0x24;
  local_98[1] = 0x30;
  local_98[2] = 0x69;
  local_98[3] = 0x33;
  local_88 = 0x61;
  local_84 = 0x4e;
  local_80 = 0x5f;
  local_7c = 0x66;
  local_78 = 0x6e;
  local_74 = 0x76;
  local_118[0] = 0x45;
  local_118[1] = 5;
  local_118[2] = 0x45;
  local_118[3] = 1;
  local_118[4] = 0x46;
  local_118[5] = 9;
  local_118[6] = 0x42;
  local_118[7] = 3;
  local_118[8] = 0x42;
  local_118[9] = 8;
  local_118[10] = 0x46;
  local_118[11] = 4;
  local_118[12] = 0x45;
  local_118[13] = 6;
  local_118[14] = 0x44;
  local_118[15] = 0;
  local_118[16] = 0x43;
  local_118[17] = 2;
  local_118[18] = 0x43;
  local_118[19] = 8;
  local_118[20] = 0x44;
  local_118[21] = 7;
  local_118[22] = 0x45;
  local_118[23] = 1;
  local_118[24] = 0x45;
  local_118[25] = 8;
  local_118[26] = 0x44;
  local_118[27] = 2;
  local_118[28] = 0x44;
  local_118[29] = 4;
  local_1c = 0;
  printf(
        "Ingresa las notas correctas para obtener el nombre de la pieza musical. Por favor hazlo de  forma que yo, un programa de computadora, pueda entender: "
        );
    strcpy(local_155 + 0xd,"69 69 70 66 66 70 69 68 67 67 68 69 69 68 68");
    local_160 = (char *)0x0;
    local_28 = strtok_r(local_155 + 0xd," ",&local_160);
    while (iVar1 = local_1c, local_28 != (char *)0x0) {
      local_1c = local_1c + 1;
      iVar2 = atoi(local_28);
      aiStack104[iVar1] = iVar2;
      printf("  %d    ",iVar2);
      local_28 = strtok_r((char *)0x0," ",&local_160);
    }
    
  //printf("%d\n",aiStack104[10]);

    for (local_1c = 0; local_1c < 0xf; local_1c = local_1c + 1) {
     
        //printf("La cadena que ingresaste es incorrecta");
        printf("%d ",local_118[(long long)local_1c * 2]);
      
      local_155[local_1c] = (char)local_98[local_118[(long long)local_1c * 2 + 1]];
    }
    printf("\nHermosa melodia! Te has ganado la flag: hackdef{%s}",local_155);
  
 
  return 0;
}