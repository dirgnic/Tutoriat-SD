#include <iostream>
#include <queue>
using namespace std;

//fie date 10 elemente dintr-un vector nesortat, 
//sa se afle primele 3 cele mai mari valori.
//dupa, mai citim 40 de elemente de la tastatura. 
//cum putem retine si updata constant 
//cele 3 cele mai amri valori?
int main(){

    vector<int> v(100, 0);
    priority_queue<int> pq; //creez un max heap de int
 

    for(int i=0; i<10; i++)
        cin>>v[i], pq.push(v[i]);

    int a = pq.top(); //cel m mare elem
    pq.pop();
    int b = pq.top(); // al doilea cel m mare elem
    pq.pop();
    int c = pq.top(); // al treilea cel m mare elem
    pq.pop();

    pq.push(a), pq.push(b), pq.push(c);

    for(int i=11; i<40; i++)
       cin>>v[i], pq.push(v[i]);
    
    int a = pq.top(); //cel m mare elem
    pq.pop();
    int b = pq.top(); // al doilea cel m mare elem
    pq.pop();
    int c = pq.top(); // al treilea cel m mare elem
    pq.pop();
    return 0;
}
