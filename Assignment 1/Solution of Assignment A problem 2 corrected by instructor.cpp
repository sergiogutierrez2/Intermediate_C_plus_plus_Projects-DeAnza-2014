/*
Sergio Gutierrez
CIS 22B
Fall 2014
Assignment A
Problem A2
Description of problem:
This program shows the different string member functions in action.
For example, it shows the use of getline (which receives and input
from the user) and the find_last_of member function.
*/

#include <iostream>
#include <cctype>
#include <string>
#include <cstring>
using namespace std;

/*
***********Function Main***********
Contains all the code and is the only function on this problem.
**********************************/

int main ()
{
string string1;
/*
**************************Exercise 1******************
The following code uses getline to receive input from the user.
The tested input is: "Good morning". It is afterwards printed.
********************************************************/
cout << "Please enter a string:" << endl;
getline (cin, string1);
cout << endl;
cout << "Exercise 1" << endl;
cout << string1 << endl;

/*
***************************Exercise 2*******************
The following code creates a new string and has text appended to it.
The content appended is " sleepy heads". This is then printed.
*********************************************************/
string string2(string1);
string2 = string2 + " sleepy heads ";
cout << endl;
cout << "Exercise 2" << endl;
cout << string2 << endl;
cout << endl;

/*
***************************Exercise 3*********************
The following code creates a string with the following content:
"bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow"
It then finds the location of the first "h" in the string.
**********************************************************/
cout << "Exercise 3" << endl;
string string3 ("bellow cello fellow hello mellow Novello Othello pillow Rollo solo yellow");
string stringh ("h");
size_t found = string3.find(stringh);
cout << "The 'h' was found at: " << found << '\n';

/*
******************************Exercise 4***********************
On the following code, a new string is created based on the
contents of another, but the first "h" is changed into a "J".
**************************************************************/
string string4;
string4 = string3;
string stringj = "J";
string4.replace(found,1,stringj);
cout<< endl;
cout << "Exercise 4" << endl;
cout << string4 << endl;
cout << endl;

/*
***************************Exercise 5**************
The find_last_of member function is used
to find the position of the last  l
************************************************/
string string5(string3);
unsigned found2 = string5.find_last_of("l");
cout << "Exercise 5" << endl;
cout << found2 << endl;
cout << endl;

/*
**************************Exercise 6*****************
On the following code, the last two letters of a
series of strings are erased based on their position.
*****************************************************/
string string6(string3);
string6.erase(found,2);
cout << "Exercise 6" << endl;
cout << string6 << endl;

/* Execution results
Please enter a string:
Good Morning

Exercise 1
Good Morning

Exercise 2
Good Morning sleepy heads

Exercise 3
The 'h' was found at: 20

Exercise 4
bellow cello fellow Jello mellow Novello Othello pillow Rollo solo yellow

Exercise 5
70

Exercise 6
bellow cello fellow hello mellow Novello Othello pillow Rollo solo yell

Process returned 0 (0x0)   execution time : 5.410 s
Press any key to continue.
*/
}

