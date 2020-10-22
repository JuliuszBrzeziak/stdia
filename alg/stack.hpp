#include <iostream>
#include <cstdlib>
using namespace std;



template<class T, int N>
class Stack {
    template<class U> //Uniwersalne referencje

    T *arr;

    public:

    void push(U&& x); //Wstawia element x na stos
    T pop(); //Usuwa element ze stosu i zwraca jego wartość
    T& top();  //Zwraca referencję do najmłodszego elementu
    int size(); //Zwraca liczbę elementów na stosie
    bool empty(); //Sprawdza czy stos jest pusty
};




//chlebek
//daniszewski
//kołodziej