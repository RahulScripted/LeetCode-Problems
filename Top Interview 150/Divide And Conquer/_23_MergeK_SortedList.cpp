// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order. Merge all the linked-lists into one sorted linked-list and return it.




#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class with mergeLists and mergeKLists functions
class Solution {
public:
    ListNode* mergeLists(ListNode* l1, ListNode* l2) {
        ListNode dummy;
        ListNode* node = &dummy;

        while (l1 && l2) {
            if (l1->val > l2->val) {
                node->next = l2;
                l2 = l2->next;
            } 
            else {
                node->next = l1;
                l1 = l1->next;
            }
            node = node->next;
        }

        node->next = l1 ? l1 : l2;
        return dummy.next;
    }    

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        while (lists.size() > 1) {
            vector<ListNode*> temp;
            for (size_t i = 0; i < lists.size(); i += 2) {
                ListNode* l1 = lists[i];
                ListNode* l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                temp.push_back(mergeLists(l1, l2));
            }
            lists = move(temp);
        }

        return lists[0];        
    }
};

// Print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;
}

int main() {
    Solution solution;

    ListNode* l1 = new ListNode(1, new ListNode(4, new ListNode(5)));
    ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    ListNode* l3 = new ListNode(2, new ListNode(6));
    vector<ListNode*> lists = {l1, l2, l3};

    ListNode* result = solution.mergeKLists(lists);
    cout << "Merged list: ";
    printList(result);

    // Cleanup: Free allocated memory
    while (result) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}