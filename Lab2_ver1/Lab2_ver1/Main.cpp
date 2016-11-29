/**********************************************************
* Project type  : Win 32 Console Application              *
* Project name  : Lab_2_ver_0.1                           *
* File name     : Main.cpp                               *
* Language      : C++, MS VS 2015                         *
* Programmer(1) : Азеева Елизавета Романовна              *
* Programmer(2) : Князев Алексей Станиславович            *
* Modified by   :         /-----//-----/                  *
* Created       : 28.11.2016 18:03                        *
* Last revision : 29.11.2016 21:35                        *
* Comment       :                                         *
*---------------------------------------------------------*
*Кафедра 302		Курс: ИНФОРМАТИКА 					  *
*Курсовая работа:	ОДНОМЕРНЫЕ МАССИВЫ					  *
*---------------------------------------------------------*
*					ВАРИАНТ № 5.1						  *
*В файле исходных данных содержится одномерный массив,    *
*состоящий из п чисел. Написать, отладить и протестировать*
*программу, выполняющую:                                  *
*1.	Чтение данных из файла.                               *
*2.	Определение в исходном массиве самой длинной          *
*последовательности, которая является геометрической      *
*прогрессией.                                             *
*3.	Печать исходного массива и найденных                  *
*последовательностей.                                     *
**********************************************************/
 
#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{

	//-------------------- Constants --------------------//
	
	const int NMAX = 8;
	// const FileName

	//-------------------- Variables --------------------//

	double seq[NMAX] = { 1,3, 9,81 ,1,2,4, 8};
	//double seq[NMAX] = { 1,2,4, 8,16,32, 64,128 };  // initial sequence
	double currentQ = seq[1]/seq[0];				// denominator of current subsequence
	int i = 1;                                      // for loop
	int endPrevSeq = 0;                             // points at end of current subsequence

	int l = -1;                                     // length of current subsequence
	int maxL = -1;                                  // length of subsequence wihh max length


	//-------------------- The program --------------------// 
	while (i<(NMAX-1))
	{
		while (i<(NMAX-1) && currentQ==(seq[i + 1] / seq[i]))
			i++;

		// now i points at the end of current subseqvense.
		// length on current seq. = i + 1 - endPrevSeq;

		l = i + 1 - endPrevSeq;
		endPrevSeq = i ;
		maxL = (maxL > l) ? maxL : l;

		cout << "Q: " << currentQ << "\tl: " << l <<  endl;

		l = 2;
		currentQ = (seq[i + 1] / seq[i]);
		i++;
	}
	cout << "maxl: " << maxL << endl;

	getchar();
	getchar();
} // End of Main
  /********** End of file "Main.cpp" **********/
