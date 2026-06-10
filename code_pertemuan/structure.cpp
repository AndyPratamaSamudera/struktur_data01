#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    int umur;
};

int main() {
    Mahasiswa pelajar;
    pelajar.nama = "Budi";
    pelajar.umur = 20;
    cout << pelajar.nama << " " << pelajar.umur << endl;
    return 0;
}
