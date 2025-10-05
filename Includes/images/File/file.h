#ifned __FILE_H
#define __FILE_H

#include <efi.h>
#include <efilib.h>

UINT64 FileSize(EFI_FILE_HANDLE FileHandle); 
UINT8 *ReadFile(EFI_FILE_HANDLE Volume, CHAR16 *FileName)

#endif 