//
//  main.cpp
//  ClassWorkProjects
//
//  Created by Eugene Sumaryev on 2/19/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "DBLList.h"


using classProgram::DBLList;
using namespace std;

// function prototype
int BinarySearch(
            const int a[ ],
            int first,
            int size,
            int target,
            int& found,
            int& location
            );
void InsertList(string name, int weight);


int main( )
{
    /*
    const int size = 10;
    int someArray[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int target;
    int found;
    int location;
    */
    string name;
    int weight;
    DBLList nameList;
    

    for (int i=0; i<15; i++){
        cout << "Please type a name and weight: " << endl;
        cin >> name;
        cin >> weight;
        nameList.insertNode(name, weight);
    }
    
    if(nameList.size()!= 0 )
        nameList.printList();

    
}

void InsertList(string name, int weight){
    
}

int BinarySearch(
            const int a[ ],
            int first,
            int size,
            int target,
            int& found,
            int& location
            )
{
    int middle;
    
    //if array size = 0 target was not found
    //otherwise divide array in 2 parts and search them
    if (size == 0) {
        found = -1;
    }
    else
    {
        middle = first + size/2;
        if (target == a[middle])
        {
            location = middle;
            found = location;
        }
        else if (target < a[middle])
            // The target is less than a[middle], so search before the middle
            BinarySearch(a, first, size/2, target, found, location);
        else
            // The target must be greater than a[middle], so search after the middle
            BinarySearch(a, middle+1, (size-1)/2, target, found, location);
    }
    
    return found;
}

    
    
