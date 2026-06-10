#include <iostream>
#include <string>

using namespace std;

struct Simpul {
    string data;
    Simpul* bawah;
};

struct Tumpukan {
    Simpul* atas = nullptr;

    void dorong(string nilai) {
        Simpul* baru = new Simpul();
        baru->data = nilai;
        baru->bawah = atas;
        atas = baru;
    }

    void tarik() {
        if (atas != nullptr) {
            Simpul* hapus = atas;
            atas = atas->bawah;
            delete hapus;
        }
    }

    string puncak() {
        if (atas != nullptr) {
            return atas->data;
        }
        return "";
    }

    bool kosong() {
        return atas == nullptr;
    }
};

int main() {
    Tumpukan tumpukan;
    tumpukan.dorong("Buku A");
    tumpukan.dorong("Buku B");
    
    while (!tumpukan.kosong()) {
        cout << tumpukan.puncak() << endl;
        tumpukan.tarik();
    }
    return 0;
}
