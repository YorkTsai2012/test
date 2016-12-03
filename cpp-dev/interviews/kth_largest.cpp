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
