// Name: �i�q�v (B11030202@mail.ntust.edu.tw)
// Date: April 19, 2023
// Last Update: April 19, 2023
// Problem statement: Cow calculation

#include <iostream>
#include <string>

using namespace std;

// Indent: String to Interger
// Pre: The function number is input number
// Post: The function returns the interger
int strToint(string number)
{
    int result(0);
    for (const char& c : number)
    {
        result *= 4;
        if (c == 'U')
            result += 1;
        else if (c == 'C')
            result += 2;
        else if (c == 'D')
            result += 3;
    }
    return result;
}

int main()
{
    cout << "COWCULATIONS OUTPUT" << endl;

    int times;
    for ((cin >> times); times--;)
    {
        string input1, input2;
        cin >> input1 >> input2;

        int num1 = strToint(input1), num2 = strToint(input2);

        for (int i = 0; i < 3; i++)
        {
            char op;
            cin >> op;
            if (op == 'A')
                num2 += num1;
            else if (op == 'R')
                num2 >>= 2;
            else if (op == 'L')
                num2 <<= 2;
        }

        string answer;
        cin >> answer;

        if (strToint(answer) == num2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    cout << "END OF OUTPUT" << endl;

    return 0;
}