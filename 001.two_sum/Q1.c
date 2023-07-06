#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

typedef struct {
    int key;
    int value;
    UT_hash_handle hh;
} IntIntHash;

void addItem(IntIntHash **hash_table, int key, int value) {
    IntIntHash *item = (IntIntHash *)malloc(sizeof(IntIntHash));
    item->key = key;
    item->value = value;
    HASH_ADD_INT(*hash_table, key, item);
}

IntIntHash *findItem(IntIntHash **hash_table, int key) {
    IntIntHash *item;
    HASH_FIND_INT(*hash_table, &key, item);
    return item;
}

void deleteItem(IntIntHash **hash_table, IntIntHash *item) {
    HASH_DEL(*hash_table, item);
    free(item);
}

void clearTable(IntIntHash **hash_table) {
    IntIntHash *current_item, *tmp;
    HASH_ITER(hh, *hash_table, current_item, tmp) {
        HASH_DEL(*hash_table, current_item);
        free(current_item);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *ans = (int *)calloc(2, sizeof(int));
    IntIntHash *hash_table = NULL;
    
    for(int i = 0; i < numsSize; ++i) {
        addItem(&hash_table, nums[i], i);
    }
    
    for(int i = 0; i < numsSize; ++i) {
        IntIntHash *item = findItem(&hash_table, target - nums[i]);
        if(item && item->value != i) {
            ans[0] = i;
            ans[1] = item->value;
            break;
        }
    }
    
    // free the hash table
    clearTable(&hash_table);
    
    return ans;
}

int main(int argc, char **argv) {
    int nums[] = {2,7,11,15};
    int numsSize = sizeof(nums) / sizeof(int);
    int target = 9;
    int returnSize;
    
    int *ans = twoSum(nums, numsSize, target, &returnSize);
    printf("%d %d\n", ans[0], ans[1]);
    
    free(ans);
    
    return 0;
}
