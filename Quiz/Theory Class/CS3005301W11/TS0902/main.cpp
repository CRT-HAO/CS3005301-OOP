// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 3, 2023
// Last Update: May 3, 2023
// Problem statement: Namespace

#include "password.h"
#include "user.h"

#include <iostream>

using namespace Authenticate;
using namespace std;

int main()
{
  inputUserName();
  inputPassword();
  cout << "Your username is " << getUserName()
       << " and your password is: " << getPassword() << endl;

  return 0;
}