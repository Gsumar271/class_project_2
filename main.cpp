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


int main( )
{
    string name;
    int weight;
    DBLList nameList;
    
    cout << "Please type a name and weight: " << endl;
    
    //get all the names from the console input
    for (int i=0; i<15; i++){

        cin >> name;
        cin >> weight;
        nameList.insertNode(name, weight);
    }
    
    if(nameList.size()!= 0 )
        nameList.printList();


}


    
    
