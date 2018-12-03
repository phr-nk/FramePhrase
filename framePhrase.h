#ifndef FRAME_PHRASE_H
#define FRAME_PHRASE_H
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
class framePhrase
{
  string s;
  char f;
  short c;
public:
    framePhrase ();
    framePhrase (const framePhrase & f);
    framePhrase (string str, char fname, short choice);
    `framePhrase ()
  {
  };
  friend istream & operator>> (istream & in, framePhrase & f);
  friend ostream & operator<< (ostream & out, const framePhrase & f);
};
#endif
