#include <iostream>
using namespace std;

class Error{               // Objects to be thrown
private:
    const string error;
public:
    Error(const string & error):error(error){}
    void print() const{
        cout<<error<<endl;
    }
};


class Event { //Base Event Classs-Abstract Class
private:
    int year,month,day,hour,min,id;
public:
    static int IdCounter; //hold how many events created

    Event(int year, int month, int day, int hour, int min) : //Constructor
            year(year), month(month),
            day(day), hour(hour), min(min) {
        IdCounter++; //Increment when the constructor works
    }
    virtual ~Event() { } //Virtual Desructor
    virtual void print() const=0; //Pure Virtual function

    // Set Functions
    void setYear(int );
    void setMonth(int );
    void setDay(int );
    void setHour(int );
    void setMin(int );
    void setId(int );

    //Get Functions
    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMin() const;
    int getId() const;
};

int Event::IdCounter=0;  //Initial value before declaration of any object


class Task: public Event{ //Derived Class
private:
    string taskname;  //name of task
public:
    Task(int year, int month, int day, int hour, int min, const string &taskname) : //Constructor with taskname argument
            Event(year, month, day, hour, min),taskname(taskname) {}

    Task(int year, int month, int day, int hour, int min) :  //Constructor without taskname argument for Event *Calendar::addEvent method
            Event(year, month, day, hour, min) {}
    virtual ~Task(){} //Virtual Destructor
    void print() const; //Virtual Print

    //Get Set Functions
    const string &getTaskname() const;
    void setTaskname(const string &taskname);
};


class Appointment: public Event{ //Appointment Class Derived Class(Abstract)
private:
    string person,place;
public:
    Appointment(int year, int month, int day, int hour, int min, const string &person, //Default Constructor
                const string &place) :  Event(year, month, day, hour, min),person(person), place(place) {}

    Appointment(int year, int month, int day, int hour, int min) :        //Constructor without person and placename argument for Event *Calendar::addEvent method
            Event(year, month, day, hour, min) {}
    virtual ~Appointment() { } //Virtual Destructor

    void print() const; //Virtual Print

    //Get Functions
    const string &getPerson() const;
    const string &getPlace() const;
    //Set Functions
    void setPerson(const string &person);
    void setPlace(const string &place);

};


class EventNode{//Linked List Node
    friend class Calendar;
    Event * element; //Node Data pointer
    EventNode * next;
    EventNode( Event *n):next(NULL),element(n){};	// constructor
    ~EventNode(){
        delete element; //delete only data pointer to protect next list for line 275
    }
};



class Calendar{   //Container Classs
    EventNode *head;
public:
    Calendar(): head(NULL) {}
    Event *addEvent(int eventType,int year,int month,int day, int hour,int min);
    ~Calendar();

    void deleteEvent(int id);
    void listEvents();
    void filterEvents(int year, int month);
};


int main() {
    Calendar My_Cal;
    Event *eptr;

    eptr=My_Cal.addEvent(0,2018,12,16,12,30); //Task 16/12/2018 12,30
    Task *tptr= dynamic_cast<Task *>(eptr); //ptr conversion from abstract class ptr to derived class ptr in order to call derived class methods such as set functions
    tptr->setTaskname("Send an e-mail");

    eptr=My_Cal.addEvent(1,2019,11,23,7,30); //Appointment 23/11/2019 7,30
    Appointment *aptr= dynamic_cast<Appointment *>(eptr); //ptr conversion from abstract class ptr to derived class ptr in order to call derived class methods such as set functions
    aptr->setPlace("İstanbul Teknik Üniversitesi");
    aptr->setPerson("Akif");

    eptr=My_Cal.addEvent(1,2019,6,12,8,45);  //Appointment 12/6/2019 8,45
    aptr= dynamic_cast<Appointment *>(eptr); //ptr conversion from abstract class ptr to derived class ptr in order to call derived class methods such as set functions
    aptr->setPlace("Maslak");
    aptr->setPerson("Mehmet");

    eptr=My_Cal.addEvent(0,2019,9,22,15,30); //Task 22/9/2019 15,30
    tptr= dynamic_cast<Task *>(eptr); //ptr conversion from abstract class ptr to derived class ptr in order to call derived class methods such as set functions
    tptr->setTaskname("Do Second Homework");

    eptr=My_Cal.addEvent(1,2018,12,23,9,37); //Task 23/12/2018 9,37
    aptr= dynamic_cast<Appointment *>(eptr); //ptr conversion from abstract class ptr to derived class ptr in order to call derived class methods such as set functions
    aptr->setPlace("Üsküdar");
    aptr->setPerson("Dr. Ali Bilir");

    My_Cal.listEvents();

    cout<<endl<<"Id 2 is deleted"<<endl<<endl;
    My_Cal.deleteEvent(2);
    My_Cal.listEvents();

    cout<<endl<<"Filtering 12/2018"<<endl<<endl;
    My_Cal.filterEvents(2018,12);

    cout<<endl<<"***Exceptions"<<endl;
    try{
        My_Cal.filterEvents(2016,12);
    }
    catch (const Error &error){
        error.print();
    }
    try{
        My_Cal.deleteEvent(6);
    }
    catch (const Error &error){
        error.print();
    }
    try{
        for (int i=4;i>0;i--){
            My_Cal.deleteEvent(i);
        }
        My_Cal.listEvents();
    }
    catch (const Error &error){
        error.print();
    }
}

