#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Student {
    int no;
    string name;
    string gender;
    string address;
    string phone;
};

int main() {
    vector<Student> students = {
        {1, "Andys Khrisna Syaputra Gani", "Laki-laki", "Kebon Hui", "083817744564"},
        {2, "Aulia Anissa Nurazizah", "Perempuan", "JL. Cihanjuang", "083813925991"},
        {3, "Bangkit Saputra", "Laki-laki", "JL. Cigugur Girang", "082128049420"},
        {4, "Delia Agustin Putri Suhendar", "Perempuan", "JL. Karyawangi", "0895400178990"},
        {5, "Edfan Prayuda", "Laki-laki", "Jl. Cihanjuang", "081361856638"},
        {6, "Galang Regina Rival", "Laki-laki", "JL. Manoko", "083148049670"},
        {7, "Gania Hafsha", "Perempuan", "JL. Ciwaruga", "082130745609"},
        {8, "Gideon Sagala", "Laki-laki", "JL. Parongpong ", "081373071732"},
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
        {20, "Muhammad Anbar Nawawi Saparudin", "Laki-laki", "JL. Lembang Asri", ""},
        {21, "Nabila Nur Fauziah", "Perempuan", "JL. Cihanjuang", ""},
        {22, "Nurrahmah Dwianti Apdi", "Perempuan", "JL. Cihanjuang", ""},
        {23, "Rafsa Dwi Munajid", "Laki-laki", "Kp. Pameuceulan", ""},
        {24, "Ramaryana", "Perempuan", "JL. Cihideung", ""},
        {25, "Randi Ramdani", "Laki-laki", "JL. Parongpong", ""},
        {26, "Rasya Zagat Kurniawan", "Laki-laki", "Kp. Pameuceulan", ""},
        {27, "Ratih Nur Alia", "Perempuan", "JL. Gereuhieum", ""},
        {28, "Rifki Irgi Pratama", "Laki-laki", "JL. Cisarua", ""},
        {29, "Rivki Muhammad Dirly", "Laki-laki", "JL.Cihanjuang", ""},
        {30, "Saputra Pratama", "Laki-laki", "Jl. Cihanjuang", ""},
        {31, "Viona Massayu Riskiani", "Perempuan", "JL. Manoko", ""},
        {32, "Zeefachrie Nadhitya", "Laki-laki", "Jl. Cihanjuang", ""}
    };

    cout << "┌" << string(4, '-') << "+" << string(32, '-') << "+" << string(13, '-') << "+" << string(20, '-') << "+" << string(15, '-') << "+" << endl;
    cout << "|" << left << setw(4) << "No" << "|"
         << setw(32) << "Nama" << "|"
         << setw(13) << "Jenis Kelamin" << "|"
         << setw(20) << "Alamat" << "|"
         << setw(15) << "No Telepon" << "|" << endl;
    cout << "+" << string(4, '-') << "+" << string(32, '-') << "+" << string(13, '-') << "+" << string(20, '-') << "+" << string(15, '-') << "+" << endl;

    for (const auto& student : students) {
        cout << "|" << left << setw(4) << (to_string(student.no) + ".") << "|"
             << setw(32) << student.name << "|"
             << setw(13) << student.gender << "|"
             << setw(20) << student.address << "|"
             << setw(15) << student.phone << "|" << endl;
    }
    cout << "+" << string(4, '-') << "+" << string(32, '-') << "+" << string(13, '-') << "+" << string(20, '-') << "+" << string(15, '-') << "+" << endl;

    int male = 0, female = 0;
    for (const auto& student : students) {
        if (student.gender == "Laki-laki") male++;
        else if (student.gender == "Perempuan") female++;
    }
    cout << "Jumlah siswa Laki-laki: " << male << endl;
    cout << "Jumlah siswa Perempuan: " << female << endl;

    return 0;
}
