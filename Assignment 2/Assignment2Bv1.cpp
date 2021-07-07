/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment B
Problem B1
Description of problem:
This program is designed to calculate the
volume of a cone with a structure, by asking
the user to input its height and radius.
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cone
{
    private:
    double height; //A double, the height of the cone
    double radius; //A double, the radius of the base of the cone
    public:
    void setUp(double height, double radius, Cone*ptr);
    double getVolume(Cone*ptr);
    void output(Cone*ptr);
};

/* *********************setUp*************************************
This function stores the height and radius in the Cone structure.
*****************************************************************/
void Cone::setUp(double height, double radius, Cone*ptr)
{
    ptr->height = height;
    ptr->radius = radius;
}

/* **************************InputData**********
This function calculates the volume of the cone.
************************************************/
double Cone::getVolume(Cone*ptr)
{

    double volume;

    volume = (PI)*(ptr->radius * ptr->radius)*(ptr->height/3);
    return volume;
}

/* ***********************output*****************************
This function prints the radius, height and volume of a cone.
************************************************************/
void Cone::output(Cone*ptr)
{
    double volume;
    volume = getvolume();
    cout << fixed << showpoint << setprecision(5) << endl;
    cout << ptr->radius << endl;
    cout << ptr->height; << endl;
    cout << volume; << endl;
}



void input(double &height, double &radius);
void setUp(double height, double radius, Cone*ptr);
void getVolume(Cone*ptr);
void output(Cone*ptr);

/* ************Main******************************************
***Calls other functions and creates/deletes the Cone pointer
************************************************************/
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

/* ***************input******************************************
This function asks the user for the height and radius of the cone
*****************************************************************/
void input(double &height, double &radius)
{
    cout << "Please enter the height of the Cone" << endl;
    cin >> height; << endl;
    cout << "Please enter the radius of the Cone" << endl;
    cin << radius << endl;
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
