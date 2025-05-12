#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int v): data(v), next(nullptr) {}
};

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int x;
    cout << "Introduceti valori (0 = stop): ";
    while (cin >> x && x != 0) {
        Node* nou = new Node(x);
        if (!head) head = tail = nou;
        else {
            tail->next = nou;
            tail = nou;
        }
    }
    if (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    cout << "Lista dupa stergerea primului nod: ";
    for (Node* p = head; p; p = p->next) cout << p->data << " ";
    cout << "\n";
    while (head) {
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    return 0;
}
