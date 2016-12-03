class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //You may assume that each input would have exactly one solution.
        vector<int> idx;
        if (nums.size() < 2) {
            return idx;
        }
        bool found = false;
        int i = -1, j = -1;
        for (i=0; i < nums.size(); i++) {
            for (j = i+1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    found = true;
                    break;
                }
            }
            if (found) break;
        }
        if (found) {
            idx.push_back(i);
            idx.push_back(j);
            return idx;
        }
        return idx;
    }
};
