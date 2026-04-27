#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    void insert(int x) {
        Node* newNode = new Node();
        newNode->data = x;

        if (head == NULL) {
            head = newNode;
            newNode->next = head; 
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; 
        }
    }

    void display() {
        cout << "Hasil:\n";
        if (head == NULL) {
            cout << "Kosong\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head); 
        
        cout << "(kembali ke " << head->data << ")" << endl;
    }
};

int main() {
    CircularLinkedList cll;
    int nilai;
    
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan angka: ";
        cin >> nilai;
        cll.insert(nilai);
    }

    cll.display();

    return 0;
}
