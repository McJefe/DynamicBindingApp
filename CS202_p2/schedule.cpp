#include "schedule.h"

/* CS202 - Jeff McHale - Program 2
           schedule.cpp
 
 Function implementation and their corresponding
 comments are found below.
 
 */

//Copy constructor
schedule::schedule (const schedule & toCopy)
{
    this -> whichForm = toCopy.whichForm;
    this -> name = toCopy.name;
    this -> timeSpent = toCopy.timeSpent;
    this -> priority = toCopy.priority;
    this -> person = toCopy.person;
    
}

//Destructor
schedule::~schedule()
{
    
    if (person != nullptr)
        delete [] person;
    
    person = NULL;

}

//Used to obtain if activity is online or in-person
void schedule::whichType (std::string type)
{
    
    std::cout << "Is this activity online or in person?" << std::endl;
    getline(std::cin, type);
    
    if (type.empty())
        return;

    this -> whichForm = type;
    

}
    
//Function to input the name of the activity being logged
void schedule::activityName(std::string nombre)
{
    std::cout << "What's the name of this activity?" << std::endl;
    getline(std::cin, nombre);
    
    if (nombre.empty())
        return;
    
    this -> name = nombre;
    
}

//Used to get the time needed for an activity
void schedule::timeUsed(std::string time)
{
    
    std::cout << "How many hours are needed for this activity?" << std::endl;
    getline (std::cin, time);
    
    if (time.empty())
        return;
    
    this -> timeSpent = time;

}

//Determines how important an activity is
//Return type is used to insert data into the correct index
int schedule::dataPriority(std::string importance)
{
    std::string transfer;
    
    std::cout <<"What's the importance of this task? (1-3):  (1) most important - (3) least important " << std::endl;
    getline(std::cin, transfer);
    
    //Set transfer to imporance's value
    importance = transfer;
    //Convert copied string to int
    std::stringstream ss(importance);
    ss >> value;

    
    this -> priority = importance;
    
    //Return the priority
    return value;
    
}

//Displays all data recieved
void schedule::display() const
{
    using namespace std;
    
    //cout << "Displaying now..." << endl;
    
    cout << "Status of Activity: " << this -> whichForm << "\n"
         << "Name of Activity: " << this -> name << "\n"
         << "Time that needs to be spent: " << this -> timeSpent << "\n"
         << "Priority of this entry: " << this -> priority << "\n" << endl;
    
}

//Returns the value to know
//which index to insert at
int schedule::aPriority()
{
    return value;
}


//--------------------------------------------------------------COURSES------------------------------------------------------------------

//NOTE:
//Most functions in the following classes will contain
//incredibly similar functionality. Thus, for similar functions
//Comments will be repeated.

//Destructor
courses::~courses()
{
    if (instructorName)
        delete [] instructorName;
    
    instructorName = NULL;
}

//Used to obtain if activity is online or in-person
//Pushes data up to base class
void courses::whichType (const std::string &type)
{
    this -> whichForm = type;
    
}

//Function to input the name of the activity being logged
//Pushes data up to base class
void courses::activityName(const std::string &nombre)
{
    this -> name = nombre;
    
}

//Used to get the time needed for an activity
//Pushes data up to base class
void courses::timeUsed(const std::string &time)
{
    this -> timeSpent = time;
    
}

//Determines how important an activity is
//Pushes data up to base class
//Return type is used to return correct index.
int courses::dataPriority(const std::string &importance)
{
    
    this -> priority = importance;
    return 0;
    
}

//Displays data of type course
void courses::display() const
{
    std::cout << "Course Information:" << std::endl;
    this -> schedule::display();
    
}


//Wrapper function to be referenced when dynamic binding occurs
int courses::setProfessor()
{
    return setProfessor(instructorName);
}

//Sets a professor name for a given course
int courses::setProfessor (char *)
{
        
    char name[50];
    
    std::cout << "What's the professor's name?" << std::endl;
    std::cin.get(name, 50, '\n');
    std::cin.ignore (100, '\n');
    

    if (instructorName)
        delete [] instructorName;
    
    instructorName = new char [strlen(name) + 1];
    strcpy (instructorName, name);
    
    //Pushes entries into a vector to keep track of professor list
    list.push_back(name);
    
    return 1;
    
}

//Copies professor data to instance of class
int courses::copyProfessor (courses & toCopy)
{
    return setProfessor(toCopy.instructorName);
}

//Displays vector of professor's inputted
int courses::displayList()
{
    std::cout << "Instructors for this term:" << std::endl;
    for (std::string i: list)
        std::cout << i << '|';
    
    return 1;
}


//--------------------------------------------------------------ASSIGNMENTS------------------------------------------------------------------

//Used to obtain if activity is online or in-person
//Pushes data up to base class
void assignments::whichType (const std::string &type)
{
    
    this -> whichForm = type;
    
}

//Function to input the name of the activity being logged
//Pushes data up to base class
void assignments::activityName(const std::string &nombre)
{
    
    this -> name = nombre;
    
}

//Used to get the time needed for an activity
//Pushes data up to base class
void assignments::timeUsed(const std::string &time)
{
    this -> timeSpent = time;
    
}

//Determines how important an activity is
//Pushes data up to base class
//Return type is used to return correct index.
int assignments::dataPriority(const std::string &importance)
{
    
    this -> priority = importance;
    return 0;
    
}

//Displays data of type assignments
void assignments::display() const
{
    std::cout << "Assignment Information:" << std::endl;
    this -> schedule::display();
}

//Stores due dates in a vector to be referenced
int assignments::dueDates(const std::string &dates)
{
    this -> name = dates;
    
    
    
    
    
    return 1;
}

//--------------------------------------------------------------TUTORING------------------------------------------------------------------

//Used to obtain if activity is online or in-person
//Pushes data up to base class
void tutoring::whichType (const std::string &type)
{
    this -> whichForm = type;

}

//Function to input the name of the activity being logged
//Pushes data up to base class
void tutoring::activityName(const std::string &nombre)
{
    
    this -> name = nombre;
    
}

//Used to get the time needed for an activity
//Pushes data up to base class
void tutoring::timeUsed(const std::string &time)
{
    this -> timeSpent = time;
    
}

//Determines how important an activity is
//Pushes data up to base class
//Return type is used to return correct index.
int tutoring::dataPriority(const std::string &importance)
{
    
    this -> priority = importance;
    return 0;
    
}

//Displays data of type tutoring
void tutoring::display() const
{
    std::cout << "Tutoring Information:" << std::endl;
    this -> schedule::display();
}

