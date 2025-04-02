#include <iostream>
using namespace std;

// Structura nodului care reprezintă fiecare element din lista dublu înlănțuită circulară
struct Node {
    int data;       // Datele stocate în nod
    Node* next;     // Pointer către nodul următor
    Node* prev;     // Pointer către nodul anterior

    // Constructor pentru inițializarea unui nod cu date și setarea next/prev la nullptr
    Node(int data) : data(data), next(nullptr), prev(nullptr) {}
};

// Clasă care reprezintă o listă dublu înlănțuită circulară
class LinkedList {
private:
    Node* head; // Pointer către capul (primul nod) listei

public:
    // Constructor pentru inițializarea unei liste goale
    LinkedList() : head(nullptr) {}

    // Metodă pentru a insera un nou nod la începutul listei
    void insertAtHead(int data) {
        Node* newNode = new Node(data); // Crearea unui nou nod cu datele date
        if (head == nullptr) {
            // Dacă lista este goală, noul nod pointează către el însuși (circular)
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode; // Setarea noului nod ca fiind capul listei
        } else {
            // Dacă lista nu este goală, actualizează pointerii pentru a insera noul nod
            Node* tail = head->prev; // Obține nodul coadă (ultimul nod din listă)
            newNode->next = head;    // Noul nod pointează către capul curent
            newNode->prev = tail;    // Noul nod pointează către coada curentă
            head->prev = newNode;    // Actualizează pointerul anterior al capului curent
            tail->next = newNode;    // Actualizează pointerul următor al cozii curente
            head = newNode;          // Setează noul nod ca fiind noul cap
        }
    }

    // Metodă pentru a afișa elementele listei
    void displayList() const {
        if (head == nullptr) {
            // Dacă lista este goală, afișează un mesaj
            cout << "Lista este goală" << endl;
            return;
        }

        Node* temp = head; // Începe de la cap
        do {
            // Afișează datele fiecărui nod
            cout << temp->data << " <-> ";
            temp = temp->next; // Treci la nodul următor
        } while (temp != head); // Oprește-te când te întorci la cap
        cout << "(cap)" << endl; // Indică natura circulară a listei
    }

    // Destructor pentru a elibera memoria și a șterge toate nodurile din listă
    ~LinkedList() {
        if (head == nullptr) return; // Dacă lista este goală, nu este nimic de șters

        Node* current = head; // Începe de la cap
        do {
            Node* temp = current; // Stochează nodul curent
            current = current->next; // Treci la nodul următor
            delete temp; // Șterge nodul curent
        } while (current != head); // Oprește-te când te întorci la cap

        head = nullptr; // Setează capul la nullptr pentru a indica faptul că lista este goală
    }
};

int main() {
    LinkedList list;

    // Inserează elemente în listă
    list.insertAtHead(10);
    list.insertAtHead(20);

    // Afișează lista
    cout << "Lista dublu înlănțuită circulară: ";
    list.displayList();

    return 0;
}
