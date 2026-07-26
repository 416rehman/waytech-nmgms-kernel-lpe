
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00010790(longlong param_1,ulonglong param_2,ulonglong param_3,ulonglong param_4)

{
  int *piVar1;
  int iVar2;
  longlong lVar3;
  undefined4 *puVar4;
  byte bVar5;
  undefined uVar6;
  undefined4 uVar7;
  undefined2 *puVar8;
  ushort uVar9;
  undefined2 *puVar10;
  undefined4 uVar11;
  uint uVar12;
  undefined4 uVar13;
  ulonglong uVar14;
  longlong lVar15;
  ulonglong uVar16;
  undefined2 uStack_438;
  
  uVar14 = 0;
  uVar16 = 0;
  if (param_1 != DAT_00012520) {
    lVar3 = *(longlong *)(param_1 + 0x40);
    LOCK();
    *(int *)(lVar3 + 0x68) = *(int *)(lVar3 + 0x68) + 1;
    UNLOCK();
    if (*(char *)(lVar3 + 5) == '\0') {
      *(char *)(param_2 + 0x43) = *(char *)(param_2 + 0x43) + '\x01';
      *(longlong *)(param_2 + 0xb8) = *(longlong *)(param_2 + 0xb8) + 0x48;
      uVar7 = IofCallDriver(*(undefined8 *)(lVar3 + 0x18),param_2);
    }
    else {
      uVar7 = 0xc0000056;
      *(undefined8 *)(param_2 + 0x38) = 0;
      *(undefined4 *)(param_2 + 0x30) = 0xc0000056;
      IofCompleteRequest(param_2,param_2 & 0xffffffffffffff00);
    }
    LOCK();
    piVar1 = (int *)(lVar3 + 0x68);
    iVar2 = *piVar1;
    *piVar1 = *piVar1 + -1;
    UNLOCK();
    if (iVar2 != 1) {
      return uVar7;
    }
    KeSetEvent(lVar3 + 0x50,0,param_3 & 0xffffffffffffff00);
    return uVar7;
  }
  lVar3 = *(longlong *)(param_2 + 0xb8);
  uVar12 = *(uint *)(lVar3 + 0x18);
  puVar10 = (undefined2 *)0x222524;
  uVar11 = 0;
  uVar7 = 0;
  if (uVar12 < 0x222525) {
    if (uVar12 == 0x222524) {
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0x18;
          goto LAB_0001144d;
        }
        goto LAB_000118ee;
      }
    }
    else {
      puVar10 = (undefined2 *)0x222484;
      if (uVar12 < 0x222485) {
        if (uVar12 == 0x222484) {
          lVar15 = *(longlong *)(param_2 + 0x18);
          uVar12 = *(uint *)(lVar3 + 8);
          if ((lVar15 != 0) && (uVar12 != 0)) {
            uVar16 = uVar14;
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar16 = 0x206d6457;
            puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar10 != (undefined2 *)0x0) {
              *(undefined *)((longlong)puVar10 + 0x81) = 10;
              goto LAB_00010aa4;
            }
            goto LAB_00010ae9;
          }
        }
        else {
          puVar10 = (undefined2 *)0x1087f;
          switch(uVar12) {
          case 0x222400:
            if (*(undefined8 **)(param_2 + 0x18) != (undefined8 *)0x0) {
              puVar10 = (undefined2 *)0x100000;
              ObReferenceObjectByHandle
                        (**(undefined8 **)(param_2 + 0x18),0x100000,0,param_4 & 0xffffffffffffff00,
                         &DAT_00012528,0);
              DAT_000123f3 = 1;
              DAT_00012400 = 0;
              DAT_000124e8 = 0;
              uVar7 = 0;
              goto LAB_00011910;
            }
            break;
          default:
            goto switchD_0001087d_caseD_222401;
          case 0x222404:
            if (DAT_00012528 != 0) {
              ObfDereferenceObject();
              DAT_00012528 = 0;
            }
            DAT_000123f3 = 0;
            goto LAB_00011910;
          case 0x222408:
            puVar4 = *(undefined4 **)(param_2 + 0x18);
            if ((puVar4 != (undefined4 *)0x0) && (*(int *)(lVar3 + 8) != 0)) {
              bVar5 = KeAcquireSpinLockRaiseToDpc(&DAT_00012530);
              uVar16 = (ulonglong)(DAT_000124e8 + 1U);
              if (0x31 < DAT_000124e8 + 1U) {
                uVar16 = uVar14;
              }
              DAT_000124e8 = (int)uVar16;
              *puVar4 = *(undefined4 *)(&DAT_00012420 + uVar16 * 4);
              puVar10 = (undefined2 *)(ulonglong)bVar5;
              KeReleaseSpinLock(&DAT_00012530,puVar10);
              uVar16 = 4;
              goto LAB_00011910;
            }
            break;
          case 0x222420:
            if (*(undefined4 **)(param_2 + 0x18) != (undefined4 *)0x0) {
              _DAT_000124f0 = **(undefined4 **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222424:
            if (*(undefined4 **)(param_2 + 0x18) != (undefined4 *)0x0) {
              DAT_000123c4 = **(undefined4 **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222440:
            if (*(undefined4 **)(param_2 + 0x18) != (undefined4 *)0x0) {
              DAT_000123c8 = **(undefined4 **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222444:
            if (*(undefined **)(param_2 + 0x18) != (undefined *)0x0) {
              DAT_000123c1 = **(undefined **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222448:
            if (*(undefined **)(param_2 + 0x18) != (undefined *)0x0) {
              DAT_000123f5 = **(undefined **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222454:
            if (*(undefined **)(param_2 + 0x18) != (undefined *)0x0) {
              DAT_000123f6 = **(undefined **)(param_2 + 0x18);
              uVar7 = uVar11;
              goto LAB_00011910;
            }
            break;
          case 0x222480:
            puVar10 = *(undefined2 **)(param_2 + 0x18);
            uVar13 = *(undefined4 *)(lVar3 + 0x10);
            if (puVar10 != (undefined2 *)0x0) {
              RtlCopyMemory(&uStack_438,puVar10,uVar13);
              if (DAT_000123e0 == 0) goto LAB_00011910;
              uVar14 = 0x206d6457;
              puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
              if (puVar10 != (undefined2 *)0x0) {
                *(undefined *)((longlong)puVar10 + 0x81) = 9;
                goto LAB_000111a3;
              }
              goto LAB_000111e5;
            }
          }
        }
      }
      else {
        puVar10 = (undefined2 *)0x10b51;
        switch(uVar12) {
        case 0x222498:
          puVar10 = *(undefined2 **)(param_2 + 0x18);
          uVar13 = *(undefined4 *)(lVar3 + 0x10);
          if (puVar10 != (undefined2 *)0x0) {
            RtlCopyMemory(&uStack_438,puVar10,uVar13);
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar14 = 0x206d6457;
            puVar10 = (undefined2 *)0x0;
            puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
            *(undefined *)((longlong)puVar8 + 0x81) = 3;
            goto LAB_000112a0;
          }
          break;
        default:
switchD_0001087d_caseD_222401:
          uVar16 = uVar14;
          uVar7 = 0xc00000bb;
          goto LAB_00011910;
        case 0x22249c:
          lVar15 = *(longlong *)(param_2 + 0x18);
          uVar12 = *(uint *)(lVar3 + 8);
          if ((lVar15 != 0) && (uVar12 != 0)) {
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar16 = 0x206d6457;
            puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar10 != (undefined2 *)0x0) {
              *(undefined *)((longlong)puVar10 + 0x81) = 4;
              goto LAB_0001144d;
            }
            goto LAB_000118ee;
          }
          break;
        case 0x2224a0:
          puVar10 = *(undefined2 **)(param_2 + 0x18);
          uVar13 = *(undefined4 *)(lVar3 + 0x10);
          if (puVar10 != (undefined2 *)0x0) {
            RtlCopyMemory(&uStack_438,puVar10,uVar13);
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar14 = 0x206d6457;
            puVar10 = (undefined2 *)0x0;
            puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
            *(undefined *)((longlong)puVar8 + 0x81) = 1;
            goto LAB_000112a0;
          }
          break;
        case 0x2224a4:
          lVar15 = *(longlong *)(param_2 + 0x18);
          uVar12 = *(uint *)(lVar3 + 8);
          if ((lVar15 != 0) && (uVar12 != 0)) {
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar16 = 0x206d6457;
            puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar10 != (undefined2 *)0x0) {
              *(undefined *)((longlong)puVar10 + 0x81) = 2;
              goto LAB_0001144d;
            }
            goto LAB_000118ee;
          }
          break;
        case 0x2224a8:
          puVar10 = *(undefined2 **)(param_2 + 0x18);
          if (puVar10 != (undefined2 *)0x0) {
            RtlCopyMemory(&uStack_438,puVar10,*(undefined4 *)(lVar3 + 0x10));
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar14 = 0x206d6457;
            puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar10 == (undefined2 *)0x0) goto LAB_000111e5;
            puVar10[1] = 0x17;
            *puVar10 = 0x88;
            *(undefined4 *)(puVar10 + 0x12) = 0;
            *(undefined8 *)(puVar10 + 0x18) = 0;
            *(undefined8 *)(puVar10 + 0x14) = 0;
            *(undefined *)(puVar10 + 0x40) = 0;
            *(undefined *)((longlong)puVar10 + 0x81) = 7;
            uVar9 = (ushort)(byte)uStack_438;
LAB_000111cd:
            puVar10[0x41] = uVar9;
            puVar10[0x42] = 0;
            *(undefined4 *)(puVar10 + 0x10) = 0;
            *(undefined8 *)(puVar10 + 0x1c) = 0;
            goto LAB_000111e5;
          }
          break;
        case 0x2224ac:
          lVar15 = *(longlong *)(param_2 + 0x18);
          uVar12 = *(uint *)(lVar3 + 8);
          if ((lVar15 != 0) && (uVar12 != 0)) {
            if (DAT_000123e0 != 0) {
              uVar16 = 0x206d6457;
              puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
              uStack_438._0_1_ = 0;
              uStack_438._1_1_ = 0;
              if (puVar10 != (undefined2 *)0x0) {
                puVar10[1] = 0x17;
                *puVar10 = 0x88;
                *(uint *)(puVar10 + 0x12) = uVar12;
                *(undefined8 *)(puVar10 + 0x18) = 0;
                *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
                *(undefined *)(puVar10 + 0x40) = 0;
                *(undefined *)((longlong)puVar10 + 0x81) = 8;
                puVar10[0x41] = 0;
                puVar10[0x42] = 0;
                *(undefined4 *)(puVar10 + 0x10) = 1;
                *(undefined8 *)(puVar10 + 0x1c) = 0;
              }
              FUN_00010690(DAT_00012408,puVar10,uVar16);
            }
            goto LAB_000118ee;
          }
          break;
        case 0x222508:
          if (*(undefined4 **)(param_2 + 0x18) != (undefined4 *)0x0) {
            _DAT_000124f4 = **(undefined4 **)(param_2 + 0x18);
            uVar7 = uVar11;
            goto LAB_00011910;
          }
          break;
        case 0x222510:
          lVar15 = *(longlong *)(param_2 + 0x18);
          uVar12 = *(uint *)(lVar3 + 8);
          if ((lVar15 != 0) && (uVar12 != 0)) {
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar16 = 0x206d6457;
            puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            uStack_438._0_1_ = 0;
            uStack_438._1_1_ = 0;
            if (puVar10 != (undefined2 *)0x0) {
              *(undefined *)((longlong)puVar10 + 0x81) = 0;
              goto LAB_0001144d;
            }
            goto LAB_000118ee;
          }
          break;
        case 0x222520:
          puVar10 = *(undefined2 **)(param_2 + 0x18);
          uVar13 = *(undefined4 *)(lVar3 + 0x10);
          if (puVar10 != (undefined2 *)0x0) {
            RtlCopyMemory(&uStack_438,puVar10,uVar13);
            if (DAT_000123e0 == 0) goto LAB_00011910;
            uVar14 = 0x206d6457;
            puVar10 = (undefined2 *)0x0;
            puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
            if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
            *(undefined *)((longlong)puVar8 + 0x81) = 0x17;
            goto LAB_000112a0;
          }
        }
      }
    }
  }
  else {
    puVar10 = (undefined2 *)0x10ef3;
    switch(uVar12) {
    case 0x222528:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar14 = 0x206d6457;
        puVar10 = (undefined2 *)0x0;
        puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
        *(undefined *)((longlong)puVar8 + 0x81) = 0x19;
LAB_000112a0:
        puVar8[1] = 0x17;
        *puVar8 = 0x88;
        *(undefined4 *)(puVar8 + 0x12) = uVar13;
        *(undefined8 *)(puVar8 + 0x18) = 0;
        *(undefined2 **)(puVar8 + 0x14) = &uStack_438;
        *(undefined *)(puVar8 + 0x40) = 0;
        puVar8[0x41] = 0;
        puVar8[0x42] = 0;
        *(undefined4 *)(puVar8 + 0x10) = 0;
        *(undefined8 *)(puVar8 + 0x1c) = 0;
        puVar10 = puVar8;
        FUN_00010690(DAT_00012408,puVar8,uVar14);
        ExFreePool(puVar8);
        uVar7 = uVar11;
        goto LAB_00011910;
      }
      break;
    default:
      goto switchD_0001087d_caseD_222401;
    case 0x22252c:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0x1a;
LAB_0001144d:
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(uint *)(puVar10 + 0x12) = uVar12;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          puVar10[0x41] = 0;
          puVar10[0x42] = 0;
          *(undefined4 *)(puVar10 + 0x10) = 1;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
          FUN_00010690(DAT_00012408,puVar10,uVar16);
          ExFreePool(puVar10);
          puVar10 = &uStack_438;
          RtlCopyMemory(lVar15,puVar10,uVar12);
          uVar16 = (ulonglong)uVar12;
          uVar7 = uVar11;
          goto LAB_00011910;
        }
LAB_000118ee:
        uVar16 = (ulonglong)uVar12;
        puVar10 = &uStack_438;
        RtlCopyMemory(lVar15,puVar10,uVar12);
        goto LAB_00011910;
      }
      break;
    case 0x222530:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 != 0) {
          uVar14 = 0x206d6457;
          puVar10 = (undefined2 *)0x0;
          puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
          if (puVar8 != (undefined2 *)0x0) {
            puVar8[1] = 0x17;
            *puVar8 = 0x88;
            *(undefined4 *)(puVar8 + 0x12) = uVar13;
            *(undefined8 *)(puVar8 + 0x18) = 0;
            *(undefined2 **)(puVar8 + 0x14) = &uStack_438;
            *(undefined *)(puVar8 + 0x40) = 0;
            *(undefined *)((longlong)puVar8 + 0x81) = 0x1b;
            puVar8[0x41] = 0;
            puVar8[0x42] = 0;
            *(undefined4 *)(puVar8 + 0x10) = 0;
            *(undefined8 *)(puVar8 + 0x1c) = 0;
            puVar10 = puVar8;
            FUN_00010690(DAT_00012408,puVar8,uVar14);
            ExFreePool(puVar8);
            uVar7 = uVar11;
          }
        }
        goto LAB_00011910;
      }
      break;
    case 0x222534:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0x1c;
          goto LAB_0001144d;
        }
        goto LAB_000118ee;
      }
      break;
    case 0x222540:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar14 = 0x206d6457;
        puVar10 = (undefined2 *)0x0;
        puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
        *(undefined *)((longlong)puVar8 + 0x81) = 0x13;
        goto LAB_000112a0;
      }
      break;
    case 0x222544:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0x14;
          goto LAB_0001144d;
        }
        goto LAB_000118ee;
      }
      break;
    case 0x222548:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar14 = 0x206d6457;
        puVar10 = (undefined2 *)0x0;
        puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar8 == (undefined2 *)0x0) goto LAB_00011910;
        *(undefined *)((longlong)puVar8 + 0x81) = 5;
        goto LAB_000112a0;
      }
      break;
    case 0x22254c:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 6;
          goto LAB_0001144d;
        }
        goto LAB_000118ee;
      }
      break;
    case 0x222550:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,*(undefined4 *)(lVar3 + 0x10));
        DAT_000123f7 = (byte)uStack_438;
        uVar7 = uVar11;
        goto LAB_00011910;
      }
      break;
    case 0x222554:
      uVar12 = *(uint *)(lVar3 + 8);
      if ((*(longlong *)(param_2 + 0x18) != 0) && (uVar12 != 0)) {
        puVar10 = (undefined2 *)&DAT_000123f7;
        RtlCopyMemory(*(longlong *)(param_2 + 0x18),&DAT_000123f7,uVar12);
        uVar16 = (ulonglong)uVar12;
        uVar7 = uVar11;
        goto LAB_00011910;
      }
      break;
    case 0x222558:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar14 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0xb;
