// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.




#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Tortoise and Hare Algorithm to detect a cycle
        ListNode *slow = head, *fast = head;
        bool flag = true;
        
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                flag = false;
                break;
            }
        }
        
        if (flag) return NULL;  
        
        // Find the start node of the cycle
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        
        return slow;
    }
};

// Print the linked list
void printList(ListNode *head, ListNode *cycleStart = NULL) {
    ListNode *current = head;
    int count = 0;
    while (current && (current != cycleStart || count < 2)) {
        cout << current->val << " -> ";
        current = current->next;
        if (current == cycleStart) count++;
    }

    if (current) cout << "(cycle starts at " << cycleStart->val << ")";

    else cout << "NULL";
    
    cout << endl;
}

int main() {
    // Creating a linked list with a cycle
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;  

    Solution sol;
    ListNode *cycleStart = sol.detectCycle(head);

    // Output the results
    if (cycleStart) cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else cout << "No cycle detected." << endl;

    // Print the linked list
    printList(head, cycleStart);

    return 0;
}