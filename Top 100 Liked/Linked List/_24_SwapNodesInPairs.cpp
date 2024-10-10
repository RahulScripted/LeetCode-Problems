// Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)





#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* connector = dummy;
        ListNode* first = head;
        ListNode* second = first->next;

        while (first && second) {
            first->next = second->next;
            second->next = first;
            connector->next = second;

            connector = first;
            first = first->next;
            if (first) second = first->next;
        }
        return dummy->next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to create a linked list from a vector
ListNode* createList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;

    ListNode* head = new ListNode(vals[0]);
    ListNode* current = head;
    for (size_t i = 1; i < vals.size(); ++i) {
        current->next = new ListNode(vals[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution sol;

    vector<int> val1 = {1, 2, 3, 4};
    vector<int> val2 = {1, 2, 3, 4, 5};

    ListNode* head1 = createList(val1);
    ListNode* head2 = createList(val2);

    cout << "Original List 1: ";
    printList(head1);
    head1 = sol.swapPairs(head1);
    cout << "Swapped Pairs List 1: ";
    printList(head1);

    cout << "Original List 2: ";
    printList(head2);
    head2 = sol.swapPairs(head2);
    cout << "Swapped Pairs List 2: ";
    printList(head2);

    return 0;
}