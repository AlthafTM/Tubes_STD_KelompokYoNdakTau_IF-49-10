#include "mll.h"

void createListFilm(ListFilm &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyFilm(ListFilm L) {
    return L.first == nullptr;
}

bool isEmptyTiket(adrFilm p) {
    return p == nullptr || p->firstTiket == nullptr;
}

adrFilm createElemenFilm(string idFilm, string judul, string jadwal, string studio, int hargaTiket) {
    adrFilm p = new elemenFilm;
    p->info.idFilm = idFilm;
    p->info.judul = judul;
    p->info.jadwal = jadwal;
    p->info.studio = studio;
    p->info.hargaTiket = hargaTiket;
    p->next = nullptr;
    p->prev = nullptr;
    p->firstTiket = nullptr;
    return p;
}

adrTiket createElemenTiket(string kodeTiket, string namaPembeli, string nomorKursi) {
    adrTiket q = new elemenTiket;
    q->info.kodeTiket = kodeTiket;
    q->info.namaPembeli = namaPembeli;
    q->info.nomorKursi = nomorKursi;
    q->next = nullptr;
    q->prev = nullptr;
    return q;
}

void insertFirstFilm(ListFilm &L, adrFilm p) {
    if (p == nullptr) {
        return;
    }

    if (isEmptyFilm(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}

void insertLastFilm(ListFilm &L, adrFilm p) {
    if (p == nullptr) {
        return;
    }

    if (isEmptyFilm(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}

void insertAfterFilm(ListFilm &L, adrFilm prec, adrFilm p) {
    if (prec == nullptr || p == nullptr) {
        return;
    }

    if (prec == L.last) {
        insertLastFilm(L, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

void insertFirstTiket(adrFilm &p, adrTiket q) {
    if (p == nullptr || q == nullptr) {
        return;
    }

    if (isEmptyTiket(p)) {
        p->firstTiket = q;
    } else {
        q->next = p->firstTiket;
        p->firstTiket->prev = q;
        p->firstTiket = q;
    }
}

void insertLastTiket(adrFilm &p, adrTiket q) {
    if (p == nullptr || q == nullptr) {
        return;
    }

    if (isEmptyTiket(p)) {
        p->firstTiket = q;
    } else {
        adrTiket r = p->firstTiket;
        while (r->next != nullptr) {
            r = r->next;
        }
        r->next = q;
        q->prev = r;
    }
}

void insertAfterTiket(adrFilm &p, adrTiket prec, adrTiket q) {
    if (p == nullptr || prec == nullptr || q == nullptr) {
        return;
    }

    q->next = prec->next;
    q->prev = prec;
    if (prec->next != nullptr) {
        prec->next->prev = q;
    }
    prec->next = q;
}

void deleteFirstFilm(ListFilm &L, adrFilm &p) {
    if (isEmptyFilm(L)) {
        p = nullptr;
        return;
    }

    p = L.first;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.first = p->next;
        L.first->prev = nullptr;
        p->next = nullptr;
    }
}

void deleteLastFilm(ListFilm &L, adrFilm &p) {
    if (isEmptyFilm(L)) {
        p = nullptr;
        return;
    }

    p = L.last;
    if (L.first == L.last) {
        L.first = nullptr;
        L.last = nullptr;
    } else {
        L.last = p->prev;
        L.last->next = nullptr;
        p->prev = nullptr;
    }
}

void deleteAfterFilm(ListFilm &L, adrFilm prec, adrFilm &p) {
    if (isEmptyFilm(L) || prec == nullptr || prec->next == nullptr) {
        p = nullptr;
        return;
    }

    p = prec->next;
    if (p == L.last) {
        L.last = prec;
        prec->next = nullptr;
        p->prev = nullptr;
    } else {
        prec->next = p->next;
        p->next->prev = prec;
        p->next = nullptr;
        p->prev = nullptr;
    }
}

void deleteFirstTiket(adrFilm &p, adrTiket &q) {
    if (isEmptyTiket(p)) {
        q = nullptr;
        return;
    }

    q = p->firstTiket;
    if (q->next == nullptr) {
        p->firstTiket = nullptr;
    } else {
        p->firstTiket = q->next;
        p->firstTiket->prev = nullptr;
        q->next = nullptr;
    }
}

void deleteLastTiket(adrFilm &p, adrTiket &q) {
    if (isEmptyTiket(p)) {
        q = nullptr;
        return;
    }

    if (p->firstTiket->next == nullptr) {
        q = p->firstTiket;
        p->firstTiket = nullptr;
    } else {
        adrTiket r = p->firstTiket;
        while (r->next != nullptr) {
            r = r->next;
        }
        q = r;
        r->prev->next = nullptr;
        q->prev = nullptr;
    }
}

void deleteAfterTiket(adrFilm &p, adrTiket prec, adrTiket &q) {
    if (isEmptyTiket(p) || prec == nullptr || prec->next == nullptr) {
        q = nullptr;
        return;
    }

    q = prec->next;
    prec->next = q->next;
    if (q->next != nullptr) {
        q->next->prev = prec;
    }
    q->next = nullptr;
    q->prev = nullptr;
}

void deleteAllTiket(adrFilm &p) {
    if (p == nullptr) {
        return;
    }

    adrTiket q;
    while (!isEmptyTiket(p)) {
        deleteFirstTiket(p, q);
        delete q;
    }
}

adrFilm searchFilm(ListFilm L, string idFilm) {
    adrFilm p = L.first;
    while (p != nullptr) {
        if (p->info.idFilm == idFilm) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}

adrTiket searchTiket(adrFilm p, string kodeTiket) {
    if (isEmptyTiket(p)) {
        return nullptr;
    }

    adrTiket q = p->firstTiket;
    while (q != nullptr) {
        if (q->info.kodeTiket == kodeTiket) {
            return q;
        }
        q = q->next;
    }
    return nullptr;
}

void displayListFilm(ListFilm L) {
    if (isEmptyFilm(L)) {
        cout << "Data film kosong." << endl;
        return;
    }

    adrFilm p = L.first;
    while (p != nullptr) {
        cout << "Film   : " << p->info.judul << " (" << p->info.idFilm << ")" << endl;
        cout << "Jadwal : " << p->info.jadwal << " | Studio " << p->info.studio << " | Rp" << p->info.hargaTiket << endl;
        cout << "Tiket  : ";

        if (isEmptyTiket(p)) {
            cout << "Belum ada";
        } else {
            adrTiket q = p->firstTiket;
            while (q != nullptr) {
                cout << q->info.kodeTiket << " - " << q->info.namaPembeli << " [" << q->info.nomorKursi << "]";
                if (q->next != nullptr) {
                    cout << ", ";
                }
                q = q->next;
            }
        }

        cout << endl;
        cout << endl;
        p = p->next;
    }
}
