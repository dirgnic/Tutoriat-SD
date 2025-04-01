#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Structura pentru nodul din lista simplu înlănțuită circulară
struct Node {
    int data;
    Node* next;
};

// Funcție pentru crearea listei simplu înlănțuite circulare
//  - primește numărul de elemente k și vectorul de valori
//  - întoarce pointer la primul nod (care conține x1)
Node* createCircularList(int k, const int values[]) {
    if (k <= 0) return nullptr;

    // Creăm primul nod (care va conține x1)
    Node* head = new Node;
    head->data = values[0];
    head->next = nullptr;

    // Nod curent folosit la construire
    Node* current = head;

    // Construim restul nodurilor
    for (int i = 1; i < k; i++) {
        Node* newNode = new Node;
        newNode->data = values[i];
        newNode->next = nullptr;
        current->next = newNode;
        current = newNode;
    }

    // Facem lista să fie circulară
    current->next = head;

    // Returnăm pointer la primul nod (nodul "distins")
    return head;
}

int main() {
    // Deschidem fișierul de intrare
    ifstream fin("date.in");
    if (!fin.is_open()) {
        cerr << "Eroare la deschiderea fisierului de intrare!\n";
        return 1;
    }

    int k, nr, n; // k elem, nr de cate ori dam la ruleta, n cate pozitii putem sari max la
    // o rotire
    fin >> k >> nr >> n; // k, nr si n

    // Verificăm condițiile de bază (k, nr, n >= 3 și n > k)
    if (k < 3 || nr < 3 || n < 3 || n <= k) {
        cerr << "Date de intrare invalide! Verificati ca (k, nr, n >= 3) si (n > k).\n";
        return 1;
    }

    // Citim valorile pentru cele k sectoare
    int* values = new int[k];
    for (int i = 0; i < k; i++) {
        fin >> values[i];
    }
    fin.close(); // nu mai avem nevoie de fișier

    // Construim lista circulară cu valorile date
    Node* head = createCircularList(k, values);
    if (!head) {
        cerr << "Nu s-a putut crea lista circulara!\n";
        delete[] values;
        return 1;
    }

    // Inițializăm generatorul de numere aleatoare
    srand((unsigned)time(nullptr));

    // Generăm aleator numărul de încercări s (între 1 și nr)
    int s = rand() % nr + 1;

    cout << "Valoarea curenta a jucatorului este: 0." << endl;
    cout << "Numarul maxim de incercari pentru acest joc este: " << s << endl;

    // Plecăm de la nodul "distins" (head)
    Node* current = head;
    long long scorCurent = 0;

    for (int i = 1; i <= s; i++) {
        cout << "\nDoriti sa invartiti roata pentru incercarea " << i
             << "/" << s << "? (y/n): ";
        string raspuns;
        cin >> raspuns;

        if (raspuns == "y" || raspuns == "Y") {
            // Generăm aleator r între 1 și n
            int r = rand() % n + 1;

            // Avansăm r pași în lista circulară
            for (int pas = 0; pas < r; pas++) {
                current = current->next; //avansare in lista
            }

            // Adăugăm valoarea nodului curent la scor
            scorCurent += current->data;

            cout << "Nodul curent are valoarea: " << current->data << endl;
            cout << "Scorul curent dupa aceasta invartire: " << scorCurent << endl;
        }
        else {
            // Jucătorul alege să nu mai învârtă; ieșim din bucla de joc
            cout << "Ati ales sa va opriti. Scorul final este: " << scorCurent << endl;
            break;
        }
    }

    // Dacă s-a terminat bucla fără ca jucătorul să oprească jocul, afișăm scorul final
    if (cin && cin.good()) {  // Verificăm că nu am ieșit deja
        cout << "\nJoc incheiat. Scorul final este: " << scorCurent << endl;
    }

    // Eliberăm memoria alocată pentru vector și noduri
    delete[] values;

    // Deoarece lista este circulară, trebuie să ștergem corect toate nodurile
    //  - atenție să nu intrăm într-un ciclu infinit
    if (head) {
        Node* start = head;
        Node* temp = head->next;
        while (temp != start) {
            Node* urm = temp->next;
            delete temp;
            temp = urm;
        }
        delete head;
        head = nullptr;
    }

    return 0;
}
