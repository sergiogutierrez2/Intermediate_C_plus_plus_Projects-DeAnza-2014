/*
Sergio Gutierrez
Timothy Lee
CIS 22B
Fall 2014
Assignment Optional Extra Credit 2
Problem Optional Extra Credit 2
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

enum Kind {business, maintenance, other, box, tank, flat, otherFreight, chair, sleeper, otherPassenger};
const string KIND_ARRAY[]={"business", "maintenance", "other", "box", "tank", "flat", "otherFreight", "chair", "sleeper", "otherPassenger"};

/* **********class Car ****************************
*** Which stores the information of cars **********
**************************************************/
  class Car
  {
    protected:

    string reportingMark;
    int carNumber;
    Kind kind;
    bool loaded;
    string destination;

    public:

     Car()  //DEFAULT
    {
      setUp("", 0, other,false, "NONE");
    }

    Car(const Car &cop) //Copy Constructor

    {
       setUp(cop.reportingMark, cop.carNumber, cop.kind, cop.loaded, cop.destination);
    }

    //The 3rd Constructor Function
    Car(const string reportingMark3, const int carNumber3, const Kind kind3, const bool loaded3, const string destination3)
    {
      setUp (reportingMark3, carNumber3, kind3, loaded3, destination3);
    }

    virtual ~Car() //Destructor
    { }

    friend bool operator==(Car LEFT, Car RIGHT);
    Car & operator = (const Car & carB);

    void setUp(string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2);
    void output();

    /* ************setKind ***************
    *****will set the correct Kind********
    *************************************/
    virtual void setKind(const Kind OBJ)

    {
        if (OBJ != business && OBJ != maintenance)  //CHANGE
            kind = other;
    }
  };

 class StringOfCars;
template <class T>
  /* **********class Node **************************************************
  *** This class uses Node objects, linked together to make a list**********
  **************************************************************************/
  class Node
  {
    private:
    Node* next;
    T* data;
    //default constructor
    Node ()
    {
     next = 0;
     data = 0;
    }

   public:

   friend class StringofCars;

   //Copy Constructor
   Node (const Node &OBJ)
   {
   }

   //destructor
   ~Node()
    {

    }

  };


  /* **********StringofCars Class *******************
  *** Which creates an array of cars ****************
  **************************************************/
  class StringofCars
 {
   private:
   Node<Car>* head;
   Node<Car>* tail;

   public:
   //default constructor
   StringofCars ()
   {
   head = 0;
   tail = 0;
   }

     //Copy Constructor
   StringofCars (const StringofCars &OBJ)
   {
        Node<Car>* currentNodePtr;
        currentNodePtr = OBJ.head;
        head = 0;
        tail = 0;
        if (OBJ.head != 0)
        {
            while(currentNodePtr != 0)
            {
              push(*currentNodePtr->data);
                currentNodePtr = currentNodePtr->next;
            }
        }
   }

   //destructor
   ~StringofCars()
    {

    }

   void output(); //Prototype of a Function named output
   void push(const Car more); //Prototype of a Function named push
 };



 /* ************************************ Function buildcar **************************************
 ******* it builds an object of type Car by using the Car constructor that has five parameters.***
 ************************************************************************************************/
  void buildCar (string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2, StringofCars &OBJ)
 {
  Car X(reportingMark2, carNumber2, kind2, loaded2, destination2);
  X.setKind(kind2);
  OBJ.push(X);

 }

  class FreightCar : public Car
 {
    public:
    FreightCar():Car()
    {
    }

    FreightCar(const FreightCar & OBJ) : Car(OBJ)
    {
    }

    FreightCar(string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2):Car(reportingMark2, carNumber2, kind2, loaded2, destination2)
    {
    }

    /* *****setKind of FreightCar ********
    *****will set the correct Kind********
    *************************************/
    void setKind(const Kind OBJ) //This could be made Virtual but it doesn't have to since its a derived class.

    {
        if (OBJ != box && OBJ != tank && OBJ != flat)
            kind = otherFreight;
    }
 };

/* ************ Function buildcar ****************
******* This one is used to build a FreightCar****
**************************************************/
void buildFreightCar (string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2, StringofCars &OBJ)
{
  FreightCar X(reportingMark2, carNumber2, kind2, loaded2, destination2);
  X.setKind(kind2);
  OBJ.push(X);

}

/* **********class PassengerCar ******************
*** Which is a class inherited from class Car ****
**************************************************/
class PassengerCar : public Car
{
    public:
    PassengerCar():Car()
    {
    }

    PassengerCar(const PassengerCar &OBJ) : Car(OBJ)
    {
    }

    PassengerCar(string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2) : Car(reportingMark2, carNumber2, kind2, loaded2, destination2)
    {
    }

    /* ***setKind of PassengerCar ********
    *****will set the correct Kind********
    *************************************/
    void setKind(const Kind k) //This could be made Virtual but it doesn't have to since its a derived class.
    {
        if (k != chair && k != sleeper)
            kind = otherPassenger;
    }
}
;

/* ************Function buildPassengerCar**************
****This one is used to build  buildPassengerCar********
********************************************************/
void buildPassengerCar (string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2, StringofCars &OBJ)
{
  PassengerCar X(reportingMark2, carNumber2, kind2, loaded2, destination2);
  X.setKind(kind2);
  OBJ.push(X);
}

