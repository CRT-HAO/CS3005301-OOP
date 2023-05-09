// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Reversal

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// Indent: Convert string to lower case
// Pre: The variable s is a string
// Post: The function returns a lower case version of s
string toLowerCase(const string &s)
{
  string r;
  for ( const char &c : s )
    r.push_back(tolower(c));
  return r;
}

// Indent: Reverse string
// Pre: The variable s is a string
// Post: The function returns a reverse version of s
string reverseString(const string &s)
{
  string r = s;
  reverse(r.begin(), r.end());
  return r;
}

int main()
{
  size_t maxLength = 0;
  string maxString;
  unordered_set<string> words;
  for ( string s; (cin >> s) && !cin.eof(); )
  {
    string lowerCase = toLowerCase(s);
    if ( words.count(reverseString(lowerCase)) )
    {
      size_t len = s.length();
      if ( len > maxLength )
      {
        maxLength = len;
        maxString = reverseString(s);
      }
    }
    words.insert(lowerCase);
  }
  cout << maxString << endl;

  return 0;
}