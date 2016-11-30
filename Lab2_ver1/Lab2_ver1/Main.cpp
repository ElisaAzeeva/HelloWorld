/**********************************************************
* Project type  : Win 32 Console Application              *
* Project name  : Lab_2_ver_0.1                           *
* File name     : Main.cpp                                *
* Language      : C++, MS VS 2015                         *
* Programmer(1) : Азеева Елизавета Романовна              *
* Programmer(2) : Князев Алексей Станиславович            *
* Modified by   :         /-----//-----/                  *
* Created       : 28.11.2016 18:03                        *
* Last revision : 29.11.2016 21:35                        *
* Comment       :                                         *
*---------------------------------------------------------*
*Кафедра 302                     Курс: ИНФОРМАТИКА        *
*Курсовая работа:  ОДНОМЕРНЫЕ МАССИВЫ                     *
*---------------------------------------------------------*
*                     ВАРИАНТ № 5.1                       *
*В файле исходных данных содержится одномерный массив,    *
*состоящий из п чисел. Написать, отладить и протестировать*
*программу, выполняющую:                                  *
*1. Чтение данных из файла.                               *
*2. Определение в исходном массиве самой длинной          *
*последовательности, которая является геометрической      *
*прогрессией.                                             *
*3. Печать исходного массива и найденных                  *
*последовательностей.                                     *
**********************************************************/
 
#include<iostream>
#include<fstream>
using namespace std;
 
int main()
{

    //-------------------- Constants --------------------//
    
    const int NMAX = 8;    // Length of initial sequence
    // const FileName

    //-------------------- Variables --------------------//

    //double seq[NMAX] = { 1,0, 1,0, 1,0, 1,0 };
     double seq[NMAX] = { 1,3, 9,81 ,1,2,4, 8};
    //double seq[NMAX] = { 1,2,4, 8,16,32, 64,128 };  // initial sequence


    double currentQ;        // Denominator of current subsequence
    int i,j;                // For loop
    int endPrevSeq;         // Points at end of current subsequence
                           
    int len;                // Length of current subsequence
    int currentFirstElement;// First Element of current subsequence

    int maxL = -1;          // Length of subsequence with max length
    double maxQ;            // Denominator of subsequence with max length
    double maxFirstElement; // First Element of subsequence with max length

    //-------------------- The program --------------------// 
    cout << "FOUND SUBSEQUENCE: " << endl;

    i = 0;
    while (i<(NMAX-1)) // While sequence not end 
    {
        currentQ = seq[i + 1] / seq[i]; // Calculate current denominator
        endPrevSeq = i;                 // Calculate end of previous subsequence 

        // While next element is part of current subsequence
        while (i < (NMAX - 1) && currentQ == (seq[i + 1] / seq[i])) 
        {
            i++;
        }
        // Now i points at the end of current subsequence.
        // Length of current seq. = i - endPrevSeq + 1
        // (+1 because index of first element of current seq. is last element of previous.)
        
        len = i - endPrevSeq + 1; // calculate length of current subsequence.
        currentFirstElement = seq[endPrevSeq]; // remember first element of current subsequence
        
        // Write current subsequence
        for (j = 0; j < len; j++)
        {
            cout << currentFirstElement * pow(currentQ, j) << "  ";
        }
        cout << endl;

        // If previous sub-seq. less than current then remember current sub-seq.
        if (maxL < len) 
        {
            maxL = len;
            maxQ = currentQ;
            maxFirstElement = currentFirstElement;
        }
    }

    // Write subsequence with max length
    cout << "SUBSEQUENCE WITH MAX LENGTH: " << endl;
    for (i = 0; i < maxL; i++)
    {
        cout << maxFirstElement * pow(maxQ, i) << "  ";
    }

    // Wait for input
    cin.get();

} // End of Main
  /********** End of file "Main.cpp" **********/
