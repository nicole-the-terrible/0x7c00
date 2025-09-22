#ifndef __TGA_H
#define __TGA_H

#define TGA_UNCOMPRESSED_RGB 0x0002
#define TGA_SIGNATURE 0x00545047

#include <efi.h>
#include <efilib.h>
#include <stdlib.h>
#include <File/file.h>
#include <Protocols/gop.h>
#include <File/volume.h>

typedef struct {
    UINT8 IdLength;
    UINT8 ColorMapType;
    UINT8 ImageType;
    UINT16 ColorMapOrigin;
    UINT16 ColorMapLength;
    UINT8 ColorMapDepth;
    UINT16 XOrigin;
    UINT16 YOrigin;
    UINT16 Height;
    UINT16 Width;
    UINT8 ImageDescriptor;
    UINT8 BitsPerPixel;
} TGA_HEADER;

UINT32 *TgaParse(unsigned char *ptr, int size);
UINT8 *LoadTgaImage(EFI_HANDLE ImageHandle, CHAR16 *TgaFileName);
VOID DrawTgaImage(UINT8 *FinalTgaBuffer, UINTN TgaImageSize);
EFI_STATUS DrawFinalImageToScreen(EFI_GRAPHICS_OUTPUT_PROTOCOL *GraphicsOutput, UINT32 *ImageData, UINTN Width, UINTN Height);

#endif 