#include <iostream>
#include <string>
#include "mll.h"

using namespace std;

int main() {
    ListJadwal LJ;
    ListMember LM;
    ListTiket LT;

    createListJadwal(LJ);
    createListMember(LM);
    createListTiket(LT);

    // Memuat data awal untuk memudahkan pengujian fitur
    initDataDummy(LJ, LM, LT);

    int pilihan = -1;
    while (pilihan != 0) {
        cout << "\n==================================================" << endl;
        cout << "      SISTEM PENJUALAN TIKET BIOSKOP (MLL-02)     " << endl;
        cout << "==================================================" << endl;
        cout << "1.  Tambah Jadwal Tayang" << endl;
        cout << "2.  Tambah Member" << endl;
        cout << "3.  Tampilkan Semua Jadwal Tayang" << endl;
        cout << "4.  Tampilkan Semua Member" << endl;
        cout << "5.  Beli Tiket Bioskop" << endl;
        cout << "6.  Batalkan Tiket Bioskop" << endl;
        cout << "7.  Tampilkan Denah Kursi Terisi per Jadwal" << endl;
        cout << "8.  Tampilkan Jadwal Beserta Penontonnya" << endl;
        cout << "9.  Tampilkan Member Beserta Riwayat Tiketnya" << endl;
        cout << "10. Laporan Film Terlaris & Top Member" << endl;
        cout << "11. Hapus Jadwal Tayang (Beserta Relasi Tiket)" << endl;
        cout << "12. Hapus Member (Beserta Relasi Tiket)" << endl;
        cout << "13. Cek Relasi & Jumlah Transaksi" << endl;
        cout << "0.  Keluar" << endl;
        cout << "==================================================" << endl;
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        if (pilihan == 1) {
            string kode, judul, studio, jam;
            int kapasitas;
            cout << "Kode Jadwal      : "; cin >> kode;
            cin.ignore();
            cout << "Judul Film       : "; getline(cin, judul);
            cout << "Studio           : "; getline(cin, studio);
            cout << "Jam Tayang       : "; getline(cin, jam);
            cout << "Kapasitas Kursi  : "; cin >> kapasitas;

            if (searchJadwal(LJ, kode) != nullptr) {
                cout << "[Gagal] Kode jadwal sudah terdaftar." << endl;
            } else {
                insertLastJadwal(LJ, createElemenJadwal(kode, judul, studio, jam, kapasitas));
                cout << "[Berhasil] Jadwal tayang berhasil ditambahkan." << endl;
            }
        } else if (pilihan == 2) {
            string id, nama;
            int poin;
            cout << "ID Member        : "; cin >> id;
            cin.ignore();
            cout << "Nama Member      : "; getline(cin, nama);
            cout << "Poin Awal        : "; cin >> poin;

            if (searchMember(LM, id) != nullptr) {
                cout << "[Gagal] ID member sudah terdaftar." << endl;
            } else {
                insertFirstMember(LM, createElemenMember(id, nama, poin));
                cout << "[Berhasil] Member berhasil ditambahkan." << endl;
            }
        } else if (pilihan == 3) {
            cout << "\n=== DAFTAR JADWAL TAYANG ===" << endl;
            displayListJadwal(LJ);
        } else if (pilihan == 4) {
            cout << "\n=== DAFTAR MEMBER ===" << endl;
            displayListMember(LM);
        } else if (pilihan == 5) {
            string kodeTiket, kodeJadwal, idMember;
            int kursi, harga;
            cout << "Kode Tiket       : "; cin >> kodeTiket;
            cout << "Kode Jadwal      : "; cin >> kodeJadwal;
            cout << "ID Member        : "; cin >> idMember;
            cout << "Nomor Kursi      : "; cin >> kursi;
            cout << "Harga Tiket (Rp) : "; cin >> harga;
            beliTiket(LJ, LM, LT, kodeTiket, kodeJadwal, idMember, kursi, harga);
        } else if (pilihan == 6) {
            string kodeTiket;
            cout << "Masukkan Kode Tiket yang akan dibatalkan: ";
            cin >> kodeTiket;
            batalkanTiket(LT, kodeTiket);
        } else if (pilihan == 7) {
            string kodeJadwal;
            cout << "Masukkan Kode Jadwal: ";
            cin >> kodeJadwal;
            tampilkanDenahKursi(LJ, LT, kodeJadwal);
        } else if (pilihan == 8) {
            cout << "\n=== DATA JADWAL BESERTA PENONTON ===" << endl;
            displayJadwalBesertaMember(LJ, LT);
        } else if (pilihan == 9) {
            cout << "\n=== DATA MEMBER BESERTA TIKET ===" << endl;
            displayMemberBesertaJadwal(LM, LT);
        } else if (pilihan == 10) {
            laporanFilmDanTopMember(LJ, LM, LT);
        } else if (pilihan == 11) {
            string kodeJadwal;
            bool berhasil = false;
            cout << "Masukkan Kode Jadwal yang akan dihapus: ";
            cin >> kodeJadwal;
            deleteJadwalBesertaRelasi(LJ, LT, kodeJadwal, berhasil);
            if (berhasil) {
                cout << "[Berhasil] Jadwal dan seluruh tiket terkait telah dihapus." << endl;
            } else {
                cout << "[Gagal] Jadwal tidak ditemukan." << endl;
            }
        } else if (pilihan == 12) {
            string idMember;
            bool berhasil = false;
            cout << "Masukkan ID Member yang akan dihapus: ";
            cin >> idMember;
            deleteMemberBesertaRelasi(LM, LT, idMember, berhasil);
            if (berhasil) {
                cout << "[Berhasil] Member dan seluruh tiket terkait telah dihapus." << endl;
            } else {
                cout << "[Gagal] Member tidak ditemukan." << endl;
            }
        } else if (pilihan == 13) {
            string kodeJadwal, idMember;
            cout << "Kode Jadwal : "; cin >> kodeJadwal;
            cout << "ID Member   : "; cin >> idMember;
            adrJadwal pJ = searchJadwal(LJ, kodeJadwal);
            adrMember pM = searchMember(LM, idMember);
            if (pJ == nullptr || pM == nullptr) {
                cout << "[Info] Jadwal atau Member tidak ditemukan." << endl;
            } else {
                cout << "Status Relasi         : "
                     << (isRelasi(LT, pJ, pM) ? "TERHUBUNG (Sudah beli tiket)" : "TIDAK TERHUBUNG") << endl;
                cout << "Jumlah Member di " << pJ->info.kode << "  : "
                     << countMemberOfJadwal(LT, pJ) << " member ("
                     << countTiketOfJadwal(LT, pJ) << " tiket)" << endl;
                cout << "Jumlah Jadwal " << pM->info.nama << "  : "
                     << countJadwalOfMember(LT, pM) << " jadwal" << endl;
            }
        } else if (pilihan == 0) {
            cout << "Terima kasih. Program selesai." << endl;
        } else {
            cout << "[Peringatan] Pilihan menu tidak valid." << endl;
        }
    }

    return 0;
}
