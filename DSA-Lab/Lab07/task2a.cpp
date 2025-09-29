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
        temp->next = n;}
}
void display(Node* head) {
    while(head) {
        cout<<head->data<<" ";
        head = head->next;}
    cout<<endl;
}
void bubbleSort(Node* head) {
    if(!head) return;
    bool swapped;
    do {
        swapped = false;
        Node* temp = head;
        while(temp->next) {
            if(temp->data > temp->next->data) {
                swap(temp->data, temp->next->data);
                swapped = true;
            }
            temp = temp->next;
        }
    } while(swapped);
}

int main() {
    Node* head = NULL;
    insert(head,4);
    insert(head,2);
    insert(head,5);
    insert(head,1);
    bubbleSort(head);
    display(head);
}
