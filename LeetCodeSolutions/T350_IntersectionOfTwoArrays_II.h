/*
	LeetCode 350 Intersecion of Two Arrays II | Easy
	Tags: Sorting; 
	Status: AC; 

	Solution: Hash map; 
		Runtime 5 ms, Memory 10.7 MB; Beat 76% / 20%; 
		TC O(len1 + len2), SC O(len1); 
*/

#ifndef LEETCODEANSWER_350
#define LEETCODEANSWER_350

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = {};
        unordered_map<int, unsigned int> mem = {};

        for (int item : nums1) {
            ++mem[item];
        }
        for (int item : nums2) {
            if (mem[item]) {
                result.push_back(item);
                --mem[item];
            }
        }

        return result;
    }
};

#endif