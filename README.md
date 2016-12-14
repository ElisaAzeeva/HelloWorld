**���������� ����������� �������� 
(������������ ����������������� �����������)**

��������� �3 ������� ����������, ����������� � �����������������

������� 302

������������ ������ �2

�� ����

  ���������� �������
======================

������ 30-107�

������� �5

���������:
������ ������� �������������,
������ ��������� ���������

�������:
������� ���� ���������

������, 2016�.

  ����������
--------------

15. ����������
178. �������
3. ���� �����
8765. ���������
1. ��� ���������
1. �����
1. �����

  �������
-----------

(https://drive.google.com/open?id=0B0p6APFtHxdrdjZRUk9Sb0JsUzQ)

  ���� �����
--------------

  ���������
-------------

	������ "���������� �������"
		������ �����
		���� ���� i < (N-1)
		��
			���� ������� ������� ����� ����, � ��������� �� ����� ���� ��
				����������� i �� 1
				���������� ������� ��������
			����� ����
		
			������� ����������� ������� ����������
			��������� ������ ������ ����������
			
			���� ���� i < (N-1) � ��������� ����������� ����� ��������
			��
				����������� i �� 1
			��
		
			������� ����� ������� ������������������
			��������� ������ ������� ������� ������������������
			����� ������� ������������������
		
			���� ����� ������� ������������������ ������ ����� ������������ ��
				��������� ������� ������������������ ��� ������������
			����� ����
		��
		����� ������������ ������������������
	������ "���������� �������" 

  ��� ���������
-----------------

	/**********************************************************
	* Project type  : Win 32 Console Application              *
	* Project name  : Lab_2_ver_0.1                           *
	* File name     : Main.cpp                                *
	* Language      : C++, MS VS 2015                         *
	* Programmer(1) : ������ ��������� ���������              *
	* Programmer(2) : ������ ������� �������������            *
	* Modified by   :         /-----//-----/                  *
	* Created       : 28.11.2016 18:03                        *
	* Last revision : 30.11.2016 11:35                        *
	* Comment       :                                         *
	*---------------------------------------------------------*
	*������� 302                     ����: �����������        *
	*�������� ������:  ���������� �������                     *
	*---------------------------------------------------------*
	*                     ������� � 5.1                       *
	*� ����� �������� ������ ���������� ���������� ������,    *
	*��������� �� n �����. ��������, �������� � ��������������*
	*���������, �����������:                                  *
	*1. ������ ������ �� �����.                               *
	*2. ����������� � �������� ������� ����� �������          *
	*������������������, ������� �������� ��������������      *
	*�����������.                                             *
	*3. ������ ��������� ������� � ���������                  *
	*�������������������.                                     *
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
	    double b;               // Current sequence element.
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
	             <<  " doesn't exist!" << endl;
	
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
	        cout << "\tError: sequence length can't be bigger than " 
	             << NMAX << endl;
	
	        fin.close();
	        cin.get(); // Wait for input
	        return -4;
	    } 
	    else if (N < 2)
	    {
	        cout << "\tError: sequence length can't be less than 2" << endl;
	
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
	        // If current element equals zero and next not zero then
	        // we can't calculate denominator 
	        if ((0 == seq[i]) && (0 != seq[i + 1])) 
	        {
	            // Increment counter and skip current iteration.
	            i++;
	            continue;
	        } // end if
	        //Now we can calculate denominator 
	
	        // Calculate current denominator and end of previous subsequence.
	        // If numerator equals zero than fraction equals zero too.
	        currentQ = (0 == seq[i + 1])? 0 : (seq[i + 1] / seq[i]);
	        endPrevSeq = i;
	
	        // While next element is part of current subsequence.
	        // Search for end of current subsequence.
	        while (i < (N - 1) && currentQ == ((0 == seq[i + 1]) ? 0 : (seq[i + 1] / seq[i])))
	        {
	            i++;
	        } // end while
	
	        // Now i points at the end of current subsequence.
	        // Length of current seq. = i - endPrevSeq + 1
	        // (+1 because first element of current seq. is last element of previous.)
	        
	        len = i - endPrevSeq + 1; // Calculate length of current subsequence.
	        currentFirstElement = seq[endPrevSeq]; // Remember first element of current subsequence.
	        
	        // Write current subsequence.
	        for (j = 0; j < len; j++)
	        {
	            b = currentFirstElement * pow(currentQ, j);
	            cout << b << "  ";
	            fout << b << "  ";
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
	        b = maxFirstElement * pow(maxQ, i);
	        cout << b << "  ";
	        fout << b << "  ";
	    } // end for
	
	    cin.get(); // Wait for input.
	
	    return 0;
	} // end of Main
	  /********** End of file "Main.cpp" **********/

  �����
---------


  �����
---------

���������� � ������� ��������� "���������� �������" ������� ���������. 
����� ������ ������� ������.
