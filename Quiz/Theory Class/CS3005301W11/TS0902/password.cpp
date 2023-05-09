// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Namespace

#pragma once

#include "password.h"

namespace Authenticate
{
  std::string password;

  void inputPassword()
  {
    do
    {
      std::cout << "Enter your password (at least 8 characters "
                << "and at least one non-letter)" << std::endl;
      std::cin >> password;
    } while ( !isValid() );
  }

  std::string getPassword()
  {
    return password;
  }
}

namespace
{
  bool isValid()
  {
    if ( Authenticate::password.length() < 8 )
      return false;

    for ( const char &c : Authenticate::password )
      if ( !std::isalpha(c) )
        return true;

    return false;
  }
}