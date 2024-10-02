// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.



#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){ // calculating length of 1st linked list
            lenA++;
            tempA = tempA -> next;
        }
        
        int lenB = 0;
        ListNode* tempB = headB;
        while(tempB != NULL){ // calculating length of 2nd linked list
            lenB++;
            tempB = tempB -> next;
        }

        tempA = headA; // resetting tempA to head of list A
        tempB = headB; // resetting tempB to head of list B

        // Move the pointer of the longer list ahead by the difference in lengths
        if(lenA > lenB){
            int diff = lenA - lenB;
            for(int i = 0; i < diff; i++) {
                tempA = tempA -> next;
            }
        } 
        else {
            int diff = lenB - lenA;
            for(int i = 0; i < diff; i++) {
                tempB = tempB -> next;
            }
        }

        // Move both pointers together until they meet or reach the end
        while(tempA != tempB){
            tempA = tempA -> next;
            tempB = tempB -> next;
        }

        // Either they meet at the intersection node or both are NULL
        return tempA;
    }
};


int main(){
    // Create common intersection nodes
    ListNode* common1 = new ListNode(7);
    ListNode* common2 = new ListNode(11);
    ListNode* common3 = new ListNode(2);
    common1->next = common2;
    common2->next = common3;

    // Create first linked list and attach common part
    ListNode* headA = new ListNode(4);
    ListNode* A1 = new ListNode(5);
    ListNode* A2 = new ListNode(1);
    ListNode* A3 = new ListNode(9);
    ListNode* A4 = new ListNode(3);
    headA->next = A1;
    A1->next = A2;
    A2->next = A3;
    A3->next = A4;
    A4->next = common2;

    // Create second linked list and attach common part
    ListNode* headB = new ListNode(4);
    ListNode* B1 = new ListNode(3);
    ListNode* B2 = new ListNode(7);
    ListNode* B3 = new ListNode(6);
    headB->next = B1;
    B1->next = B2;
    B2->next = B3;
    B3->next = common2;


    Solution solve;
    ListNode* result = solve.getIntersectionNode(headA,headB);

    if(result) cout<<result->val<<endl;
    else cout<<"NULL"<<endl;
}