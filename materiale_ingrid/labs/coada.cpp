#include <iostream>
#include <stack>
 
using namespace std;
 
struct Coada {
    int value;
    Coada* next;
};
 
void push(Coada* &st, Coada* &dr, int val) {
    Coada* x = new Coada;
    x -> value = val;
    x -> next = NULL;
    if(st == NULL) {
        st = dr = x;
    } else {
        dr -> next = x;
        dr = x;
    }
}
 
int front(Coada* st) {
    return st -> value;
}
 
void pop(Coada* &st) {
    Coada* t = st;
    st = st -> next;
    delete t;
}
 
bool empty(Coada* st) {
    return st == NULL;
}
 
int main() {
    Coada* st = NULL;
    Coada* dr = NULL;
    push(st, dr, 3);
    push(st, dr, 4);
    push(st, dr, 5);
    cout << front(st) << '\n';
    pop(st);
    cout << front(st);
    return 0;
}