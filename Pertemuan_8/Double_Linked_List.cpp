#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoubleLinkedList {
private:
    Node* head;

public:
    DoubleLinkedList() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void display() {
        cout << "Hasil:\n";
        if (head == NULL) {
            cout << "NULL\n";
            return;
        }
        Node* temp = head;
        cout << "NULL <-> ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoubleLinkedList dll;
    int nilai;
    
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan angka: ";
        cin >> nilai;
        dll.insert(nilai);
    }

    dll.display();

    return 0;
}
