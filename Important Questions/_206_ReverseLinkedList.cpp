// Given the head of a singly linked list, reverse the list, and return the reversed list.




#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // Recursive Way
        if (head == NULL || head->next == NULL) return head;
        ListNode* prev = NULL;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = prev;
        return newHead;

        // Iterative Way
        // ListNode* prev = NULL;
        // ListNode* curr = head;

        // while (curr != NULL) {
        //     ListNode* forward = curr->next;
        //     curr->next = prev;
        //     prev = curr;
        //     curr = forward;
        // }
        // return prev;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to create a linked list
ListNode* createList() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    return head;
}

int main() {
    Solution solution;

    // Create a linked list 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = createList();

    cout << "Original List: ";
    printList(head);

    // Reverse the list recursively
    ListNode* reversedHead = solution.reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead);

    return 0;
}