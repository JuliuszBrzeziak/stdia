#include<iostream>
using namespace std;

int main()
{
  int *a, *b, c;
  
  c = 5;
  a = &c; //zmienna a wskazuje na adres zmiennej c
  b = &c; //zmienna b wskazuje na adres zmiennej c
  
  cout<<*a<<" "<<*b<<endl; //wypisanie wartości, którą przechowuje zmienna  c (2 razy 5)
  
  *a = 7; //zmiana wartosci zmiennej c
  
  cout<<*a<<" "<<*b<<" "<<c; //zostanie wypisana trzy razy wartość 7 
  
  return 0;
}