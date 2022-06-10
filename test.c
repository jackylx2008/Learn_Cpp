#include <stdio.h>
#include <string.h>
#define Q "\"his hamlet was funny without being vulgar.\""

int main(int argc, char *argv[]) {
    char name[30];
    printf("%s has %ld\n", Q, strlen(Q));
    printf("%2.2e , %2.2f\n", 1201.0, 1201.0);
    printf("sizeof name = %ld\n", sizeof name);

    return 0;
}
