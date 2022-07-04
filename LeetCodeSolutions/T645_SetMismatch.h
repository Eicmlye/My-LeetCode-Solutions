/*
	LeetCode 645 Set Mismatch | Easy
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 29 ms, Memory 22.2 MB; Beat 95% / 48%;
		TC O(n), SC O(n);
*/

#ifndef LEETCODEANSWER_645
#define LEETCODEANSWER_645

#include <vector>

using std::vector;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> cache(nums.size());
        size_t index = 0;
        int dup = -1;
        int miss = -1;

        for (; index < nums.size(); ++index) {
            ++cache.at(nums.at(index) - 1);
        }
        for (index = 0; index < nums.size(); ++index) {
            if (cache.at(index) == 2) {
                dup = index + 1;
            }
            if (cache.at(index) == 0) {
                miss = index + 1;
            }

            if (dup != -1 && miss != -1) {
                return { dup, miss };
            }
        }

        return {};
    }
};

#endif