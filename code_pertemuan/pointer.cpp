#include <iostream>

using namespace std;

int main() {
    int angka = 10;
    int* penunjuk = &angka;
    cout << *penunjuk << endl;
    return 0;
}
