#include "solution.h"

int max_subarray_sum(const int *nums, int n) {
    if (n <= 0) return 0;
    int max_so_far = nums[0];
    int curr_max = nums[0];
    for (int i = 1; i < n; i++) {
        curr_max = (nums[i] > curr_max + nums[i]) ? nums[i] : (curr_max + nums[i]);
        if (curr_max > max_so_far) {
            max_so_far = curr_max;
        }
    }
    return max_so_far;
}
