/*
	LeetCode 976 Largest Perimeter Triangle | Easy
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 49 ms, Memory 21.9 MB; Beat 60% / 22%;
		TC O(nlogn), SC O(logn) [function iteration stack];
*/

#ifndef LEETCODEANSWER_976
#define LEETCODEANSWER_976

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());

        size_t longest = 0;
        size_t len = nums.size() - 2;
        int cache = 0;

        while (longest < len) {
            cache = nums.at(longest + 1) + nums.at(longest + 2);

            if (nums.at(longest++) < cache) {
                return nums.at(--longest) + cache;
            }
        }

        return 0;
    }
};

#endif