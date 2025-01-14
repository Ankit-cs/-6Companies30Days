/*
INTUTION:
The key intuition behind merging `k` sorted linked-lists is to use a **min-heap (priority queue)**. Here's the step-by-step breakdown:

1. **Min-Heap Usage**: A min-heap helps us efficiently find the smallest element from the `k` sorted linked-lists. By maintaining the smallest element at the top of the heap, we can always pop the smallest node from the heap and add it to the result list.

2. **Heap Initialization**: Initially, we insert the head node of each list into the heap. This allows us to track the smallest node across all lists.

3. **Heap Processing**: After popping the smallest node, we append it to the result list. If the node has a next node in its linked-list, we push that next node into the heap.

4. **Result Construction**: The heap ensures that every time we extract a node, the next smallest element is available. This guarantees the merged list remains sorted at all times.

5. **Time Complexity**: The time complexity is driven by the heap operations (insertion and removal), which are O(log k), and we perform these operations for each node in the linked-lists. Thus, the overall complexity is O(n log k), where `n` is the total number of nodes across all lists, and `k` is the number of linked-lists.

In essence, the min-heap allows us to efficiently merge multiple sorted linked-lists by always processing the smallest node available, ensuring a time-efficient merge.*/
code:
#include <queue>
#include <vector>
using namespace std;

// // Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode* next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // Custom comparator for the priority queue (min-heap)
        auto compare = [](ListNode* a, ListNode* b) {
            return a->val > b->val; // Min-heap: smallest value at the top
        };

        // Priority queue to keep track of the smallest elements
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);

        // Push the head of each linked list into the priority queue
        for (ListNode* node : lists) {
            if (node) {
                pq.push(node);
            }
        }

        // Dummy node to simplify result list construction
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Extract the smallest element from the heap and append it to the result
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();
            tail->next = minNode;
            tail = tail->next;

            // If the extracted node has a next node, push it into the heap
            if (minNode->next) {
                pq.push(minNode->next);
            }
        }

        // Return the merged sorted list
        return dummy->next;
    }
};
