#include <iostream>
#include <algorithm> // untuk sort()
#include <math.h>    // untuk floor()
using namespace std;

int main() {
    int N;

    cout << "Masukkan jumlah data: ";
    cin >> N;

    int data[N];
    cout << "Masukkan " << N << " data (acak):\n";
    for (int i = 0; i < N; i++) {
        cin >> data[i];
    }

    // Urutkan data ascending agar bisa digunakan untuk Interpolation Search
    sort(data, data + N);

    cout << "\nData setelah diurutkan: ";
    for (int i = 0; i < N; i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    int cari;
    cout << "\nMasukkan data yang ingin dicari: ";
    cin >> cari;

    int low = 0, high = N - 1, flag = 0;
    int posisi;
    float posisi1;

    // TODO: Proses Interpolation Search
    while (low <= high && cari >= data[low] && cari <= data[high]) {
        posisi1 = low + ((float)(cari - data[low]) * (high - low)) / (data[high] - data[low]);
        posisi = floor(posisi1);

        cout <<"\nPosisi perkiraan = " << posisi1 << "-> dibulatkan ke " << posisi;

        if (data[posisi] == cari) {
            flag = 1;
            break;
        }

        if (data[posisi] > cari) {
            high = posisi - 1;
        } else {
            low = posisi + 1;
        }

        // Hitung posisi menggunakan rumus Interpolation Search
        posisi1 = low + ((float)(high - low) / (data[high] - data[low])) * (cari - data[low]);
        int pos = floor(posisi1);

        cout << "Posisi yang diestimasi: " << pos << endl;

        // Cek apakah data ditemukan
        if (data[pos] == cari) {
            posisi = pos;
            flag = 1;
            break;
        }

        // Jika data lebih besar, cari di bagian kanan
        if (data[pos] < cari) {
            low = pos + 1;
        }
        // Jika data lebih kecil, cari di bagian kiri
        else {
            high = pos - 1;
        }
    }
    

    cout << "\n\nHasil: ";
    if (flag == 1)
        cout << "Data " << cari << " ditemukan pada indeks ke-" << posisi << endl;
    else
        cout << "Data " << cari << " tidak ditemukan dalam array." << endl;

    return 0;
}
