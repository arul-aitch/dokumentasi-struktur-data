#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<string> antrian;

void enqueue(string nama) {
	antrian.push(nama);
	cout << "Mahasiswa " << nama << " masuk antrian." << endl;
}

void dequeue() {
	if (antrian.empty()) {
		cout << "Antrian kosong!" << endl;
	} else {
		cout << "Mahasiswa " << antrian.front() << " sedang dilayani." << endl;
	antrian.pop();
	}
}

void display() {
	if (antrian.empty()) {
		cout << "Kondisi antrian: Kosong\n" << endl;
	} else {
		cout << "Kondisi antrian saat ini:" << endl;
		queue<string> tempQueue = antrian;
		while (!tempQueue.empty()) {
			cout << "- Mahasiswa " << tempQueue.front() << endl;
			tempQueue.pop();
		}
		cout << endl;
	}
}

int main() {
	enqueue("A");
	enqueue("B");
	enqueue("C");

	display();

	dequeue();

	display();

	enqueue("D");

	display();

	return 0;
}
