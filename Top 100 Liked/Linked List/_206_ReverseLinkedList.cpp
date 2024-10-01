// Given the head of a singly linked list, reverse the list, and return the reversed list.




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

// ReverseList function.
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Recursive Way
        if (head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;  // Set the original node's next pointer to null
        return newHead;

        // Uncomment the following code block for the iterative way.
        /*
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
        */
    }
};

// Helper function to create a new ListNode
ListNode* createNode(int value) {
    return new ListNode(value);
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Create a linked list
ListNode* createSampleList() {
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    return head;
}

int main() {
    ListNode* head = createSampleList();

    cout << "Original List: ";
    printList(head);

    // Reverse the linked list
    Solution solution;
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);
}