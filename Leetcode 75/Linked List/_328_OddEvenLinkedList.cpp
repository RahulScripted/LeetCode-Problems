// Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list. The first node is considered odd, and the second node is even, and so on.





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
    ListNode* oddEvenList(ListNode* head) {
        // Approach 2
        if (head == nullptr || head->next == nullptr) return head; 

        ListNode* odd = head; 
        ListNode* even = head->next; 
        ListNode* temp = even; 

        while (even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }

        odd->next = temp;
        return head;

        // Approach 1
        // ListNode oddHead(0);
        // ListNode evenHead(0);
        // ListNode* odd = &oddHead;
        // ListNode* even = &evenHead;

        // for (int isOdd = 0; head; head = head->next){
        //     if (isOdd ^= 1) {
        //         odd->next = head;
        //         odd = odd->next;
        //     } 
        //     else {
        //         even->next = head;
        //         even = even->next;
        //     }
        // }

        // odd->next = evenHead.next;
        // even->next = nullptr;
        // return oddHead.next;
    }
};

ListNode* newNode(int val) {
    return new ListNode(val);
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* result = sol.oddEvenList(head);
    cout << "Reordered List: ";
    printList(result);
}