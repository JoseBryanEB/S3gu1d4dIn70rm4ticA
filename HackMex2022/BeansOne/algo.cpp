#include <cstddef>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
//ETSCTF_a714276437001595a94466
//ETSCTF_a7142764370015a9594466
string str = "cpqapb}UOP\x81\x82NURP\x82Q\x80ULL\x82O\x82S\x82W\x82SW\x80PP\x83RR";

//string str = "cpqapb}UOPNURPQULLOSWSWPPRR";
char * ETSCTF_GLOBAL = const_cast<char*>(str.c_str());
void xor2(void)

{
  size_t sVar1;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    sVar1 = strlen(ETSCTF_GLOBAL);
    if (sVar1 <= (unsigned long)(long)local_1c) break;
    ETSCTF_GLOBAL[local_1c] = ETSCTF_GLOBAL[local_1c] ^ 1;
    local_1c = local_1c + 1;
  }
  return;
}

void unrot16(void)

{
  size_t sVar1;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    sVar1 = strlen(ETSCTF_GLOBAL);
    if (sVar1 <= (unsigned long)(long)local_1c) break;
    ETSCTF_GLOBAL[local_1c] = ETSCTF_GLOBAL[local_1c] + -0x10;
    local_1c = local_1c + 1;
  }
  return;
}
void unrot13(void)

{
  size_t sVar1;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    sVar1 = strlen(ETSCTF_GLOBAL);
    if (sVar1 <= (unsigned long)(long)local_1c) break;
    ETSCTF_GLOBAL[local_1c] = ETSCTF_GLOBAL[local_1c] + -0xd;
    local_1c = local_1c + 1;
  }
  return;
}

void decode_flag(void)

{
  xor2();
  unrot16();
  unrot13();
  return;
}

main (){
    decode_flag();
    puts(ETSCTF_GLOBAL);
}