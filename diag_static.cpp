#include <stdio.h>
#include <windows.h>

// 模拟 applog.h
#define _log (*(void*)0)

int main() {
    printf("step1: entering main\n"); fflush(stdout);
    AllocConsole();
    printf("step2: after AllocConsole\n"); fflush(stdout);
    return 0;
}
