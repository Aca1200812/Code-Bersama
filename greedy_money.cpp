#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> makeChange(int amount, vector<int>& coins) {
    vector<int> result;
    
    sort(coins.rbegin(), coins.rend());

    for (int coin : coins) {
        while (amount >= coin) {
            result.push_back(coin);
            amount -= coin;
        }
    }

    return result;
}

int main() {
    
    vector<int> coins = {1000, 500, 200, 100, 50, 20, 10, 5, 1};

    int amount;
    cout << "Masukkan jumlah uang yang ingin dijumlahkan: ";
    cin >> amount;

    vector<int> change = makeChange(amount, coins);

    cout << "Koin yang digunakan: ";
    for (int coin : change) {
        cout << coin << " ";
    }
    cout << endl;

    cout << "Jumlah koin minimum: " << change.size() << endl;

    return 0;
}
