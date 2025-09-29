#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d): data(d), next(NULL) {}
};

void insert(Node*& head, int data) {
    Node* n = new Node(data);
    if(!head) head = n;
    else {
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
    }
}

void display(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void mergeAlternate(Node*& head1, Node*& head2) {
    Node* cur1 = head1;
    Node* cur2 = head2;
    Node* next1;
    Node* next2;
    while(cur1 && cur2) {
        next1 = cur1->next;
        next2 = cur2->next;
        cur1->next = cur2;
        cur2->next = next1;
        cur1 = next1;
        cur2 = next2;
    }
    head2 = cur2;
}

int main() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    insert(head1,1);
    insert(head1,2);
    insert(head1,3);
    insert(head2,4);
    insert(head2,5);
    insert(head2,6);
    insert(head2,7);
    insert(head2,8);
    mergeAlternate(head1,head2);
    display(head1);
    display(head2);
}
