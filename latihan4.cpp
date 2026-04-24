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

void sisipDiAwal(Node*& kepala, int nilai) {
    Node* baru = new Node{nilai, kepala};
    kepala = baru;
}

void tampilkanLinkedList(Node* kepala) {
    for (Node* p = kepala; p; p = p->next) {
        cout << p->data;
        if (p->next)
            cout << " -> ";
        else
            cout << " -> NULL\n";
    }
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
    int n, x, tambahan;
    cout << "Masukkan jumlah data: ";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Masukkan data ke " << i << ": ";
        cin >> x;
        tambahBelakang(kepala, x);
    }
    cout << "Masukkan data yang ditambahkan di awal: ";
    cin >> tambahan;
    sisipDiAwal(kepala, tambahan);
    cout << "Data setelah ditambah di awal:\n";
    tampilkanLinkedList(kepala);
    hapusSemua(kepala);
    return 0;
}
