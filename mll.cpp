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

// ============================================================================
// IMPLEMENTASI FUNGSIONALITAS KHUSUS & BANTUAN TOPIK 11
// ============================================================================

void beliTiket(ListJadwal &LJ, ListMember &LM, ListTiket &LT,
               const string &kodeTiket, const string &kodeJadwal,
               const string &idMember, int nomorKursi, int harga) {
    adrJadwal pJadwal = searchJadwal(LJ, kodeJadwal);
    adrMember pMember = searchMember(LM, idMember);

    if (pJadwal == nullptr) {
        cout << "[Gagal] Kode jadwal '" << kodeJadwal << "' tidak ditemukan." << endl;
    } else if (pMember == nullptr) {
        cout << "[Gagal] ID member '" << idMember << "' tidak ditemukan." << endl;
    } else if (searchTiket(LT, kodeTiket) != nullptr) {
        cout << "[Gagal] Kode tiket '" << kodeTiket << "' sudah digunakan." << endl;
    } else if (nomorKursi < 1 || nomorKursi > pJadwal->info.kapasitas) {
        cout << "[Gagal] Nomor kursi harus berada pada rentang 1 s.d. " << pJadwal->info.kapasitas << "." << endl;
    } else if (countTiketOfJadwal(LT, pJadwal) >= pJadwal->info.kapasitas) {
        cout << "[Gagal] Kapasitas kursi untuk jadwal ini sudah penuh." << endl;
    } else if (searchTiketKursi(LT, pJadwal, nomorKursi) != nullptr) {
        cout << "[Gagal] Kursi nomor " << nomorKursi << " sudah terisi pada jadwal ini." << endl;
    } else {
        adrTiket q = createElemenTiket(kodeTiket, nomorKursi, harga, pJadwal, pMember);
        insertLastTiket(LT, q);
        pMember->info.poin += 10;
        cout << "[Berhasil] Tiket " << kodeTiket << " berhasil dibeli oleh "
             << pMember->info.nama << " (Kursi " << nomorKursi
             << " | Poin sekarang: " << pMember->info.poin << ")." << endl;
    }
}

void batalkanTiket(ListTiket &LT, const string &kodeTiket) {
    adrTiket q = searchTiket(LT, kodeTiket);
    if (q == nullptr) {
        cout << "[Gagal] Tiket dengan kode '" << kodeTiket << "' tidak ditemukan." << endl;
    } else {
        adrMember pMember = q->member;
        string namaMember = pMember->info.nama;

        if (pMember->info.poin >= 10) {
            pMember->info.poin -= 10;
        } else {
            pMember->info.poin = 0;
        }

        bool berhasil = false;
        deleteRelasi(LT, kodeTiket, berhasil);
        if (berhasil) {
            cout << "[Berhasil] Tiket " << kodeTiket << " dibatalkan. Poin "
                 << namaMember << " dikurangi menjadi " << pMember->info.poin << "." << endl;
        }
    }
}

void tampilkanDenahKursi(ListJadwal LJ, ListTiket LT, const string &kodeJadwal) {
    adrJadwal pJadwal = searchJadwal(LJ, kodeJadwal);
    if (pJadwal == nullptr) {
        cout << "[Gagal] Jadwal dengan kode '" << kodeJadwal << "' tidak ditemukan." << endl;
    } else {
        int terisi = countTiketOfJadwal(LT, pJadwal);
        cout << "\n==================================================" << endl;
        cout << "DENAH KURSI STUDIO " << pJadwal->info.studio << " - " << pJadwal->info.judulFilm << endl;
        cout << "Jam Tayang : " << pJadwal->info.jamTayang
             << " | Terisi : " << terisi << "/" << pJadwal->info.kapasitas << " kursi" << endl;
        cout << "==================================================" << endl;
        cout << "                 [ LAYAR BIOSKOP ]                \n" << endl;

        int kursi = 1;
        while (kursi <= pJadwal->info.kapasitas) {
            adrTiket q = searchTiketKursi(LT, pJadwal, kursi);
            string nomorStr = (kursi < 10 ? "0" : "") + to_string(kursi);
            if (q == nullptr) {
                cout << "[ " << nomorStr << ": Kosong ]\t";
            } else {
                cout << "[ " << nomorStr << ": " << q->member->info.nama << " ]\t";
            }

            if (kursi % 4 == 0) {
                cout << endl;
            }
            kursi++;
        }
        cout << endl;
    }
}

int hitungTiketJudulFilm(ListTiket LT, const string &judulFilm) {
    int total = 0;
    adrTiket q = LT.first;
    while (q != nullptr) {
        if (q->jadwal->info.judulFilm == judulFilm) {
            total++;
        }
        q = q->next;
    }
    return total;
}

void laporanFilmDanTopMember(ListJadwal LJ, ListMember LM, ListTiket LT) {
    cout << "\n=== LAPORAN FILM TERLARIS & TOP MEMBER ===" << endl;

    if (isEmptyJadwal(LJ)) {
        cout << "Film Terlaris : (Belum ada data jadwal tayang)" << endl;
    } else {
        adrJadwal p = LJ.first;
        string filmTerlaris = p->info.judulFilm;
        int maxPenonton = hitungTiketJudulFilm(LT, p->info.judulFilm);

        p = p->next;
        while (p != nullptr) {
            int jumlah = hitungTiketJudulFilm(LT, p->info.judulFilm);
            if (jumlah > maxPenonton) {
                maxPenonton = jumlah;
                filmTerlaris = p->info.judulFilm;
            }
            p = p->next;
        }

        if (maxPenonton == 0) {
            cout << "Film Terlaris : Belum ada tiket yang terjual." << endl;
        } else {
            cout << "Film Terlaris : " << filmTerlaris << " (" << maxPenonton << " penonton)" << endl;
        }
    }

    if (isEmptyMember(LM)) {
        cout << "Top Member    : (Belum ada data member)" << endl;
    } else {
        adrMember m = LM.first;
        adrMember topMember = m;
        m = m->next;
        while (m != nullptr) {
            if (m->info.poin > topMember->info.poin) {
                topMember = m;
            }
            m = m->next;
        }
        cout << "Top Member    : " << topMember->info.nama << " (" << topMember->info.idMember
             << ") - " << topMember->info.poin << " poin" << endl;
    }
}

void initDataDummy(ListJadwal &LJ, ListMember &LM, ListTiket &LT) {
    insertLastJadwal(LJ, createElemenJadwal("J01", "Interstellar", "1", "14:00", 12));
    insertLastJadwal(LJ, createElemenJadwal("J02", "Dune: Part Two", "2", "16:30", 16));
    insertLastJadwal(LJ, createElemenJadwal("J03", "Oppenheimer", "3", "19:00", 12));

    insertFirstMember(LM, createElemenMember("M01", "Andi", 20));
    insertFirstMember(LM, createElemenMember("M02", "Budi", 10));
    insertFirstMember(LM, createElemenMember("M03", "Citra", 30));

    beliTiket(LJ, LM, LT, "T01", "J01", "M01", 1, 50000);
    beliTiket(LJ, LM, LT, "T02", "J01", "M03", 2, 50000);
    beliTiket(LJ, LM, LT, "T03", "J02", "M02", 5, 60000);
}
