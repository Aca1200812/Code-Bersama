#include <iostream>
#include <cmath>

using namespace std;

int main() {
    char lagi;
    do {
        int pilihan;
        double luas;

        cout << "Program Menghitung Luas Bangun Datar" << endl;
        cout << "====================================" << endl;
        cout << "1. Persegi" << endl;
        cout << "2. Persegi Panjang" << endl;
        cout << "3. Segitiga" << endl;
        cout << "4. Lingkaran" << endl;
        cout << "Pilih bangun datar (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                double sisi;
                cout << "Masukkan panjang sisi persegi: ";
                cin >> sisi;
                luas = sisi * sisi;
                cout << "Luas Persegi: " << luas << endl;
                cout << "Penjelasan: Luas persegi dihitung dengan rumus sisi * sisi, karena persegi memiliki empat sisi yang sama panjang." << endl;
                break;
            }
            case 2: {
                double panjang, lebar;
                cout << "Masukkan panjang persegi panjang: ";
                cin >> panjang;
                cout << "Masukkan lebar persegi panjang: ";
                cin >> lebar;
                luas = panjang * lebar;
                cout << "Luas Persegi Panjang: " << luas << endl;
                cout << "Penjelasan: Luas persegi panjang dihitung dengan rumus panjang * lebar, karena merupakan perkalian dimensi panjang dan lebar." << endl;
                break;
            }
            case 3: {
                double alas, tinggi;
                cout << "Masukkan alas segitiga: ";
                cin >> alas;
                cout << "Masukkan tinggi segitiga: ";
                cin >> tinggi;
                luas = 0.5 * alas * tinggi;
                cout << "Luas Segitiga: " << luas << endl;
                cout << "Penjelasan: Luas segitiga dihitung dengan rumus 0.5 * alas * tinggi, karena itu adalah rumus standar untuk menghitung area segitiga." << endl;
                break;
            }
            case 4: {
                double radius;
                cout << "Masukkan jari-jari lingkaran: ";
                cin >> radius;
                luas = M_PI * radius * radius;
                cout << "Luas Lingkaran: " << luas << endl;
                cout << "Penjelasan: Luas lingkaran dihitung dengan rumus π * r², di mana π adalah konstanta matematika dan r adalah jari-jari." << endl;
                break;
            }
            default: {
                cout << "Pilihan tidak valid!" << endl;
                break;
            }
        }

        cout << "Apakah ingin menghitung luas bangun datar lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    cout << "Terima kasih telah menggunakan program ini!" << endl;
    return 0;
}
