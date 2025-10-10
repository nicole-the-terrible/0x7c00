#include <efi.h>
#include <efilib.h>
#include <Protocols/gop.h>
#include <File/volume.h>
#include <File/file.h>
#include <Images/png.h>
#include <Images/tga.h>
#include <config.h>

EFI_STATUS 
EFIAPI
efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    InitializeLib(ImageHandle, SystemTable);
    
    EFI_STATUS Status;
    UINT8 *Imagebuffer;
    UINTN ImagebufferSize;

    Status = InitGraphicsOutputProtocol();
    if(EFI_ERROR(Status)) {
        Print(L"Failed to init graphics out protocol! Reason: %r\n", Status); // mark for edit

    }

    Status = InitBootConfig(ImageHandle);
    if(!EFI_ERROR(Status)) {
        Print(L"Config init!\n");
        //Print(L"Kernel path : %.*a\n", GetConfigValue("KERNEL_PATH=")) 
        // MARK FOR EDIT
    }
    
};