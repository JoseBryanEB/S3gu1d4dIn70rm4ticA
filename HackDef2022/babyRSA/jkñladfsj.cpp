void main.followMe(undefined4 param_1,undefined *param_2)

{
  uint *puVar1;
  uint uVar2;
  undefined **ppuVar3;
  undefined **ppuVar2;
  int *in_GS_OFFSET;
  undefined1 *local_234;
  undefined4 local_230;
  undefined *local_22c;
  int local_228;
  undefined **local_224;
  undefined4 local_220;
  undefined4 local_21c;
  uint local_20c;
  undefined local_208 [84];
  undefined local_1b4 [44];
  uint local_188 [48];
  uint local_c8 [48];
  undefined *local_8;
  undefined4 local_4;
  
  puVar1 = (uint *)(*(int *)(*in_GS_OFFSET + -4) + 8);
  ppuVar2 = (undefined **)register0x00000010;
  if ((undefined *)*puVar1 <= local_1b4 && local_1b4 != (undefined *)*puVar1) {
    ppuVar2 = &local_234;
    FUN_080a1a40();
    FUN_080a1da0();
    FUN_080a1a40();
    local_234 = local_208;
    local_230 = param_1;
    local_22c = param_2;
    runtime.stringtoslicerune();
    ppuVar3 = (undefined **)0x0;
    for (uVar2 = 0; (int)uVar2 < 0x30; uVar2 = uVar2 + 1) {
      if (ppuVar3 == (undefined **)&DAT_00000008) {
        ppuVar3 = (undefined **)0x0;
      }
      if (0x2f < uVar2) goto LAB_080c5626;
      if (local_224 <= ppuVar3) goto LAB_080c561f;
      local_188[uVar2] = local_c8[uVar2] ^ *(uint *)(local_228 + (int)ppuVar3 * 4);   //XOR
      ppuVar3 = (undefined **)((int)ppuVar3 + 1);
    }
    if (((((local_188[0] != 0x68) || (local_188[1] != 0x61)) || (local_188[2] != 99)) ||
        ((local_188[3] != 0x6b || (local_188[4] != 100)))) ||
       ((local_188[5] != 0x65 || ((local_188[6] != 0x66 || (local_188[7] != 0x7b)))))) {
      return;
    }
    uVar2 = 0;
    while( true ) {
      if (0x2f < (int)uVar2) {
        return;
      }
      local_8 = (undefined *)0x0;
      local_4 = 0;
      if (0x2f < uVar2) break;
      local_20c = uVar2;
      local_234 = (undefined1 *)local_188[uVar2];
      runtime.convT32();
      local_8 = &DAT_080cd460;
      local_4 = local_230;
      local_234 = go.itab.*os.File,io.Writer;
      local_230 = os.Stdout;
      local_22c = &DAT_080d76ea;
      local_228 = 2;
      local_224 = &local_8;
      local_220 = 1;
      local_21c = 1;
      fmt.Fprintf();
      uVar2 = local_20c + 1;
    }
    runtime.panicIndex();
LAB_080c561f:
    runtime.panicIndex();
LAB_080c5626:
    runtime.panicIndex();
  }
  *(undefined4 *)((int)ppuVar2 + -4) = 0x80c5636;
  runtime.morestack_noctxt();
  main.followMe();
  return;
}
