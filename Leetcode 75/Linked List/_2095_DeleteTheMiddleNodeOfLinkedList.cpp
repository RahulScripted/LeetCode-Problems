// You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list. The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.




#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        // Handle base cases
        if (head == NULL || head->next == NULL) return NULL; 

        // Initialize slow and fast pointers
        ListNode* slow = head;
        ListNode* fast = head->next;

        // Move the slow and fast pointers
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete the middle node
        slow->next = slow->next->next;

        return head;

        // Finding the length
        // ListNode* temp = head;
        // int len = 0;
        // while(temp){
        //     len++;
        //     temp = temp -> next;
        // }
        
        // if(len == 1) return NULL;
        // if(len == 2){
        //     head -> next = NULL;
        //     return head;
        // }

        // int idx = ceil(len / 2);
        // temp = head;
        // for(int i = 0;i < (idx - 1);i++) temp = temp -> next;
        // temp -> next = temp -> next -> next;
        // return head;
    }
};

// Create a linked list
ListNode* createLinkedList(vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;
    for (int i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }
    return head;
}

// Print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create linked list from the vector
    vector<int> list_values = {1, 2, 3, 4, 5}; 
    ListNode* head = createLinkedList(list_values);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Delete the middle node
    Solution solution;
    head = solution.deleteMiddle(head);

    // Print the modified list
    cout << "List after deleting middle node: ";
    printList(head);

    return 0;
}