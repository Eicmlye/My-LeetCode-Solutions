/*
	LeetCode 888 Fair Candy Swap | Easy
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 109 ms, Memory 52.2 MB; Beat 82% / 20%;
		TC O(), SC O();
*/

#ifndef LEETCODEANSWER_888
#define LEETCODEANSWER_888

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int diff = 0;
        unordered_map<int, bool> boxB = {};

        for (size_t index = 0; index < aliceSizes.size(); ++index) {
            diff += aliceSizes.at(index);
        }
        for (size_t jndex = 0; jndex < bobSizes.size(); ++jndex) {
            boxB[bobSizes.at(jndex)] = true;
            diff -= bobSizes.at(jndex);
        }

        diff /= 2;
        for (size_t index = 0; index < aliceSizes.size(); ++index) {
            if (boxB[aliceSizes.at(index) - diff]) {
                return { aliceSizes.at(index), aliceSizes.at(index) - diff };
            }
        }

        return {};
    }
};

#endif