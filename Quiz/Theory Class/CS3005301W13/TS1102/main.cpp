// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 21, 2023
// Last Update: May 21, 2023
// Problem statement: Matrix Multiplication

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> matrixA;
    vector<vector<int>> matrixB;
    vector<vector<int>> matrixAns;

    int matrixAM, matrixAN;
    int matrixBM, matrixBN;

    cin >> matrixAM >> matrixAN >> matrixBM >> matrixBN;

    if ( matrixAN != matrixBM )
    {
        cout << "Matrix multiplication failed." << endl;
        return 1;
    }

    matrixA.clear();
    matrixB.clear();

    matrixA.resize(matrixAM, vector<int>(matrixAN, 0));
    matrixB.resize(matrixBM, vector<int>(matrixBN, 0));

    // Input Matrix A
    for ( int i = 0; i < matrixAM; ++i )
    {
        for ( int j = 0; j < matrixAN; ++j )
            cin >> matrixA[i][j];
    }

    // Input Matrix B
    for ( int i = 0; i < matrixBM; ++i )
    {
        for ( int j = 0; j < matrixBN; ++j )
            cin >> matrixB[i][j];
    }

    int matrixAnsM = matrixAM;
    int matrixAnsN = matrixBN;

    matrixAns.resize(matrixAnsM, vector<int>(matrixAnsN, 0));

    // Calculate Matrix Multiplication
    for ( int i = 0; i < matrixAnsM; ++i )
    {
        for ( int j = 0; j < matrixAnsN; ++j )
        {
            matrixAns[i][j] = 0;
            for ( int k = 0; k < matrixAN; ++k )
            {
                matrixAns[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }

    // Output Answer
    for ( const auto &i : matrixAns )
    {
        for ( const auto &j : i )
        {
            cout << j;
            if ( &j - &i[0] != i.size() - 1 )
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}