//Event Set Functions
void Event::setYear(int year) {
    Event::year = year;
}
void Event::setMonth(int month) {
    Event::month = month;
}
void Event::setDay(int day) {
    Event::day = day;
}
void Event::setHour(int hour) {
    Event::hour = hour;
}
void Event::setMin(int min) {
    Event::min = min;
}
void Event::setId(int id) {
    Event::id = id;
}

//Event Get Functions
int Event::getYear() const {
    return year;
}
int Event::getMonth() const {
    return month;
}
int Event::getDay() const {
    return day;
}
int Event::getHour() const {
    return hour;
}
int Event::getMin() const {
    return min;
}
int Event::getId() const {
    return id;
}
void Event::print() const { //Pure Virtual print functions
    cout<<" with id "<<getId()<<" at "
        <<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<", "
        <<getHour()<<":"<<getMin()<<": "<<endl;
}


void Task::print() const {
    cout<<"***Task";
    Event::print(); //Base Class method
    cout<<getTaskname()<<endl;
}
const string &Task::getTaskname() const {
    return taskname;
}
void Task::setTaskname(const string &taskname) {
    Task::taskname = taskname;
}



void Appointment::print() const {
    cout << "***Appointment";
    Event::print(); //Base Class method
    cout << getPerson() << ", " << getPlace() << endl;
}
//Get and Set Functions
const string &Appointment::getPerson() const {
    return person;
}
const string &Appointment::getPlace() const {
    return place;
}
void Appointment::setPerson(const string &person) {
    Appointment::person = person;
}
void Appointment::setPlace(const string &place) {
    Appointment::place = place;
}





Event *Calendar::addEvent(int eventType, int year, int month, int day, int hour, int min) {
    Event *eptr; //Base class ptr
    if (eventType==0){ //With respect to evenType, it creates object
        eptr=new Task(year, month, day, hour, min); //because of constructor, IdCounter increase
    }else if(eventType==1) {
        eptr=new Appointment(year, month, day, hour, min); //because of constructor, IdCounter increase
    }
    else
        return 0;

    eptr->setId(Event::IdCounter);
    EventNode *previous,*current;
    if (head){ // if head is not empty
        current=head;
        while (current->next){ //till going last list
            current=current->next;
        }
        current->next=new EventNode(eptr); //creates new node
        return eptr;
    }else{ //if head is empty
        head=new EventNode(eptr);
        return eptr; //return pointer which points created object
    }
}


void Calendar::deleteEvent(int id) {
    if (head==NULL)
        throw Error("Calendar is empty!");
    if(id>Event::IdCounter || id<1)
        throw Error("Event Not Found!"); //Exception
    EventNode *temp=head;
    EventNode *DeletedNode=NULL;
    if (id==1){
        head=temp->next;
        delete temp;
        temp=head; //to arrange next list' private id to decrease
    }else{
        for (int i=2;temp!=NULL && i<id;i++){ //it goes to the list which is requested to delete
            temp=temp->next;
        }
        DeletedNode=temp->next;
        temp->next=temp->next->next;
        temp=temp->next;
        delete DeletedNode; //it deletes DeletedNode->element
    }
    while (temp){ //to arrange id number of next list data
        temp->element->setId(id);
        id++;
        temp=temp->next;
    }
}

void Calendar::listEvents() {
    if (head==NULL)
        throw Error("Calendar is empty!");
    EventNode *Curr=head;
    while(Curr){ //till the last list, it prints every node data
        Curr->element->print();
        Curr=Curr->next;
    }
}
//Filter Method
void Calendar::filterEvents(int year, int month) {
    EventNode *curr=head;
    bool IsMatched= false;
    while (curr){
        if(curr->element->getYear()==year && curr->element->getMonth()==month){ //if mount and year is equal to arg, print its functions
            curr->element->print();
            IsMatched= true;
        }
        curr=curr->next;
    }
    if (!IsMatched)
        throw Error("No Matching Event!");
}
Calendar::~Calendar(){  //remove every node separately
        EventNode *temp;
        while(head){        // if the list is not empty
            temp=head;
            head=head->next;
            delete temp;
        }
}
