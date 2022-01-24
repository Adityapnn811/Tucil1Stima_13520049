#ifndef WORDSEARCH_HPP
#define WORDSEARCH_HPP

#include <string>

#define ROW 100
#define COL 100

typedef struct Matrix
{
  char content[ROW][COL];
  int rowEff = 0;
  int colEff = 0;
} Matrix;

typedef struct ListOfWords
{
  std::string word[50];
  int idxEff;
} ListOfWords;

/* *** Selektor *** */
#define ROWS(M) (M).rowEff
#define COLS(M) (M).colEff
#define ELMT(M, i, j) (M).content[(i)][(j)]
#define IDX_EFF(L) (L).idxEff
#define WORD_ELMT(L, i) (L).word[(i)]
#define WORD_ELMT_2(L, i, j) (L).word[(i)][(j)]

/***** MEMBUAT MATRIKS WORD PUZZLE *****/
void ReadAndCreateMatrix(Matrix *mat, ListOfWords *list, std::string filename);
// Nanti akan read txt files terus ngebuat matriks puzzle

/***** MENCOCOKAN KATA *****/
bool MatchWord(Matrix mat, int *x, int *y, int *arah, std::string word, int *countCompare);
// Nanti akan ngecocokin kata dan kalo cocok return true
// x dan y bakal nyimpen kata pertamanya, arah nilainya 1 - 8, kalo 1 dia ke atas, 2 ke kanan atas, dst

bool Match1(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 1
bool Match2(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 2
bool Match3(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 3
bool Match4(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 4
bool Match5(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 5
bool Match6(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 6
bool Match7(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 7
bool Match8(Matrix mat, int x, int y, std::string word, int *countCompare);
// buat arah 8

bool NumInArray(int x, int y, int wordLength, int arrx[], int arry[]);
// ngecek (x,y) ada di array atau tidak

/***** OUTPUT *****/
void PrintOutput(Matrix mat, int x, int y, int arah, int wordLength, int countCompare);

/* 
nanti ada while loop berdasarkan panjang word, trus fungsi MatchWord itu return true atau false setelah ngecek 8 arah mata angin
trus nanti yg traversal di puzzle siapa? wklw asw bingung
*/
#endif