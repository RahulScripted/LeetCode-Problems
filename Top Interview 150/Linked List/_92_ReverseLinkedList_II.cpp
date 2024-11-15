// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.





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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; i++) prev = prev->next;

        ListNode* cur = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;   
    }
};

// Helper function to create a linked list from an array
ListNode* createLinkedList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : arr) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(values);

    cout << "Original list: ";
    printLinkedList(head);

    Solution solution;
    int left = 2, right = 4;
    ListNode* newHead = solution.reverseBetween(head, left, right);

    cout << "Reversed list between positions " << left << " and " << right << ": ";
    printLinkedList(newHead);
}