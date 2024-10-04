// Given the head of a linked list, remove the nth node from the end of the list and return its head.



#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0;i < (n + 1);i++){
            if(fast == NULL) return head -> next;
            fast = fast -> next;
        }

        while(fast != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return head;

        // Approach1: Calculate length
        // ListNode* temp = head;
        // int len = 0;
        // while(temp != NULL){
        //     len++;
        //     temp = temp -> next;
        // }
        // if(len == n) return head -> next;
        // int idx = (len - n - 1);
        // temp = head;
        // for(int i = 0;i < idx;i++) temp = temp -> next;
        // temp -> next = temp -> next -> next;
        // return head;
    }
};

void display(ListNode* head){
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

    // Link nodes to form the list: 4 -> 5 -> 1 -> 9
    head->next = second;
    second->next = third;
    third->next = fourth;

    int n = 2;
    Solution solve;
    cout<<"Before deletion : ";
    display(head);

    solve.removeNthFromEnd(head,n);
    cout<<"After deletion : ";
    display(head);
}