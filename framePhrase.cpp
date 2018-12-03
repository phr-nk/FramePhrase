#include"framePhrase.h"
#include<iostream>
#include<iomanip>
#include<vector>
using namespace std;
short LongestWord (string str)
{
  string tempstring;
  string maxword;
  short max;
  int len = str.length ();
  for (int i = 0; i <= len; i++)
    {
      if (tempstring.length () > maxword.length ())
	{
	  maxword = tempstring;
	}
      if (str[i] != ' ')
	{
	  tempstring = tempstring + str[i];
	}
      else
	{
	  tempstring = '\0';
	}
    }
  max = maxword.size ();
  return max;
}

short numWords (string str)
{
  short words = 0;
  for (size_t i = 0; i < str.size (); ++i)
    {
      if (str[i] == ' ')
	words = words + 1;
    }
  return words + 1;
}

framePhrase::framePhrase (string str, char fname, short choice):s (str), f (fname),
c (choice)
{
  s = str;
  f = fname;
  c = choice;
}

istream & operator>> (istream & in, framePhrase & f)
{
  string str = f.s;
  char fname = f.f;
  short choice = f.c;
  in >> str >> fname >> choice;
  return in;
}

ostream & operator<< (ostream & out, const framePhrase & f)
{
  string str = f.s;
  char fname = f.f;
  short choice = f.c;
  short t = numWords (str);
  const short pad = 1;
  const int rows = pad * 2 + t;
  const short cols = str.size () + pad * 2 + 2;
  out << endl;
  short r = 0;
//insert each word into a vector
  vector < string > ret;
  typedef string::size_type string_size;
  string_size i = 0;
  while (i != str.size ())
    {
      while (i != str.size () && isspace (str[i]))
	++i;
      string_size
	j = i;
      while (j != str.size () && !isspace (str[j]))
	j++;
      if (i != j)
	{
	  ret.push_back (str.substr (i, j - i));
	  i = j;
	}
    }

 while (r != rows)
    {
      short c = 0;
      for (ssize_t i = 0; i < LongestWord (str) + 2; ++i)
	{
	  if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
	    {			// if in bordering column or row
	      out << fname;	//output *
	    }
	  else
	    {
	      if (r == pad && c == pad)
		{		//if on row
		  for (size_t p = 0; p < ret.size (); ++p)
		    {
		      if (choice == 1)
			out << setw ((LongestWord (str) - ret[p].size ()) /
				     2) << "" << ret[p] <<
			  setw ((LongestWord (str) -
				 ret[p].size ()) / 2) << "" << fname << "\n" <
			  <fname;
		      else if (choice == 2)
			out << ret[p] <<
			  setw ((LongestWord (str) -
				 ret[p].
				 size ())) << "" << fname << "\n" << fname;
		      else if (choice == 3)
			out << setw (LongestWord (str)) << ret[p] << fname <<
			  "\n" << fname;
		      else
			cin >> choice;
		    }
		  out << setw (LongestWord (str) + 1) << fname;
		  c += (LongestWord (str) - 1);	// adjust
		  r = (numWords (str));
		}
	      else
		{
		  out << " ";
		}
	    }
	  ++c;
	}
      ++r;
//out<< fname;
      out << std::endl;
    }
}
