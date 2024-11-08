#include <iostream>
#include <vector>

using namespace std;

// Template class definition for Queue
template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    int queueSize;

public:
    Queue() : frontNode(nullptr), rearNode(nullptr), queueSize(0) {}

    ~Queue() {
        while (!empty()) {
            pop();
        }
    }

    // Push element to queue
    void push(T value) {
        Node* newNode = new Node(value);
        if (empty()) {
            frontNode = rearNode = newNode;
        }
        else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        queueSize++;
    }

    // Pop element
    void pop() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
        queueSize--;
    }

    // Get front element
    T front() {
        if (!empty()) {
            return frontNode->data;
        }
        throw out_of_range("Queue is empty");
    }

    // Get size
    int size() {
        return queueSize;
    }

    // Check if empty
    bool empty() {
        return queueSize == 0;
    }

    // Move front element to rear
    void move_to_rear() {
        if (empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        T frontVal = front();
        pop();
        push(frontVal);
    }

    // Display all elements
    void display() {
        Node* current = frontNode;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

// Recursive Linear Search function to find the last occurrence of a target in a vector
int recursiveLinearSearchLast(const std::vector<int>& vec, int target, int index) {
    if (index == -1) {
        return -1;  // Return -1 if target is not found
    }
    if (vec[index] == target) {
        // Search backward to find the last occurrence
        int nextIndex = recursiveLinearSearchLast(vec, target, index - 1);
        return (nextIndex == -1) ? index : nextIndex;
    }
    return recursiveLinearSearchLast(vec, target, index - 1);
}

// Linked List class definition
class LinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Insert node at end
    void push(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Insertion sort
    void insertionSort() {
        if (!head) return;

        Node* sorted = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            if (sorted == nullptr || sorted->data >= current->data) {
                current->next = sorted;
                sorted = current;
            }
            else {
                Node* temp = sorted;
                while (temp->next != nullptr && temp->next->data < current->data) {
                    temp = temp->next;
                }
                current->next = temp->next;
                temp->next = current;
            }
            current = next;
        }
        head = sorted;
    }

    // Display list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    // Queue Operations
    Queue<int> q;
    cout << "Pushing elements into the queue: ";
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    cout << "Queue contents: ";
    q.display();

    cout << "Moving front element to rear." << endl;
    q.move_to_rear();
    q.display();

    // Recursive Linear Search
    vector<int> vec = { 1, 3, 5, 7, 3, 9, 3 };
    int target = 3;
    int lastIndex = recursiveLinearSearchLast(vec, target, vec.size() - 1);
    cout << "Last occurrence of " << target << " is at index: " << lastIndex << endl;

    // Linked List Sorting
    LinkedList list;
    list.push(5);
    list.push(2);
    list.push(8);
    list.push(3);
    list.push(7);

    cout << "Linked List before sorting: ";
    list.display();

    list.insertionSort();

    cout << "Linked List after sorting: ";
    list.display();

    return 0;
}
