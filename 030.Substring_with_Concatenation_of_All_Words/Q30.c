
// LeetCode Problem:
// Title: Substring with Concatenation of All Words
// URL: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char *key;
    int count;
} WordArr;

// BKDRHash
unsigned long BKDRHash(char *str) {
    unsigned long h = 0;
    for(; *str; ++str) {
        h = h * 31 + *str;
    }
    return h;
}

int findBucket(WordArr *arr, char *key, int size) {
    int h = BKDRHash(key) % size;
    if(arr[h].key == NULL) {       // key is not found, create a new hash bucket
        arr[h].key = strdup(key);
    }
    while(strcmp(arr[h].key, key)) {
        h = (h + 1) % size;

        if(arr[h].key == NULL) {   // key is not found, create a new hash bucket
            arr[h].key = strdup(key);
        }
    }
    return h;
}

bool isKeyExist(WordArr *arr, char *key, int size) {
    int h = BKDRHash(key) % size;
    int init_h = h;
    if(arr[h].key == NULL) {
        return false;
    }
    while(strcmp(arr[h].key, key)) {
        h = (h + 1) % size; // traverse the entire hash table and does not find this key
        if(h == init_h) {
            return false;
        }
        if(arr[h].key == NULL) {
            return false;
        }
    }
    return true;
}

// add a word to hash table
void addWord(WordArr *arr, char *key, int size, int num) {
    int h = findBucket(arr, key, size);
    arr[h].count += num;
}

void freeWordArr(WordArr *arr, int size) {
    for(int i = 0; i < size; ++i) {
        free(arr[i].key);
    }
    free(arr);
}

void clearWordArr(WordArr *arr, int size) {
    for(int i = 0; i < size; ++i) {
        arr[i].count = 0;
    }
}

int *findSubstring(char *s, char **words, int wordsSize, int *returnSize){
    int *ans = (int *)calloc(strlen(s), sizeof(int));
    *returnSize = 0;
    
    // take the word as key, and the count number as value
    WordArr *wordCount = (WordArr *)calloc(wordsSize, sizeof(WordArr));
    for(int i = 0; i < wordsSize; ++i) {
        addWord(wordCount, words[i], wordsSize, 1);
    }
    
    int wordSize = strlen(words[0]);
    WordArr *currWordCount = (WordArr *)calloc(wordsSize, sizeof(WordArr));
    char *word = (char *)calloc(wordSize + 1, sizeof(char));
    char *leftWord = (char *)calloc(wordSize + 1, sizeof(char));
    for(int i = 0; i < wordSize; ++i) {
        int start = i;
        int count = 0;
        clearWordArr(currWordCount, wordsSize);
        
        for(int j = i; j <= (int)strlen(s) - wordSize; j += wordSize) {
            strncpy(word, s + j, wordSize);
            if(isKeyExist(wordCount, word, wordsSize)) {
                int h = findBucket(currWordCount, word, wordsSize);
                ++currWordCount[h].count;
                ++count;
                
                while(currWordCount[h].count > wordCount[findBucket(wordCount, word, wordsSize)].count) {
                    strncpy(leftWord, s + start, wordSize);
                    --currWordCount[findBucket(currWordCount, leftWord, wordsSize)].count;
                    --count;
                    start += wordSize;
                }
                
                if(count == wordsSize) {
                    ans[(*returnSize)++] = start;
                    strncpy(leftWord, s + start, wordSize);
                    --currWordCount[findBucket(currWordCount, leftWord, wordsSize)].count;
                    --count;
                    start += wordSize;
                }
            }
            else {
                clearWordArr(currWordCount, wordsSize);
                count = 0;
                start = j + wordSize;
            }
        }
    }
    
    freeWordArr(wordCount, wordsSize);
    freeWordArr(currWordCount, wordsSize);
    free(word);
    free(leftWord);
    
    return ans;
}

int main(int argc, char **argv) {
    char *s = "barfoofoobarthefoobarman";
    char *words[] = {"bar","foo","the"};
    int wordsSize = sizeof(words) / sizeof(words[0]);
    int *returnSize = (int *)calloc(1, sizeof(int));
    
    int *ans = findSubstring(s, words, wordsSize, returnSize);
    
    for(int i = 0; i < *returnSize; ++i) {
        printf("%d\n", ans[i]);
    }
    
    /* free the memory */
    free(ans);
    free(returnSize);
    return 0;
}