#include <stdio.h>
#include <stdlib.h>
#include "solution.h"

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) {
        return 1;
    }
    int *nums = (int *)malloc(sizeof(int) * n);
    if (!nums) return 1;
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            free(nums);
            return 1;
        }
    }
    int ans = max_subarray_sum(nums, n);
    printf("%d\n", ans);
    free(nums);
    return 0;
}