LAB_000111a3:
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(undefined4 *)(puVar10 + 0x12) = uVar13;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          uVar9 = (ushort)(char)DAT_000123f7;
          goto LAB_000111cd;
        }
LAB_000111e5:
        FUN_00010690(DAT_00012408,puVar10,uVar14);
        uVar7 = uVar11;
        goto LAB_00011910;
      }
      break;
    case 0x22255c:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0xc;
LAB_00010aa4:
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(uint *)(puVar10 + 0x12) = uVar12;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          puVar10[0x41] = (short)(char)DAT_000123f7;
          puVar10[0x42] = 0;
          *(undefined4 *)(puVar10 + 0x10) = 1;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
        }
LAB_00010ae9:
        FUN_00010690(DAT_00012408,puVar10,uVar16);
        uVar6 = KeAcquireSpinLockRaiseToDpc(&DAT_00012530);
        KeReleaseSpinLock(&DAT_00012530,uVar6);
        goto LAB_000118ee;
      }
      break;
    case 0x222568:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar14 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0xf;
          goto LAB_000111a3;
        }
        goto LAB_000111e5;
      }
      break;
    case 0x22256c:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          *(undefined *)((longlong)puVar10 + 0x81) = 0x10;
          goto LAB_00010aa4;
        }
        goto LAB_00010ae9;
      }
      break;
    case 0x222570:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar13 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar13);
        if (DAT_000123e0 != 0) {
          uVar14 = 0x206d6457;
          puVar10 = (undefined2 *)0x0;
          puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
          if (puVar8 != (undefined2 *)0x0) {
            puVar8[1] = 0x17;
            *puVar8 = 0x88;
            *(undefined4 *)(puVar8 + 0x12) = uVar13;
            *(undefined8 *)(puVar8 + 0x18) = 0;
            *(undefined2 **)(puVar8 + 0x14) = &uStack_438;
            *(undefined *)(puVar8 + 0x40) = 0;
            *(undefined *)((longlong)puVar8 + 0x81) = 0x11;
            puVar8[0x41] = 1;
            puVar8[0x42] = 0;
            *(undefined4 *)(puVar8 + 0x10) = 0;
            *(undefined8 *)(puVar8 + 0x1c) = 0;
            puVar10 = puVar8;
            FUN_00010690(DAT_00012408,puVar8,uVar14);
            ExFreePool(puVar8);
            uVar7 = uVar11;
          }
        }
        goto LAB_00011910;
      }
      break;
    case 0x222574:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar11 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar11);
        if (DAT_000123e0 != 0) {
          uVar14 = 0x206d6457;
          puVar10 = (undefined2 *)0x0;
          puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
          if (puVar8 != (undefined2 *)0x0) {
            puVar8[1] = 0x17;
            *puVar8 = 0x88;
            *(undefined4 *)(puVar8 + 0x12) = uVar11;
            *(undefined8 *)(puVar8 + 0x18) = 0;
            *(undefined2 **)(puVar8 + 0x14) = &uStack_438;
            *(undefined *)(puVar8 + 0x40) = 0;
            *(undefined *)((longlong)puVar8 + 0x81) = 0x11;
            puVar8[0x41] = 2;
            puVar8[0x42] = 0;
            *(undefined4 *)(puVar8 + 0x10) = 0;
            *(undefined8 *)(puVar8 + 0x1c) = 0;
            puVar10 = puVar8;
            FUN_00010690(DAT_00012408,puVar8,uVar14);
            ExFreePool(puVar8);
          }
        }
        goto LAB_00011910;
      }
      break;
    case 0x222578:
      puVar10 = *(undefined2 **)(param_2 + 0x18);
      uVar11 = *(undefined4 *)(lVar3 + 0x10);
      if (puVar10 != (undefined2 *)0x0) {
        RtlCopyMemory(&uStack_438,puVar10,uVar11);
        if (DAT_000123e0 != 0) {
          uVar14 = 0x206d6457;
          puVar10 = (undefined2 *)0x0;
          puVar8 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
          if (puVar8 != (undefined2 *)0x0) {
            puVar8[1] = 0x17;
            *puVar8 = 0x88;
            *(undefined4 *)(puVar8 + 0x12) = uVar11;
            *(undefined8 *)(puVar8 + 0x18) = 0;
            *(undefined2 **)(puVar8 + 0x14) = &uStack_438;
            *(undefined *)(puVar8 + 0x40) = 0;
            *(undefined *)((longlong)puVar8 + 0x81) = 0x11;
            puVar8[0x41] = 3;
            puVar8[0x42] = 0;
            *(undefined4 *)(puVar8 + 0x10) = 0;
            *(undefined8 *)(puVar8 + 0x1c) = 0;
            puVar10 = puVar8;
            FUN_00010690(DAT_00012408,puVar8,uVar14);
            ExFreePool(puVar8);
          }
        }
        goto LAB_00011910;
      }
      break;
    case 0x222580:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(uint *)(puVar10 + 0x12) = uVar12;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          *(undefined *)((longlong)puVar10 + 0x81) = 0x12;
          puVar10[0x41] = 1;
          puVar10[0x42] = 0;
          *(undefined4 *)(puVar10 + 0x10) = 1;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
          FUN_00010690(DAT_00012408,puVar10,uVar16);
          ExFreePool(puVar10);
          puVar10 = &uStack_438;
          RtlCopyMemory(lVar15,puVar10,uVar12);
          uVar16 = (ulonglong)uVar12;
          goto LAB_00011910;
        }
        goto LAB_000118ee;
      }
      break;
    case 0x222584:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(uint *)(puVar10 + 0x12) = uVar12;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          *(undefined *)((longlong)puVar10 + 0x81) = 0x12;
          puVar10[0x41] = 2;
          puVar10[0x42] = 0;
          *(undefined4 *)(puVar10 + 0x10) = 1;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
          FUN_00010690(DAT_00012408,puVar10,uVar16);
          ExFreePool(puVar10);
          puVar10 = &uStack_438;
          RtlCopyMemory(lVar15,puVar10,uVar12);
          uVar16 = (ulonglong)uVar12;
          goto LAB_00011910;
        }
        goto LAB_000118ee;
      }
      break;
    case 0x222588:
      lVar15 = *(longlong *)(param_2 + 0x18);
      uVar12 = *(uint *)(lVar3 + 8);
      if ((lVar15 != 0) && (uVar12 != 0)) {
        if (DAT_000123e0 == 0) goto LAB_00011910;
        uVar16 = 0x206d6457;
        puVar10 = (undefined2 *)ExAllocatePoolWithTag(0,0x88);
        if (puVar10 != (undefined2 *)0x0) {
          puVar10[1] = 0x17;
          *puVar10 = 0x88;
          *(uint *)(puVar10 + 0x12) = uVar12;
          *(undefined8 *)(puVar10 + 0x18) = 0;
          *(undefined2 **)(puVar10 + 0x14) = &uStack_438;
          *(undefined *)(puVar10 + 0x40) = 0;
          *(undefined *)((longlong)puVar10 + 0x81) = 0x12;
          puVar10[0x41] = 3;
          puVar10[0x42] = 0;
          *(undefined4 *)(puVar10 + 0x10) = 1;
          *(undefined8 *)(puVar10 + 0x1c) = 0;
          FUN_00010690(DAT_00012408,puVar10,uVar16);
          ExFreePool(puVar10);
        }
        goto LAB_000118ee;
      }
    }
  }
  uVar7 = 0xc0000017;
