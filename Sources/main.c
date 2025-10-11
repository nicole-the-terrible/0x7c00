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
    UINT8 *ImageTgaBuffer;
    UINTN ImageTgaBufferSize;

    Status = InitGraphicsOutputProtocol();
    if(EFI_ERROR(Status)) {
        Print(L"Failed to init graphics out protocol! Reason: %r\n", Status); // mark for edit

    }

    Status = InitBootConfig(ImageHandle);
    if(!EFI_ERROR(Status)) {
        Print(L"Config init!\n");
        //Print(L"Kernel path : %.*a\n", GetConfigValue("KERNEL_PATH=")) 
        // MARK FOR EDIT
    } else {
        Print(L"Check init boot.cgl! Reason: %r\n", Status);
    }

    Print(L"Check tga header... \n");

    ImageTgaBuffer = LoadTgaImage(ImageHandle, L"image.tga");
    if(ImageTgaBuffer != NULL) {
        Print(L"Tga imange header loaded successfully!\n");

        ImageTgaBufferSize = sizeof(ImageTgaBuffer);

        DrawTgaImage(ImageTgaBuffer, ImageTgaBufferSize);
    }

    while(1){};
    
    return EFI_SUCCESS
}