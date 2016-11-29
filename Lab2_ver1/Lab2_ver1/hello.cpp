/***************************************************************************************************
* Project type  : Win 32 Console Application                                                       *
* Project name  : Lab_2_ver_0.1                                                                    *
* File name     : Magic.cpp                                                                        *
* Language      : C++, MS VS 2013                                                                  *
* Programmer(1) : Азеева Елизавета Романовна                                                       *
* Programmer(2) : Князев Алексей Станиславович                                                     *
* Modified by   :         /-----//-----/                                                           *
* Created       : 28.11.2016 18:03                                                                 *
* Last revision : 29.11.2016 21:35                                                                 *
* Comment       :                                                                                  *
*--------------------------------------------------------------------------------------------------*
*Кафедра 302   Курс: ИНФОРМАТИКА                                                                   *
*Задание 2: Табулирование функций.                                                                 *
*--------------------------------------------------------------------------------------------------*
*                                          ВАРИАНТ № 5                                             *
*Разработать, отладить и протестировать программу, которая разбивает отрезок [А;В] на N интервалов;*
*в зависимости от значений А, В и N вычисляет величину шага h = (В - А) / N, с которым происходит  *
*приращение аргумента Xi = А + i * h, и в каждой точке Xi печатает значения функций:               *
*F(xi) = sin(x) * cos(x)                                                                           *
*G(xi) = 2 sin (2x) + 1                                                                            *
*Результаты вычислений представить в виде таблицы.                                                 *
*В качестве одного из вариантов исходных данных взять:                                             *
*А = - Pi/4, В = Pi/2, N=15.                                                                       *
*--------------------------------------------------------------------------------------------------*
* Замечание: Для корректного отображения русских символов в консоли необходимо перед компиляцией   *
* перекодировать файл с помощью кодировки OEM 866. В Visual Studio это можно сделать через меню    *
* Файл>Дополнительные параметры сохранения...                                                      *
****************************************************************************************************/
 
#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{

	//-------------------- Constants --------------------//
	
	const int NMAX = 8;
	// const FileName

	//-------------------- Variables --------------------//
 
	int N = 0;    // The array length 
	int i = 0;    // The loop counter 
	int j = 0;    // The loop counter #2 
	int ArrGeomProgression[NMAX]={2,4,8,3,5,1,2,4};
	double ArrQuotent[NMAX]; // Array of quotent pairs
	int Count = 1; // Pair counter 
	int MaxCount = 0; // Max pair length 
 
	//-------------------- The program --------------------// 
 
	for(i = 0; i < NMAX-1; i++) // NMAX-1 because [i+1]
	{
		ArrQuotent[i] = ArrGeomProgression[i+1]* 1.0 / ArrGeomProgression[i] ; //find 
		//cout << "ArrQuotent[" << i <<"]=" << ArrQuotent[i] << endl;
	
	}

	for( i = 0; i < NMAX-2; i++)
	{
		if ( ArrQuotent[i] == ArrQuotent[i+1])
			{
				Count++;
				//cout << "count" << Count << endl;
			}
		else
		{
			if (Count > MaxCount)
			{ MaxCount = Count;
			Count = 1;
			} //if
		} //else
	} //for i

	if ( Count > MaxCount )
		MaxCount = Count;
	   //cout << MaxCount << endl;
	Count = 1;

	for( i = 0; i < NMAX-2; i++)
	{
		//cout << "i   " << i << endl;
		//cout << "ArrQuotent   " << ArrQuotent[i] << endl;

		if ( ArrQuotent[i] == ArrQuotent[i+1])
		{
			Count++;
			//cout << "i+1" << i+1 << endl;
			//cout << "Count" << Count << endl;
			//cout << "MaxCount" << MaxCount << endl;
			if ( ((i+1) == NMAX-2) && (Count == MaxCount))
				for ( j = i+1 - MaxCount; j < i + 1 + MaxCount; j++)
				{
					cout << ArrGeomProgression[j] << "[j]="<< j << endl;
					cout << "error1" << endl;
				}
		}
		else
		{
			if (Count == MaxCount)
			{ 
				for ( j = i + 1 - MaxCount; j < i + MaxCount; j++)
				{
					cout << ArrGeomProgression[j] << endl;
					cout << "error2" << endl;
				}
			Count = 1;
			} //if
		} //else

		

	} //for i
	//cout << "ArrQuotent6   " << ArrQuotent[6] << endl;
	getchar();
	getchar();
		//return 0;
} // End of Main
  /********** End of file "Main.cpp" **********/
