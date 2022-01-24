#include "WordSearch.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

/***** MEMBUAT MATRIKS WORD PUZZLE *****/
void ReadAndCreateMatrix(Matrix *mat, ListOfWords *list, string filename) {
  // KAMUS
  int row, col, idx, i, j, idxList;
  string line;
  filename += ".txt";
  ifstream FilePuzzle(filename);
  bool puzzlePart = true;

  // ALGORITMA
  row = 0;
  idxList = 0;
  while (getline (FilePuzzle, line)) {
    // Buat handle txt bagian puzzle
    if (puzzlePart && line.length() != 0) {
      idx = 0;
      col = 0;
      while (idx < line.length()) {
        if (int(line[idx]) >= 65 && int(line[idx]) <= 90) {
          ELMT(*mat, row, col) = line[idx];
          col += 1;
        }
        idx += 1; 
      }
      if (col > COLS(*mat)) {
        COLS(*mat) = col;
      }
      row += 1;
    } else if (puzzlePart == true && line.length() == 0) { // Mengubah boolean puzzlePart
      puzzlePart = false;
    } else if (!puzzlePart){ // Handle txt bagian word yg harus ditemukan
      WORD_ELMT(*list, idxList) = line;
      idxList += 1;
    }
  }
  IDX_EFF(*list) = idxList; // Menyamakan jumlah kata yg harus dicari
  ROWS(*mat) = row;

  FilePuzzle.close();
}

/***** MENCOCOKAN KATA *****/
bool MatchWord(Matrix mat, int *x, int *y, int *arah, std::string word, int *countCompare) {
  // KAMUS
  bool found = false;
  *arah = 0;
  *x = 0;
  *y = 0;
  int x_cap = COLS(mat) - 1;
  int y_cap = ROWS(mat) - 1;
  int compAwal = *countCompare;

  // ALGORITMA
  while (!found && (*y <= y_cap)) {
    if ((*arah % 8) + 1 == 1) { // kalo sisa modulo nya + 1 = 1, dia arah 1
      found = Match1(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 2) {
      found = Match2(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 3) {
      found = Match3(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 4) {
      found = Match4(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 5) {
      found = Match5(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 6) {
      found = Match6(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 7) {
      found = Match7(mat, *x, *y, word, countCompare);
    } else if ((*arah % 8) + 1 == 8) {
      found = Match8(mat, *x, *y, word, countCompare);
      if (found == false) {
        *x += 1;
        if (*x > x_cap) {
          *x = 0;
          *y += 1;
        }
      }
    }
    *arah += 1;
  }
  if (found) {
    *arah -= 1;
  }
  cout << "Dilakukan perbandingan sebanyak " << *countCompare - compAwal << " kali untuk kata di bawah ini\n";
  return found;
}

bool Match1(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 >= 0  && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      y1 -= 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match2(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 >= 0 && x1 < COLS(mat) && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 += 1; y1 -= 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match3(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && x1 < COLS(mat) && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 += 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match4(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 < ROWS(mat) && x1 < COLS(mat) && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 += 1; y1 += 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match5(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 < ROWS(mat) && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      y1 += 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match6(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 < ROWS(mat) && x1 >= 0 && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 -= 1; y1 += 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match7(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && x1 >= 0 && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 -= 1;  idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

bool Match8(Matrix mat, int x, int y, std::string word, int *countCompare) {
  // KAMUS
  bool match = true;
  int x1, y1, idx;

  // ALGORITMA
  idx = 0;
  x1 = x;
  y1 = y;
  while (match && y1 >= 0 && x1 >= 0 && idx < word.length()) {
    if (ELMT(mat, y1, x1) != word[idx]) {
      match = false;
    } else {
      x1 -= 1; y1 -= 1; idx += 1;
    }
    *countCompare += 1;
  }
  if (idx < word.length()) {
    match = false;
  }
  return match;
}

/***** OUTPUT *****/
void PrintOutput(Matrix mat, int x, int y, int arah, int wordLength, int countCompare) {
  // KAMUS
  int x1, y1, i, j;
  int x_idx_arr[wordLength], y_idx_arr[wordLength];
  // ALGORITMA
  x_idx_arr[0] = x;
  y_idx_arr[0] = y;

  // Simpan koordinat kata dulu
  for (i = 1; i < wordLength; i++){
    if ((arah % 8) + 1 == 1) {
      y_idx_arr[i] = y_idx_arr[i - 1] - 1;
      x_idx_arr[i] = x_idx_arr[i - 1]; // tetep
    } else if ((arah % 8) + 1 == 2) {
      y_idx_arr[i] = y_idx_arr[i - 1] - 1;
      x_idx_arr[i] = x_idx_arr[i - 1] + 1;
    } else if ((arah % 8) + 1 == 3) {
      y_idx_arr[i] = y_idx_arr[i - 1]; // tetep
      x_idx_arr[i] = x_idx_arr[i - 1] + 1;
    } else if ((arah % 8) + 1 == 4) {
      y_idx_arr[i] = y_idx_arr[i - 1] + 1;
      x_idx_arr[i] = x_idx_arr[i - 1] + 1;
    } else if ((arah % 8) + 1 == 5) {
      y_idx_arr[i] = y_idx_arr[i - 1] + 1;
      x_idx_arr[i] = x_idx_arr[i - 1]; // tetep
    } else if ((arah % 8) + 1 == 6) {
      y_idx_arr[i] = y_idx_arr[i - 1] + 1;
      x_idx_arr[i] = x_idx_arr[i - 1] - 1;
    } else if ((arah % 8) + 1 == 7) {
      y_idx_arr[i] = y_idx_arr[i - 1]; // tetep
      x_idx_arr[i] = x_idx_arr[i - 1] - 1;
    } else if ((arah % 8) + 1 == 8) {
      y_idx_arr[i] = y_idx_arr[i - 1] - 1;
      x_idx_arr[i] = x_idx_arr[i - 1] - 1;
    }
    
  }

  for (i = 0; i < ROWS(mat); i++) {
    for (j = 0; j < COLS(mat); j++) {
      if (NumInArray(j, i, wordLength, x_idx_arr, y_idx_arr)) {
        cout << ELMT(mat, i, j) << ' ';
      } else {
        cout << "- ";
      }
    }
    cout << endl;
  }
}

bool NumInArray(int x, int y, int wordLength, int arrx[], int arry[]) {
  // KAMUS
  bool found = false;
  int i, j;
  i = 0;

  // ALGORITMA
  while (!found && i < wordLength) {
    if (x == arrx[i] && y == arry[i]) {
      found = true;
    } else {
      i += 1;
    }
  }
  return found;
}