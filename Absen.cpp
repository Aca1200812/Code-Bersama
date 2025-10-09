#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Murid {
    int no;
    string name;
    string gender;
    string address;
    string phone;
};

int main() {
    vector<Murid> murid = {
        {1, "Andys Khrisna Syaputra Gani", "Laki-laki", "Kebon Hui", "083817744564"},
        {2, "Aulia Anissa Nurazizah", "Perempuan", "JL. Cihanjuang", "083813925991"},
        {3, "Bangkit Saputra", "Laki-laki", "JL. Cigugur Girang", "082128049420"},
        {4, "Delia Agustin Putri Suhendar", "Perempuan", "JL. Karyawangi", "0895400178990"},
        {5, "Edfan Prayuda", "Laki-laki", "Jl. Cihanjuang Rahayu", "081361856638"},
        {6, "Galang Regina Rival", "Laki-laki", "JL. Manoko", "083148049670"},
        {7, "Gania Hafsha", "Perempuan", "JL. Ciwaruga", "082130745609"},
        {8, "Gideon Sagala", "Laki-laki", "JL. Parongpong", "081373071732"},
        {9, "Indira Desti Novianti", "Perempuan", "JL. Kancah", "0881022086976"},
        {10, "Kanindya Pradita", "Perempuan", "JL. Manoko", "0882001360146"},
        {11, "Keisya Nur Hafizah", "Perempuan", "JL. Cihideung", "089629969732"},
        {12, "Lalu Yuda Pratama Riady Alwi", "Laki-laki", "JL. Parongpong", "088214936515"},
        {13, "Lovely Illyyin Azzahwa", "Perempuan", "JL. Cisarua", "081211500524"},
        {14, "M. Yoga Maulana", "Laki-laki", "JL. Cihideung", "08814001509"},
        {15, "Moch Daffa Apridatulloh", "Laki-laki", "JL. Bongkor", "089698943491"},
        {16, "Mochammad Raffi Alfatih", "Laki-laki", "JL. Cihanjuang", "08988202738"},
        {17, "Muhamad Hapid Nugraha", "Laki-laki", "JL. Karyawangi", ""},
        {18, "Muhamad Ridwan", "Laki-laki", "JL. Cihideung", ""},
        {19, "Muhammad Agung Setiawan", "Laki-laki", "JL. Panyairan", ""},
        {20, "Muhammad Anbar Namawi Saparudin", "Laki-laki", "JL. Lembang Asri", ""},
        {21, "Nabila Nur Fauziah", "Perempuan", "JL. Cihanjuang", ""},
        {22, "Nurrahmah Dwianti Apdi", "Perempuan", "JL. Cihanjuang", ""},
        {23, "Rafsa Dwi Munajid", "Laki-laki", "Kp. Pameuceulan", ""},
        {24, "Ramaryana", "Laki-Laki", "JL. Cihideung", ""},
        {25, "Randi Ramdani", "Laki-laki", "JL. Parongpong", ""},
        {26, "Rasya Zagat Kurniawan", "Laki-laki", "Kp. Pameuceulan", ""},
        {27, "Ratih Nur Alia", "Perempuan", "JL. Gereuhieum", ""},
        {28, "Rifki Irgi Pratama", "Laki-laki", "JL. Cisarua", ""},
        {29, "Rivki Muhammad Dirly", "Laki-laki", "JL. Cihanjuang", ""},
        {30, "Saputra Pratama", "Laki-laki", "Jl. Cihanjuang", ""},
        {31, "Viona Massayu Riskiani", "Perempuan", "JL. Manoko", ""},
        {32, "Zeefachrie Nadhitya", "Laki-laki", "Jl. Cihanjuang", ""}
    };

    const int wNo = 5, wName = 30, wGender = 14, wAddress = 22, wPhone = 15;
    const int totalWidth = 91;

    
    cout << "Daftar Absen Kelas 11- H" << endl << endl;

    cout << string(totalWidth, '-') << endl;

  
    cout << "| " << left << setw(wNo - 2) << "No" << "| "
         << setw(wName - 1) << "Nama" << "| "
         << setw(wGender - 1) << "Jenis Kelamin" << "| "
         << setw(wAddress - 1) << "Alamat" << "| "
         << setw(wPhone - 1) << "No Telepon" << "|" 
         << endl;

    
    cout << string(totalWidth, '-') << endl;

   
    for (const auto& s : murid) {
        string nomor = to_string(s.no) + ".";
        cout << "| " << left << setw(wNo - 2) << nomor << "| "
             << setw(wName - 1) << s.name << "| "
             << setw(wGender - 1) << s.gender << "| "
             << setw(wAddress - 1) << s.address << "| "
             << setw(wPhone - 1) << s.phone << "|" << endl;

        cout << string(totalWidth, '-') << endl;
    }

    int male = 0, female = 0;
    for (const auto& s : murid) {
        string g = s.gender;
        transform(g.begin(), g.end(), g.begin(), ::tolower);
        if (g == "laki-laki") male++;
        else if (g == "perempuan") female++;
    }
    cout << "Jumlah siswa Laki-laki: " << male << endl;
    cout << "Jumlah siswi Perempuan: " << female << endl;

    return 0;
}
