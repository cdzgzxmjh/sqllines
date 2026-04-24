#include <stdio.h>
#include <windows.h>

extern void* CreateParserObject();

BOOL WINAPI DllMain(HINSTANCE h, DWORD reason, LPVOID reserved) {
    printf("DllMain reason=%lu\n", reason); fflush(stdout);
    if(reason == DLL_PROCESS_ATTACH) {
        printf("DLL_PROCESS_ATTACH\n"); fflush(stdout);
        printf("before AllocConsole\n"); fflush(stdout);
        BOOL ok = AllocateConsole();
        printf("AllocateConsole=%d\n", ok); fflush(stdout);
        printf("before mutex check\n"); fflush(stdout);
    }
    return TRUE;
}

int main() {
    printf("main called\n"); fflush(stdout);
    void* p = CreateParserObject();
    printf("CreateParserObject returned %p\n", p); fflush(stdout);
    return 0;
}
