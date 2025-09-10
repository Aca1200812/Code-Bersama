#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    vector<int> denominations = {100000, 50000, 25000, 10000, 5000, 1000, 500, 100, 50, 25};
    vector<int> counts(denominations.size(), 0);

    
    long long price;
    cout << "Masukkan harga produk: ";
    cin >> price;

    
    long long cash;
    cout << "Masukkan jumlah uang yang dibayarkan: ";
    cin >> cash;

    
    long long change = cash - price;

    if (change < 0) {
        cout << "Uang tidak cukup! Kekurangan: " << -change << endl;
        return 0;
    } else if (change == 0) {
        cout << "Tidak ada kembalian." << endl;
        return 0;
    }

    cout << "Kembalian: " << change << endl;

    
    for (size_t i = 0; i < denominations.size(); ++i) {
        if (change >= denominations[i]) {
            counts[i] = change / denominations[i];
            change %= denominations[i];
        }
    }

        cout << "Rekomendasi pecahan:" << endl;
    for (size_t i = 0; i < denominations.size(); ++i) {
        if (counts[i] > 0) {
            long long total = denominations[i] * counts[i];
            cout << total << endl;
        }
    }

    
    if (change > 0) {
        cout << "Sisa yang tidak bisa dibagi: " << change << endl;
    }
    return 0;
}