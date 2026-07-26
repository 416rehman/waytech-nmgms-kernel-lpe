
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int entry(longlong param_1)

{
  int iVar1;
  longlong lVar2;
  undefined8 *puVar3;
  longlong local_28 [2];
  
  RtlInitUnicodeString(&DAT_00012510,L"\\Device\\nmgms");
  iVar1 = IoCreateDevice(param_1,0x20,&DAT_00012510,0x22,0,0,local_28);
  if (-1 < iVar1) {
    lVar2 = *(longlong *)(local_28[0] + 0x40);
    *(longlong *)(lVar2 + 8) = lVar2;
    *(longlong *)lVar2 = lVar2;
    *(undefined8 *)(lVar2 + 0x18) = 0;
    *(undefined4 *)(lVar2 + 0x10) = 0;
    DAT_00012520 = local_28[0];
    DAT_00012528 = 0;
    _DAT_0001253c = 0;
    _DAT_00012540 = 0;
    _DAT_00012530 = 0;
    puVar3 = (undefined8 *)(param_1 + 0x70);
    for (lVar2 = 0x1c; lVar2 != 0; lVar2 = lVar2 + -1) {
      *puVar3 = &LAB_000104b0;
      puVar3 = puVar3 + 1;
    }
    *(undefined8 *)(param_1 + 0x70) = &LAB_00012880;
    *(undefined **)(param_1 + 0x80) = &LAB_00012880;
    *(undefined **)(param_1 + 0xe0) = &LAB_00010790;
    *(undefined **)(param_1 + 0xe8) = &LAB_00011f80;
    *(undefined **)(param_1 + 0x148) = &LAB_00012c60;
    *(undefined **)(param_1 + 0x120) = &LAB_00012a90;
    *(undefined **)(*(longlong *)(param_1 + 0x30) + 8) = &LAB_00012930;
    *(undefined **)(param_1 + 0x68) = &LAB_00012a70;
  }
  return iVar1;
}

