#include <stdio.h>
#include <stdlib.h>

/**
 * The key idea of this problem is: treat the entries with the same first character
 * as a zone. Identify zone where k resides when permutation size is n, and append
 * first character of that zone to the answer. Then, update k and n. Next, find
 * the interval where k resides when the size is n-1, and continue this process
 * until n=1.
 */

char * getPermutation(int n, int k){
    int factValue[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    k -= 1;

    int count = 0;
    char *ans = (char *)calloc(n + 1, sizeof(char));
    char *arr = (char *)calloc(n + 1, sizeof(char));
    for(int i = 0; i < n; ++i) {
        arr[i] = '1' + i;
    }

    while(n > 1) {
        // find zone where k located
        int zone = (int)(k / factValue[n - 1]);
        // add this char to answer and delete this char
        ans[count++] = arr[zone];
        // delete the previous zones
        for(int i = zone; i < n - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        // update k and n
        k -= factValue[n - 1] * zone;
        --n;
    }

    ans[count] = arr[0];

    free(arr);
    return ans;
}

int main(int argc, char **argv) {
    int n = 4;
    int k = 15;

    char *ans = getPermutation(n, k);
    printf("%s\n", ans);

    free(ans);
    return 0;
}