// Given the head of a linked list, rotate the list to the right by k places.




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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
      
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        if (k > len) {
            k = k % len;
            if (k == 0) return head;
        }

        if (k <= len) {
            k = len - k;
            if (k == 0) return head;
        }

        int count = 1;
        ListNode* curr = head;
        while (count < k && curr != NULL) {
            curr = curr->next;
            count++;
        }

        ListNode* temp = curr->next; 
        curr->next = NULL; 
        tail->next = head;
        return temp;
    }
};

// Create a linked list from an array
ListNode* createLinkedList(const vector<int>& arr) {
    ListNode* dummy = new ListNode(0);
    ListNode* current = dummy;
    for (int val : arr) {
        current->next = new ListNode(val);
        current = current->next;
    }
    return dummy->next;
}

// Print a linked list
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

    // Call rotateRight with k = 2
    Solution solution;
    int k = 2;
    ListNode* rotatedHead = solution.rotateRight(head, k);

    cout << "List after rotating right by " << k << ": ";
    printLinkedList(rotatedHead);
}