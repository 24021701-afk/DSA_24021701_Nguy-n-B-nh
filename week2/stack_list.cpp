#include "../week1/list.cpp"

struct Stack {
    List items;

    Stack() {
        items.initList();
    }

    bool isEmpty() {
        return items.size == 0;
    }

    void push(int value) {
        if (items.size >= 100) {
            return;
        }

        items.insertTail(value);
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        int value = items.data[items.size - 1];
        items.deleteTail();
        return value;
    }

    int size() {
        return items.size;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }

        return items.data[items.size - 1];
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
