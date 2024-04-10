#include <stdio.h>

int conta_caratteri (char *_s, char _c) {
    if (*_s == '\0')
        return 0;

    if (*_s == _c)
        return 1 + conta_caratteri (_s+1, _c);
    return conta_caratteri(_s+1, _c);
}

int main () {
    char stringa[8] = "ciccio";
    char c = 'c';

    printf("%d", conta_caratteri(stringa, c));
}