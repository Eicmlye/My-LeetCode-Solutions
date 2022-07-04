/*
	LeetCode 389 Find the Difference | Easy
	Tags: Sorting; 
	Status: AC; 

	Solution 1: Quick sort; 
		Runtime 7 ms, Memory 6.6 MB; Beat 30% / 67%; 
		TC O(nlogn), SC O(logn) [function iteration stack]; 

    Solution 2: Hash map; 
        Runtime 4 ms, Memory 6.6 MB; Beat 59% / 87%; 
        TC O(n), SC O(n); 

    Solution 3: Sum up to get the difference; 
        https://leetcode.com/problems/find-the-difference/discuss/1751509/C%2B%2B-or-Time%3A-100-or-Memory%3A-98.6-or-3-lines-or-Propagate-the-difference-or-ASCII
        Runtime 0 s, Memory 6.7 MB; 
*/

#ifndef LEETCODEANSWER_389
#define LEETCODEANSWER_389

#include <vector>
#include <string>
#include <unordered_map>

using std::pair; 
using std::string; 
using std::unordered_map; 

class Solution {
public:
    // Solution 1; 
    char findTheDifference_1(string s, string t) {
        if (s.empty()) {
            return t.at(0);
        }

        size_t len = s.size();
        QuickSort(s, 0, len - 1);
        QuickSort(t, 0, t.size() - 1);

        char diff = '\0';
        for (size_t index = 0; index < len; ++index) {
            diff = t.at(index);
            if (diff != s.at(index)) {
                return diff;
            }
        }

        return t.at(len);
    }

    // Solution 2; 
    char findTheDifference_2(string s, string t) {
        unordered_map<char, unsigned int> mem = {};
        for (char ch : t) {
            ++mem[ch];
        }
        for (char ch : s) {
            --mem[ch];
        }
        for (pair<char, unsigned int> pr : mem) {
            if (pr.second > 0) {
                return pr.first;
            }
        }
    }

    // Solution 3: 
    char findTheDifference_3(string s, string t)
    {
        size_t len = s.size();

        for (size_t index = 0; index < len; ++index) {
            t.at(index + 1) += t.at(index) - s.at(index);
        }

        return t.at(t.size() - 1);
    }

private:
    void QuickSort(string& str, size_t low, size_t high)
    {
        if (low < high) {
            size_t pivotPos = Partition(str, low, high);
            if (pivotPos > low + 1) {
                QuickSort(str, low, pivotPos - 1);
            }
            if (pivotPos + 1 < high) {
                QuickSort(str, pivotPos + 1, high);
            }
        }

        return;
    }

    size_t Partition(string& str, size_t low, size_t high)
    {
        size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
        char pivot = str.at(ind);
        str.at(ind) = str.at(low);
        str.at(low) = pivot;

        while (low < high) {
            while (low < high && str.at(high) >= pivot) {
                --high;
            }
            str.at(low) = str.at(high);

            while (low < high && str.at(low) <= pivot) {
                ++low;
            }
            str.at(high) = str.at(low);
        }
        str.at(low) = pivot;

        return low;
    }
};

#endif