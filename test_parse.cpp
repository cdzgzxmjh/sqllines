#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("=== argc=%d ===\n", argc);
    for(int i=1; i<argc; i++) printf("argv[%d]=[%s]\n", i, argv[i]);

    // Build comline
    static char comline[4096];
    int pos = 0;
    for(int i=1; i<argc; i++) {
        int len = strlen(argv[i]);
        for(int j=0; j<len; j++) comline[pos++] = argv[i][j];
        if(i < argc-1) comline[pos++] = ' ';
    }
    comline[pos] = '\0';
    printf("\n=== comline ===\n[%s]\n\n", comline);

    // LoadString parse
    const char* PARAMETER_START_TOKEN = "-";
    const char* cur = comline;
    while(*cur)
    {
        // Skip to parameter
        while(*cur && strncmp(cur, PARAMETER_START_TOKEN, 1) != 0) cur++;
        if(!(*cur)) break;

        // Get name until =, CR, NL, TAB, or SPACE
        char name[256];
        int ni = 0;
        name[ni++] = *cur++;
        while(*cur && *cur != '=' && *cur != '\r' && *cur != '\n' && *cur != '\t' && *cur != ' ')
            name[ni++] = *cur++;
        name[ni] = '\0';

        // Skip space
        while(*cur == ' ' || *cur == '\t') cur++;

        // Get value
        char value[1024];
        int vi = 0;
        while(*cur && *cur != '\r' && *cur != '\n')
            value[vi++] = *cur++;
        value[vi] = '\0';

        printf("  name=[%s] value=[%s]\n", name, value);

        // Skip EOL
        while(*cur == '\r' || *cur == '\n') cur++;
    }
    return 0;
}
