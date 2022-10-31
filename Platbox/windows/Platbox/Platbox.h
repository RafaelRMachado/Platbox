#pragma once
#include <ntddk.h>

#ifndef PAGE_SIZE
	#define PAGE_SIZE 0x1000
#endif

#define IOCTL_ISSUE_SW_SMI  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_EXECUTE_SHELLCODE  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_PCI_HEADER  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_PCI_BYTE  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_PCI_WORD  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_PCI_DWORD  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_PCI_BYTE  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_PCI_WORD  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x807, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_PCI_DWORD  CTL_CODE(FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_GET_PCI_BAR_SIZE CTL_CODE(FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_PHYSICAL_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80A, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_PHYSICAL_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80B, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_READ_MSR CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80C, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_MSR CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80D, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_PATCH_CALLBACK CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80E, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_RESTORE_CALLBACK CTL_CODE(FILE_DEVICE_UNKNOWN, 0x80F, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_REMOVE_ALL_CALLBACKS_HOOKS CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_MAP_PHYSICAL_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_UNMAP_PHYSICAL_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_ALLOC_MEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x813, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_READ_KMEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x814, METHOD_BUFFERED, FILE_ANY_ACCESS)
#define IOCTL_WRITE_KMEM CTL_CODE(FILE_DEVICE_UNKNOWN, 0x815, METHOD_BUFFERED, FILE_ANY_ACCESS)

#define IOCTL_GET_PHYSICAL_RANGES CTL_CODE(FILE_DEVICE_UNKNOWN, 0x816, METHOD_BUFFERED, FILE_ANY_ACCESS)

DRIVER_INITIALIZE    DriverEntry;
DRIVER_UNLOAD        IrpUnloadHandler;
DRIVER_DISPATCH      IrpNotImplementedHandler;

__drv_dispatchType(IRP_MJ_CREATE)            DRIVER_DISPATCH    IrpCreateHandler;
__drv_dispatchType(IRP_MJ_CLOSE)             DRIVER_DISPATCH    IrpCloseHandler;
__drv_dispatchType(IRP_MJ_DEVICE_CONTROL)    DRIVER_DISPATCH    IrpDeviceIoCtlHandler;

VOID        IrpUnloadHandler(IN PDRIVER_OBJECT DriverObject);
NTSTATUS    IrpCloseHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS    IrpCreateHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS    IrpDeviceIoCtlHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS    IrpNotImplementedHandler(IN PDEVICE_OBJECT DeviceObject, IN PIRP Irp);
NTSTATUS    DriverEntry(IN PDRIVER_OBJECT DriverObject, IN PUNICODE_STRING RegistryPath);

NTSTATUS	SendSWSmiHandler(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ExecuteShellcodeHandler(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPCIHeaderHandler(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPCIByte(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPCIWord(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPCIDword(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WritePCIByte(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WritePCIWord(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WritePCIDword(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPCIBarSize(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadPhysicalMemory(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WritePhysicalMemory(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadMSR(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WriteMSR(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS PatchCallback(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS RestoreCallback(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS RemoveAllCallbackHooks(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS MapPhysicalMemory(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS UnmapPhysicalMemory(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS AllocateUserMemory(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS ReadKMem(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);
NTSTATUS WriteKMem(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);

NTSTATUS GetPhysicalMemoryRanges(IN PIRP Irp, IN PIO_STACK_LOCATION IrpSp);

typedef char BYTE;



typedef struct _SW_SMI_CALL {
	UINT8 SwSmiNumber; // 0xb2
	UINT8 SwSmiData; // 0xb3
	UINT64 rax;
	UINT64 rbx;
	UINT64 rcx;
	UINT64 rdx;
	UINT64 rsi;
	UINT64 rdi;
} SW_SMI_CALL, *PSW_SMI_CALL;

void _swsmi(
	unsigned int smi_code_data,
	unsigned int rax_value,
	unsigned int rbx_value,
	unsigned int rcx_value, 
	unsigned int rdx_value,
	unsigned int rsi_value,
	unsigned int rdi_value
);


typedef struct _READ_PCI_CONFIGURATION_SPACE_CALL {
	UINT8 bus;
	UINT8 device;
	UINT8 function;
} READ_PCI_CONFIGURATION_SPACE_CALL, *PREAD_PCI_CONFIGURATION_SPACE_CALL;

void _read_pci_compatible_configuration_space(
	UINT8 bus,
	UINT8 device,
	UINT8 function,
	PVOID pOut
);

typedef struct _READ_PCI_DATA_CALL {
	UINT8 bus;
	UINT8 device;
	UINT8 function;
	UINT8 offset;
} READ_PCI_DATA_CALL, *PREAD_PCI_DATA_CALL;

void _read_pci_byte(UINT32 CF8, PVOID pOut);
void _read_pci_word(UINT32 CF8, PVOID pOut);
void _read_pci_dword(UINT32 CF8, PVOID pOut);
void _read_pci_bar_size(UINT32 CF8, PVOID pOut);

typedef struct _WRITE_PCI_DATA_CALL {
	UINT8 bus;
	UINT8 device;
	UINT8 function;
	UINT8 offset;
	UINT32 value;
} WRITE_PCI_DATA_CALL, *PWRITE_PCI_DATA_CALL;

void _write_pci_byte(UINT32 CF8, UINT32 value);
void _write_pci_word(UINT32 CF8, UINT32 value);
void _write_pci_dword(UINT32 CF8, UINT32 value);

typedef struct _READ_PHYSICAL_MEM_CALL {
	PHYSICAL_ADDRESS address;
} READ_PHYSICAL_MEM_CALL, *PREAD_PHYSICAL_MEM_CALL;

typedef struct _WRITE_PHYSICAL_MEM_CALL {
	PHYSICAL_ADDRESS address;
	UINT32 size;
	UCHAR data[0x1000];
} WRITE_PHYSICAL_MEM_CALL, *PWRITE_PHYSICAL_MEM_CALL;

struct alloc_user_physmem {
	UINT64 va;
	UINT64 pa;
	UINT32 size;
};


void _rdmsr(UINT32 msr, PVOID pOut);
void _wrmsr(UINT32 msr, UINT64 value);
typedef struct _READ_MSR_CALL {
	UINT32 msr;
} READ_MSR_CALL, *PREAD_MSR_CALL;

typedef struct _WRITE_MSR_CALL {
	UINT32 msr;
	UINT64 value;
} WRITE_MSR_CALL, *PWRITE_MSR_CALL;




typedef struct _MAP_PHYSICAL_MEM_CALL {
	PHYSICAL_ADDRESS phys_address;
} MAP_PHYSICAL_MEM_CALL, *PMAP_PHYSICAL_MEM_CALL;

typedef struct _UNMAP_PHYSICAL_MEM_CALL {
	PVOID user_address;
} UNMAP_PHYSICAL_MEM_CALL, *PUNMAP_PHYSICAL_MEM_CALL;

typedef struct _USER_MAPPED_MEM {
	PHYSICAL_ADDRESS phys_address;
	PVOID kernel_va;
	PMDL mdl;	
	PVOID user_address;
	BOOLEAN is_allocation;
	struct _USER_MAPPED_MEM *next;
} USER_MAPPED_MEM, *PUSER_MAPPED_MEM;


typedef struct _READ_KMEM_IN {
	UINT64 vaddr;
	UINT32 size;
} READ_KMEM_IN, *PREAD_KMEM_IN;

typedef struct _WRITE_KMEM_IN {
	UINT64 target_vaddr;
	UINT64* src_vaddr;
	UINT32 size;
} WRITE_KMEM_IN, * PWRITE_KMEM_IN;