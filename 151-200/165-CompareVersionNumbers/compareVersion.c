#include <stdlib.h>
#include <string.h>

int compareVersion(char * version1, char * version2){
    const char delim[] = ".";
    char *rev1, *rev2;
    int revNum1, revNum2;

    rev1 = strtok_r(version1, delim, &version1);
    rev2 = strtok_r(version2, delim, &version2);

    while (rev1 || rev2) {
        if (rev1) {
            revNum1 = atoi(rev1);
            rev1 = strtok_r(version1, delim, &version1);
        } else revNum1 = 0;
        if (rev2) {
            revNum2 = atoi(rev2);
            rev2 = strtok_r(version2, delim, &version2);
        } else revNum2 = 0;

        if (revNum1 > revNum2)
            return 1;
        else if (revNum1 < revNum2)
            return -1;
    }

    return 0;
}
