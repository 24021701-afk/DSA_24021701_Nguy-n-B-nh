#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* taonode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void duyetxuoi(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << (temp->next != nullptr ? ", " : "");
        temp = temp->next;
    }
    cout << endl;
}

void duyetnguoc(Node* tail) {
    Node* temp = tail;
    while (temp != nullptr) {
        cout << temp->data << (temp->prev != nullptr ? ", " : "");
        temp = temp->prev;
    }
    cout << endl;
}

void chendau(Node* &head, Node* &tail, int x) {
    Node* newNode = taonode(x);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void chencuoi(Node* &head, Node* &tail, int x) {
    Node* newNode = taonode(x);
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void chenvitrik(Node* &head, Node* &tail, int x, int k) {
    if (k < 0){
        return;
    }
    if (k == 0) {
        chendau(head, tail, x);
        return;
    }

    Node* temp = head;
    for (int i = 0; temp != nullptr && i < k - 1; i++) {
        temp = temp->next;
    }
    if (temp == nullptr){ 
        return;
    }
    if (temp == tail) {
        chencuoi(head, tail, x);
        return;
    }

    Node* newNode = taonode(x);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void xoadau(Node* &head, Node* &tail) {
    if (head == nullptr){
        return;
    }
    Node* temp = head;
    head = head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
}

void xoacuoi(Node* &head, Node* &tail) {
    if (tail == nullptr){
        return;
    }
    Node* temp = tail;
    tail = tail->prev;

    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
}

void xoavitrik(Node* &head, Node* &tail, int k) {
    if (head == nullptr || k < 0){
        return;
    }
    if (k == 0) {
        xoadau(head, tail);
        return;
    }
    Node* temp = head;
    for (int i = 0; temp != nullptr && i < k; i++) {
        temp = temp->next;
    }
    if (temp == nullptr){
        return;
    }
    if (temp == tail) {
        xoacuoi(head, tail);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    chendau(head, tail, 32);      
    chencuoi(head, tail, 50);
    chendau(head, tail, 10);     
    chenvitrik(head, tail, 99, 1);
    xoadau(head, tail);
    xoacuoi(head, tail);
    xoavitrik(head, tail, 0);
    cout << "Duyet xuoi: ";
    duyetxuoi(head);
    cout << endl;
    cout << "Duyet nguoc: ";
    duyetnguoc(tail);
    return 0;
}
