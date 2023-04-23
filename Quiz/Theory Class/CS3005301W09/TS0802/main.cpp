// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 24, 2023
// Last Update: April 24, 2023
// Problem statement: Matrix Multiplication

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int row_a, col_a, row_b, col_b;
	cin >> row_a >> col_a >> row_b >> col_b;

	if (col_a != row_b)
	{
		cout << "Matrix multiplication failed." << endl;
		return 0;
	}

	int row_ans = row_a, col_ans = col_b;

	vector<vector<int>> m_a(row_a, vector<int>(col_a, 0));
	vector<vector<int>> m_b(row_b, vector<int>(col_b, 0));
	vector<vector<int>> m_c(row_ans, vector<int>(col_ans, 0));

	for (int i = 0; i < row_a; i++)
		for (int j = 0; j < col_a; j++)
			cin >> m_a[i][j];

	for (int i = 0; i < row_b; i++)
		for (int j = 0; j < col_b; j++)
			cin >> m_b[i][j];

	for (int i = 0; i < row_ans; i++)
	{
		for (int j = 0; j < col_ans; j++)
		{
			int sum = 0;
			for (int k = 0; k < col_a; k++)
			{
				sum += m_a[i][k] * m_b[k][j];
			}
			m_c[i][j] = sum;
		}
	}

	for (const auto& i : m_c)
	{
		int i_j = 0;
		for (const int& j : i)
		{
			cout << j;
			if (i_j < col_ans - 1)
				cout << " ";
			i_j += 1;
		}
		cout << endl;
	}


	return 0;
}