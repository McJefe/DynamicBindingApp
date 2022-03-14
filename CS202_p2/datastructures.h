#include "schedule.h"

/* CS202 - Jeff McHale - Program 2
         datastructures.h
 
 Within this header file, the requested array of DLLs
 is supported. The node class determines which derived
 object to generate, copying the data to itself to
 be added in the doubly linked list.
 
 The Table class manages an array of DLLs,
 setting node data within it. Functionality
 within this class includes: inserting a node,
 displaying a specific index, displaying all,
 and removing everything.
 
 */

class node
{
    public:
    
    node ();
    node (const node & toCopy);
    
    //Sets data for a node through upcasting
    bool setData (char response);
    //Copies the nodes data
    int copyNode (const node & toCopy);
    //Displays a node's data
    int display();
    //Used to insert at a specified index in the
    //array of DLLs
    int value();
    
    //Returns a next pointer
    node * &getNext();
    //Returns a previous pointer
    node * &getPrev();
//    void linkNext (node * connect);
//    void linkPrev (node * connect);
    
    
    protected:
    node * next;
    node * prev;
    //Allows upcasting
    schedule * data;
};

class Table
{
    public:
    
    //Constructor - Sets index of array of DLLs
    Table (int size = 3);
    //Destructor
    ~Table();
    
    //Inserts a node into the array of DLLs
    int insert (node & toIns);
    //Displays all entries in the array of DLLs
    int displayAll (int index);
    //Works in tandem with "displayAll" to display
    //everything in a row
    int displayADJ (int index);
    //Displays everything in a specified row
    int displayRow(int index);
    //Wrapper function(s) to recursively destroy entire table
    void deleteTable();
    void deleteTable (int i);
    
    
    private:
    //Deletes all nodes in a row
    void deleteTable (int i, node * &head);
    //Displays data for a specified row
    int displayRow (node * head, int index);
    
    node ** list;
    int listSize;
};

