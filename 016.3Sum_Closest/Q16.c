#include <stdlib.h>
#include <stdio.h>
//#include <math.h>

int compare(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int threeSumClosest(int* nums, int numsSize, int target){
    int closest = nums[0]+nums[1]+nums[2];

    qsort(nums, numsSize, sizeof(int), compare);

    for(int i=0; i<numsSize-2; ++i) {
        while(i>0 && i<numsSize && nums[i]==nums[i-1])
            ++i;
        int j = i + 1;
        int l = numsSize - 1;

        closest = abs(target-closest)<abs(target-(nums[0]+nums[1]+nums[2])) ? closest : nums[0]+nums[1]+nums[2];

        while (j < l) {
            int sum = nums[i] + nums[j] + nums[l];

            if(sum < target) {
                ++j;
                closest = abs(target-closest)<abs(target-sum) ? closest : sum;
            }
            else if(sum > target) {
                --l;
                closest = abs(target-closest)<abs(target-sum) ? closest : sum;
            }
            else {
                return target;
            }

            while(j-1!=i && j<l && nums[j]==nums[j-1])
                ++j;
            while(l<numsSize-1 && j<l && nums[l]==nums[l+1])
                --l;
        }
    }

    return closest;
}

int main(int argc, char **argv) {

    int nums[] = {-1,2,1,-4};
    int target = 1;

    printf("%d\n", threeSumClosest(nums, sizeof(nums)/sizeof(int), target));

    return 0;
}