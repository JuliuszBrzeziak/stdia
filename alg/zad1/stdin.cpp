#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n  = stoi(s);
        for(int i = 0; i < n; i++){
            cin >> s;
            cout <<"odebrałem"<< s << endl;
        }
    cout << "koncze" << endl;
    return 0;
}