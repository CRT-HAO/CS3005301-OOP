// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Namespace

#pragma once

#include <iostream>
#include <vector>

namespace Authenticate
{
  void inputUserName();
  std::string getUserName();
}

namespace
{
  bool isValid();
}