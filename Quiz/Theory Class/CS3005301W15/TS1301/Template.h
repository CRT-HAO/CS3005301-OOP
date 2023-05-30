// Name: 張皓鈞 (B11030202@mail.ntust.edu.tw)
// Date: May 31, 2023
// Last Update: May 31, 2023
// Problem statement: Template Binary Search

#pragma once

#include <iostream>

template <typename T>
void ItrBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
    found = false;
    int f = first, l = last;
    while ( l >= f )
    {
        int mid = (f + l) / 2;
        if ( a[mid] == key )
        {
            found = true;
            location = mid;
            break;
        }
        else if ( key < a[mid] )
            l = mid - 1;
        else if ( key > a[mid] )
            f = mid + 1;
    }
}

template <typename T>
void RecBinarySearch(const T a[], int first, int last, T key, bool &found, int &location)
{
    if ( first > last )
        return;

    found = false;

    int mid = (first + last) / 2;

    if ( a[mid] == key )
    {
        location = mid;
        found = true;
    }
    else if ( key < a[mid] )
    {
        RecBinarySearch(a, first, mid - 1, key, found, location);
    }
    else if ( key > a[mid] )
    {
        RecBinarySearch(a, mid + 1, last, key, found, location);
    }
}