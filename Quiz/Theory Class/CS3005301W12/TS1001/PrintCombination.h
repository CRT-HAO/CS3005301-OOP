// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 9, 2023
// Last Update: May 9, 2023
// Problem statement: Combinations

#pragma once

#include <iostream>

void getCombination(int array[], int data[], size_t start, size_t end,
                    size_t index, size_t r)
{
    // Print the result if index == r
    if ( index == r )
    {
        for ( size_t i = 0; i < r; ++i )
        {
            std::cout << data[i];
            if ( i != r - 1 )
                std::cout << ' ';
        }

        std::cout << std::endl;
        return;
    }

    for ( size_t i = start; i <= end && end - i + 1 >= r - index; ++i )
    {
        data[index] = array[i];
        getCombination(array, data, i + 1, end, index + 1, r);
    }
}

void PrintCombination(int array[], int size, int choice)
{
    // Create a temporary array to save the results
    int *data = new int[choice];
    getCombination(array, data, 0, size - 1, 0, choice);
    // Delete the temporary array
    delete[] data;
}