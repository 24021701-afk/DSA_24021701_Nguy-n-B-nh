#include "../week1/singly_linked_list.cpp"

struct Queue {
    SinglyLinkedList items;

    bool isEmpty() {
        return items.head == nullptr;
    }

    void enqueue(int value) {
        items.insertTail(value);
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        int value = items.head->data;
        items.deleteHead();
        return value;
    }

    int peek() {
        if (isEmpty()) {
            return -1;
        }

        return items.head->data;
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
