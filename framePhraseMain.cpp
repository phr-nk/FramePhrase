#include"framePhrase.cpp"
#include "framePhrase.h"
#include<iostream>
#include <fstream>
  using namespace std;

 
int main () 
{
  
 
char input, fname;
  
 
string str, fstr;
  
 
short choice;
  
 
while (true)
    {
      cout << "1. Output to screen: " << endl << "2. Output to file: " <<
	endl <<"3. Quit" << endl;;
      cin >> input;
      switch (input)
      {
          case '1':
          case 's':
          case 'S':
          {
              cout << "Enter phrase: " << endl;
              cin.ignore ();
              getline (cin, str);
              cin.clear ();
              cout << "Enter a character for the border: " << endl;
              cin >> fname;
              cout << "Enter the justification that you want(1 = center, 2 = left, 3 = right) " << endl;
              cin >> choice;
              framePhrase a (str, fname, choice);
              cout << a;
              break;
              
          }
          case '2':
          case 'f':
          case 'F':
          {
              cout << "Enter name of a file: " << endl;
              cin >> fstr;
              ofstream out;
              cout << "Enter phrase: " << endl;
              cin.ignore ();
              getline (cin, str);
              cin.clear ();
              cout << "Enter character for border: " << endl;
              cin >> fname;
              cout << "Enter the justification that you want(1 = center, 2 = left, 3 = right) " << endl;
              cin >> choice;
              framePhrase a (str, fname, choice);
              out.open (fstr.c_str ());
              out << a;
              out.close ();
              break;
              
          }
          case '3':
          case 'q':
          case 'Q':
          cout << "Have a nice day! " << endl;
          return 0;
          
      }
        
    }
    return 0;
