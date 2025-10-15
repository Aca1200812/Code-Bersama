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
        {6, "Fajar Sidik Permana", "Laki-laki", "JL. Pameuceulan", "083822054878"},
        {7, "Galang Regina Rival", "Laki-laki", "JL. Manoko", "083148049670"},
        {8, "Gania Hafsha", "Perempuan", "JL. Ciwaruga", "082130745609"},
        {9, "Gideon Sagala", "Laki-laki", "JL. Parongpong", "081373071732"},
        {10, "Indira Desti Novianti", "Perempuan", "JL. Kancah", "0881022086976"},
        {11, "Kanindya Pradita", "Perempuan", "JL. Manoko", "0882001360146"},
        {12, "Keisya Nur Hafizah", "Perempuan", "JL. Cihideung", "089629969732"},
        {13, "Lalu Yuda Pratama Riady Alwi", "Laki-laki", "JL. Parongpong", "088214936515"},
        {14, "Lovely Illyyin Azzahwa", "Perempuan", "JL. Cisarua", "081211500524"},
        {15, "M. Yoga Maulana", "Laki-laki", "JL. Cihideung", "08814001509"},
        {16, "Moch Daffa Apridatulloh", "Laki-laki", "JL. Bongkor", "089698943491"},
        {17, "Mochammad Raffi Alfatih", "Laki-laki", "JL. Cihanjuang", "08988202738"},
        {18, "Muhamad Hapid Nugraha", "Laki-laki", "JL. Karyawangi", "083117250245"},
        {19, "Muhamad Ridwan", "Laki-laki", "JL. Cihideung", "083862213899"},
        {20, "Muhammad Agung Setiawan", "Laki-laki", "JL. Panyairan", "082119036762"},
        {21, "Muhammad Anbar Namawi", "Laki-laki", "JL. Lembang Asri", "0895700836655"},
        {22, "Nabila Nur Fauziah", "Perempuan", "JL. Cihanjuang", "085173298526"},
        {23, "Nurrahmah Dwianti Apdi", "Perempuan", "JL. Cihanjuang", "081461252368"},
        {24, "Rafsa Dwi Munajid", "Laki-laki", "Kp. Pameuceulan", "081221864448"},
        {25, "Ramaryana", "Laki-Laki", "JL. Cihideung", "082116299617"},
        {26, "Randi Ramdani", "Laki-laki", "JL. Parongpong", "085189928807"},
        {27, "Rasya Zagat Kurniawan", "Laki-laki", "Kp. Pameuceulan", "083131739579"},
        {28, "Ratih Nur Alia", "Perempuan", "JL. Gereuhieum", "085722410684"},
        {29, "Rifki Irgi Pratama", "Laki-laki", "JL. Cisarua", "083194110815"},
        {30, "Rivki Muhammad Dirly", "Laki-laki", "JL. Cihanjuang", "085798607370"},
        {31, "Saputra Pratama", "Laki-laki", "Jl. Cihanjuang", "089519685494"},
        {32, "Viona Massayu Riskiani", "Perempuan", "JL. Manoko", "082258115938"},
        {33, "Zeefachrie Nadhitya", "Laki-laki", "Jl. Cihanjuang", "083850960343"}
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
