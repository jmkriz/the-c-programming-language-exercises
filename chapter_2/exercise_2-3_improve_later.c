#include <stdio.h>

int htoi(char h[]) {
    int start = 0;
    // if the string starts with 0x or 0X, skip that part
    if (h[0] != '\0' && h[0] == '0' && h[1] != '\0' && (h[1] == 'x' || h[1] == 'X')) {
        start = 2;
    }
    int ret = 0;

    // check that all the characters are valid
    // return -1 if an invalid one is found
    // also check that the
    int count = 0;
    for (int i = start; h[i] != '\0'; i++, count++) {
        if (!(h[i] >= '0' && h[i] <= '9') && !(h[i] >= 'a' && h[i] <= 'f') && !(h[i] >= 'A' && h[i] <= 'F')) {
            return -1;
        }
        if (count > 8) {
            return -2;
        }
    }

    for (int i = start; h[i] != '\0'; i++) {
        ret *= 16;
        if (h[i] >= '0' && h[i] <= '9') {
            ret += (h[i] - '0');
        }
        else if (h[i] >= 'a' && h[i] <= 'f'){
            ret += (h[i] - 'a' + 10);
        }
        else { // else is fine here since we already know the string is only valid characters
            ret += (h[i] - 'A' + 10);
        }
    }

    return ret;
}

int main() {
    // some test cases
    // printing as signed integers to (try to) visualize errors
    printf("%d\n", htoi("0x0"));
    printf("%d\n", htoi("0"));
    printf("%d\n", htoi("f"));
    printf("%d\n", htoi("0X1D"));
    printf("%d\n", htoi("0x1234"));
    printf("%d\n", htoi("1234567"));
    printf("%d\n", htoi("FFFFFFFF")); //-1 due to printing as signed integer
    printf("%d\n", htoi("FFFFFFFFFFFFFFFFFFFFFFFF")); //-2 because it's too long
    printf("%d\n", htoi("asdf")); //-1 because it has invalid characters
}