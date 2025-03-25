#include <iostream>
#include <stack>
 
using namespace std;
 
struct Stiva {
    int value;
    Stiva* next;
};
 
void push(Stiva* &s, int val) {
    Stiva* x = new Stiva;
    x -> value = val;
    if(s == NULL) {
        x -> next = NULL;
        s = x;
    } else {
        x -> next = s;
        s = x;
    }
}
 
int top(Stiva* s) {
    return s -> value;
}
 
void pop(Stiva* &s) {
    Stiva* t = s;
    s = s -> next;
    delete t;
}
 
bool empty(Stiva* s) {
    return s == NULL;
}
 
bool parantezare(string &s) {
    Stiva* st = NULL;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '[') {
            push(st, s[i]);
        } else {
            if(empty(s)) {
                return false;
            } else {
                if(s[i] == ')' && top(st) != '(') {
                    return false;
                }
                if(s[i] == ']' && top(st) != '[') {
                    return false;
                }
                pop(st);
            }
        }
    }
    return empty(st);
}
 
void afisare(Stiva* s) {
    while(s != NULL) {
        cout << s -> value << ' ';
        s = s -> next;
    }
}
 
const int NMAX = 1e5;
int a[NMAX + 1];
int sol[NMAX + 1];
 
int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    Stiva* s = NULL;
    for(int i = n; i >= 1; i--) {
        while(!empty(s) && a[i] >= top(s)) {
            pop(s);
        }
        if(empty(s)) {
            sol[i] = -1;
        } else {
            sol[i] = top(s);
        }
        push(s, a[i]);
    }
    for(int i = 1; i <= n; i++) {
        cout << sol[i] << ' ';
    }
    return 0;
}