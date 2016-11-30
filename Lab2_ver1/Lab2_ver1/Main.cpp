/**********************************************************
* Project type  : Win 32 Console Application              *
* Project name  : Lab_2_ver_0.1                           *
* File name     : Main.cpp                                *
* Language      : C++, MS VS 2015                         *
* Programmer(1) : Азеева Елизавета Романовна              *
* Programmer(2) : Князев Алексей Станиславович            *
* Modified by   :         /-----//-----/                  *
* Created       : 28.11.2016 18:03                        *
* Last revision : 30.11.2016 11:35                        *
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
    
    const int  NMAX = 100;                       // Max length of initial sequence.
    const char INPUT_FILE_NAME[] = "Input.txt";  // Input file name.
    const char OUTPUT_FILE_NAME[] = "Result.txt";// Output file name.

    //-------------------- Variables --------------------//

    double seq[NMAX] = {0}; // Initial sequence.

    int N;                  // True length of initial sequence.

    double currentQ;        // Denominator of current subsequence
    int i,j;                // For loop
    int endPrevSeq;         // Points at end of current subsequence
                           
    int len;                // Length of current subsequence
    int currentFirstElement;// First Element of current subsequence

    int maxL = -1;          // Length of subsequence with max length
    double maxQ;            // Denominator of subsequence with max length
    double maxFirstElement; // First Element of subsequence with max length

    //-------------------- Reading file --------------------// 

    ifstream fin(INPUT_FILE_NAME); // Input file.

    // Check if file exists.
    if (!fin)
    {
        cout << "\tError: input file: " << INPUT_FILE_NAME 
             <<  " dosen't exist!" << endl;

        fin.close();
        cin.get(); // Wait for input
        return -1;
    } //end if

    // Read length of initial sequence.
    fin >> N;

    if (fin.eof()) //If input file empty then exit.
    {
        cout << "\tError: input file: " << INPUT_FILE_NAME
             << " is empty!" << endl;

        fin.close();
        cin.get(); // Wait for input
        return -2;
    } // end if

    // Check content of the file.
    if (fin.fail()) 
    {
        cout << "\tError: incorrect format of the input file : " 
             << INPUT_FILE_NAME << endl;

        fin.close();
        cin.get(); // Wait for input
        return -3;
    } // end if

    //Write true length of initial sequence.
    cout << "N: " << N << endl;

    // Check array length.
    if (N > NMAX)
    {
        cout << "\tError: sequance length can't be bigger than " 
             << NMAX << endl;

        fin.close();
        cin.get(); // Wait for input
        return -4;
    } 
    else if (N < 2)
    {
        cout << "\tError: sequance length can't be less than 2" << endl;

        fin.close();
        cin.get(); // Wait for input
        return -4;
    } // end if 

    // Read initial sequence.
    i = 0;
    while (i<N && !fin.eof())
    {
        fin >> seq[i];
        i++;
    } // end while

    // Write initial sequence.
    cout << "INITIAL SEQUANCE: " << endl;
    for (i = 0; i < N; i++)
    {
        cout << seq[i] << "  ";
    } // end for
    cout << endl;


    //-------------------- The program  --------------------// 
    ofstream fout(OUTPUT_FILE_NAME);  // Output file.

    cout << "FOUND SUBSEQUENCE: " << endl;
    fout << "FOUND SUBSEQUENCE: " << endl;

    i = 0;
    while (i<(N-1)) // While sequence not end 
    {
        currentQ = seq[i + 1] / seq[i]; // Calculate current denominator.
        endPrevSeq = i;                 // Calculate end of previous subsequence.

        // While next element is part of current subsequence.
        // Search for end of current subsequence.
        while (i < (N - 1) && currentQ == (seq[i + 1] / seq[i])) 
        {
            i++;
        } // end while
        // Now i points at the end of current subsequence.
        // Length of current seq. = i - endPrevSeq + 1
        // (+1 because first element of current seq. is last element of previous.)
        
        len = i - endPrevSeq + 1; // calculate length of current subsequence.
        currentFirstElement = seq[endPrevSeq]; // remember first element of current subsequence
        
        // Write current subsequence
        for (j = 0; j < len; j++)
        {
            cout << currentFirstElement * pow(currentQ, j) << "  ";
            fout << currentFirstElement * pow(currentQ, j) << "  ";
        } // end for
        cout << endl;
        fout << endl;

        // If previous sub-seq. less than current then remember current sub-seq.
        if (maxL < len) 
        {
            maxL = len;
            maxQ = currentQ;
            maxFirstElement = currentFirstElement;
        } // end if
    } // end while

    // Write subsequence with max length.
    cout << "FIRST SUBSEQUENCE WITH MAX LENGTH: " << endl;
    fout << "FIRST SUBSEQUENCE WITH MAX LENGTH: " << endl;
    for (i = 0; i < maxL; i++)
    {
        cout << maxFirstElement * pow(maxQ, i) << "  ";
        fout << maxFirstElement * pow(maxQ, i) << "  ";
    } // end for

    cin.get(); // Wait for input.

    return 0;
} // end of Main
  /********** End of file "Main.cpp" **********/