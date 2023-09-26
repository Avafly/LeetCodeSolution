// LeetCode Problem:
// Title: Longest Palindromic Substring
// URL: https://leetcode.com/problems/longest-palindromic-substring/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 Two conditions for Palindrome:
 1. Ensuring the string is valid, i.e., s <= pos - sz, which means the
    string must start from the address of s. If the address is earlier
    than s, the string is garbled.
 2. Comparing whether char is equal, i.e., *(pos - sz) == *(pos + sz).
 */

char* longestPalindrome(char* s) {
    int max = 1;
    char *max_start = s;
    for(char *pos = s; *pos; ++pos) {
        // check odd length palindromes
        int sz;
        for(sz = 1; s <= pos - sz && *(pos - sz) == *(pos + sz); ++sz);
        if(sz * 2 - 1 > max) {
            max_start = pos - sz + 1;
            max = sz * 2 - 1;
        }
        // check even length palindromes
        for(sz = 0; s <= pos - sz && *(pos - sz) == *(pos + sz + 1); ++sz);
        if(sz * 2 > max) {
            max_start = pos - sz + 1;
            max = sz * 2;
        }
    }
    char *ans = (char*)calloc(max + 1, sizeof(char));
    memcpy(ans, max_start, max);
    return ans;
}

int main(int argc, char **argv) {
    char *s = "slvafhpfjpbqbpcuwxuexavyrtymfydcnvvbvdoitsvumbsvoayefsnusoqmlvatmfzgwlhxtkhdnlmqmyjztlytoxontggyytcezredlrrimcbkyzkrdeshpyyuolsasyyvxfjyjzqksyxtlenaujqcogpqmrbwqbiaweacvkcdxyecairvvhngzdaujypapbhctaoxnjmwhqdzsvpyixyrozyaldmcyizilrmmmvnjbyhlwvpqhnnbausoyoglvogmkrkzppvexiovlxtmustooahwviluumftwnzfbxxrvijjyfybvfnwpjjgdudnyjwoxavlyiarjydlkywmgjqeelrohrqjeflmdyzkqnbqnpaewjdfmdyoazlznzthiuorocncwjrocfpzvkcmxdopisxtatzcpquxyxrdptgxlhlrnwgvee";
    char *ans = longestPalindrome(s);
    printf("%s\n", ans);
    free(ans);

    return 0;
}
