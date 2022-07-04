/*
	LeetCode 295 Find Median from Data Stream | Hard
	Tags: Sorting;
	Status: AC;

	Solution: Heap sort; 
		Runtime 410 ms, Memory 117.1 MB; Beat 72% / 65%;
		TC O(logn), SC O(n);
*/

#ifndef LEETCODEANSWER_295
#define LEETCODEANSWER_295

#include <vector>
#include <queue>

using std::vector;
using std::priority_queue; // max heap by default; <data, vector<data>, greater<data>> for min heap; 

class MedianFinder {
public:
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if (this->maxHeap_.empty() || num < this->maxHeap_.top()) {
            this->maxHeap_.push(num);
        }
        else {
            this->minHeap_.push(num);
        }

        if (this->maxHeap_.size() > this->minHeap_.size() + 1) {
            this->minHeap_.push(this->maxHeap_.top());
            this->maxHeap_.pop();
        }
        if (this->minHeap_.size() > this->maxHeap_.size() + 1) {
            this->maxHeap_.push(this->minHeap_.top());
            this->minHeap_.pop();
        }

        return;
    }

    double findMedian()
    {
        if (this->maxHeap_.size() == this->minHeap_.size()) {
            if (this->maxHeap_.empty()) {
                return 0;
            }

            return (this->maxHeap_.top() + this->minHeap_.top()) / 2.0;
        }
        else {
            return (this->maxHeap_.size() > this->minHeap_.size()) ? this->maxHeap_.top() : this->minHeap_.top();
        }
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> minHeap_;
    priority_queue<int> maxHeap_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
#endif