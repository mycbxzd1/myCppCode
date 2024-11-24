#include <iostream>
using namespace std;
char letter[3] = {'A', 'B', 'C'};
int n, number = 0;
bool check(string a) {
    if(a.size() < 4) {
        return true;
    }
    for (int i = 0; i < a.size() - 3; ++i) {
        if(a[i] == a[i + 2] && a[i + 1] == a[i + 3]) {
            return false;
        }
    }
    return true;
}
void substring(string a) {
    if(a.length() == n) {
        number++;
        return;
    }
    for (char i : letter) {
        a += i;
        if(check(a)) substring(a);
        a = a.substr(0, a.length() -1);
    }
}

int main() {
    cin >> n;string a;
    substring(a);
    cout << number;
}
