/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment B
Problem B1
Description of problem:
This program is designed to calculate the
volume of a cone with a structure, by asking
the user to provide its height and radius.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

struct Cone
{
    double height; //A double, the height of the cone
    double radius; //A double, the radius of the base of the cone
};

void input(double &height, double &radius);
void setUp(double height, double radius, Cone*ptr);
double getVolume(Cone*ptr);
void output(Cone*ptr);
const double PI = 3.14159265358979323846;

/* ************Main*******************************************************************
**This function calls the other functions. It also creates & deletes the Cone pointer*
*************************************************************************************/
int main ()
{
    Cone *ptr;
    ptr = new Cone;
    double height;
    double radius;
    input(height, radius);
    setUp(height, radius, ptr);
    output(ptr);
    delete ptr;
    ptr = 0;
    return 0;
}

/* ***************input********************************
Requests height and radius from the user.**************
*******************************************************/
void input(double &height, double &radius)
{
    cout << "Please enter the height of the Cone:" << endl;
    cin >> height;
    cout << "Please enter the radius of the Cone:" << endl;
    cin >> radius;
}
/* *********************setUp**********************
Stores height and radius in the Cone structure.****
***************************************************/
void setUp(double height, double radius, Cone*ptr)
{
    ptr->height = height;
    ptr->radius = radius;
}

/* ****************InputData*********************
*This function computes the volume of the cone***
*************************************************/
double getVolume(Cone*ptr)
{
    return PI * pow(ptr->radius,2) *ptr->height/3;
}

/* ***********************output************************************************
*This function prints the radius, height and volume of a cone in a fancy manner*
********************************************************************************/
void output(Cone *ptr)
{
    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "**********************************" << endl;
    cout << "The Height of the cone is "  << right << setw(7) << ptr->height << endl;
    cout << "The Radius of the cone is " << setw(7) << ptr->radius << endl;
    cout << "The Volume of the cone is " << setw(7) << getVolume(ptr) << endl;
    cout << "**********************************" << endl;
}

/*Execution results
Please enter the height of the Cone:
6
Please enter the radius of the Cone:
2

**********************************
The Height of the cone is   6.00
The Radius of the cone is   2.00
The Volume of the cone is   25.13
**********************************

Process returned 0 (0x0)   execution time : 5.870 s
Press any key to continue.
*/
