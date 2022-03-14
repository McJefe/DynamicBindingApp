#include "datastructures.h"

/* CS202 - Jeff McHale - Program 2
            main.cpp
 
File to simulate the client test bed.
Here, a user will have the option to create a derived object,
fill necessary data about that activity, and perform operations
once the data is set. Operations include:

1) Inserting data to a derived instance
2) Displaying a given row in the array of DLLs
3) Display all professor names inputted
4) Display everything
 
 */

using namespace std;


int main()
{
    Table table;
   
    char response;
    char again;
    int x = 0;
    courses course;
    
  
    do
    {
        
        if (x < 1)
        {
            cout << "Welcome, this program will allow you to keep track of your school schedule.\n"
                << "You may store information regarding your courses, assignments, and tutoring.\n"
                << "\nLets first create some entries." << endl;
        }
        else
        {
            cout << "What would you like to log now?\n";
        }
      
    
        cout << "\n(C)ourses\n"
             << "(A)ssignments\n"
             << "(T)utoring\n";
    
        cin >> response;
        cin.ignore (100, '\n');
        response = toupper(response);
    
        node Node;
        
        //Return value used to signal writing to vector in course class
        bool check = Node.setData(response);
        table.insert(Node);
        
        if (check)
        {
            course.setProfessor();
        }
        
      
        cout << "Continue adding entries? (y/n)" << endl;
        cin >> again;
        again = toupper(again);
        
        ++x;
      
    } while (again == 'Y');
    
  do
  {
      
      int branch = 0;
      
      cout << "\nWhat would you like to do now?\n"
           << "1) Display specific row of your entries\n"
           << "2) Display Instructor list for this term\n"
           << "3) Display all entries inputted\n" << endl;
      
      cin >> branch;
      cin.ignore (100, '\n');
      
      if (branch == 1)
      {
          int index = 0;
          cout << "Which row do you want to display?\n"
               << "1) == Most important\n"
               << "2) == Somewhat important\n"
               << "3) == Least important. " << endl;
          cin >> index;
          cin.ignore (100, '\n');
      
          table.displayRow(index);
      }
      else if (branch == 2)
      {
          course.displayList();
      }
      
      else if (branch == 3)
      {
          table.displayAll(0);
      }
      
      else
      {
          cout << "\nThanks for using this program!" << endl;
          return 0;
      }
        
      
      cout << "\nContinue working with data? (y/n)" << endl;
      cin >> again;
      again = toupper(again);
    
  } while (again == 'Y');
    
    
    cout << "\nThanks for using this program!" << endl;

    return 0;
}
