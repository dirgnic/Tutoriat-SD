#include <iostream>
using namespace std;

// Simplu înlănțuită
struct NodeS {
    int data;
    NodeS* next;
    NodeS(int v): data(v), next(this) {}
};

void clearCircularS(NodeS*& head) {
    if (!head) return;
    NodeS* cur = head->next;
    while (cur != head) {
        NodeS* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

// Dublu înlănțuită
struct NodeD {
    int data;
    NodeD* next;
    NodeD* prev;
    NodeD(int v): data(v), next(this), prev(this) {}
};

void clearCircularD(NodeD*& head) {
    if (!head) return;
    NodeD* cur = head->next;
    while (cur != head) {
        NodeD* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
    delete head;
    head = nullptr;
}

int main() {
    NodeS* headS = new NodeS(1);
    headS->next = headS;
    clearCircularS(headS);
    cout << "Lista circulara simplu inlantuaita curatata.\n";

    NodeD* headD = new NodeD(2);
    headD->next = headD;
    headD->prev = headD;
    clearCircularD(headD);
    cout << "Lista circulara dublu inlantuaita curatata.\n";
    return 0;
}
