// Given head, the head of a linked list, determine if the linked list has a cycle in it. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter. Return true if there is a cycle in the linked list. Otherwise, return false.




#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // Using the Slow and Fast Pointer approach
        if(head == NULL || head->next == NULL) return false;
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;

        // Using Map
        // unordered_map<ListNode*,bool>mp;
        // ListNode* temp = head;
        // while(temp){
        //     if(mp.find(temp) == mp.end()) mp[temp] = true;
        //     else if(mp[temp] == true) return true;
        //     temp = temp -> next;
        // }
        // return false;

        // Two Pointer
        // ListNode* slow = head;
        // ListNode* fast = head;
        // while(fast != NULL && fast -> next != NULL){
        //     slow = slow -> next;
        //     fast = fast -> next -> next;
        //     if(slow == fast) return true;
        // }
        // return false;
    }
};

// Function to create a linked list 
ListNode* createLinkedList(vector<int>& nodes, int pos) {
    if(nodes.empty()) return NULL;

    // Create the head node
    ListNode* head = new ListNode(nodes[0]);
    ListNode* tail = head;
    queue<ListNode*> q;
    q.push(head);

    // Create remaining nodes
    for(int i = 1; i < nodes.size(); ++i) {
        ListNode* newNode = new ListNode(nodes[i]);
        tail->next = newNode;
        tail = newNode;
        q.push(newNode);
    }

    // Creating a cycle if pos is valid (0-indexed)
    if(pos >= 0) {
        ListNode* cycleNode = head;
        for(int i = 0; i < pos; ++i) {
            cycleNode = cycleNode->next;
        }
        tail->next = cycleNode;
    }
    return head;
}

// Print the linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while(temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    vector<int> nodes = {3, 2, 0, -4};
    int cyclePos = 1; 

    // Create linked list using BFS
    ListNode* head = createLinkedList(nodes, cyclePos);

    // Check if the linked list has a cycle
    Solution solution;
    bool has_cycle = solution.hasCycle(head);
    if(has_cycle) cout<<"Linked List has a cycle"<<endl;
    else cout<<"Linked list has not a cycle"<<endl;
}