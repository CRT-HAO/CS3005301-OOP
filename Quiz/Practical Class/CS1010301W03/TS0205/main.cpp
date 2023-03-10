// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: March 10, 2023
// Last Update: March 10, 2023
// Problem statement: Adding Large Numbers

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct BigInt
{
    string num;
};

BigInt Add(const BigInt& lhs, const BigInt& rhs)
{
    string number1 = lhs.num, number2 = rhs.num;

    if (number1.length() > number2.length())
        swap(number1, number2);

    string sum = "";

    int len1 = number1.length();
    int len2 = number2.length();
    int digitDiff = len2 - len1;
    int carry = 0;
    int intSum;

    for (int i = len1 - 1; i >= 0; i--) {
        intSum = ((number1[i] - '0') + (number2[i + digitDiff] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }

    for (int i = digitDiff - 1; i >= 0; i--) {
        intSum = ((number2[i] - '0') + carry);
        sum.push_back(intSum % 10 + '0');
        carry = intSum / 10;
    }

    if (carry)
        sum.push_back(carry + '0');

    reverse(sum.begin(), sum.end());

    return BigInt{ sum };
}

bool checkBigIntValid(BigInt bigInt)
{
    for (auto i : bigInt.num)
    {
        if (i > '9' || i < '0')
            return false;
    }
    return true;
}

int main()
{
    unsigned int n;
    cin >> n;

    for (unsigned int i = 0; i < n; i++)
    {
        BigInt a, b, sum;
        cin >> a.num >> b.num;

        if (checkBigIntValid(a) && checkBigIntValid(b))
        {
            sum = Add(a, b);
            cout << sum.num << endl;
        }
        else
        {
            cout << "Not a valid number, please try again." << endl;
        }
    }

    return 0;
}
