/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment B
Problem B1
Description of problem:
On this program, Function main calls 4 different functions
which will ask the user how many strings they want, allow
him/her to type them and then print them
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Cone;
{
    double height; //A double, the height of the cone
    double radius; //A double, the radius of the base of the cone
};

void input(double &height, double &radius);
void setUp(double height, double radius, Cone*ptr);
void getVolume(Cone*ptr);
void output(Cone*ptr);

/* ************Main***********
***Calls the other functions**
******************************/
int main ()
{
    const double PI = 3.14159265358979323846;
    Cone *ptr;
    ptr = new Cone;
    double height;
    double radius;
    input(height, radius);
    setUp(height, radius, &ptr);
    //getVolume(Thestrings,numstrings);
    output(&ptr);
    delete ptr;
}

/* ***************input*********************
It asks the user how many strings they want
***********************************************/
void input(double &height, double &radius)
{
    cout << "Please enter the height of the Cone" << endl;
    cin >> height; << endl;
    cout << "Please enter the radius of the Cone" << endl;
    cin << radius << endl;
}
/* *********************getSpace***********************
Gets an array in the heap of the size requested by the user.
**********************************************************/
void setUp(double height, double radius, Cone*ptr)
{
    ptr->height = height;
    ptr->radius = radius;
}

/* **************************InputData***************************
Allows the user to input the strings and stores them in the array
****************************************************************/
double getVolume(Cone*ptr)
{

    double volume;

    volume = (PI)*(ptr->radius * ptr->radius)*(ptr->height/3);
    return volume;
}

/* ***********************output***************
It prints all the strings, one string per line
*************************************************/
void output(Cone*ptr)
{
    double volume;
    volume = (PI)()

    cout << fixed << showpoint << setprecision(5);
    return volume;
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
