#include <iostream>
#include <string>

using namespace std;
void print(string ref){
    cout << "[" << ref << "]" << endl;
}

string hello(string& ref){
    return "hell";
}

int main(){
 
    string str{"asdasd"};
                //T& T::operator=(char T&)
    str = {"re"}; //operator przypisania kopiujący T& T::operator=(T&&)
    string& re = str;
   // string& re = string{"12"};


    print(str);
    string&& tmp = string{"abc"};

    str = tmp; // sting::operator=(const string&)
    print(str);

    str = move(tmp); //string::operator=(string&&) operator przenoszoący po prawiej jest tymczasowy
    print(str);

    int i; //l value
    int j;



}
