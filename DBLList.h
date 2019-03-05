//
//  DBLList.h
//  ClassWorkProjects
//
//  Created by Eugene Sumaryev on 2/26/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef DBLList_h
#define DBLList_h
#include <cstdlib>   // Provides size_t and NULL
#include "dllnode.h"   // Provides node class



namespace classProgram
{
    class DBLList
    {
    public:
        // TYPEDEFS
        typedef std::size_t sizeType;
        typedef dllnode::valueTypeName valueTypeName;
        typedef dllnode::valueTypeWeight valueTypeWeight;
        // CONSTRUCTORS and DESTRUCTOR
        DBLList();
        void insertNode(const valueTypeName& entryName, const valueTypeWeight& entryWeight);
        void printList();

        // CONSTANT MEMBER FUNCTIONS
        sizeType size( ) const { return sizeList; }
    private:
        dllnode *headPtrName;       // List head pointer for name
        dllnode *headPtrWeight;     //List head pointer for weight
        sizeType sizeList; // Number of nodes on the list
    };

}

#endif /* DBLList_h */
