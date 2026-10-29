#include<bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node *next;
};
typedef struct node node;
// 1. Chen vao dau
void themdau(node *&head, int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

// 2. Chen vao cuoi
void themcuoi(node *&head, int x) {
    node *newNode = new node;
    newNode->data = x;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// 3. Chen  vào vi tri k
void themk(node *&head, int x, int k) {
    if (k <= 1) {
        themdau(head, x);
        return;
    }
    
    node *temp = head;
    
    for (int i = 1; i < k - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        themcuoi(head, x);
        return;
    }
    
    node *newNode = new node;
    newNode->data = x;
    newNode->next = temp->next;
    temp->next = newNode;
}
// 4. Xoa phan tu dau
void xoadau(node *&head) {
    if (head == NULL) return;
    
    node *temp = head;
    head = head->next;
    delete temp;
}

// 5. Xóa phan tu cuoi
void xoacuoi(node *&head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    
    node *temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    delete temp->next; 
    temp->next = NULL; 
}

// 6. Xoa phan tu thu k
void xoak(node *&head, int k) {
    if (head == NULL) return;
    if (k <= 1) {
        xoadau(head);
        return;
    }
    
    node *temp = head;
    for (int i = 1; i < k - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    
    
    if (temp->next == NULL) return; 
    
    node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
}


// 7.xuoi
void duyetxuoi(node *head) {
    node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// 8.nguoc
void duyetnguoc(node *head) {
    if (head == NULL) return;
    
    duyetnguoc(head->next); 
    cout << head->data << " ";
}
int main() {
    node *head = NULL;
    

    themdau(head, 10);
    themdau(head, 20); //  20 -> 10
    themcuoi(head, 30); // 20 -> 10 -> 30
    themk(head, 15, 2); //  20 -> 15 -> 10 -> 30
    
    cout << "Duyet xuoi: ";
    duyetxuoi(head);
    
    cout << "Duyet nguoc: ";
    duyetnguoc(head);
    cout << endl;
    
    
    xoadau(head); //  15 -> 10 -> 30
    xoacuoi(head); //  15 -> 10
    themk(head, 25, 2); 15 -> 25 -> 10
    xoak(head, 2); 15 -> 10
    
    cout << "Sau khi xoa (Duyet xuoi): ";
    duyetxuoi(head);
    return 0;
}
