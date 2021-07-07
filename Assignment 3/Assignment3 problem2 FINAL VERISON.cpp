/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment C
Problem C2
Description of problem:
This program shows the functionality of a class
called Car and its members (both public and private).
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

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
        setUp(" ", 0, "other",false, "NONE");
    }

    Car(Car &cop) //Copy Constructor
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

    void setUp(string reportingMark2, int carNumber2, string kind2, bool loaded2, string destination2);
    void output();
};


void input(string &reportingMark, int &carNumber, string &kind, bool &loaded, string &destination);

/* ******************************Main******************************
*Calls other functions, defines 5 variables and Car instances******
*******************************************************************/
int main ()
{
    string reportingMark; //Must have between 2 and 4 letters.
    int carNumber; //A number....
    string kind; // business, maintenance or other
    bool loaded; //Its either true or false
    string destination; // Contain the destination or the word none.

    input(reportingMark, carNumber, kind, loaded, destination);

    // This is initialized with the user's previous input:
    Car car1(reportingMark, carNumber, kind, loaded, destination);
    Car car2 = car1; // This will be initialized with Copy Constructor. It will copy car1.
    Car car3; //This will be created with constructor number 3, all by itself.

    car1.output();
    car2.output();
    car3.output();

    return 0;
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

    cout << setprecision(2) << fixed;
    cout << endl;
    cout << "********************************************" << endl;
    cout << "Reporting mark of the car: "  << right << setw(3) << reportingMark << endl;
    cout << "The number of the car: " << setw(3) << carNumber << endl;
    cout << "The kind of car: " << setw(3) << kind << endl;
    if (loaded == 1)
    cout << "Loaded car: " << boolalpha << true << endl;
    else
    cout << "Loaded car: " << boolalpha << false << endl;
    cout << "The destination of the car is: " << setw(3) << destination << endl;
    cout << "********************************************" << endl;
}


/* ************************input*******************************
This function obtains from the user the values of 5 variables.
**************************************************************/
void input(string &reportingMark, int &carNumber, string &kind, bool &loaded, string &destination)
{
      char choicedestination;
      string choiceloaded;

      //*******To Obtain the ReportingMark****
       do
       {
       cout << "Please enter the Reporting Mark, which must contain between 2 and 4 letters:" << endl;
       cin >> reportingMark;

            for (int count = 0; count  < reportingMark.length(); ++count)
            {
                 //Input validation rejects non-alpha numeric characters
                 if (!(isalpha(reportingMark[count])))
                {reportingMark = "false";}
            }
       } while ((!(reportingMark.length() >= 2 && reportingMark.length() <= 4 )) || reportingMark == "false");

      //Convert lowercase letters to uppercase
      for (int index = 0; index  < reportingMark.length(); ++index)
      {
      reportingMark[index] = toupper(reportingMark[index]);
      }

      //*****To Obtain CarNumber******
      cout << "Please enter the car number: " << endl;
      cin >> carNumber;

      //******To obtain the Kind*******
      do
      {
          cout << "For the kind, type in either business, maintenance or other." << endl;
          cin >> kind;
      }   while (!(kind == "business" || kind == "maintenance" || kind == "other"));

    //******To obtain loaded and destination*****

      do
      {
      cout << "Is it loaded? Please enter either true or false: " << endl;
      cin >> choiceloaded;
       //Convert lowercase to uppercase. Rejects strings other than "TRUE" or "FALSE".
        for (int index = 0; index  < choiceloaded.length(); ++index)
        {
         choiceloaded[index] = toupper(choiceloaded[index]);
        }

      } while (!(choiceloaded == "TRUE" || choiceloaded == "FALSE"));

    //stores values in the bool loaded.
    if (choiceloaded == "TRUE")
    {
        loaded = 1;
    }
    else
    {
        loaded = 0;
    }

    //If loaded is false, give the option to provide destination. Otherwise it'll be NONE
    if (loaded == 0)
    {
        cout << "Would you like to enter a destination anyway? Y or N?" << endl;
        cin >> choicedestination;

        while (!(toupper(choicedestination) == 'Y' || toupper(choicedestination) == 'N'))
        {
           cout << "Please enter either Y (for Yes) or N (for No):" << endl;
           cin >> choicedestination;
        }

        if (toupper(choicedestination) == 'N')
        {
         destination = "NONE";
        }

        if (toupper(choicedestination) == 'Y')
        {
         cout << "Please enter a destination:" << endl;
         cin.ignore();
         getline (cin, destination);
        }
    }

    //****If loaded is true, the user must provide a destination****.
    if (loaded == 1)
    {
        cout << "Please enter a destination:" << endl;
        cin.ignore();
        getline (cin, destination);
    }

}

/*
Execution results:
Please enter the Reporting Mark, which must contain between 2 and 4 letters:
SP
Please enter the car number:
34567
For the kind, type in either business, maintenance or other.
business
Is it loaded? Please enter either true or false:
true
Please enter a destination:
Salt Lake City

********************************************
Reporting mark of the car:  SP
The number of the car: 34567
The kind of car: business
Loaded car: true
The destination of the car is: Salt Lake City
********************************************

********************************************
Reporting mark of the car:  SP
The number of the car: 34567
The kind of car: business
Loaded car: true
The destination of the car is: Salt Lake City
********************************************

********************************************
Reporting mark of the car:
The number of the car:   0
The kind of car: other
Loaded car: false
The destination of the car is: NONE
********************************************

Process returned 0 (0x0)   execution time : 30.439 s
Press any key to continue.
*/

