#pragma once
#include "global.h"


/* Hook Kernel Callbacks */
void parse_kernel_hook_operation(int argc, char **argv);
typedef struct _PATCH_CALLBACK {
	PVOID targetAddress;
	UINT32 contentSize;
	PVOID patchContent;
} PATCH_CALLBACK, *PPATCH_CALLBACK;

typedef struct _RESTORE_CALLBACK {
	PVOID targetAddress;
} RESTORE_CALLBACK, *PRESTORE_CALLBACK;

/* Page Tables */
void __get_nt_base(UINT64* base);
void find_pml4_idx();
UINT64 get_pxe_address(UINT64 address);
void resolve_nt_functions(void);

typedef NTSTATUS(NTAPI *_NtAllocateVirtualMemory)
(
  HANDLE ProcessHandle,
  PVOID* BaseAddress,
  ULONG zerobytes,
  PSIZE_T RegionSize,
  ULONG AllocationType,
  ULONG Protect
);

typedef NTSTATUS(NTAPI *_NtFreeVirtualMemory)
(
  HANDLE  ProcessHandle,
  PVOID   *BaseAddress,
  PSIZE_T RegionSize,
  ULONG   FreeType
);

extern _NtAllocateVirtualMemory NtAllocateVirtualMemory;
extern _NtFreeVirtualMemory NtFreeVirtualMemory;



#define MAX_E820_DESCRIPTORS 64
#define IOCTL_GET_EFI_MEMORY_MAP CTL_CODE(FILE_DEVICE_UNKNOWN, 0x814, METHOD_BUFFERED, FILE_ANY_ACCESS)

#pragma pack (push, 8)			/*  in case driver and application
                        get compiled differently  */
typedef struct _E820_DESCRIPTOR {
    UINT64 Base;
    UINT64 Size;
    ULONG Type;
    ULONG ExtAttr;                      // not actually used by WINLOAD
} E820_DESCRIPTOR, * PE820_DESCRIPTOR;

typedef struct _E820_MAP {
    ULONG Count;
    E820_DESCRIPTOR Descriptors[MAX_E820_DESCRIPTORS];
} E820_MAP, * PE820_MAP;

#pragma pack (pop)

struct ACPISDTHeader {
  char Signature[4];
  uint32_t Length;
  uint8_t Revision;
  uint8_t Checksum;
  char OEMID[6];
  char OEMTableID[8];
  uint32_t OEMRevision;
  uint32_t CreatorID;
  uint32_t CreatorRevision;
};

struct GenericAddressStructure
{
  uint8_t AddressSpace;
  uint8_t BitWidth;
  uint8_t BitOffset;
  uint8_t AccessSize;
  uint64_t Address;
};

typedef struct { 
   ACPISDTHeader  Header; 
   DWORD          FIRMWARE_CTRL; 
   DWORD          DSDT; 
   BYTE           Reserved; 
   BYTE           Preferred_PM_Profile; 
   WORD           SCI_INT; 
   DWORD          SMI_CMD; 
   BYTE           ACPI_ENABLE; 
   BYTE           ACPI_DISABLE; 
   BYTE           S4BIOS_REQ; 
   BYTE           PSTATE_CNT; 
   DWORD          PM1a_EVT_BLK; 
   DWORD          PM1b_EVT_BLK; 
   DWORD          PM1a_CNT_BLK; 
   DWORD          PM1b_CNT_BLK; 
   DWORD          PM2_CNT_BLK; 
   DWORD          PM_TMR_BLK; 
   DWORD          GPE0_BLK; 
   DWORD          GPE1_BLK; 
   BYTE           PM1_EVT_LEN; 
   BYTE           PM1_CNT_LEN; 
   BYTE           PM2_CNT_LEN; 
   BYTE           PM_TMR_LEN; 
   BYTE           GPE0_BLK_LEN; 
   BYTE           GPE1_BLK_LEN; 
   BYTE           GPE1_BASE; 
   BYTE           CST_CNT; 
   WORD           P_LVL2_LAT; 
   WORD           P_LVL3_LAT; 
   WORD           FLUSH_SIZE; 
   WORD           FLUSH_STRIDE; 
   BYTE           DUTY_OFFSET; 
   BYTE           DUTY_WIDTH; 
   BYTE           DAY_ALRM; 
   BYTE           MON_ALRM; 
   BYTE           CENTURY; 
   WORD           IAPC_BOOT_ARCH; 
   BYTE           Reserved2; 
   DWORD          Flags; 
   struct GenericAddressStructure     RESET_REG; 
   BYTE           RESET_VALUE; 
   BYTE           Reserved3[3]; 
   DWORD64          X_FIRMWARE_CTRL; 
   DWORD64          X_DSDT; 
   struct GenericAddressStructure     X_PM1a_EVT_BLK; 
   struct GenericAddressStructure     X_PM1b_EVT_BLK; 
   struct GenericAddressStructure     X_PM1a_CNT_BLK; 
   struct GenericAddressStructure     X_PM1b_CNT_BLK; 
   struct GenericAddressStructure     X_PM2_CNT_BLK; 
   struct GenericAddressStructure     X_PM_TMR_BLK; 
   struct GenericAddressStructure     X_GPE0_BLK; 
   struct GenericAddressStructure     X_GPE1_BLK; 
} RTACPI_FADT, RTACPI_FACP;

UINT32 GetFADT_Address();