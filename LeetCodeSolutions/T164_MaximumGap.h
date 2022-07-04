/*
	LeetCode 164 Maximum Gap | Hard
	Tags: Sorting;
	Status: AC;

	Solution: REAL bucket sort
		Runtime 159 ms, Memory 76.9 MB; Beat 98% / 52%;
		TC O(), SC O();
*/

#ifndef LEETCODEANSWER_164
#define LEETCODEANSWER_164

#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int maxNum = 0;
        int minNum = *min_element(nums.begin(), nums.end());

        for (int& item : nums) {
            // normalize the vector; 
            item -= minNum;

            if (maxNum < item) { // find maxNum; 
                maxNum = item;
            }
        }

        if (maxNum == minNum) {
            return 0;
        }

        int gap = maxNum / (nums.size() - 1) + 1;
        int bucketNum = maxNum / gap + 1;
        vector<int> bucketUpper(bucketNum, -1);
        vector<int> bucketLower(bucketNum, -1);

        for (int item : nums) {
            size_t index = item / gap;

            if (bucketUpper.at(index) == -1) {
                bucketUpper.at(index) = item;
                bucketLower.at(index) = item;
            }
            else {
                if (bucketUpper.at(index) < item) {
                    bucketUpper.at(index) = item;
                }
                if (bucketLower.at(index) > item) {
                    bucketLower.at(index) = item;
                }
            }
        }

        int result = bucketUpper.at(0) - bucketLower.at(0);
        int preMax = bucketUpper.at(0);
        for (size_t index = 1; index < bucketNum; ++index) {
            if (bucketUpper.at(index) == -1) {
                continue;
            }

            if (result < bucketLower.at(index) - preMax) {
                result = bucketLower.at(index) - preMax;
            }
            preMax = bucketUpper.at(index);
        }

        return result;
    }
};

#endif