// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.




#include <iostream>
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head; 

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                while (curr->next != NULL && curr->val == curr->next->val) curr = curr->next;
                prev->next = curr->next;
            }
            else prev = curr;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Print a linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Create a linked list from a vector
ListNode* createList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    Solution solution;

    vector<int> values = {1, 2, 3, 3, 4, 4, 5};
    ListNode* head = createList(values);
    cout << "Original List: ";
    printList(head);

    ListNode* result = solution.deleteDuplicates(head);
    cout << "Modified List: ";
    printList(result);
}