#include <iostream>
#include <string>

using namespace std;

int main() {
    for (string line; getline(cin, line);) {
        // int l = atoi(line);
        const char *t = line.c_str();
        int j = atoi(t);

        for(int i = 0; i < j; i++){
            cout<< i ;
        }
        cout << "stdin"<<line << endl;
    }
    return 0;
}