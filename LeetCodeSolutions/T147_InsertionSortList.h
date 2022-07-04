/*
	LeetCode 147 Insertion Sort List | Medium
	Tags: Sorting;
	Status: AC;

	Solution:
		Runtime 17 ms, Memory 9.7 MB; Beat 92% / 36%;
		TC O(n^2), SC O(1);
*/

#ifndef LEETCODEANSWER_147
#define LEETCODEANSWER_147

#include <vector>

using std::vector;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head->next == nullptr) {
            return head;
        }

        ListNode* header = new ListNode(0, head);
        ListNode* mov = head->next;
        ListNode* pred = head;
        ListNode* orderedTail = head;

        while (mov != nullptr) {
            if (mov->val > orderedTail->val) {
                orderedTail = mov;
            }
            else {
                // initialize probe; 
                pred = header;
                // pop mov; 
                orderedTail->next = mov->next;
                // find insert position; 
                while (pred->next->val < mov->val) {
                    pred = pred->next;
                }
                // insert mov; 
                mov->next = pred->next;
                pred->next = mov;
            }

            // get next mov; 
            mov = orderedTail->next;
        }

        head = header->next;
        delete header;

        return head;
    }
}; 

#endif