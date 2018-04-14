#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <Windows.h>
#include "Struct.h"



int TaskNumb();
void StructFilling(Goods * goods, int * countOfGoods);
void PCFilling(PC * pc, int * countOfGoods);
void CharFileFIlling(FILE * file);
void Case4FileFilling(FILE * file);
void Case4ArrFilling(FILE * file, int * arr);
void Case4EvenNumbs(FILE * file, int * arr);
void Case4OddnNumbs(FILE * file, int * arr);
int CharCount(FILE *file);
void Case4FromFileToChar(FILE * file, char * arr, int * length);
void Case4PutExclaimMark(FILE * file, char * arr, int * length);