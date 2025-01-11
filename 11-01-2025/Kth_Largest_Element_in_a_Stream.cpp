/*
Most INtutive:
The `KthLargest` class uses a **min-heap** (priority queue) to efficiently track the `k`th largest element in a dynamic stream of numbers. 

- **Min-Heap of Size `k`**: The heap is maintained with at most `k` elements, ensuring that the smallest element in the heap is always the `k`th largest element in the stream.
- **Initialization**: When the object is initialized, all elements from the input list are added to the heap. If the heap exceeds size `k`, the smallest element is removed.
- **Adding New Scores**: When a new score is added:
  - If the heap has fewer than `k` elements, the score is added directly.
  - If the heap has `k` elements, the smallest element (root) is replaced only if the new score is larger.
- **Efficiency**: The heap ensures that each insertion and removal of the smallest element happens in `O(log k)` time, making it efficient for large streams.

This approach ensures that after every insertion, the `k`th largest element can be retrieved efficiently from the heap’s root.*/
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        } else {
            if (val > minHeap.top()) {
                minHeap.pop();
                minHeap.push(val);
            }
        }
        return minHeap.top();
    }
};