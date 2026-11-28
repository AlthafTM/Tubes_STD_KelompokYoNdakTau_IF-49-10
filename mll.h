#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct elemenJadwal;
struct elemenMember;
struct elemenTiket;

typedef elemenJadwal* adrJadwal;
typedef elemenMember* adrMember;
typedef elemenTiket*  adrTiket;

struct Jadwal {
    string kode;
    string judulFilm;
    string studio;
    string jamTayang;
    int kapasitas;
};

struct Member {
    string idMember;
    string nama;
    int poin;
};

struct Tiket {
    string kodeTiket;
    int nomorKursi;
    int harga;
};

struct elemenJadwal {
    Jadwal info;
    adrJadwal next;
};

struct elemenMember {
    Member info;
    adrMember next;
};

struct elemenTiket {
    Tiket info;
    adrJadwal jadwal;
    adrMember member;
    adrTiket next;
};

struct ListJadwal {
    adrJadwal first;
    adrJadwal last;
};

struct ListMember {
    adrMember first;
};

struct ListTiket {
    adrTiket first;
    adrTiket last;
};

void createListJadwal(ListJadwal &L);
void createListMember(ListMember &L);
void createListTiket(ListTiket &L);

bool isEmptyJadwal(ListJadwal L);
bool isEmptyMember(ListMember L);
bool isEmptyTiket(ListTiket L);

adrJadwal createElemenJadwal(const string &kode, const string &judulFilm,
                             const string &studio, const string &jamTayang, int kapasitas);
adrMember createElemenMember(const string &idMember, const string &nama, int poin);
adrTiket createElemenTiket(const string &kodeTiket, int nomorKursi, int harga,
                           adrJadwal pJadwal, adrMember pMember);

void insertLastJadwal(ListJadwal &L, adrJadwal p);
void insertFirstMember(ListMember &L, adrMember p);
void insertLastTiket(ListTiket &L, adrTiket p);

void deleteFirstJadwal(ListJadwal &L, adrJadwal &p);
void deleteLastJadwal(ListJadwal &L, adrJadwal &p);
void deleteAfterJadwal(ListJadwal &L, adrJadwal prec, adrJadwal &p);

void deleteFirstMember(ListMember &L, adrMember &p);
void deleteLastMember(ListMember &L, adrMember &p);
void deleteAfterMember(ListMember &L, adrMember prec, adrMember &p);

void deleteFirstTiket(ListTiket &L, adrTiket &q);
void deleteLastTiket(ListTiket &L, adrTiket &q);
void deleteAfterTiket(ListTiket &L, adrTiket prec, adrTiket &q);

void deleteJadwalTertentu(ListJadwal &L, adrJadwal target, adrJadwal &p);
void deleteMemberTertentu(ListMember &L, adrMember target, adrMember &p);
void deleteTiketTertentu(ListTiket &L, adrTiket target, adrTiket &q);

void deleteTiketByJadwal(ListTiket &LT, adrJadwal pJadwal);
void deleteTiketByMember(ListTiket &LT, adrMember pMember);
void deleteJadwalBesertaRelasi(ListJadwal &LJ, ListTiket &LT, const string &kode, bool &berhasil);
void deleteMemberBesertaRelasi(ListMember &LM, ListTiket &LT, const string &idMember, bool &berhasil);
void deleteRelasi(ListTiket &LT, const string &kodeTiket, bool &berhasil);

adrJadwal searchJadwal(ListJadwal L, const string &kode);
adrMember searchMember(ListMember L, const string &idMember);
adrTiket searchTiket(ListTiket L, const string &kodeTiket);
adrTiket searchTiketKursi(ListTiket L, adrJadwal pJadwal, int nomorKursi);
bool isRelasi(ListTiket L, adrJadwal pJadwal, adrMember pMember);

int countMemberOfJadwal(ListTiket L, adrJadwal pJadwal);
int countJadwalOfMember(ListTiket L, adrMember pMember);
int countTiketOfJadwal(ListTiket L, adrJadwal pJadwal);

void displayListJadwal(ListJadwal L);
void displayListMember(ListMember L);
void displayJadwalBesertaMember(ListJadwal LJ, ListTiket LT);
void displayMemberBesertaJadwal(ListMember LM, ListTiket LT);

// tambahan
void beliTiket(ListJadwal &LJ, ListMember &LM, ListTiket &LT,const string &kodeTiket, const string &kodeJadwal,const string &idMember, int nomorKursi, int harga);
void batalkanTiket(ListTiket &LT, const string &kodeTiket);
void tampilkanDenahKursi(ListJadwal LJ, ListTiket LT, const string &kodeJadwal);
int hitungTiketJudulFilm(ListTiket LT, const string &judulFilm);
void laporanFilmDanTopMember(ListJadwal LJ, ListMember LM, ListTiket LT);
void initDataDummy(ListJadwal &LJ, ListMember &LM, ListTiket &LT);
#endif
