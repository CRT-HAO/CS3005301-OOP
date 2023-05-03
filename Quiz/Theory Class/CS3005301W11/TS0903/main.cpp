// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: The Translation Machine

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Type definition Dictionary
typedef vector<pair<char, char>> Dict_t;

// Indent: Find char index in dictionary
// Pre: The variables dict is the dictionary, c is the character to search for
// Post: The function returns the index of the character in the dictionary
int findCharInDict(const Dict_t &dict, const char &c)
{
  int i = 0;
  for ( const auto &d : dict )
  {
    if ( d.first == c )
      return i;
    i++;
  }

  return -1;
}

// Indent: Get replace char in dictionary
// Pre: The variables dict is the dictionary, c is the character to search for
//      target is the target character to replace
// Post: The function returns the replace character
char getReplaceCharInDict(const Dict_t &dict, const char &c, const char &target)
{
  Dict_t d = dict;
  for ( int index = findCharInDict(d, c); index != -1;
        index = findCharInDict(d, c) )
  {
    char replaceChar = dict.at(index).second;
    if ( c == replaceChar || c == target )
      return c;

    d.erase(d.begin() + index);

    char find = getReplaceCharInDict(d, c, target);
    if ( find == target )
      return find;

    return getReplaceCharInDict(d, replaceChar, target);
  }

  return c;
}

// Indent: Replace string with dictionary
// Pre: The variables dict is the dictionary, str is the string to replace
//      target is the target string to replace
// Post: The function returns the replaced string
string replaceString(const Dict_t &dict, const string &original, const string &target)
{
  string r = original;
  for ( size_t i = 0; i < r.length(); ++i )
    r[i] = getReplaceCharInDict(dict, r[i], target[i]);

  return r;
}

int main()
{
  for ( size_t m, n; (cin >> m >> n) && m > 0 && n > 0 && !cin.eof(); )
  {
    Dict_t dict;

    for ( size_t i = 0; i < m; ++i )
    {
      char original, replace;
      cin >> original >> replace;
      dict.push_back(make_pair(original, replace));
    }

    for ( size_t i = 0; i < n; ++i )
    {
      string original, target;
      cin >> original >> target;
      // Debug
      // cout << replaceString(dict, original, target) << endl;
      cout << ((replaceString(dict, original, target) == target)
                   ? "yes"
                   : "no")
           << endl;
    }
  }

  return 0;
}