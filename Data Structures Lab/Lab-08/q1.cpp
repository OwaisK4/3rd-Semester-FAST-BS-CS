#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Node {
public:
    int element;
    int priority;
    Node *next;
    Node() {
        element = 0;
        priority = 0;
        next = NULL;
    }
    Node(int e, int p) {
        element = e;
        priority = p;
        next = NULL;
    }
};

class PriorityQueue {
public:
    Node *front;
    PriorityQueue() {
        front = NULL;
    }
    void updated_enqueue(int e, int p) { // Lower value of p indicates higher priority
        Node *temp = new Node(e, p);
        if (front == NULL || temp->priority <= front->priority) {
            temp->next = front;
            front = temp;
        } else {
            Node *prev = NULL;
            Node *current = front;
            while (current != NULL && temp->priority >= current->priority) {
                prev = current;
                current = current->next;
            }
            temp->next = prev->next;
            prev->next = temp;
        }
    }
    Node *dequeue() {
        Node *temp;
        if (front == NULL) // Empty queue
            return temp;
        else {
            temp = front;
            front = front->next;
            return temp;
        }
    }
};

int main() {
    srand(time(0));
    PriorityQueue queue;
    Node *temp;

    for (int i = 0; i < 10; i++) {
        queue.updated_enqueue(i, (float)rand() / RAND_MAX * 50.0);
    }

    cout << "Value,\tPriority\n";
    for (int i = 0; i < 10; i++) {
        temp = queue.dequeue();
        if (temp == NULL) {
            cout << "All elements dequeued.";
            break;
        }
        cout << temp->element << ",\t" << temp->priority;
        cout << "\n";
    }

    return 0;
}
