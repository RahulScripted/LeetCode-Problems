// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.





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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            if (l1 != nullptr) {
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                carry += l2->val;
                l2 = l2->next;
            }
            curr->next = new ListNode(carry % 10);
            carry /= 10;
            curr = curr->next;
        }

        return dummy->next;
    }
};

// Print a linked list.
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) {
            cout << " -> ";
        }
        node = node->next;
    }
    cout << endl;
}

// Create a linked list
ListNode* createList(const int arr[], int size) {
    ListNode* head = new ListNode(arr[0]);
    ListNode* curr = head;
    for (int i = 1; i < size; i++) {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

int main() {
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    ListNode* l1 = createList(arr1, 3);
    ListNode* l2 = createList(arr2, 3);

    Solution solution;
    ListNode* result = solution.addTwoNumbers(l1, l2);

    // Print the resulting linked list.
    cout << "Sum of the two linked lists: ";
    printList(result);

    return 0;
}