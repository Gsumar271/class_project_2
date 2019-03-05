//
//  dllnode.cpp
//  ClassWorkProjects
//
//  Created by Eugene Sumaryev on 2/22/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <cassert>    //
#include <cstdlib>    //
#include "dllnode.h"

using namespace std;


namespace classProgram
{
    //method to get list length
    size_t listLength(const dllnode* headPtr)
    {
        const dllnode *cursor;
        size_t answer;

        answer = 0;
        for (cursor = headPtr; cursor != NULL; cursor = cursor->getNameLink())
            ++answer;

        return answer;
    }

    
    //method to insert the first node of the list
    void listHeadInsert(dllnode*& headPtrName, dllnode*& headPtrWeight,
                        const dllnode::valueTypeName& entryName,
                        const dllnode::valueTypeWeight& entryWeight)
    {
        headPtrName = new dllnode(entryName, entryWeight, headPtrName, headPtrWeight);
        headPtrWeight = headPtrName;
    }
     

//method to insert a node
    void listInsert(dllnode*& headPtrName, dllnode*& headPtrWeight,
      const dllnode::valueTypeName& entryName, const dllnode::valueTypeWeight& entryWeight)
    {
        //pointer to insert
        dllnode *insertPtr;

        insertPtr = new dllnode(entryName, entryWeight, NULL, NULL);

        //insert the name link
        listInsertName(headPtrName, insertPtr);
        
        //insert the weight link
        listInsertWeight(headPtrWeight, insertPtr);

    }
    
    void listInsertName(dllnode*& headPtrName,
                        dllnode*& insertPtr){

        //used to traverse a list
        dllnode *cursor;
        //used to keep a pointer to previous link
        dllnode *prevPtr;
        bool done = false;
        
        //insertName
        prevPtr = headPtrName;
        cursor = headPtrName;
        while (cursor != NULL && !done){
            if ((insertPtr->getName()).compare(cursor->getName()) <= 0 ){
                //traverse the list until the Name is smaller
                // than the next node's
                done = true;
            }
            else{
                prevPtr = cursor;
                cursor = cursor->getNameLink();
            }
        }
        
        insertPtr->setNameLink(cursor);
        
        //if inserted node is a first element, make head pointer point to it
        if(headPtrName == cursor)
            headPtrName = insertPtr;
        else
            prevPtr->setNameLink(insertPtr);
    }
    
    
    void listInsertWeight(dllnode*& headPtrWeight,
                          dllnode*& insertPtr){
        
        //used to traverse a list
        dllnode *cursor;
        //used to keep a pointer to previous link
        dllnode *prevPtr;
        bool done = false;
        
        //insertWeight
        prevPtr = headPtrWeight;
        cursor = headPtrWeight;
        while (cursor != NULL && !done){
            if (insertPtr->getWeight() <= cursor->getWeight()){
                //traverse the list until the weight is smaller
                // than the next node's
                done = true;
            }
            else{
                prevPtr = cursor;
                cursor = cursor->getWeightLink();
            }
        }
        
        insertPtr->setWeightLink(cursor);
        
        //if inserted node is a first element, make head pointer point to it
        if(headPtrWeight == cursor)
            headPtrWeight = insertPtr;
        else
            prevPtr->setWeightLink(insertPtr);
        
    }

    
    //method to search a node
    dllnode* listSearch(dllnode* headPtrName, const dllnode::valueTypeName& target)
    {
        dllnode *cursor;

        //insert name
        for (cursor = headPtrName; cursor != NULL; cursor = cursor->getNameLink())
            if (target == cursor->getName())
                return cursor;
        return NULL;
    }

    //another method to search a node but keeping head pointer a constant
    const dllnode* listSearch(const dllnode* headPtrName, const dllnode::valueTypeName& target)
    {
        const dllnode *cursor;

        for (cursor = headPtrName; cursor != NULL; cursor = cursor->getNameLink())
            if (target == cursor->getName())
                return cursor;
        return NULL;
    }

    //method to locate a node at a particular position
    dllnode* listLocate(dllnode* headPtrName, size_t position)
    {
        dllnode *cursor;
        size_t i;

        cursor = headPtrName;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->getNameLink();
        return cursor;
    }

    //another method to locate pointer but using a constant declaration
    const dllnode* listLocate(const dllnode* headPtrName, size_t position)
    {
        const dllnode *cursor;
        size_t i;

        assert (0 < position);
        cursor = headPtrName;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->getNameLink();
        return cursor;
    }

    //method to remove head pointer
    void listHeadRemove(dllnode*& headPtrName)
    {
        dllnode *removePtr;

        removePtr = headPtrName;
        headPtrName = headPtrName->getNameLink();
        delete removePtr;
    }

    //method to remove pointer after prev pointer
    void listRemove(dllnode* previousPtr)
    {
        dllnode *removePtr;

        removePtr = previousPtr->getNameLink();
        previousPtr->setNameLink( removePtr->getNameLink());
        delete removePtr;
    }

    //method to clear entire list
    void listClear(dllnode*& headPtr)
    // Library facilities used: cstdlib
    {
        while (headPtr != NULL)
            listHeadRemove(headPtr);
    }

    //method to copy a list
    void listCopy(const dllnode* sourcePtr, dllnode*& headPtr, dllnode*& tailPtr)
    {
        headPtr = NULL;
        tailPtr = NULL;

        // Handle the case of the empty list.
        if (sourcePtr == NULL)
            return;

        // Make the head node for the newly created list, and put data in it.
        listHeadInsert(headPtr, tailPtr, sourcePtr->getName(), sourcePtr->getWeight());
        tailPtr = headPtr;

        // Copy the rest of the nodes one at a time, adding at the tail of new list.
        sourcePtr = sourcePtr->getNameLink();
        while (sourcePtr != NULL)
        {
            listInsert(tailPtr, headPtr, sourcePtr->getName(), sourcePtr->getWeight());
            tailPtr = tailPtr->getNameLink();
            sourcePtr = sourcePtr->getNameLink();
        }
    }


}
