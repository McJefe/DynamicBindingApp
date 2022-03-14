#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

/* CS202 - Jeff McHale - Program 2
           schedule.h
 
 The purpose of this header file is to utilize an abstract base class
 and virtual functions for the three derived classes:
 Courses, Assignments, Tutoring
 
 Each class has it's own set of functions, but the primary purpose
 of each is to utilize their inherited virtual functions from the
 base class.
 
 Data is set to a given activity, regarding:
 1) If it's online or in person
 2) What the activity name is
 3) How much time needs to be spent on this
 4) The priority (used to insert data into correct index of array of DLLs)
 
 */

//Abstract base class. Outside of being primarily used for virtual functions,
//some other functionality is included.
class schedule
{
    public:
    //Default Constructor
    schedule(): whichForm(), name(), timeSpent(), priority(), person(nullptr), value(0) {}
    //Copy Constructor
    schedule (const schedule & toCopy);
    //Destructor
    virtual ~schedule();
    
                //Virtual Functions

    //Sets data regarding if activity is online/remote
    virtual void whichType(std::string type);
    //Sets the name of the activity
    virtual void activityName(std::string nombre);
    //Sets the time spent on a given activity
    virtual void timeUsed (std::string time);
    //Sets the priority of this item; compared with other entries to sort data in array of DLLs
    virtual int dataPriority(std::string importance);
    
    //Used to determine where to insert in the array of DLLs
    int aPriority();
  
    //Displays data
    virtual void display () const;
    
    
    protected:
    std::string whichForm;
    std::string name;
    std::string timeSpent;
    std::string priority;
    char * person;
    int value;
};

//Derived class to simulate the client's courses being taken
class courses: public schedule
{
    public:
    
    //Default constructor
    courses(): instructorName (nullptr) {}
    //Copy Constructor
    courses(const courses & source): schedule(source) {}
    ~courses();
    
                //Virtual Functions
    
    //Sets data regarding if activity is online/remote
    void whichType(const std::string &type);
    //Sets the activity data being logged
    void activityName(const std::string &nombre);
    //Sets the time used for a given activity
    void timeUsed (const std::string &time);
    //Sets the priority of the data item being entered
    int dataPriority(const std::string &importance);
    //Displays member data
    void display() const;
    
    //These block of functions relate to maintaining
    //professor names by inserting them in a vector.
    int setProfessor();
    int setProfessor (char *);
    int copyProfessor (courses & toCopy);
    //Displays all professors inserted in the vector
    int displayList();
    
    private:
    char * instructorName;
    std::vector<std::string> list;
    
};


//Derived class to simulate tutoring information
class tutoring: public schedule
{
    
    public:
    tutoring(): something(0) {}
    tutoring(const tutoring & source): schedule(source) {}
    
                //Virtual Functions
    
    //Sets data regarding if activity is online/remote
    void whichType(const std::string &type);
    //Sets the activity data being logged
    void activityName(const std::string &nombre);
    //Sets the time used for a given activity
    void timeUsed (const std::string &time);
    //Sets the priority of the data item being entered
    int dataPriority(const std::string &importance);
   
    //Displays data
    void display() const;
    
    protected:
    int something;
};

//Derived class to simulate assignments the user needs to keep track of
class assignments: public schedule
{
    
    public:
    //Constructor
    assignments(): another(0) {}
    //Copy Constructor
    assignments(const assignments & source): schedule(source) {}
    
                //Virtual Functions
            
    //Sets data regarding if activity is online/remote
    void whichType(const std::string &type);
    //Sets the activity data being logged
    void activityName(const std::string &nombre);
    //Sets the time used for a given activity
    void timeUsed (const std::string &time);
    //Sets the priority of the data item being entered
    int dataPriority(const std::string &importance);
    
    //Stores due dates of upcoming assignments
    int dueDates(const std::string &dates);
   
    
    //Displays data
    void display() const;
    
    protected:
    int another;
};
