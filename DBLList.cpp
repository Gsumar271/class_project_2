//
//  DBLList.cpp
//  ClassWorkProjects
//
//  Created by Eugene Sumaryev on 2/26/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <cassert>
#include <cstdlib> 
#include "dllnode.h"  // Provides node and the linked list functions
#include "DBLList.h"
#include <iostream>

using namespace std;

namespace classProgram
{

    DBLList::DBLList( )

    {
        headPtrName = NULL;
        headPtrWeight = NULL;
        sizeList = 0;
    }

    /*
    DBLList::DBLList(const DBLList& source)

    {
        dllnode *tailPtr;  // Needed for argument of list_copy

        listCopy(source.headPtrName, headPtrName, tailPtr);
        sizeList = source.sizeList;
    }
     

    DBLList::~DBLList( )

    {
        listClear(headPtrName);
        sizeList = 0;
    }
     */

    /*
    DBLList::sizeType DBLList::count(const valueTypeName& target) const
    {
        sizeType answer;
        const dllnode *cursor; // Use const node* since we don't change the nodes.

        answer = 0;
        cursor = listSearch(headPtrName, target);
        while (cursor != NULL)
        {
            // Each time that cursor is not NULL, there is another occurrence of
            // target, so one is added to the answer, and move cursor is moved to next
            // occurrence
            ++answer;
            cursor = cursor->getNameLink();
            cursor = listSearch(cursor, target);
        }
        return answer;
    }
     */

    void DBLList::insertNode(const valueTypeName& entryName, const valueTypeWeight& entryWeight)
    {
        //if list is empty, insert at the head
        if(sizeList == 0)
            listHeadInsert(headPtrName, headPtrWeight, entryName, entryWeight);
         else
            listInsert(headPtrName, headPtrWeight, entryName, entryWeight);
        
        //if list is not empty, 
        ++sizeList;
    }
    
    void DBLList::printList()
    {
        dllnode *cursor;
        
        //Names
        cout << "Names & weights sorted(ascending) by name : ";
        for (cursor = headPtrName; cursor != NULL; cursor = cursor->getNameLink())
            cout << " " << cursor->getName() << " - " << cursor->getWeight() << ", ";
        
        cout << "Size of List: " << size() << endl;
        cout << "Head ptr: " << headPtrWeight->getName() << endl;
        
        //Weights
        cout << "Names & weights sorted(ascending) by weight : ";
        for (cursor = headPtrWeight; cursor != NULL; cursor = cursor->getWeightLink())
            cout << " " << cursor->getName() << " - " << cursor->getWeight() << ", ";
        cout << endl;
        
        
        
    }

}
