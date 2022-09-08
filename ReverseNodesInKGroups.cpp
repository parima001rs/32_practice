#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    node* next;
    int data;

    node(int val){
        data = val;
        next = NULL;
    }
};

void insert(node* &head, int val){
    node* n = new node(val);
    if(!head){
        head = n;
        return;
    }
    node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node* head){
    while(head){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<"NULL"<<endl;
}
 
node* solve(node* &head, int k){
    if(!head || !head->next) return head;

    int len = 0;
    node* pseudoHead = head;
    while(pseudoHead){ //evaluating length
        len++;
        pseudoHead = pseudoHead->next;
    }
    
    node* dummy = new node(0);
    dummy->next = head;
    node* pre = dummy;
    node* cur;
    node* nex;
    
    while(len >= k){
        cur = pre->next;
        nex = cur->next;
        for(int i=1; i<k; i++){
            cur->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = cur->next;
        }
        pre = cur;
        len -= k;
    }
    return dummy->next;
}

int main(){
    node* head = NULL;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 5);
    insert(head, 6);
    insert(head, 7);
    insert(head, 8);
    display(head);

    int k = 3;
    node* newHead = solve(head, k);
    display(newHead);

    return 0;
}