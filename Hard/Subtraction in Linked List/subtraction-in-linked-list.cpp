//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
private:
    int len(Node* node) {
        Node* curr{node};
        int l{0};
        while(curr){
            l++;
            curr = curr->next;
        }
        return l;
    }
    
    Node* stripLeadingZeroes(Node* head)
    {
        while(head && head->next && head->data == 0)
        {
            Node* trash{head};
            head = head->next;
            delete trash;   // could make it lil fast by removing this line 
                            // but will do memory leak
        }
        return head;
    }
    
    Node* reverse(Node* node) {
        if(!node || !node->next) return node;
        
        Node* prev{nullptr};
        Node* curr{node};
        Node* next{node->next};
        
        while(curr)
        {
            curr->next = prev;
            // ----
            prev = curr;
            curr = next;
            if(next) next = next->next;
        }
        
        return prev;
    }

public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // strip leading zeroes
        head1 = stripLeadingZeroes(head1);
        head2 = stripLeadingZeroes(head2);

        
        int l1{len(head1)};
        int l2{len(head2)};
        
        
        // maintain head1 > head2 numerically   
        // find which is greater
        // ans swap accordingly
        // straight forward
        if(l2 > l1) std::swap(head1, head2);
        // need to check numerically
        if(l1 == l2)
        {
            Node* c1{head1};
            Node* c2{head2};
            while(c1 && c2)
            {
                if(c1->data > c2->data) break;
                if(c1->data < c2->data){
                    std::swap(head1, head2);
                    break;
                }
                c1 = c1->next;
                c2 = c2->next;
            }
        }
        

        // actual subtraction
        int borrow{0};
        head1 = reverse(head1);
        head2 = reverse(head2);
        
        Node* curr1{head1};
        Node* curr2{head2};
        
        while(curr1 && curr2)
        {
            int a{curr1->data};
            int b{curr2->data};
        
            if((a + borrow) < b) {
                curr1->data = a + 10 + borrow  - b;
                if(!borrow) borrow = -1;
            } else {
                curr1->data = a + borrow - b;
                borrow = 0;
            }
    
    
            // ------ 
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        // do subtraction on remainng part        
        while(borrow && curr1)
        {
            int a{curr1->data};
            if((borrow + a) < 0)
            {
                a += 10 + borrow;
            } else {
                a += borrow;
                borrow = 0;
            }
            
            curr1->data = a;
            
            curr1 = curr1->next;
        }
        
        // back to original answer stripping leading zeroes
        return stripLeadingZeroes(reverse(head1));
    }
};


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends