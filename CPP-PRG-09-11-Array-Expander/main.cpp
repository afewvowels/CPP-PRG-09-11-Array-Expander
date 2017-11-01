//
//  main.cpp
//  CPP-PRG-09-11-Array-Expander
//
//  Created by Keith Smith on 10/31/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a function that accepts an int array and the array's size as arguments. The
//  function should create a new array that is twice the size of the argument array. The
//  function should copy the contents of the argument array to the new array and intialize
//  the unused elements of the second array with 0. The function should return a pointer
//  to the new array.

#include <iostream>

using namespace std;

int *getArraySize();
int *fillArray(int *, int);
int *modifyArray(int *, int);
void displayArray(int *, int);

int main()
{
    int *intArrSize = nullptr;
    int *intArrNumbers = nullptr;
    int *intArrNumbersResized = nullptr;
    
    intArrSize = getArraySize();
    
    intArrNumbers = fillArray(intArrNumbers, *intArrSize);
    
    intArrNumbersResized = modifyArray(intArrNumbers, *intArrSize);
    
    displayArray(intArrNumbersResized, *intArrSize);
    
    return 0;
}

int *getArraySize()
{
    int *intArrSize = nullptr;
    
    intArrSize = new int;
    
    cout << "Please enter the size of the initial array: ";
    cin >> *intArrSize;
    while(!cin || *intArrSize <= 1 || *intArrSize > 100)
    {
        cout << "Please enter a number between 2 and 100: ";
        cin.clear();
        cin.ignore();
        cin >> *intArrSize;
    }
    
    return intArrSize;
}

int *fillArray(int *intArr, int intSize)
{
    intArr = new int[intSize];
    
    for (int i = 0 ; i < intSize ; i++)
    {
        cout << "Please enter number " << (i + 1) << " of " << intSize << ": ";
        cin >> intArr[i];
        while(!cin || intArr[i] < -100 || intArr[i] > 100)
        {
            cout << "Enter a number between -100 and 100: ";
            cin.clear();
            cin.ignore();
            cin >> intArr[i];
        }
    }
    
    return intArr;
}

int *modifyArray(int *intArr, int intSize)
{
    int *intSizeNew = nullptr;
    int *intArrNew = nullptr;
    
    intSizeNew = new int;
    
    *intSizeNew = 2 * intSize;
    
    intArrNew = new int[*intSizeNew];
    
    for (int i = 0 ; i < intSize ; i++)
    {
        intArrNew[i] = intArr[i];
    }
    
    for (int i = intSize ; i < *intSizeNew ; i++)
    {
        intArrNew[i] = 0;
    }
    
    return intArrNew;
}

void displayArray(int *intArr, int intSize)
{
    for (int i = 0 ; i < intSize * 2 ; i++)
    {
        cout << intArr[i] << endl;
    }
}
