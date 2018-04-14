#include "Header.h"

void main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE * file;
	int task;
	do
	{
		task = TaskNumb();
		switch (task)
		{	
			case 1:
			{
				/*7.	Создать бинарный файл, компонентами которого является структура, содержащая следующие поля :
				a. Наименование товара;
				b. Стоимость единицы товара;
				c. Количество каждого товара.
					d.Определить общую стоимость товара, предложенного для реализации, и его среднюю цену
*/
				Goods *goods;
				int length = 4 + rand() % 4;
				goods = (Goods *)calloc(length, sizeof(Goods));
				if (goods == NULL)
				{
					printf("Error\n");
					exit(1);
				}
				StructFilling(goods, &length);
				errno_t err = fopen_s(&file, "Case1", "wb");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				fwrite(goods, sizeof(Goods), length, file);
				fclose(file);
				free(goods);
			} break;

			case 2:
			{
			/*	8.	Создать бинарный файл с информацией о наличии компьютеров для продажи :
				a. название компьютера;
				b. частота процессора;
				c. объем оперативной памяти;
				d. объем жесткого диска;
				e. цена.
					f.Определить общую стоимость предложенных к продаже компьютеров, 
					у которых частота процессора более 2 ГГц / сек фирмы «Asus» и напечатать информацию о них.*/
				PC * pc;
				int length = 4 + rand() % 4;
				pc = (PC*)calloc(length, sizeof(PC));
				if (pc == NULL)
				{
					printf("Error\n");
					exit(1);
				}
				PCFilling(pc, &length);
				errno_t err = fopen_s(&file, "Case2", "wb");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				fwrite(pc, sizeof(Goods), length, file);
				fclose(file);
				free(pc);
			} break;

			case 3:
			{
				/*1.	Имеется текстовый файл.Переписать его строки в другой файл.Порядок строк во втором файле должен :
				a.совпадать с порядком строк в заданном файле;
				b.быть обратным по отношению к порядку строк в заданном файле.*/
				FILE * file1;
				errno_t err = fopen_s(&file, "Case3.txt", "w");
				if (err != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				CharFileFIlling(file);
				fclose(file);
				err = fopen_s(&file, "Case3.txt", "rb");
				errno_t err1 = fopen_s(&file1, "Case3_1.txt", "w");
				if (err != 0 && err1 != 0)
				{
					perror("Error");
					system("pause");
					exit(1);
				}
				char * buffer;
				fseek(file, 0, SEEK_END);
				long lSize = ftell(file);
				rewind(file);
				buffer = (char*)calloc(lSize, sizeof(char));
				fread(buffer, sizeof(char), lSize, file);
				puts(buffer);
				fclose(file);
				fclose(file1);
				free(buffer);
			} break;

			case 4:
			{
			//	5.	Записать в файл g все чётные числа файла f, а в файл h все нечётные.Порядок следования чисел сохраняется
				errno_t err = fopen_s(&file, "Case4_f.txt", "w");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				Case4FileFilling(file);
				fclose(file);
				err = fopen_s(&file, "Case4_f.txt", "r");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				int numbs[20];
				Case4ArrFilling(file, numbs);
				fclose(file);
				err = fopen_s(&file, "Case4_g.txt", "w");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				Case4EvenNumbs(file, numbs);
				fclose(file);
				err = fopen_s(&file, "Case4_h.txt", "w");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				Case4OddnNumbs(file, numbs);
				fclose(file);
			} break;

			case 5:
			{
				//3.	Имеется текстовый файл.Получить текст, в котором в конце каждой строки из заданного файла добавлен восклицательный знак.
				errno_t err = fopen_s(&file, "Case5_1.txt", "r");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				
				/*fseek(file, 0, SEEK_END);
				long lSize = ftell(file);
				rewind(file);*/
				
				int count = CharCount(file);
				rewind(file);
				printf("Char quantity is %d\n", count);
				char * arr = (char*)calloc(count, sizeof(char));
				if (arr == NULL)
				{
					printf("Error\n");
					exit(1);
				}
				Case4FromFileToChar(file, arr, &count);
				fclose(file);
				err = fopen_s(&file, "Case5_2.txt", "w");
				if (err != 0)
				{
					perror("Error");
					exit(1);
				}
				Case4PutExclaimMark(file, arr, &count);
				free(arr);
				fclose(file);
				
			} break;
		}
	} while (task != 0);
}