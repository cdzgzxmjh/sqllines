#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;

#define PARAMETER_START_TOKEN '-'

struct Str {
    static const char* SkipSpaces(const char* s) {
        while(*s && (*s==' '||*s=='\t')) s++;
        return s;
    }
    static void TrimTrailingSpaces(string& s) {
        while(!s.empty() && (s.back()==' '||s.back()=='\t'||s.back()=='\r'))
            s.pop_back();
    }
};

int main(int argc, char** argv) {
    printf("=== argc=%d ===\n", argc);
    for(int i=1; i<argc; i++) printf("argv[%d]=[%s]\n", i, argv[i]);
    
    string comline;
    for(int i=1; i<argc; i++) {
        comline += argv[i];
        comline += " ";
    }
    printf("\n=== comline ===\n[%s]\n\n", comline.c_str());
    
    const char* cur = comline.c_str();
    printf("=== parsed params ===\n");
    while(*cur) {
        string name, value;
        cur = Str::SkipSpaces(cur);
        if(!*cur || *cur=='\r'||*cur=='\n'||*cur=='\t') break;
        while(*cur && *cur!='=' && *cur!='\r'&&*cur!='\n'&&*cur!='\t') {
            if(*cur==PARAMETER_START_TOKEN && !name.empty()) break;
            name += *cur++;
        }
        Str::TrimTrailingSpaces(name);
        if(*cur=='=') cur++;
        cur = Str::SkipSpaces(cur);
        while(*cur && *cur!='\r'&&*cur!='\n'&&*cur!='\t') {
            if(*cur==PARAMETER_START_TOKEN && cur[-1]==' ' && cur[1]!=' ') break;
            value += *cur++;
        }
        Str::TrimTrailingSpaces(value);
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        printf("  name=[%s] value=[%s]\n", name.c_str(), value.c_str());
    }
    return 0;
}
