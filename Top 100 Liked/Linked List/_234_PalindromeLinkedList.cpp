// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.




#include <iostream>
#include <stack>
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
    ListNode* curr;
    bool solve(ListNode* head) {
        if (head == nullptr) return true;
        bool ans = solve(head->next) && head->val == curr->val;
        curr = curr->next;
        return ans;
    }

    bool isPalindrome(ListNode* head) {
        // Using Stack
        stack<int> stack;
        ListNode* curr = head;
        while (curr) {
            stack.push(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr && curr->val == stack.top()) {
            stack.pop();
            curr = curr->next;
        }
        return curr == nullptr;

        // Uncomment for recursion solution
        // curr = head;
        // return solve(head);
    }
};

// Function to insert a node at the end of the list
void insert(ListNode*& head, int val) {
    if (head == nullptr) head = new ListNode(val);
    else {
        ListNode* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new ListNode(val);
    }
}

// Function to print the list (for testing purposes)
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = nullptr;
    int n, val;
    
    cout << "Enter the number of nodes in the list: ";
    cin >> n;
    
    cout << "Enter the values of the nodes: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> val;
        insert(head, val);
    }
    
    Solution solution;
    if (solution.isPalindrome(head)) cout << "The linked list is a palindrome." << endl;
    else cout << "The linked list is not a palindrome." << endl;
}