// Program Selection Sort
#include <iostream>  // Menyertakan library untuk input/output standar
using namespace std;

int main() {
    int n;
    // Meminta pengguna untuk memasukkan jumlah elemen data
    cout << "Masukkan jumlah elemen data: ";
    cin >> n;

    int data[n];  // Membuat array untuk menampung elemen data dengan ukuran n
    cout << "Masukkan elemen-elemen data: ";
    
    // Mengambil input data elemen satu per satu dari pengguna
    for (int i = 0; i < n; i++) {
        cin >> data[i];  // Menyimpan elemen yang dimasukkan oleh pengguna ke dalam array data
    }

    // Selection Sort dari terbesar hingga terkecil
    // Loop utama untuk melakukan proses sorting
    for(int i = 0; i < n - 1; i++) {
        int maxIndex = i;  // Anggap elemen pertama dalam sub-array yang belum terurut adalah yang terbesar
        // Mencari elemen terbesar di antara elemen yang belum terurut
        for (int j = i + 1; j < n; j++) {
            // Jika ditemukan elemen yang lebih besar dari elemen yang sudah dianggap terbesar
            if(data[j] > data[maxIndex]) {
                maxIndex = j;  // Update indeks elemen terbesar
            }
        }
        
        // Jika elemen terbesar yang ditemukan bukan elemen di posisi i, lakukan pertukaran
        if(maxIndex != i) {
            int temp = data[i];  // Menyimpan nilai data[i] sementara
            data[i] = data[maxIndex];  // Memindahkan elemen terbesar ke posisi i
            data[maxIndex] = temp;  // Memindahkan elemen di posisi i ke posisi maxIndex
        }
    }

    // Menampilkan hasil setelah proses sorting selesai
    cout << "Data setelah diurutkan dari terbesar hingga terkecil:\n";
    // Menampilkan elemen-elemen dalam array yang sudah diurutkan
    for (int i = 0; i < n; i++) {
        cout << data[i] << " ";  // Menampilkan setiap elemen di array
    }
    cout << endl;

    return 0;  // Program selesai
}
