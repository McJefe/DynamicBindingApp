#include "datastructures.h"

/* CS202 - Jeff McHale - Program 2
         datastructures.cpp
 
 Function implementation and their corresponding
 comments are found below.
 
 */

//Default Constructor
node::node()
{
    next = NULL;
    prev = NULL;
}

//Copy constructor
node::node (const node & toCopy) : data(toCopy.data), next(toCopy.next), prev(toCopy.prev) {}

//Copies the data to a node being created
int node::copyNode (const node & toCopy)
{
    this -> data = toCopy.data;
    this -> next = toCopy.next;
    this -> prev = toCopy.prev;
    
    return 1;
}

//Function that determines which object to create at runtime.
bool node::setData (char response)
{
    bool flag = false;
    std::string type, activity, timeSpent, importance;
    
    //Dynamic binding takes place here
    switch (response)
    {
        case 'C': data = new courses;
                  flag = true;
                  break;
        case 'A': data = new assignments;
                  break;
        case 'T': data = new tutoring;
                  break;
        default: std::cout << "Let's assume you meant courses\n";
            data = new courses;
            
    }
    
    //Reference dynamic object's virtual functions
    data -> whichType(type);
    data -> activityName(activity);
    data -> timeUsed(timeSpent);
    data -> dataPriority(importance);
    
    if (!flag)
        return 0;
    
    return 1;
}

//Displays a node's data
int node::display()
{
    data -> display();
    return 1;
}

//Value returned is used to determine which index to insert at
//in the array of DLLs
int node::value()
{
    std::string check;
    
    //Decrement to get value of index 
    int num = data -> aPriority() - 1;
    
    //Testing
    //std::cout << "The index we're inserting at is: " << num << std::endl;
    
    
    return num;
}

//Returns a next pointer
node * &node::getNext()
{
    return next;
}

//Returns a previous pointer
node * &node::getPrev()
{
    return prev;
}

//Links next node
//void node::linkNext(node * connect)
//{
//    if (!connect)
//        next = NULL;
//    else
//        next = connect;
//}
//
////Links previous node
//void node::linkPrev(node * connect)
//{
//    if (!connect)
//        prev = NULL;
//    else
//        prev = connect;
//}

//--------------------------------------------------------------TABLE------------------------------------------------------------------

//Constructor
Table::Table(int size)
{
    list = new node * [size];
    
    for (int i = 0; i < size; ++i)
        list[i] = NULL;
    
    listSize = size;
    
}

//Destructor calls recursive function to destroy entire table
//and corresponding nodes
Table::~Table()
{
    deleteTable();

}
//Used to delete table
void Table::deleteTable()
{
    int i = 0;
    return deleteTable(i);
}

//Used to delete table
void Table::deleteTable(int i)
{
    //If i is greater/equal to the table size,
    //list is empty. Delete list,
    //then return
    if (i >= listSize)
    {
        delete list;
        return;
    }
    
    node * head = list[i];
    
    return deleteTable (i, head);
}

//Recursively destroys each row in the array of DLLs
void Table::deleteTable (int i, node * &head)
{
    //If the entire row is deleted,
    //increment the index to start on next list
    if (!head)
        return deleteTable(++i);
    else
    {
        deleteTable (i, head->getNext());
        delete head;
    }
   
}

//Inserts a node into the array of DLLs
int Table::insert(node &toIns)
{
    
    node * hold = new node(toIns);
    
    //If we're unable to copy data to the node
    //delete it
    if (!hold -> copyNode(toIns))
    {
        //std::cout << "Unable to copy (Table:insert)" << std::endl;
        delete hold;
        hold = NULL;
        return 0;
    }
    
    //If index doesn't have data,
    //populate it.
    if (!list[hold -> value()])
    {
        list[hold -> value()] = hold;
        hold -> getNext() = NULL;
        hold -> getPrev() = NULL;
    }
       
    //If an index already has data, push new data to the front of the list
    //linking up pointers
    else
    {
        node * temp = list[hold -> value()];
        hold -> getNext() = temp;
        temp -> getPrev() = hold;
        
        list[hold -> value()] = hold;
    }
    
    return 1;
}

//Recurisevly travels through the array of DLLs
int Table::displayAll (int index)
{
    node * current = list[index];
    
    //If index is 'greater' than listSize,
    //return
    if (index == listSize)
        return 0;
    
    //If the index exists, print data
    if (list[index])
    {
        current -> display();
        
        //If next pointer exists, call displayAdj
        if (current -> getNext())
            displayADJ(index);
        
            if (!current)
                std::cout << "Empty" << std::endl;
    }
    
    return displayAll(++index);
}

//The non-recursive display function..
//Cycles through each row, displaying each row
int Table::displayADJ(int index)
{
    //Pointer to index currently being worked on
    node * temp = list[index];
   
    //Check if pointer has next pointer before dereferencing
    while (temp -> getNext() != NULL)
    {
        temp = temp -> getNext();
        temp -> display();
    }
   
    return 0;
}

//Wrapper function to display a specific row
int Table::displayRow(int index)
{
    if (index < 0)
    {
        std::cout << "Invalid Index" << std::endl;
        return 0;
    }
    
    
    //Decrement value by 1 to insert at correct index
    node * head = list[index - 1];
    
    return displayRow(head, index);
}

//Displays a specific row in the array of DLLs
int Table::displayRow(node * head, int index)
{
   
    if (!head)
    {
        std::cout << "All entries in row " << index << " have been printed.\n"
                  << "–––––––––––––––––––––––––––––––––––––––" << std::endl;
        return 0;
    }
      
//    if (list[index] == nullptr)
//    {
//        std::cout << "Error, index doesn't exist." << std::endl;
//        return 0;
//    }

    
    head -> display();
    
    return displayRow (head -> getNext(), index);
    
}
