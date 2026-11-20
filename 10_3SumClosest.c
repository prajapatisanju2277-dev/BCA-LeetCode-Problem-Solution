int cmpClosest(const void *a, const void *b) {
    int x = *(int*)a, y = *(int*)b;
    return (x > y) - (x < y);
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmpClosest);

    long long best = (long long)nums[0] + nums[1] + nums[2];

    for(int i = 0; i < numsSize - 2; i++) {
        int left = i + 1;
        int right = numsSize - 1;

        while(left < right) {
            long long sum = (long long)nums[i] +
                            nums[left] + nums[right];

            if(llabs(sum - target) < llabs(best - target))
                best = sum;

            if(sum < target)
                left++;
            else if(sum > target)
                right--;
            else
                return (int)sum;
        }
    }

    return (int)best;
}