#include <iostream>
using namespace std;
// Node structure
struct Node {
    int data;
    Node* next;
};
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Function to insert a node at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    // Function to delete a node from the beginning
    void deleteFromBeginning() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Function to insert a node at a specific position
    void insertAtPosition(int value, int position) {
        if (position <= 0)
            return;

        Node* newNode = new Node{value, nullptr};

        if (position == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 1; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (current) {
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Function to delete a node from a specific position
    void deleteFromPosition(int position) {
        if (position <= 0 || !head)
            return;

        if (position == 1) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        for (int i = 1; i < position && current; ++i) {
            previous = current;
            current = current->next;
        }

        if (current) {
            previous->next = current->next;
            delete current;
        }
    }

    // Function to display the linked list
    void display() const {
        Node* current = head;

        while (current) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }

    // Function to search for a value in the linked list
    bool search(int value) const {
        Node* current = head;

        while (current) {
            if (current->data == value)
                return true;
            current = current->next;
        }

        return false;
    }

    // Function to update the value at a specific position
    void updateAtPosition(int value, int position) {
        if (position <= 0 || !head)
            return;

        Node* current = head;

        for (int i = 1; i < position && current; ++i) {
            current = current->next;
        }

        if (current) {
            current->data = value;
        }
    }

    // Function to delete a node from the end
    void deleteFromEnd() {
        if (!head)
            return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        Node* previous = nullptr;

        while (current->next) {
            previous = current;
            current = current->next;
        }

        delete current;
        previous->next = nullptr;
    }

    // Destructor to free memory
    ~LinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList L;

    // Insert at the beginning
    L.insertAtBeginning(3);
   L.insertAtBeginning(2);
   L.insertAtBeginning(1);

    // Display the linked list
    cout << "Linked List: ";
    L.display();

    // Search for a value
    int searchValue = 2;
    cout << "Search for " << searchValue << ": " << (L.search(searchValue) ? "Found" : "Not Found") << endl;

    // Update at a specific position
    int updatePosition = 2;
    int updateValue = 5;
    cout << "Update value at position " << updatePosition << " to " << updateValue << endl;
    L.updateAtPosition(updateValue, updatePosition);
    L.display();

    // Insert at a specific position
    int insertPosition = 2;
    int insertValue = 4;
    cout << "Insert value " << insertValue << " at position " << insertPosition << endl;
    L.insertAtPosition(insertValue, insertPosition);
    L.display();

    // Delete from the beginning
    cout << "Delete from the beginning" << endl;
    L.deleteFromBeginning();
    L.display();

    // Delete from the end
    cout << "Delete from the end" << endl;
    L.deleteFromEnd();
    L.display();

    // Delete from a specific position
    int deletePosition = 2;
    cout << "Delete from position " << deletePosition << endl;
    L.deleteFromPosition(deletePosition);
    L.display();

    return 0;
}