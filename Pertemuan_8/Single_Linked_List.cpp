#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
private:
    Node* head;

public:
    SingleLinkedList() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        cout << "Hasil:\n";
        if (head == NULL) {
            cout << "NULL\n";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    SingleLinkedList sll;
    int nilai;
    
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan angka: ";
        cin >> nilai;
        sll.insert(nilai);
    }

    sll.display();

    return 0;
}
