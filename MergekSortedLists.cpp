/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <queue>
class Compare {
    public:
        bool operator() (ListNode* a, ListNode* b) {
            return a->val >  b->val;
        }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        ListNode* curr_node = new ListNode();
        ListNode* prev_node = curr_node;
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        // Pushes heads of all linked lists to PQ
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i]) {
                pq.push(lists[i]);
            }
        }
        if (pq.empty()) return NULL;
        // Goes through PQ and adds each node to list 
        while (!pq.empty()) {
            ListNode* next_node = pq.top();
            curr_node->next = next_node;
            pq.pop();
            curr_node = curr_node->next;
            next_node = next_node->next;
            if (next_node) {
                pq.push(next_node);
            }
        }
        return prev_node->next;
    }
};
