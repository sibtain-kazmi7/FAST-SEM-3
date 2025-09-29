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

void deleteFront(Node*& head) {
    if(!head) return;
    Node* temp = head;
    head = head->next;
    if(head) head->prev = NULL;
    delete temp;
}

void deleteLast(Node*& head) {
    if(!head) return;
    Node* temp = head;
    while(temp->next) temp = temp->next;
    if(temp->prev) temp->prev->next = NULL;
    else head = NULL;
    delete temp;
}

void deleteAt(Node*& head, int pos) {
    if(!head) return;
    Node* temp = head;
    for(int i=1; temp && i<pos; i++) temp = temp->next;
    if(!temp) return;
    if(temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if(temp->next) temp->next->prev = temp->prev;
    delete temp;
}

int main() {
    Node* head = NULL;
    for(int i=1;i<=5;i++) insert(head,i);
    deleteFront(head);
    display(head);
    deleteLast(head);
    display(head);
    deleteAt(head,2);
    display(head);
}
