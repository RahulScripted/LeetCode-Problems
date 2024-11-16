// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.





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

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessDummy(0), greaterDummy(0);
        ListNode* less = &lessDummy;
        ListNode* greater = &greaterDummy;

        // Traverse the list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } 
            else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        greater->next = nullptr;
        less->next = greaterDummy.next;

        return lessDummy.next;
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

    vector<int> values = {1, 4, 3, 2, 5, 2};
    int x = 3;
    ListNode* head = createList(values);
    cout << "Original List: ";
    printList(head);

    ListNode* result = solution.partition(head, x);
    cout << "Modified List: ";
    printList(result);
}