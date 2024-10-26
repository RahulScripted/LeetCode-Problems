// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list. k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.





#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        ListNode* x1 = nullptr;
        ListNode* x2 = head;
        ListNode* x3 = head;
        int cnt = 0, x = k;
        while (p) {
            cnt++;
            p = p->next;
        }
        cnt /= k;
        p = head;

        if (!cnt) return head; // if total node count is less than k, return head

        while (x--) { // first reverse of k nodes
            x3 = x3->next;
            x2->next = x1;
            x1 = x2;
            x2 = x3;
        }

        head = x1; // head will be the kth node from start
        cnt--; // as one group of k nodes is reversed, decrease cnt by 1

        while (cnt--) { // for the rest of the nodes, reverse in groups of k and update pointer "p"
            x = k;
            x1 = nullptr;
            while (x--) {
                x3 = x3->next;
                x2->next = x1;
                x1 = x2;
                x2 = x3;
            }
            p->next = x1;
            while (p->next) p = p->next;
        }

        p->next = x2; // at last, for the group of nodes less than k, just add them to the chain

        return head;
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution solution;

    // Test case: reverse groups of k in the linked list
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    
    ListNode* head = createLinkedList(arr, 8);
    cout << "Original List: ";
    printLinkedList(head);

    head = solution.reverseKGroup(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printLinkedList(head);

    return 0;
}