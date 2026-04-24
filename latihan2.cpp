#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void tambahBelakang(Node*& kepala, int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (!kepala) {
        kepala = baru;
        return;
    }
    Node* p = kepala;
    while (p->next) p = p->next;
    p->next = baru;
}

void tampilkanSemuaData(Node* kepala) {
    int indeks = 1;
    for (Node* p = kepala; p; p = p->next) {
        cout << "Data ke " << indeks << ": " << p->data << "\n";
        indeks++;
    }
}

int cariNilaiTerbesar(Node* kepala) {
    if (!kepala) return 0;
    int maks = kepala->data;
    for (Node* p = kepala->next; p; p = p->next)
        if (p->data > maks) maks = p->data;
    return maks;
}

void hapusSemua(Node*& kepala) {
    while (kepala) {
        Node* t = kepala;
        kepala = kepala->next;
        delete t;
    }
}

int main() {
    Node* kepala = nullptr;
    int n, x;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> x;
        tambahBelakang(kepala, x);
    }
    tampilkanSemuaData(kepala);
    cout << "Terbesar adalah : " << cariNilaiTerbesar(kepala) << "\n";
    hapusSemua(kepala);
    return 0;
}
