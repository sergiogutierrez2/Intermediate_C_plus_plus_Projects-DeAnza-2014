/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment D
Problem D1
Description of problem:
This program shows the functionality of a class
called Car and its members (both public and private).
It also shows how information is read from a file.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;


/* **********class Car ****************************
*** Which stores the information of cars **********
**************************************************/
class Car
{
    private:
    string reportingMark;
    int carNumber;
    string kind;
    bool loaded;
    string destination;

    public:
     Car()  //DEFAULT
    {
      setUp("", 0, "other",false, "NONE");
    }

    Car(const Car &cop) //Copy Constructor

    {
       setUp(cop.reportingMark, cop.carNumber, cop.kind, cop.loaded, cop.destination);
    }

    //The 3rd Constructor Function
    Car(const string reportingMark3, const int carNumber3, const string kind3, const bool loaded3, const string destination3)
    {
      setUp (reportingMark3, carNumber3, kind3, loaded3, destination3);
    }

    ~Car() //Destructor
    { }

    friend bool operator==(Car LEFT, Car RIGHT);
    void setUp(string reportingMark2, int carNumber2, string kind2, bool loaded2, string destination2);
    void output();
};

void input();

/* *************Main********************
*It only calls a function called input.*
****************************************/
int main ()
{
 input();
}

/* ***********************************setUp**************************************************
This function receives 5 parameters by value and stores them in the object's private members.
*********************************************************************************************/
void Car::setUp(string reportingMark2, int carNumber2, string kind2, bool loaded2, string destination2)
{
    reportingMark = reportingMark2;
    carNumber = carNumber2;
    kind = kind2;
    loaded = loaded2;
    destination = destination2;
}

/* **********************************output*************************************
This function prints the reportingMark, carNumber, kind, loaded and destination.
*******************************************************************************/
void Car::output()
{

    cout << endl;
    cout << "********************************************" << endl;
    cout << left << setw(31) << "Reporting mark of the car: " << reportingMark << endl;
    cout << setw(31) << "The number of the car:     " << carNumber << endl;
    cout << setw(31) << "The kind of car:           " << kind << endl;
    if (loaded == 1)
    cout << setw(31) << "Loaded car:                " << boolalpha << true << endl;
    else
    cout << setw(31) << "Loaded car:                " << boolalpha << false << endl;
    cout << setw(31) << "Destination of the car:    " << destination << endl;
    cout << "********************************************" << endl;
}


/* ********************* function bool operator == and its content*******************/
bool operator==(Car LEFT, Car RIGHT)
{
    return (LEFT.reportingMark == RIGHT.reportingMark && LEFT.carNumber == RIGHT.carNumber);
}

/* ************************input*******************************
This function opens a file and reads from it. If the file fails
to open, the function will display an error message.***********
**************************************************************/
void input()
{

      ifstream inputFile ("MotorVehicle.txt");

      if (inputFile.fail())
      {
          fputs("The file was not successfully opened.", stderr);
          exit(EXIT_FAILURE);
      }
      else
      {

      string reportingMark;
      int carNumber;
      string kind;
      bool loaded;
      string loaded2;
      string destination;
      string type;

      while (inputFile.peek() != EOF)
        {
            inputFile >> type;
            inputFile >> reportingMark;
            inputFile >> carNumber;
            inputFile >> kind;

            inputFile >> loaded2;
            if (loaded2 == "true")
            {loaded = 1;}
            else
            {loaded = 0;}

            while (inputFile.peek() == ' ')
            inputFile.get();
            getline(inputFile, destination);

            Car temp(reportingMark, carNumber, kind, loaded, destination);
            temp.output();
         }

    inputFile.close();

    }
}

/*
Execution results if the file is successfully opened:

********************************************
Reporting mark of the car:     CN
The number of the car:         819481
The kind of car:               maintenance
Loaded car:                    false
Destination of the car:        NONE
********************************************

********************************************
Reporting mark of the car:     SLSF
The number of the car:         46871
The kind of car:               business
Loaded car:                    true
Destination of the car:        Memphis
********************************************

********************************************
Reporting mark of the car:     AOK
The number of the car:         156
The kind of car:               tender
Loaded car:                    true
Destination of the car:        McAlester
********************************************

Process returned 0 (0x0)   execution time : 0.389 s
Press any key to continue.

---------------------------------------------------
Execution results if the file is NOT successfully opened:

The file was not successfully opened.
Process returned 1 (0x1)   execution time : 0.347 s
Press any key to continue.
*/
