#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>

#define TESTSTATUS 0

#if TESTSTATUS
#include "T88_MergeSortedArray.h"
#endif

using std::cout; 
using std::endl; 
using std::vector; 
using std::pair; 
using std::stack; 
using std::queue;
using std::priority_queue;
using std::string; 
using std::unordered_map; 

#if TESTSTATUS
enum class ReturnValue { SUCCESS = 0, FAILURE };
ReturnValue ret_val = ReturnValue::SUCCESS;

unsigned int passed_test = 0; 
unsigned int valid_test = 0; 

template <typename Function, typename AnsType>
bool test(unsigned int ques_num, Function sol, AnsType ans); 

ReturnValue main(void) {



	return ret_val; 
}

template <typename Function, typename AnsType>
bool test(unsigned int ques_num, Function sol, AnsType ans)
{

}
#endif

#if !TESTSTATUS
int maximumGap(vector<int>& nums);

#if 0
void QuickSort(vector<int>& nums, size_t low, size_t high);
size_t Partition(vector<int>& nums, size_t low, size_t high);
void QuickSort(string& str, size_t low, size_t high); 
size_t Partition(string& str, size_t low, size_t high); 
#endif 

class MedianFinder {
public:
    MedianFinder()
    {

    }

    void addNum(int num)
    {
        if (maxHeap.empty() || num > maxHeap.top()) {
            minHeap.push(num);
        }
        else {
            maxHeap.push(num);
        }

        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }

        return;
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size()) {
            if (maxHeap.empty()) {
                return 0;
            }

            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        else {
            return (maxHeap.size() > minHeap.size()) ? maxHeap.top() : minHeap.top();
        }
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> maxHeap;
    priority_queue<int> minHeap;
};

int main(void) {
#if 0
    vector<int> nums = { 3,6,9,1 };
    cout << maximumGap(nums);
    cout << endl;
#endif
#if 1
    MedianFinder* obj = new MedianFinder();
    obj->addNum(-1);
    cout << obj->findMedian() << endl;
    obj->addNum(-2);
    cout << obj->findMedian() << endl;
    obj->addNum(-3);
    cout << obj->findMedian() << endl;
    obj->addNum(-4);
    cout << obj->findMedian() << endl;
    obj->addNum(-5);
    cout << obj->findMedian() << endl;
    delete obj;
#endif
	return 0; 
}

#if 0
void QuickSort(vector<int>& nums, size_t low, size_t high)
{
    if (low < high) {
        size_t pivotPos = Partition(nums, low, high);
        if (pivotPos > low + 1) { // size_t should not be negative; 
            QuickSort(nums, low, pivotPos - 1);
        }
        if (pivotPos + 1 < high) {
            QuickSort(nums, pivotPos + 1, high);
        }
    }

    return;
}

size_t Partition(vector<int>& nums, size_t low, size_t high)
{
    // choose pivot randomly; 
    // rand() generates integer between 0 and INT_MAX; 
    size_t ind = low + (size_t)((high - low) * (rand() / (double)(RAND_MAX)));
    int pivot = nums.at(ind);
    // standardize pivot to the first element; 
    nums.at(ind) = nums.at(low);
    nums.at(low) = pivot;


    while (low < high) {
        while (low < high && nums.at(high) >= pivot) {
            --high;
        }
        nums.at(low) = nums.at(high);

        while (low < high && nums.at(low) <= pivot) {
            ++low;
        }
        nums.at(high) = nums.at(low);
    }

    nums.at(low) = pivot;

    return low;
}
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
#endif

#endif