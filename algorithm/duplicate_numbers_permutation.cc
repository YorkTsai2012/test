#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

void backtrack(std::vector<std::vector<int> >& result, std::vector<int>& tmp, std::vector<int>& nums, int full_size) {
    if (tmp.size() >= full_size) {
        result.push_back(tmp);
        return;
    }
    // choose
    std::set<int> unique;
    unique.insert(nums.begin(), nums.end());
    for (auto iter : unique) {
        tmp.push_back(iter);
        auto position = tmp.size() - 1;
        auto sub_nums = nums;
        for (auto it = sub_nums.begin(); it != sub_nums.end(); it++) {
            if (iter == *it) {
                sub_nums.erase(it);
                break;
            }
        }
        backtrack(result, tmp, sub_nums, full_size);
        tmp.erase(tmp.begin() + position);
    }
}

void duplicate_numbers_permutations(std::vector<int> nums) {
    std::vector<std::vector<int> > result;
    std::vector<int> tmp;
    backtrack(result, tmp, nums, nums.size());
    for (auto outer = result.begin(); outer != result.end(); outer++) {
        for (auto inner = outer->begin(); inner != outer->end(); inner++) {
            std::cout << *inner << "\t";
        }
        std::cout << "\n";
    }
}


// used: value copy
void backtrack2(std::vector<std::vector<int> >& result,
                std::vector<int>& tmp,
                std::vector<int>& nums,
                std::vector<bool> used) {
    if (tmp.size() >= nums.size()) {
        result.push_back(tmp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        // current choosed or
        // previous not choosed and the same as current
        if (used[i] ||
            (i > 0 && !used[i-1] && nums[i] == nums[i-1])) {
            continue;
        }
        tmp.push_back(nums[i]);
        // if nums using value copy, do not need pos
        auto pos = tmp.size() - 1;
        used[i] = true;
        backtrack2(result, tmp, nums, used);
        tmp.erase(tmp.begin() + pos);
        used[i] = false;
    }
}

void duplicate_numbers_permutations2(std::vector<int>& nums) {
    std::vector<std::vector<int> > result;
    std::vector<int> tmp;
    std::vector<bool> used;

    std::sort(nums.begin(), nums.end());

    for (auto i : nums) {
        used.push_back(false);
    }
    backtrack2(result, tmp, nums, used);
    for (auto outer : result) {
        for (auto inner : outer) {
            std::cout << inner << "\t";
        }
        std::cout << "\n";
    }
}

int main(int argc, char* argv[]) {
    std::cout <<"example 1 4 3 2" << std::endl;
    std::vector<int> nums = {1,4,3,2};
    duplicate_numbers_permutations2(nums);

    std::cout <<"example 1 3 1 3 1" << std::endl;
    std::vector<int> nums2 = {1,3,1,3,1};
    duplicate_numbers_permutations2(nums2);
    return 0;
}
