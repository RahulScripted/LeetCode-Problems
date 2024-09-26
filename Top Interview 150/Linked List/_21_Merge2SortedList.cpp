// You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.




#include <iostream>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(10);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = dummy;

        // Merging the two lists
        while (temp1 && temp2) {
            if (temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        // If 1st list ode has more nodes
        if (temp1) temp->next = temp1;

        // If 2nd list ode has more nodes
        if (temp2) temp->next = temp2;
        
        return dummy->next;
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
    vector<int> list1_values = {1, 2, 4};
    vector<int> list2_values = {1, 3, 4};

    // Create linked lists from the vectors
    ListNode* list1 = createLinkedList(list1_values);
    ListNode* list2 = createLinkedList(list2_values);

    // Print the initial lists
    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    // Merge the lists
    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}