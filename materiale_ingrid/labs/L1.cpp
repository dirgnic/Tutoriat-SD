#include <bits/stdc++.h>

using namespace std;

struct Nod {
    int value;
    Nod *next;
};

int sz = 0;

void afisare(Nod* p) {
    if(p == NULL) {
        cout << "Lista vida";
    } else {
        while(p != NULL) {
            cout << p -> value << ' ';
            p = p -> next;
        }
    }
    cout << '\n';
}

//adauga la final de lista
void addEnd(Nod* &start, Nod* &end, int val) {
    Nod* x = new Nod;
    x -> value = val;
    x -> next = NULL;
    if(end == NULL) {
        end = x;
        start = end;
    } else {
        end -> next = x;
        end = x;
    }
    sz++;
}

//adauga la inceput de lista
void addBegin(Nod* &start, Nod* &end, int val) {
    Nod* x = new Nod;
    x -> value = val;
    if(start == NULL) {
        x -> next = NULL;
        end = x;
        start = end;
    } else {
        x -> next = start;
        start = x;
    }
    sz++;
}

//adauga in orice pozitie (numerotata de la 1)
void addPosition(Nod* &start, Nod* &end, int pos, int val) {
    if(pos < 1 || pos > sz + 1) {
        cout << "Pozitie invalida\n";
    } else {
        if(pos == 1) {
            addBegin(start, end, val);
        } else {
            if(pos == sz + 1) {
                addEnd(start, end, val);
            } else {
                Nod* st = start;
                for(int i = 1; i < pos - 1; i++) {
                    st = st -> next;
                }
                Nod* dr = st -> next;
                Nod* x = new Nod;
                x -> value = val;
                st -> next = x;
                x -> next = dr;
                sz++;
            }
        }
    }
}

//cauta o valoare
bool Search(Nod* p, int val) {
    while(p != NULL) {
        if(p -> value == val) {
            return true;
        }
    }
    return false;
}

//stergerea unei valori de la o pozitie
void deletePosition(Nod* &start, Nod* &end, int pos) {
    if(pos < 1 || pos > sz) {
        cout << "Pozitie invalida\n";
    } else {
        if(pos == 1) {
            Nod* temp = start;
            start = start -> next;
            delete temp;
        } else {
            if(pos == sz) {
                Nod* st = start;
                for(int i = 1; i < pos - 1; i++) {
                    st = st -> next;
                }
                Nod* temp = st -> next;
                st -> next = NULL;
                end = st;
                delete temp;
            } else {
                Nod* st = start;
                for(int i = 1; i < pos - 1; i++) {
                    st = st -> next;
                }
                Nod* temp = st -> next;
                Nod* dr = temp -> next;
                st -> next = dr;
                delete temp;
            }
        }
    }
    sz--;
}

//reverse la lista cu O(1) memorie extra
void reverse(Nod* &start, Nod* end) {
    if(sz >= 2) {
        Nod* st = start;
        Nod* dr = start -> next;
        start -> next = NULL;
        while(dr != NULL) {
            Nod* x = dr -> next;
            dr -> next = st;
            st = dr;
            dr = x;
        }
        start = end;
    }
}

//sortare prin insertie
void insertionSort() {
    Nod *start = NULL;
    Nod *end = NULL;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        if(sz == 0) {
            addBegin(start, end, val);
        } else {
            if(val <= start -> value) {
                addBegin(start, end, val);
            } else {
                if(val >= end -> value) {
                    addEnd(start, end, val);
                } else {
                    Nod* st = start;
                    while(true) {
                        if(st -> value <= val && val <= st -> next -> value) {
                            Nod* x = new Nod;
                            x -> value = val;
                            x -> next = st -> next;
                            st -> next = x;
                            break;
                        }
                        st = st -> next;
                    } 
                }
            }
        }
    }
    afisare(start);
}

//adunare numere mari
void add(Nod* st1, Nod* st2, Nod* &st3, Nod* &dr3) {
    int t = 0;
    while(st1 != NULL && st2 != NULL) {
        int sum = st1 -> value + st2 -> value + t;
        addBegin(st3, dr3, sum % 10);
        t = sum / 10;
        st1 = st1 -> next;
        st2 = st2 -> next;
    }
    while(st1 != NULL) {
        int sum = st1 -> value + t;
        addBegin(st3, dr3, sum % 10);
        t = sum / 10;
        st1 = st1 -> next;
    }
    while(st2 != NULL) {
        int sum = st2 -> value + t;
        addBegin(st3, dr3, sum % 10);
        t = sum / 10;
        st2 = st2 -> next;
    }
    if(t > 0) {
        addBegin(st3, dr3, t);
    }
}

//pentru primele cerinte + reverse
void test1() {
    Nod* start = NULL;
    Nod* end = NULL;
    for(int i = 1; i <= 5; i++) {
        addEnd(start, end, i);
    }
    afisare(start);
    deletePosition(start, end, 5);
    deletePosition(start, end, 4);
    //deletePosition(start, end, 2);
    //reverse(start, end);
    afisare(start);
}

//pentru adunare numere mari
void test2() {
    Nod* st1 = NULL;
    Nod* dr1 = NULL;
    Nod* st2 = NULL;
    Nod* dr2 = NULL;
    string nr1, nr2;
    cin >> nr1;
    for(int i = 0; i < (int)nr1.size(); i++) {
        addBegin(st1, dr1, nr1[i] - '0');
    }
    cin >> nr2;
    for(int i = 0; i < (int)nr2.size(); i++) {
        addBegin(st2, dr2, nr2[i] - '0');
    }
    Nod* st3 = NULL;
    Nod* dr3 = NULL;
    add(st1, st2, st3, dr3);
    afisare(st3);
}

int main() {
    test1();
    //insertionSort();
    //test2();
    return 0;
}