/* ****** Function Input Prototype ************/
void input(StringofCars &OBJ);
/* ****** Function output Prototype ************/
void output();

/* ****************Main*****************
*Calls the input function***************
***************************************/
int main()

{
    StringofCars string1;
    input(string1);
    StringofCars string2(string1);
    string2.output();
    return 0;
}

/* ***********************************setUp**************************************************
This function receives 5 parameters by value and stores them in the object's private members.
*********************************************************************************************/
void Car::setUp(string reportingMark2, int carNumber2, Kind kind2, bool loaded2, string destination2)
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
    cout << setw(31) << "The kind of car:           " << KIND_ARRAY[kind] << endl;
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
void StringofCars::push(const Car more)
{

    Car* currentCarPtr;
    Node<Car>* currentNodePtr;

    currentNodePtr = new Node<Car>;
    currentCarPtr = new Car(more);

    currentNodePtr->data = currentCarPtr;

    if(head == 0)
    {
        head = currentNodePtr;
        tail = currentNodePtr;
        currentNodePtr->next = 0;
    }
    else
    {
        tail->next = currentNodePtr;
        tail = currentNodePtr;
    }
}

/* *************************StringofCars::output******************************
******A StringofCars function which sends an array of pointers to output.*****
******************************************************************************/
void StringofCars::output()
{
    Node<Car>* currentNodePtr;
    int Carnum = 0;
    if(head == 0)
    {
        cout << "NO cars \n";
    }
    else
    {
        currentNodePtr = head;
        while (currentNodePtr != 0)
        {
        Carnum ++;
        cout <<endl << "Car # : " << Carnum << endl;
            currentNodePtr->data->output();
            currentNodePtr = currentNodePtr->next;
        }
    }
}

/* ************************input*******************************
****This function reads car related information from a file****
**************************************************************/
void input(StringofCars &OBJ)
{
        string type;
        string reportingMark;
        string order;
        int carNumber;
        Kind kind2 = otherPassenger;
        string kind;
        bool loaded;
        string loaded2;
        string destination;
        int orderNum = 0;

        ifstream inputFile ("AUTOS.txt");

      if (inputFile.fail())
      {
          fputs("The file was not successfully opened.", stderr);
          exit(EXIT_FAILURE);
      }

      else
      {

       while (inputFile.peek() != EOF)

        {
            orderNum++;
            inputFile >> type;
            inputFile >> order;
            inputFile >> reportingMark;
            inputFile >> carNumber;
            inputFile >> kind;

            for (int count = 0; count < 9; count ++)

            {

                if (kind == KIND_ARRAY[count])

                {
                    kind2 = static_cast<Kind>(count);
                    break;
                }

                else
                kind2 = otherFreight;

            }

            inputFile >> loaded2;

            if (loaded2 == "true"){ loaded = 1; }
            else {loaded = 0;}

            while (inputFile.peek() == ' ')
            inputFile.get();

            getline(inputFile, destination);

            if (type == "Car")
            {
                buildCar(reportingMark,carNumber,kind2,loaded,destination, OBJ);
            }
            else if (type == "FreightCar")
            {
                buildFreightCar(reportingMark, carNumber, kind2, loaded, destination, OBJ);
            }
            else if (type == "PassengerCar")
            {
                buildPassengerCar(reportingMark, carNumber, kind2, loaded, destination, OBJ);
            }
        }
    }

    inputFile.close();
}

/*

Car # : 1

********************************************
Reporting mark of the car:     CN
The number of the car:         819481
The kind of car:               maintenance
Loaded car:                    false
Destination of the car:        NONE
********************************************

Car # : 2

********************************************
Reporting mark of the car:     SLSF
The number of the car:         46871
The kind of car:               business
Loaded car:                    true
Destination of the car:        Memphis
********************************************

Car # : 3

********************************************
Reporting mark of the car:     AOK
The number of the car:         156
The kind of car:               other
Loaded car:                    true
Destination of the car:        McAlester
********************************************

Car # : 4

********************************************
Reporting mark of the car:     MKT
The number of the car:         123456
The kind of car:               tank
Loaded car:                    false
Destination of the car:        Fort Worth
********************************************

Car # : 5

********************************************
Reporting mark of the car:     MP
The number of the car:         98765
The kind of car:               box
Loaded car:                    true
Destination of the car:        Saint Louis
********************************************

Car # : 6

********************************************
Reporting mark of the car:     SP
The number of the car:         567890
The kind of car:               flat
Loaded car:                    true
Destination of the car:        Chicago
********************************************

Car # : 7

********************************************
Reporting mark of the car:     GMO
The number of the car:         7878
The kind of car:               otherFreight
Loaded car:                    true
Destination of the car:        Mobile
********************************************

Car # : 8

********************************************
Reporting mark of the car:     KCS
The number of the car:         7893
The kind of car:               chair
Loaded car:                    true
Destination of the car:        Kansas City
********************************************

Car # : 9

********************************************
Reporting mark of the car:     PAPX
The number of the car:         145
The kind of car:               sleeper
Loaded car:                    true
Destination of the car:        Tucson
********************************************

Car # : 10

********************************************
Reporting mark of the car:     GN
The number of the car:         744
The kind of car:               otherPassenger
Loaded car:                    false
Destination of the car:        NONE
********************************************

Process returned 0 (0x0)   execution time : 0.390 s
Press any key to continue.
*/
