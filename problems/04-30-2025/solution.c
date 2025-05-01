int findNumbers(int* nums, int numsSize) {
    int ans = 0;

    for(int i = 0; i < numsSize; i++) {
        int digit = 0;
        int num = nums[i];
        while(1) {
            if (num < 1) break;
            num /= 10;
            digit++;
        }

        if(digit % 2 == 0) ans++;
    }

    return ans;
}