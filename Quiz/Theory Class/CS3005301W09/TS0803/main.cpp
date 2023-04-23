// Name: ±iµq¶v (B11030202@mail.ntust.edu.tw)
// Date: April 24, 2023
// Last Update: April 24, 2023
// Problem statement: Memory Simulator

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<uint8_t> gMemory;

bool inRange(int position, int size)
{
	return ((position + size) <= gMemory.size());
}

int main()
{
	int s, n;
	cin >> s >> n;

	gMemory.resize(s, 0b00000000);

	for (int i = 0; i < n; i++)
	{
		string command;
		int position;
		string type;
		cin >> command >> position >> type;
		if (command == "Get")
		{
			if (type == "char")
			{
				if (!inRange(position, 1))
				{
					cout << "Violation Access." << endl;
					continue;
				}

				uint32_t val;
				val = gMemory[position];

				cout << val << endl;
			}
			else if (type == "short")
			{
				const size_t DATA_SIZE = 2;

				if (!inRange(position, DATA_SIZE))
				{
					cout << "Violation Access." << endl;
					continue;
				}

				uint16_t val = 0;

				for (int i = (position + DATA_SIZE - 1); i >= position; i--)
				{
					val <<= 8;
					val |= (uint16_t)(gMemory[i] & 0xff);
				}

				cout << val << endl;
			}
			else if (type == "int")
			{
				const size_t DATA_SIZE = 4;

				if (!inRange(position, DATA_SIZE))
				{
					cout << "Violation Access." << endl;
					continue;
				}

				uint32_t val = 0;

				for (int i = (position + DATA_SIZE - 1); i >= position; i--)
				{
					val <<= 8;
					val |= (uint32_t)(gMemory[i] & 0xff);
				}

				cout << val << endl;
			}
			else if (type == "String")
			{
				for (int i = position;
					i < gMemory.size() && gMemory[i] != '\0'; i++)
				{
					cout << gMemory[i];
				}

				cout << endl;
			}
		}
		else if (command == "Set")
		{
			if (type == "char")
			{
				if (!inRange(position, 1))
				{
					cout << "Violation Access." << endl;
					continue;
				}

				uint32_t val;

				cin >> val;

				if (val > 255)
					val = 255;

				gMemory[position] = val;
			}
			else if (type == "short")
			{
				const size_t DATA_SIZE = 2;

				if (!inRange(position, DATA_SIZE))
				{
					cout << "Violation Access." << endl;
					// continue;
				}

				uint16_t val;

				cin >> val;

				for (int i = position;
					i < (position + DATA_SIZE) && i < gMemory.size();
					val >>= 8, i++)
						gMemory[i] = (uint8_t)(val & 0xff);
			}
			else if (type == "int")
			{
				const size_t DATA_SIZE = 4;

				if (!inRange(position, DATA_SIZE))
				{
					cout << "Violation Access." << endl;
					// continue;
				}

				uint32_t val;

				cin >> val;

				for (int i = position;
					i < (position + DATA_SIZE) && i < gMemory.size();
					val >>= 8, i++)
						gMemory[i] = (uint8_t)(val & 0xff);
			}
			else if (type == "String")
			{
				string val;

				cin.get();
				getline(cin, val);

				size_t data_size = val.length();

				if (!inRange(position, data_size))
				{
					cout << "Violation Access." << endl;
					// continue;
				}

				for (int i = position, j = 0;
					i < (position + data_size) && i < gMemory.size();
					i++, j++)
					gMemory[i] = val[j];
			}
		}
	}

	return 0;
}