#include <iostream>
#include <string>

using namespace std;

struct Simpul {
    string data;
    Simpul* lanjut;
};

struct Antrean {
    Simpul* depan = nullptr;
    Simpul* belakang = nullptr;

    void masuk(string nilai) {
        Simpul* baru = new Simpul();
        baru->data = nilai;
        baru->lanjut = nullptr;
        
        if (belakang == nullptr) {
            depan = baru;
            belakang = baru;
        } else {
            belakang->lanjut = baru;
            belakang = baru;
        }
    }

    void keluar() {
        if (depan != nullptr) {
            Simpul* hapus = depan;
            depan = depan->lanjut;
            if (depan == nullptr) {
                belakang = nullptr;
            }
            delete hapus;
        }
    }

    string paling_depan() {
        if (depan != nullptr) {
            return depan->data;
        }
        return "";
    }

    bool kosong() {
        return depan == nullptr;
    }
};

int main() {
    Antrean antrean;
    antrean.masuk("Orang 1");
    antrean.masuk("Orang 2");
    
    while (!antrean.kosong()) {
        cout << antrean.paling_depan() << endl;
        antrean.keluar();
    }
    return 0;
}
