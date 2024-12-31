#include<iostream>
using namespace std;
/*In case of an empty class, our object is allocated a memory of 1 byte.
We can access the class properties (or data members) using "." (dot) operator.

There are 3 types of access modifiers : private, public and protected. They tell us about where we can access these class properties (or data members).
public means we can access them both inside and outside the class. 
private means we can access them only inside the class and by default if we don't mention anything, then they are under the category of private.
Now even if we want to access those private members outside the class, then although we can't do this directly but can make use of "getter/setter." 

className objectName is static way and objectName *pointerName = new objectName is dynamic way. 
In case of static allocation, we write objectName.(the property) and in case of dynamic, we will write (*pointerName).(the property) 
or pointerName->(property), that means making use of -> (arrow operator).

Whenever we create an object, then what happens in/with the compiler is that the constructor gets called. 
Now constructor has the properties that it gets invoked at the time of object creation and it doesn't have a return type. 
Also whenever we create an class, a default constructor with a name exactly same name as the className gets created. 
And the constructor can be either with parameter or without any parameter.
If we want to create a constructor, then we can write inside the class as className() { and inside these curly braces, any set of statements we want}
and inside those parenthesis, we can either pass some parameter or leave it empty. 
Now when the name of input parameter and the data member of class are same, then it might become confusing. So here comes the role of "this" keyword.
so what happens is that the address of the current object is stored inside the "this" keyword. That means "this" is a pointer which is pointing towards
our current object. 
And whenever we do custom implementation of a constructor, then the already inbuilt constructors or the constructors without any parameter
are self destroyed, that is they no longer exists. 

Now comes the destructor which is used to deallocate the memory. So whenever our objects are at the verge of becoming out of scope or their lifetime
is going to end shortly, then the destructor gets called to free the allocated memory. 
Whenever our class is created, just like the constructor, the destructor is also created and we can also create our own destructor. 
It has the properties that its name is also same as that of the className, it has no return type and in the byDefault destructor, there aren't any parameters.
Now when we are creating a destructor, we need to use "~" symbol before its name so that we can distinguish between the constructor and the destructor
as they both have got similar properties. 
Important : For objects which are statically allocated, the destructor is automatically called. 
For dynamically allocated objects, we need to call the destructor manually and that we can do by writing delete objectName. 

And let's talk about the static keyword. This is used to create a data member that belongs to the class and this hits different because in order
to access this data member, there is no need to create an object. And when we are creating this static member, we need to initialise it and this we
will be doing outside the class in the following manner : 
(dataType of the member) className :: (:: is scope resolution operator) dataMemberName = (and now the value we want to put in). 

If we talk about static functions, then here also we don't need to create an object to access them.
Important: these functions don't have "this" keyword because this keyword is basically a pointer to the current object, but since there are no objects, 
so how can we create a pointer pointing towards them. 
Also these functions can only and only access static members. */

class person {
    private:
    int weight = 64;

    public:
    string name;
    int age;
    float CGPA;
    //creating a data member using static keyword
    static int timeToComplete;

    person() {
        cout << "Simple constructor called....." << endl << endl;
    }

    //Parameterised constructor
    person(int weight, float CGPA){
        cout << "Parameterised constructor called....." << endl << endl;
        this->weight = weight;
        this->CGPA = CGPA;
    }

    //Copy constructor. 
    person(person &temp){
        cout << "Copy constructor called....." << endl << endl;
        this->weight = temp.weight;
        this->CGPA = temp.CGPA;
    }

    void print(){
        cout << "Weight : " << this->weight << endl;
        cout << "CGPA : " << this->CGPA << endl;
    }

    int getWeight(){
        return weight;
    }

    int setWeight(int w){
        weight = w;
    }

    //Creating a static function
    static int random(){
        return timeToComplete;
    }
};

//That data member intialisation which is being created using the static keyword. 
int person :: timeToComplete = 5; 

int main(){
    person details; // this is basically the creation of an object (here named as details) for the class (here person).
    details.name = "Manan";
    details.age = 18;
    details.CGPA = 8.18;

    cout << "Earlier Weight was : " << details.getWeight() << endl; //So this would be giving us the value 64 as we have assigned to it otherwise any garbage value.
    details.setWeight(70); //Now we are trying to change the value of weight as per our requirements. 

    cout << "Personal Details are as follows --> " << endl;
    cout << "Name : " << details.name << endl;
    cout << "Age : " << details.age << endl;
    cout << "CGPA : " << details.CGPA << endl;
    cout << "Current Weight : " << details.getWeight() << endl << endl;

    person testing(75, 8.52);
    testing.print();
    cout << endl;

    /*Copy constructor and this is the byDefault one. However we can also create our own copy constructor. 
    and when we create our own one, then the default one gets self destroyed. 
    
    By using a default copy constructor, a SHALLOW COPY is created which means that we are trying to access the same memory with two different names.
    And we can create DEEP COPY by using our own copy constructor. */
    person reTesting(testing);
    reTesting.print();
    cout << endl;

    //Now accessing that data member which we created using static keyword. 
    cout << "Accessing static keyword as well as function....." << endl << endl;
    cout << "Value is : " << person :: timeToComplete << endl;
    cout << "Value after accessing the function is : " << person :: random() << endl;

    return 0;
}