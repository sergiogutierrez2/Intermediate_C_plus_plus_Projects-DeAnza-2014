/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment B
Problem B2
Description of problem:
This program is designed to calculate the
volume of a cone with a Class, by asking
the user to provide its height and radius.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;
const double PI = 3.14159265358979323846;

class Cone
{
    private:
    double height; //A double, the height of the cone
    double radius; //A double, the radius of the base of the cone
    double *ptrheight = &height; //A pointer to the height of the cone
    double *ptrradius = &radius; //A pointer to the radius of the cone
    public:
    void setUp(double height, double radius);
    double getVolume();
    void output();
};

/* *********************setUp*************************************
This function stores the height and radius in the Cone structure.
*****************************************************************/
void Cone::setUp(double height, double radius)
{
    *ptrheight = height;
    *ptrradius = radius;
}

/* ****************InputData*********************
*This function computes the volume of the cone***
*************************************************/
double Cone::getVolume()
{
   return PI * pow(radius,2) * height/3;
}

/* ***********************output************************************************
*This function prints the radius, height and volume of a cone in a fancy manner*
********************************************************************************/
void Cone::output()
{
    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "**********************************" << endl;
    cout << right << "The Height of the cone is " << setw(7) << height << endl;
    cout << "The Radius of the cone is " << setw(7) << radius << endl;
    cout << "The Volume of the cone is " << setw(7) << getVolume() << endl;
    cout << "**********************************" << endl;
}

void input(double &height, double &radius);

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
    ptr->setUp(height, radius);
    ptr->output();
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

/*Execution results
Please enter the height of the Cone:
6
Please enter the radius of the Cone:
2

**********************************
The Height of the cone is    6.00
The Radius of the cone is    2.00
The Volume of the cone is   25.13
**********************************

Process returned 0 (0x0)   execution time : 2.271 s
Press any key to continue.
*/
