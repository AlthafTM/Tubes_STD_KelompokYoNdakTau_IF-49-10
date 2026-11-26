#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct elemenFilm;
struct elemenTiket;

typedef elemenFilm* adrFilm;
typedef elemenTiket* adrTiket;

struct Film {
    string idFilm;
    string judul;
    string jadwal;
    string studio;
    int hargaTiket;
};

struct Tiket {
    string kodeTiket;
    string namaPembeli;
    string nomorKursi;
};

struct elemenFilm {
    Film info;
    adrFilm next;
    adrFilm prev;
    adrTiket firstTiket;
};

struct elemenTiket {
    Tiket info;
    adrTiket next;
    adrTiket prev;
};

struct ListFilm {
    adrFilm first;
    adrFilm last;
};

void createListFilm(ListFilm &L);
bool isEmptyFilm(ListFilm L);
bool isEmptyTiket(adrFilm p);

adrFilm createElemenFilm(string idFilm, string judul, string jadwal, string studio, int hargaTiket);
adrTiket createElemenTiket(string kodeTiket, string namaPembeli, string nomorKursi);

void insertFirstFilm(ListFilm &L, adrFilm p);
void insertLastFilm(ListFilm &L, adrFilm p);
void insertAfterFilm(ListFilm &L, adrFilm prec, adrFilm p);

void insertFirstTiket(adrFilm &p, adrTiket q);
void insertLastTiket(adrFilm &p, adrTiket q);
void insertAfterTiket(adrFilm &p, adrTiket prec, adrTiket q);

void deleteFirstFilm(ListFilm &L, adrFilm &p);
void deleteLastFilm(ListFilm &L, adrFilm &p);
void deleteAfterFilm(ListFilm &L, adrFilm prec, adrFilm &p);

void deleteFirstTiket(adrFilm &p, adrTiket &q);
void deleteLastTiket(adrFilm &p, adrTiket &q);
void deleteAfterTiket(adrFilm &p, adrTiket prec, adrTiket &q);
void deleteAllTiket(adrFilm &p);

adrFilm searchFilm(ListFilm L, string idFilm);
adrTiket searchTiket(adrFilm p, string kodeTiket);

void displayListFilm(ListFilm L);

#endif
