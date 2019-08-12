#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function for finding
// elements which are there
// in a[] but not in b[].
void findMissing(int a[], int b[], size_t a_size, size_t b_size) {
    int same_flag = 0;
    for(int i=0; i<a_size; i++) {
        same_flag = 0;
        for(int j=0; j<b_size; j++) {
            if(a[i] == b[j]) { same_flag = 1; break;}
        }
        if(!same_flag) printf("%d\n", a[i]);
    }

}


int main(void) {
    
    int a[] = {1, 2, 3, 4, 5, 10};
    int b[] = {2, 3, 1, 0, 5};

    size_t a_size = sizeof(a)/sizeof(a[0]);
    size_t b_size = sizeof(b)/sizeof(b[0]);

    printf("sizeof a=%ld, b=%ld\n", a_size, b_size);
    findMissing(a, b, a_size, b_size);

    return 0;
}
