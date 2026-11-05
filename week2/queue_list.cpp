#include "../week1/list.cpp"

struct Queue {
    List items;

    Queue() {
        items.initList();
    }

    bool isEmpty() {
        return items.size == 0;
    }

    void enqueue(int value) {
        if (items.size >= 100) {
            return;
        }

        items.insertTail(value);
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = items.data[0];
        items.deleteHead();
        return value;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }

        return items.data[0];
    }

    int size() {
        return items.size;
    }
};

// int main() {
//     Queue queue;

//     queue.enqueue(10);
//     queue.enqueue(20);
//     queue.enqueue(30);

//     cout << "Front element: " << queue.peek() << endl;
//     while (!queue.isEmpty()) {
//         cout << "Dequeued: " << queue.dequeue() << endl;
//     }

//     if (queue.isEmpty()) {
//         cout << "The queue is empty." << endl;
//     }

//     return 0;
// }
