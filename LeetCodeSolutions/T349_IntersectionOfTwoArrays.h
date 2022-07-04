/*
	LeetCode 349 Intersection of Two Arrays | Easy
	Tags: Sorting; 
	Status: AC; 

	Solution: Hash map; 
		Runtime 3 ms, Memory 10.7 MB; Beat 96% / 23%; 
        TC O(len1 + len2), SC O(len1); 
*/

#ifndef LEETCODEANSWER_349
#define LEETCODEANSWER_349

#include <vector>
#include <unordered_map>

using std::vector;
using std::unordered_map;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result = {};
        unordered_map<int, bool> mem = {};

        for (int item : nums1) {
            mem[item] = true;
        }
        for (int item : nums2) {
            if (mem[item]) {
                result.push_back(item);
                mem[item] = false;
            }
        }

        return result;
    }
};

#endif