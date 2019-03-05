//
//  dllnode.h
//  ClassWorkProjects
//
//  Created by Eugene Sumaryev on 2/22/19.
//  Copyright © 2019 com.eugene. All rights reserved.
//

#ifndef dllnode_h
#define dllnode_h

#include <string>
#include <cstdlib>

namespace classProgram
{
    class dllnode
    {
    public:
        // TYPEDEF
        typedef std::string valueTypeName;
        typedef double valueTypeWeight;

        // CONSTRUCTOR
        dllnode(
            const valueTypeName& initName = valueTypeName(),
            const valueTypeWeight& initWeight = valueTypeWeight(),
            dllnode* initNameLink = NULL,
            dllnode* initWeightLink = NULL
            )
        {
            nameField = initName;
            weightField = initWeight;
            linkName = initNameLink;
            linkWeight = initWeightLink;
        }

        // Member functions to set the data and link fields:
        void setName(const valueTypeName& newName) { nameField = newName; }
        void setWeight(const valueTypeWeight& newWeight) { weightField = newWeight; }
        void setNameLink(dllnode* newNameLink)            { linkName = newNameLink; }
        void setWeightLink(dllnode* newWeightLink)        { linkWeight = newWeightLink; }

        // Const member function to retrieve the current name and weight:
        valueTypeName getName( ) const { return nameField; }
        valueTypeWeight getWeight( ) const { return weightField; }

        // Two slightly different member functions to retrieve each current link:
        const dllnode* getNameLink( ) const { return linkName; }
        dllnode* getNameLink( )             { return linkName; }
        const dllnode* getWeightLink( ) const { return linkWeight; }
        dllnode* getWeightLink( )             { return linkWeight; }
    private:
        valueTypeName nameField;
        valueTypeWeight weightField;
        dllnode *linkName;
        dllnode *linkWeight;
    };


    // FUNCTIONS for the linked list
    std::size_t listLength(const dllnode* headPtr);
    void listHeadInsert(dllnode*& headPtrName, dllnode*& headPtrWeight,
                        const dllnode::valueTypeName& entryName,
                        const dllnode::valueTypeWeight& entryWeight);
    void listInsert(dllnode*& headPtrName, dllnode*& headPtrWeight,
                    const dllnode::valueTypeName& entryName,
                    const dllnode::valueTypeWeight& entryWeight);
    void listInsertName(dllnode*& headPtrName, dllnode*& insertPtr);
    void listInsertWeight(dllnode*& headPtrWeight, dllnode*& insertPtr);
    dllnode* listSearch(dllnode* headPtr, const dllnode::valueTypeName& target);
    const dllnode* listSearch
    (const dllnode* headPtr, const dllnode::valueTypeName& target);
   dllnode* listLocate(dllnode* headPtr, std::size_t position);
    const dllnode* listLocate(const dllnode* headPtr, std::size_t position);
    void listHeadRemove(dllnode*& headPtr);
    void listRemove(dllnode* previousPtr);
    void listClear(dllnode*& headPtr);
    void listCopy(const dllnode* sourcePtr, dllnode*& headPtr, dllnode*& tailPtr);


}




#endif /* dllnode_h */
