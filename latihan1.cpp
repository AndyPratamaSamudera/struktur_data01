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

void tampilkanTraversalDanJumlah(Node* kepala) {
    int indeks = 1;
    int jumlah = 0;
    for (Node* p = kepala; p; p = p->next) {
        cout << "Data ke " << indeks << ": " << p->data << "\n";
        indeks++;
        jumlah++;
    }
    cout << "Jumlah data: " << jumlah << "\n";
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
    tampilkanTraversalDanJumlah(kepala);
    hapusSemua(kepala);
    return 0;
}