LAB_00011910:
  *(ulonglong *)(param_2 + 0x38) = uVar16;
  *(undefined4 *)(param_2 + 0x30) = uVar7;
  IofCompleteRequest(param_2,(ulonglong)puVar10 & 0xffffffffffffff00);
  return uVar7;
}



// ======================================== //
//   INTERNAL SUBFUNCTIONS CALLED BY DISPATCH   //
// ======================================== //


undefined8 FUN_00010690(longlong param_1,undefined8 param_2,ulonglong param_3)

{
  longlong lVar1;
  int iVar2;
  longlong lVar3;
  ulonglong uVar4;
  ulonglong uVar5;
  undefined4 local_58;
  undefined4 local_54;
  undefined local_50 [16];
  undefined local_40 [32];
  
  lVar1 = *(longlong *)(param_1 + 0x40);
  KeInitializeEvent(local_40,0,param_3 & 0xffffffffffffff00);
  uVar5 = 0;
  uVar4 = 0;
  lVar3 = IoBuildDeviceIoControlRequest
                    (0x220003,*(undefined8 *)(lVar1 + 0x18),0,0,0,0,1,local_40,local_50);
  if (lVar3 == 0) {
    return 0xc000009a;
  }
  *(undefined8 *)(*(longlong *)(lVar3 + 0xb8) + -0x40) = param_2;
  iVar2 = IofCallDriver(*(undefined8 *)(lVar1 + 0x18),lVar3);
  if (iVar2 == 0x103) {
    local_58 = 0xff676980;
    local_54 = 0xffffffff;
    uVar5 = uVar5 & 0xffffffffffffff00;
    uVar4 = uVar4 & 0xffffffffffffff00;
    iVar2 = KeWaitForSingleObject(local_40,0,uVar4,uVar5,&local_58);
    if (iVar2 == 0x102) {
      IoCancelIrp(lVar3);
      KeWaitForSingleObject(local_40,0,uVar4 & 0xffffffffffffff00,uVar5 & 0xffffffffffffff00,0);
    }
  }
  return 0;
}

