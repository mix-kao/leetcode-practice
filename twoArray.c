#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 256

int a[] = {1, 2, 3, 4, 5, 10};
int b[] = {2, 3, 1, 0, 5};



int main(void) {
    size_t a_size = sizeof(a)/sizeof(int);
    size_t b_size = sizeof(b)/sizeof(int);
    int same_flag = 0;

    printf("sizeof a=%ld, b=%ld\n", a_size, b_size);

    for(int i=0; i<a_size; i++) {
        same_flag = 0;
        for(int j=0; j<b_size; j++) {
            if(a[i] == b[j]) { same_flag = 1; break;}
        }
        if(same_flag==0) printf("%d\n", a[i]);
    }
    return 0;
}
