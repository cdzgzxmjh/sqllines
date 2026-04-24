#include <stdio.h>
#include <windows.h>
int main() {
    printf("1-start\n"); fflush(stdout);
    AllocConsole();
    printf("2-console\n"); fflush(stdout);
    return 0;
}
