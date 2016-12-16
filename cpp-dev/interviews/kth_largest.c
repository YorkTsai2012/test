#include <stdio.h>

/*
class Solution {
public:

    static bool cmp(const int a, const int b) {
        return a > b;
    }

    
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};

*/

void swap(int* nums, int i, int j) {
    int tmp = nums[i];
    nums[i] = nums[j];
    nums[j] = tmp; 
}

//考虑partition函数的正确性 
//数组包含相等元素、数组已经有序（递增或递减）
int partition(int* nums, int left, int right) {
    int pivot = nums[left];
    int pivotIndex = left;
    //先把pivot放到一旁 然后分割数组
    swap(nums, pivotIndex, right);
    for (int i = left; i < right; i++) {
        if (nums[i] > pivot) {
            swap(nums, i, pivotIndex);
            pivotIndex++;
        }
    }
    //再把pivot放回正确的位置
    //right 保存的元素 <= pivot
    swap(nums, right, pivotIndex);
    return pivotIndex;
}

int rFind(int* nums, int left, int right, int k) {
    //递归终止条件
    if (left >= right) {
        return nums[left];
    }
    //寻找 第k大的index
    int pivotIndex = partition(nums, left, right);
    if (pivotIndex == k) {
        return nums[pivotIndex];
    } else if (pivotIndex < k ) {
        return rFind(nums, pivotIndex  + 1, right, k);
    } else {
        return rFind(nums, left, pivotIndex - 1, k);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    if (k < 1 || k > numsSize) {
        return -1;
    }
    return rFind(nums, 0, numsSize - 1, k - 1 );
}


int main(int argc, char* argv[]) {
    int nums[] = {4,3,2,1};
    int k = 4;
    printf("%d th largest: %d \n", k, findKthLargest(nums, sizeof(nums)/sizeof(nums[0]), k));
    return 0;
}
