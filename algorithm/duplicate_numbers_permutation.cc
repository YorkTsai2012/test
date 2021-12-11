#include<iostream>
#include<vector>
#include<set>

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

int main(int argc, char* argv[]) {
    std::cout <<"example 1 2 3 4" << std::endl;
    std::vector<int> nums = {1,2,3,4};
    duplicate_numbers_permutations(nums);

    std::cout <<"example 1 1 2 2" << std::endl;
    nums = {1,1,2,2};
    duplicate_numbers_permutations(nums);
    return 0;
}
