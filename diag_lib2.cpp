#include <stdio.h>
#include <windows.h>

// extern from sqlparser.a (C++ mangled)
extern void* CreateParserObject();

int main(int argc, char** argv) {
    printf("step1: main argc=%d\n", argc); fflush(stdout);
    AllocConsole();
    printf("step2: after AllocConsole\n"); fflush(stdout);
    void* p = CreateParserObject();
    printf("step3: CreateParserObject=%p\n", p); fflush(stdout);
    return 0;
}
