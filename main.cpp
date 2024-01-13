#include <stdexcept>
#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while(current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void deleteWithValue(int data) {
        if (head == nullptr) {
            return;
        }

        if (head->data == data) {
            Node* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;
        } else {
            Node* current = head;
            while(current->next != nullptr) {
                if(current->next->data == data) {
                    Node* nodeToRemove = current->next;
                    current->next = nodeToRemove->next;
                    delete nodeToRemove;
                    break;
                }
                current = current->next;
            }
        }

        return;
    }

    void reverse() {
        if (head == nullptr || head->next == nullptr) {
            return;

        }
        Node* previos = nullptr;
        Node* current = head;
        Node* next;

        while(current != nullptr) {
            next = current->next;
            current->next = previos;
            previos = current;
            current = next;
        }

        head = previos;
    }

    int length() {
        Node* current = head;
        int counter = 0;

        while(current != nullptr) {
            counter++;
            current = current->next;
        }

        return counter;
    }

    void insertAtPosition(int position, int data) {
        if(position < 0 || position > length()) {
            throw std::logic_error("Position is out of range of this list");
        }

        if(position == 0) {
            Node* newNode = new Node(data);
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            for(int i = 0; i < position - 1; i++) {
                    current = current->next;
            }

            Node* newNode = new Node(data);
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void removeAtPosition(int position) {
        const size_t len = length();
        if(position < 0 || position >= len) {
            throw std::logic_error("Position is out of range of this list");
        }

        Node dummy(0);
        dummy.next = head;
        Node* previous = &dummy;

        for(int i = 0; i < position; i++) {
            previous = previous->next;
        }

        Node* nodeToRemove = previous->next;
        previous->next = nodeToRemove->next;

        if (nodeToRemove == head) {
            head = nodeToRemove->next;
        }

        delete nodeToRemove;
    }

    void pushBack(int data) {
        Node* newNode = new Node(data);
        Node* current = head;

        for(int i = 0; i < length() - 1; i++) {
            current = current->next;
        }

        current->next = newNode;
    }

    void pushFront(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void popFront() {
        if(head == nullptr) {
            return;
        }

        Node* nodeToRemove = head;
        head = head->next;
        delete nodeToRemove;
    }

    void popBack() {
        if (head == nullptr) {
            return;
        }
        Node dummy(0);
        dummy.next = head;
        Node* previous = &dummy;
        for(int i = 0; i < length() - 1; i++) {
            previous = previous->next;
        }

        Node* nodeToDelete = previous->next;
        previous->next = nullptr;
        delete nodeToDelete;
    }

    bool empty() {
        return head == nullptr;
    }

    void print() {
        Node* current = head;

        while(current != nullptr) {
            std::cout << current->data << std::endl;
            current = current->next;
        }

        return;
    }

    void valueAt(int position) {
        if (position < 0 || position > length() - 1) {
            throw std::logic_error("Position is out of range of this object");
        }

        Node* current = head;
        for(int i = 0; i < position; i++) {
            current = current->next;
        }
        std::cout << current->data << std::endl;
    }

    void erase() {
        int len = length();

        if(len < 2) {
            delete head;
            return;
        }

        for(int i = 0; i < len - 1; i++) {
            Node* nodeToRemove = head;
            head = head->next;
            delete nodeToRemove;
        }
    }


    LinkedList() : head(nullptr) {}
    ~LinkedList() = default;
};

int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    list.append(40);

    list.print();
}
