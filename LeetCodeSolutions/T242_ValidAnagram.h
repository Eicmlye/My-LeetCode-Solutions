/*
    LeetCode 242 Valid Anagram | Easy
    Tags: Sorting; 
    Status: AC; 

    Solution1: Hash map; 
        Runtime 14 ms, Memory 7.4 MB; Beat 54% / 46%; 
        TC O(sLen + tLen), SC O(sLen); 

    Solution 2: Quick sort; 
        Runtime 366 ms, Memory 7.4 MB; Beat 5% / 8%; 
        TC O(maxLen logmaxLen), SC O(logmaxLen) [function iterartion stack]; 
*/

#ifndef LEETCODEANSWER_242
#define LEETCODEANSWER_242

#include <vector>
#include <string>
#include <unordered_map>

using std::pair; 
using std::string; 
using std::unordered_map;

class Solution {
public:
    // Solution 1;
    bool isAnagram_1(string s, string t) 
    {
        unordered_map<char, unsigned int> mem = {};

        for (char ch : s) {
            ++mem[ch];
        }
        for (char ch : t) {
            if (mem.count(ch) == 0 || mem[ch] == 0) {
                return false;
            }
            --mem[ch];
        }

        for (pair<char, unsigned int> pr : mem) {
            if (pr.second > 0) {
                return false;
            }
        }

        return true;
    }

    // Solution 2; 
    bool isAnagram_2(string s, string t) 
    {
        QuickSort(s, 0, s.size() - 1);
        QuickSort(t, 0, t.size() - 1);

        return s == t;
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