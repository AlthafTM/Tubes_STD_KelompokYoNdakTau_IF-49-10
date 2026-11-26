#include "mll.h"

void createListJadwal(ListJadwal &L) {
    L.first = nullptr;
    L.last = nullptr;
}

void createListMember(ListMember &L) {
    L.first = nullptr;
}

void createListTiket(ListTiket &L) {
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmptyJadwal(ListJadwal L) {
    return L.first == nullptr;
}

bool isEmptyMember(ListMember L) {
    return L.first == nullptr;
}

bool isEmptyTiket(ListTiket L) {
    return L.first == nullptr;
}

adrJadwal createElemenJadwal(const string &kode, const string &judulFilm,
                             const string &studio, const string &jamTayang, int kapasitas) {
    adrJadwal p = new elemenJadwal;
    p->info.kode = kode;
    p->info.judulFilm = judulFilm;
    p->info.studio = studio;
    p->info.jamTayang = jamTayang;
    p->info.kapasitas = kapasitas;
    p->next = nullptr;
    return p;
}

adrMember createElemenMember(const string &idMember, const string &nama, int poin) {
    adrMember p = new elemenMember;
    p->info.idMember = idMember;
    p->info.nama = nama;
    p->info.poin = poin;
    p->next = nullptr;
    return p;
}

adrTiket createElemenTiket(const string &kodeTiket, int nomorKursi, int harga,
                           adrJadwal pJadwal, adrMember pMember) {
    adrTiket q = new elemenTiket;
    q->info.kodeTiket = kodeTiket;
    q->info.nomorKursi = nomorKursi;
    q->info.harga = harga;
    q->jadwal = pJadwal;
    q->member = pMember;
    q->next = nullptr;
    return q;
}

void insertLastJadwal(ListJadwal &L, adrJadwal p) {
    if (p != nullptr) {
        if (isEmptyJadwal(L)) {
            L.first = p;
            L.last = p;
        } else {
            L.last->next = p;
            L.last = p;
        }
    }
}

void insertFirstMember(ListMember &L, adrMember p) {
    if (p != nullptr) {
        p->next = L.first;
        L.first = p;
    }
}

void insertLastTiket(ListTiket &L, adrTiket q) {
    if (q != nullptr) {
        if (isEmptyTiket(L)) {
            L.first = q;
            L.last = q;
        } else {
            L.last->next = q;
            L.last = q;
        }
    }
}

void deleteFirstJadwal(ListJadwal &L, adrJadwal &p) {
    if (isEmptyJadwal(L)) {
        p = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        if (L.first == nullptr) {
            L.last = nullptr;
        }
        p->next = nullptr;
    }
}

void deleteLastJadwal(ListJadwal &L, adrJadwal &p) {
    if (isEmptyJadwal(L)) {
        p = nullptr;
    } else if (L.first == L.last) {
        p = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        adrJadwal prec = L.first;
        while (prec->next != L.last) {
            prec = prec->next;
        }
        p = L.last;
        L.last = prec;
        L.last->next = nullptr;
    }
}

void deleteAfterJadwal(ListJadwal &L, adrJadwal prec, adrJadwal &p) {
    if (prec == nullptr || prec->next == nullptr) {
        p = nullptr;
    } else {
        p = prec->next;
        prec->next = p->next;
        if (p == L.last) {
            L.last = prec;
        }
        p->next = nullptr;
    }
}

void deleteFirstMember(ListMember &L, adrMember &p) {
    if (isEmptyMember(L)) {
        p = nullptr;
    } else {
        p = L.first;
        L.first = p->next;
        p->next = nullptr;
    }
}

void deleteLastMember(ListMember &L, adrMember &p) {
    if (isEmptyMember(L)) {
        p = nullptr;
    } else if (L.first->next == nullptr) {
        p = L.first;
        L.first = nullptr;
    } else {
        adrMember prec = L.first;
        while (prec->next->next != nullptr) {
            prec = prec->next;
        }
        p = prec->next;
        prec->next = nullptr;
    }
}

void deleteAfterMember(ListMember &L, adrMember prec, adrMember &p) {
    if (prec == nullptr || prec->next == nullptr) {
        p = nullptr;
    } else {
        p = prec->next;
        prec->next = p->next;
        p->next = nullptr;
    }
}

void deleteFirstTiket(ListTiket &L, adrTiket &q) {
    if (isEmptyTiket(L)) {
        q = nullptr;
    } else {
        q = L.first;
        L.first = q->next;
        if (L.first == nullptr) {
            L.last = nullptr;
        }
        q->next = nullptr;
    }
}

void deleteLastTiket(ListTiket &L, adrTiket &q) {
    if (isEmptyTiket(L)) {
        q = nullptr;
    } else if (L.first == L.last) {
        q = L.first;
        L.first = nullptr;
        L.last = nullptr;
    } else {
        adrTiket prec = L.first;
        while (prec->next != L.last) {
            prec = prec->next;
        }
        q = L.last;
        L.last = prec;
        L.last->next = nullptr;
    }
}

void deleteAfterTiket(ListTiket &L, adrTiket prec, adrTiket &q) {
    if (prec == nullptr || prec->next == nullptr) {
        q = nullptr;
    } else {
        q = prec->next;
        prec->next = q->next;
        if (q == L.last) {
            L.last = prec;
        }
        q->next = nullptr;
    }
}

void deleteJadwalTertentu(ListJadwal &L, adrJadwal target, adrJadwal &p) {
    if (target == nullptr || isEmptyJadwal(L)) {
        p = nullptr;
    } else if (target == L.first) {
        deleteFirstJadwal(L, p);
    } else {
        adrJadwal prec = L.first;
        while (prec != nullptr && prec->next != target) {
            prec = prec->next;
        }
        deleteAfterJadwal(L, prec, p);
    }
}

void deleteMemberTertentu(ListMember &L, adrMember target, adrMember &p) {
    if (target == nullptr || isEmptyMember(L)) {
        p = nullptr;
    } else if (target == L.first) {
        deleteFirstMember(L, p);
    } else {
        adrMember prec = L.first;
        while (prec != nullptr && prec->next != target) {
            prec = prec->next;
        }
        deleteAfterMember(L, prec, p);
    }
}

void deleteTiketTertentu(ListTiket &L, adrTiket target, adrTiket &q) {
    if (target == nullptr || isEmptyTiket(L)) {
        q = nullptr;
    } else if (target == L.first) {
        deleteFirstTiket(L, q);
    } else {
        adrTiket prec = L.first;
        while (prec != nullptr && prec->next != target) {
            prec = prec->next;
        }
        deleteAfterTiket(L, prec, q);
    }
}

void deleteTiketByJadwal(ListTiket &LT, adrJadwal pJadwal) {
    adrTiket q = LT.first;
    adrTiket nxt;
    adrTiket r;
    while (q != nullptr) {
        nxt = q->next;
        if (q->jadwal == pJadwal) {
            deleteTiketTertentu(LT, q, r);
            delete r;
        }
        q = nxt;
    }
}

void deleteTiketByMember(ListTiket &LT, adrMember pMember) {
    adrTiket q = LT.first;
    adrTiket nxt;
    adrTiket r;
    while (q != nullptr) {
        nxt = q->next;
        if (q->member == pMember) {
            deleteTiketTertentu(LT, q, r);
            delete r;
        }
        q = nxt;
    }
}

void deleteJadwalBesertaRelasi(ListJadwal &LJ, ListTiket &LT, const string &kode, bool &berhasil) {
    adrJadwal p = searchJadwal(LJ, kode);
    adrJadwal hapus;
    if (p == nullptr) {
        berhasil = false;
    } else {
        deleteTiketByJadwal(LT, p);
        deleteJadwalTertentu(LJ, p, hapus);
        delete hapus;
        berhasil = true;
    }
}

void deleteMemberBesertaRelasi(ListMember &LM, ListTiket &LT, const string &idMember, bool &berhasil) {
    adrMember p = searchMember(LM, idMember);
    adrMember hapus;
    if (p == nullptr) {
        berhasil = false;
    } else {
        deleteTiketByMember(LT, p);
        deleteMemberTertentu(LM, p, hapus);
        delete hapus;
        berhasil = true;
    }
}

void deleteRelasi(ListTiket &LT, const string &kodeTiket, bool &berhasil) {
    adrTiket q = searchTiket(LT, kodeTiket);
    adrTiket hapus;
    if (q == nullptr) {
        berhasil = false;
    } else {
        deleteTiketTertentu(LT, q, hapus);
        delete hapus;
        berhasil = true;
    }
}

adrJadwal searchJadwal(ListJadwal L, const string &kode) {
    adrJadwal p = L.first;
    while (p != nullptr && p->info.kode != kode) {
        p = p->next;
    }
    return p;
}

adrMember searchMember(ListMember L, const string &idMember) {
    adrMember p = L.first;
    while (p != nullptr && p->info.idMember != idMember) {
        p = p->next;
    }
    return p;
}

adrTiket searchTiket(ListTiket L, const string &kodeTiket) {
    adrTiket q = L.first;
    while (q != nullptr && q->info.kodeTiket != kodeTiket) {
        q = q->next;
    }
    return q;
}

adrTiket searchTiketKursi(ListTiket L, adrJadwal pJadwal, int nomorKursi) {
    adrTiket q = L.first;
    while (q != nullptr && !(q->jadwal == pJadwal && q->info.nomorKursi == nomorKursi)) {
        q = q->next;
    }
    return q;
}

bool isRelasi(ListTiket L, adrJadwal pJadwal, adrMember pMember) {
    adrTiket q = L.first;
    while (q != nullptr && !(q->jadwal == pJadwal && q->member == pMember)) {
        q = q->next;
    }
    return q != nullptr;
}

int countMemberOfJadwal(ListTiket L, adrJadwal pJadwal) {
    int total = 0;
    adrTiket q = L.first;
    adrTiket r;
    bool sudahAda;
    while (q != nullptr) {
        if (q->jadwal == pJadwal) {
            sudahAda = false;
            r = L.first;
            while (r != q) {
                if (r->jadwal == pJadwal && r->member == q->member) {
                    sudahAda = true;
                }
                r = r->next;
            }
            if (!sudahAda) {
                total++;
            }
        }
        q = q->next;
    }
    return total;
}

int countJadwalOfMember(ListTiket L, adrMember pMember) {
    int total = 0;
    adrTiket q = L.first;
    adrTiket r;
    bool sudahAda;
    while (q != nullptr) {
        if (q->member == pMember) {
            sudahAda = false;
            r = L.first;
            while (r != q) {
                if (r->member == pMember && r->jadwal == q->jadwal) {
                    sudahAda = true;
                }
                r = r->next;
            }
            if (!sudahAda) {
                total++;
            }
        }
        q = q->next;
    }
    return total;
}

int countTiketOfJadwal(ListTiket L, adrJadwal pJadwal) {
    int total = 0;
    adrTiket q = L.first;
    while (q != nullptr) {
        if (q->jadwal == pJadwal) {
            total++;
        }
        q = q->next;
    }
    return total;
}

void displayListJadwal(ListJadwal L) {
    adrJadwal p = L.first;
    if (isEmptyJadwal(L)) {
        cout << "Data jadwal kosong." << endl;
    } else {
        while (p != nullptr) {
            cout << p->info.kode << " | " << p->info.judulFilm
                 << " | Studio " << p->info.studio
                 << " | " << p->info.jamTayang
                 << " | Kapasitas " << p->info.kapasitas << endl;
            p = p->next;
        }
    }
}

void displayListMember(ListMember L) {
    adrMember p = L.first;
    if (isEmptyMember(L)) {
        cout << "Data member kosong." << endl;
    } else {
        while (p != nullptr) {
            cout << p->info.idMember << " | " << p->info.nama
                 << " | Poin " << p->info.poin << endl;
            p = p->next;
        }
    }
}

void displayJadwalBesertaMember(ListJadwal LJ, ListTiket LT) {
    adrJadwal p = LJ.first;
    adrTiket q;
    int jumlah;
    if (isEmptyJadwal(LJ)) {
        cout << "Data jadwal kosong." << endl;
    } else {
        while (p != nullptr) {
            cout << "Jadwal : " << p->info.kode << " - " << p->info.judulFilm
                 << " | Studio " << p->info.studio
                 << " | " << p->info.jamTayang << endl;
            jumlah = 0;
            q = LT.first;
            while (q != nullptr) {
                if (q->jadwal == p) {
                    cout << "   - " << q->member->info.nama
                         << " (" << q->member->info.idMember << ")"
                         << " | Kursi " << q->info.nomorKursi
                         << " | Rp" << q->info.harga << endl;
                    jumlah++;
                }
                q = q->next;
            }
            if (jumlah == 0) {
                cout << "   (belum ada tiket terjual)" << endl;
            }
            cout << endl;
            p = p->next;
        }
    }
}

void displayMemberBesertaJadwal(ListMember LM, ListTiket LT) {
    adrMember p = LM.first;
    adrTiket q;
    int jumlah;
    if (isEmptyMember(LM)) {
        cout << "Data member kosong." << endl;
    } else {
        while (p != nullptr) {
            cout << "Member : " << p->info.nama << " (" << p->info.idMember << ")"
                 << " | Poin " << p->info.poin << endl;
            jumlah = 0;
            q = LT.first;
            while (q != nullptr) {
                if (q->member == p) {
                    cout << "   - " << q->jadwal->info.judulFilm
                         << " | " << q->jadwal->info.jamTayang
                         << " | Studio " << q->jadwal->info.studio
                         << " | Kursi " << q->info.nomorKursi << endl;
                    jumlah++;
                }
                q = q->next;
            }
            if (jumlah == 0) {
                cout << "   (belum membeli tiket)" << endl;
            }
            cout << endl;
            p = p->next;
        }
    }
}