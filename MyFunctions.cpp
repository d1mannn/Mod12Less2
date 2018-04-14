#include "Header.h"


int TaskNumb()
{
	int task;
	printf("¬ведите номер задани€ (дл€ выхода введите 0)\n --->  ");
	scanf_s("%d", &task);
	return task;
}

void StructFilling(Goods * goods, int * countOfGoods)
{	
	int length = 0;
	for (int i = 0; i < *countOfGoods; i++)
	{	
		length = 4 + rand() % 4;
		for (int j = 0; j < length; j++)
		{
			goods[i].name[j] = (char)97 + rand() % 26;
			if(j == 0)
				goods[i].name[0] = toupper(goods[i].name[0]);
		}
		goods[i].price = 1000 + rand() % 50000;
		goods[i].count = 10 + rand() % 250;
	}
}

void PCFilling(PC * pc, int * countOfGoods)
{
	int length = 0;
	for (int i = 0; i < *countOfGoods; i++)
	{
		length = 4 + rand() % 4;
		for (int j = 0; j < length; j++)
		{
			pc[i].name[j] = (char)97 + rand() % 26;
			if (j == 0)
				pc[i].name[0] = toupper(pc[i].name[0]);
		}
		pc[i].cpu = 1700 + rand() % 500;
		pc[i].hdd = 250 + rand() % 480;
		pc[i].ram = 8 + rand() % 8;
		pc[i].price = 200000 + rand() % 50000;
	}
}

void CharFileFIlling(FILE * file)
{
	int length = 4 + rand() % 5;
	int length2 = 0;
	int n = 0;
	for (int i = 0; i < length; i++)
	{
		length2 = 20 + rand() % 4;
		for (int j = 0; j < length2; j++)
		{
			if (j == 0)
			{
				fprintf_s(file, "%d)", i + 1);
				j++;
			}
			else if (j == length2 - 1)
			{
				fprintf(file, "\n");
			}
			else
			{
				n = 97 + rand() % 26;
				fprintf(file, "%c", n);
			}
		}
	}
}

void Case4FileFilling(FILE * file)
{	
	int n;
	for (int i = 0; i < 20; i++)
	{
		n = -100 + rand() % 200;
		fprintf(file, "%d\n", n);
	}
}

void Case4ArrFilling(FILE * file, int * arr)
{
	for (int i = 0; i < 20; i++)
	{
		fscanf_s(file, "%d", &arr[i]);
		printf("%d\n", arr[i]);
	}
}

void Case4EvenNumbs(FILE * file, int * arr)
{
	for (int i = 0; i < 20; i++)
	{
		if (arr[i] % 2 == 0)
			fprintf(file, "%d\n", arr[i]);
	}
}

void Case4OddnNumbs(FILE * file, int * arr)
{
	for (int i = 0; i < 20; i++)
	{
		if (arr[i] % 2 != 0)
			fprintf(file, "%d\n", arr[i]);
	}
}

int CharCount(FILE *file)
{
	int count = 0;
	while (fgetc(file) != EOF)
	{	
		count++;
	}
	return count;
}

void Case4FromFileToChar(FILE * file, char * arr, int * length)
{
	for (int i = 0; i < *length; i++)
	{
		fscanf_s(file, "%c", &arr[i]);
		printf("%c", arr[i]);
	}
}

void Case4PutExclaimMark(FILE * file, char * arr, int * length)
{
	for (int i = 0; i < *length; i++)
	{
		if (arr[i] != '\n')
			fprintf(file, "%c", arr[i]);
		else
			fprintf(file, "!%c", arr[i]);
	}
}