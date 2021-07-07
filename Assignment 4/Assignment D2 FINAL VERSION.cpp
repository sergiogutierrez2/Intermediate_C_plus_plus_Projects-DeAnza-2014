/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment D
Problem D2
Description of problem:
This program shows the functionality of a class
called Car and its members (both public and private).
It also shows how information is read from a file, and
shows how to push and pop a string of cars.
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
    Car & operator = (const Car & carB);
};

/* **********StringofCars Class *******************
*** Which creates an array of cars ****************
**************************************************/
class StringofCars
{
   private:
   Car *point;
   static const int ARRAY_MAX_SIZE = 10;
   int size;

   public:
   //default constructor
   StringofCars ()
   {
    point = new Car [ARRAY_MAX_SIZE];
    size = 0;
   }

   //Copy Constructor
   StringofCars (const StringofCars &OBJ)
   {
    size = OBJ.size;
    point = new Car[ARRAY_MAX_SIZE];
    for(int index = 0; index < ARRAY_MAX_SIZE; index++)
    point[index] = OBJ.point[index];
   }

   //destructor
   ~StringofCars()
   {
    delete [] point;
   }

   void output(); //Prototype of a Function named output
   void push(Car more); //Prototype of a Function named push
   void pop(Car &X); //Prototype of a Function named pop

};


/* ****** Function Input Prototype ************/
void input(StringofCars &OBJ);
/* ****** Function output Prototype ************/
void output();

/* ************************************Main******************************************
*Initializes 3 car objects, does 3 tests and calls the pop and output functions.*****
*************************************************************************************/
int main ()
{
  // Test the Car operator=   function.
  cout << "TEST 1" << endl;
  Car car1 ("SP", 34567, "business", true, "Salt Lake City");
  Car car2;
  car2 = car1;
  car2.output();

  // Test the StringOfCar push function.
  StringofCars string1;
  cout << endl;
  cout << "TEST 2" << endl;
  input(string1);
  cout << "STRING 1" << endl;
  string1.output();

  //Test the String of Cars pop function
  cout << endl;
  cout << "TEST 3" << endl;
  Car car3;
  string1.pop(car3);
  cout << "CAR 3" << endl;
  car3.output();
  cout << endl;
  cout << "STRING 1" << endl;
  string1.output();
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

// Car  operator=  **************************************************
Car & Car::operator=(const Car & carB)
{
  setUp(carB.reportingMark, carB.carNumber, carB.kind, carB.loaded, carB.destination);

  return * this;
}

/* *************************StringofCars::push*******************************
*********a StringofCars function which adds a car to the string of cars *****
****************************************************************************/
void StringofCars::push(Car more)
{
    point[size] = more;
    ++size;
}

/* *************************StringofCars::pop********************************
*****A StringofCars function which removes a car from the string of cars*****
****************************************************************************/
void StringofCars::pop(Car &X)
{
    X = point[0];
    for(int count = 0; count < size; count++)
        point[count] = point[count + 1];
    size--;
}

/* *************************StringofCars::output******************************
******A StringofCars function which sends an array of pointers to output.*****
******************************************************************************/
void StringofCars::output()
{
    if( size > 0)
    {
      for (int count = 0; count < size; count++)
      {
         cout << endl;
         cout<<"The car # is: "<< (count + 1)<<endl;
         point[count].output();
      }
    }

    else { cout << "There's no car information to display." << endl; }
}

/* ************************input*******************************
This function obtains from the user the values of 5 variables.
**************************************************************/
void input(StringofCars &OBJ)
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
            OBJ.push(temp);
         }

    inputFile.close();

    }
}

/*
Execution Results when the file is successfully opened:
TEST 1

********************************************
Reporting mark of the car:     SP
The number of the car:         34567
The kind of car:               business
Loaded car:                    true
Destination of the car:        Salt Lake City
********************************************
TEST 2
STRING 1
The car # is: 1

********************************************
Reporting mark of the car:     CN
The number of the car:         819481
The kind of car:               maintenance
Loaded car:                    false
Destination of the car:        NONE
********************************************
The car # is: 2

********************************************
Reporting mark of the car:     SLSF
The number of the car:         46871
The kind of car:               business
Loaded car:                    true
Destination of the car:        Memphis
********************************************
The car # is: 3

********************************************
Reporting mark of the car:     AOK
The number of the car:         156
The kind of car:               tender
Loaded car:                    true
Destination of the car:        McAlester
********************************************
TEST 3
CAR 3

********************************************
Reporting mark of the car:     CN
The number of the car:         819481
The kind of car:               maintenance
Loaded car:                    false
Destination of the car:        NONE
********************************************
STRING 1
The car # is: 1

********************************************
Reporting mark of the car:     SLSF
The number of the car:         46871
The kind of car:               business
Loaded car:                    true
Destination of the car:        Memphis
********************************************
The car # is: 2

********************************************
Reporting mark of the car:     AOK
The number of the car:         156
The kind of car:               tender
Loaded car:                    true
Destination of the car:        McAlester
********************************************

Process returned 0 (0x0)   execution time : 0.509 s
Press any key to continue.

Execution Results when the file is NOT successfully opened:

TEST 1

********************************************
Reporting mark of the car:     SP
The number of the car:         34567
The kind of car:               business
Loaded car:                    true
Destination of the car:        Salt Lake City
********************************************
TEST 2
The file was not successfully opened.
Process returned 1 (0x1)   execution time : 1.616 s
Press any key to continue.
*/
