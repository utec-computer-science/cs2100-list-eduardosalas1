#include <iostream>
#include "List.h"
using namespace std;



int main(){

    List<int> lista;
    lista.push_back(8);
    lista.push_back(1);
    lista.push_back(3);
    lista.push_back(2);
    lista.push_back(9);
    lista.push_back(5);;
    lista.push_back(7);
    lista.push_back(7);
    lista.pop_back();
    lista.pop_front();
    lista.pop_front();
    lista.pop_front();
    lista.clear();
    lista.push_front(2);
    cout<<lista;


    return 0;
}
