#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
// without temp also you can print 
// void display(Node* head){
//     while(head!=NULL){
//         cout<<head->val<<" ";
//         head = head->next;
//     }
//     cout<<endl;
// }

// Calculation of LL size
int size(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp!=NULL){
        n++;
        temp = temp->next;
    }
    return n;
}

// recursive display
void displayRec(Node* head){
    // base case
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayRec(head->next);
}

int main(){
    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    display(a);

    cout<<size(a)<<" "<<endl;

    displayRec(a);

}