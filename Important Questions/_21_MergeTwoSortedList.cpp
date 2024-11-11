// You are given the heads of two sorted linked lists list1 and list2. Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists. Return the head of the merged linked list.





#include <bits/stdc++.h>
using namespace std;

// Define ListNode as in the provided code
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution class as defined
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(10);
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* temp = dummy;
        
        // Merging
        while(temp1 && temp2) {
            if(temp1->val < temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
                temp = temp->next;
            } 
            else {
                temp->next = temp2;
                temp2 = temp2->next;
                temp = temp->next;
            }
        }

        // Attach remaining nodes
        if(temp1) temp->next = temp1;
        if(temp2) temp->next = temp2;

        return dummy->next;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while(current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& arr) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int val : arr) {
        ListNode* newNode = new ListNode(val);
        if(!head) {
            head = newNode;
            tail = newNode;
        } 
        else {
            tail->next = newNode;
            tail = tail->next;
        }
    }
    return head;
}

int main() {
    // Test case
    vector<int> list1Vals = {1, 2, 4};
    vector<int> list2Vals = {1, 3, 4};

    ListNode* list1 = createList(list1Vals);
    cout<<"First list : ";
    printList(list1);

    ListNode* list2 = createList(list2Vals);
    cout<<"Second list : ";
    printList(list2);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
