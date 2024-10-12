// Given the head of a linked list, return the list after sorting it in ascending order.



#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* newNode = new ListNode(100);
        ListNode* tempC = newNode;
        while(list1 != NULL && list2 != NULL){
            if(list1 -> val <= list2 -> val){
                tempC -> next = list1;
                tempC = list1;
                list1 = list1 -> next;
            }
            else{
                tempC -> next = list2;
                tempC = list2;
                list2 = list2 -> next;
            }
        }
        
        if(list1 == NULL) tempC -> next = list2;
        else tempC -> next = list1;

        return newNode -> next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head ->next == NULL) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast != NULL && fast -> next != NULL){
            temp = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        temp -> next = NULL;

        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);

        return merge(l1,l2);
    }
};

void display(ListNode* head) {
    ListNode* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    // Create nodes
    ListNode* head = new ListNode(4);
    ListNode* second = new ListNode(5);
    ListNode* third = new ListNode(1);
    ListNode* fourth = new ListNode(9);
    ListNode* fifth = new ListNode(3);
    ListNode* sixth = new ListNode(7);
    ListNode* seventh = new ListNode(11);
    ListNode* eight = new ListNode(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;

    cout << "Before sorting: ";
    display(head);
    Solution solve;

    head = solve.sortList(head);
    cout << "After sorting: ";
    display(head);

    return 0;
}