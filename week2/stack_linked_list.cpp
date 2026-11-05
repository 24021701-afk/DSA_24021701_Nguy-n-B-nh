#include "../week1/singly_linked_list.cpp"

struct Stack {
    SinglyLinkedList items;

    bool isEmpty() {
        return items.head == nullptr;
    }

    void push(int value) {
        items.insertHead(value);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        int value = items.head->data;
        items.deleteHead();
        return value;
    }

    int size() {
        int count = 0;
        Node* current = items.head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }

        return count;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        return items.head->data;
    }
};

// int main() {
//     Stack stack;

//     stack.push(10);
//     stack.push(20);
//     stack.push(30);

//     cout << "Top element: " << stack.top() << endl;
//     while (!stack.isEmpty()) {
//         cout << "Popped: " << stack.pop() << endl;
//     }

//     if (stack.isEmpty()) {
//         cout << "The stack is empty." << endl;
//     }

//     return 0;
// }
