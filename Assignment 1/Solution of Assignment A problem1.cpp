/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment A
Problem A1
Description of problem:
On this program, Function main calls 5 different functions
which will ask the user how many strings they want, allow
him/her to type them and then print them
*/

#include <iostream>
#include <string>
using namespace std;

void getSize(int&numstrings);
void getSpace(string *&Thestrings, int&numstrings);
void inputData(string *&Thestrings, int&numstrings);
void printData(string *&Thestrings, int&numstrings);
void destroy(string *&Thestrings, int&numstrings);

/* ************Main***********
***Calls the other functions**
******************************/
int main ()
{
    int numstrings;
    string *Thestrings;
    getSize(numstrings);
    getSpace(Thestrings,numstrings);
    inputData(Thestrings,numstrings);
    printData(Thestrings,numstrings);
    destroy(Thestrings,numstrings);
}

/* ***************getSize*********************
It asks the user how many strings they want
***********************************************/
void getSize(int &numstrings)
{
    cout << "How many strings do you want?" << endl;
    cin >> numstrings;
    numstrings = numstrings+1;
}
/* *********************getSpace***********************
Gets an array in the heap of the size requested by the user.
**********************************************************/
void getSpace(string *&Thestrings, int &numstrings)
{
    Thestrings = new string[numstrings];
}

/* **************************InputData***************************
Allows the user to input the strings and stores them in the array
****************************************************************/
void inputData(string *&Thestrings, int &numstrings)
{

    cout << "Please enter the information you want on each string:" << endl;
    for (int index = 0; index < numstrings; index++)
    {
        getline (cin,Thestrings[index]);
    }
}

/* ***********************printData***************
It prints all the strings, one string per line
*************************************************/
void printData(string *&Thestrings, int &numstrings)
{
    cout << endl;
    cout << "These are the strings you entered:" << endl;
        for (int index = 0; index < numstrings; index++)
    {
    cout << Thestrings[index];
    cout << endl;
    }
}

/* *****************Destroy**************
It returns all the space to the heap
****************************************/
void destroy (string *&Thestrings,int&numstrings)
{
    delete []Thestrings;
    Thestrings = 0;
}

/*Execution results
How many strings do you want?
3
Please enter the information you want on each string:
Hi my name is Sergio Gutierrez
This is the second string I'm entering
This is the third and last

These are the strings you entered:

Hi my name is Sergio Gutierrez
This is the second string I'm entering
This is the third and last

Process returned 0 (0x0)   execution time : 47.541 s
Press any key to continue.
*/

