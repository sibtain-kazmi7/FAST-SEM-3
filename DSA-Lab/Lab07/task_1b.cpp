#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int d): data(d), next(NULL), prev(NULL) {}
};

void insert(Node*& head, int data) {
    Node* n = new Node(data);
    if(!head) head = n;
    else {
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }
}

void display(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* reverse(Node* head) {
    if(!head) return NULL;
    Node* temp = head->next;
    head->next = head->prev;
    head->prev = temp;
    if(!head->prev) return head;
    return reverse(head->prev);
}

int main() {
    Node* head = NULL;
    for(int i=1;i<=5;i++) insert(head,i);
    head = reverse(head);
    display(head);
}
