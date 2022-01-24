#include "WordSearch.hpp"
#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;

int main(){
  // KAMUS
  int i, j, idx, x, y, arah, countCompare;
  string fname;
  ListOfWords list;
  Matrix mat;
  uint64_t akhir;

  // ALGORITMA
  countCompare = 0;
  cout << "Masukkan nama file: ";
  cin >> fname;
  ReadAndCreateMatrix(&mat, &list, "../test/" + fname);

  // TESTING
  // if (MatchWord(mat, &x, &y, &arah, "VITA", &countCompare)) {
  //   cout << "match VITA" <<endl;
  //   cout << x << ' ' << y << ' ' << arah << endl;
  //   PrintOutput(mat, x, y, arah, 4, countCompare);
  // }
  // cout << "tes num in array\n";
  // if (NumInArray(21, 10, arr)) {
  //   cout << "angka 22 di array\n";
  // }


  idx = 0;
  uint64_t awal = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
  while (idx < IDX_EFF(list)) {
    x = 0; y = 0; arah = 0;
    if (MatchWord(mat, &x, &y, &arah, WORD_ELMT(list, idx), &countCompare)) {
      akhir = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
      cout << "DITEMUKAN KATA: " << WORD_ELMT(list, idx) << " !\n";
      PrintOutput(mat, x, y, arah, WORD_ELMT(list, idx).length(), countCompare);
    }
    idx += 1;
  }
  cout << "Terjadi perbandingan total sebanyak " << countCompare << " kali\n";
  int satuan = 0, selisih = akhir - awal;
  if (akhir - awal >= 1000) {
    satuan = 1;
    selisih = akhir - awal - 1000;
  }
  cout << "Diperlukan waktu sebanyak " << satuan << "," << selisih << " detik\n";

  // TESTING  
  // for (i = 0; i < ROWS(mat); i++) {
  //   for (j = 0; j < COLS(mat); j++) {
  //     cout << ELMT(mat, i, j);
  //   }
  //   cout << endl;
  // }

  // for (i = 0; i < IDX_EFF(list); i++) {
  //   cout << WORD_ELMT(list, i) << endl;
  // }
  return 0;
}