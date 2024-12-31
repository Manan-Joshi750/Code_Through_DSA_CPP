#include<iostream>
using namespace std;
/*ENCAPSULATION means wrapping up data members and functions. And a fully encapsulated class means that we have marked all the data members as private, 
that means the same class can only access these data members and no other class can do. 
A synonym for encapsulation would be information hiding or we can say data hiding and here are some of its advantages : 
--> Data hide (security increases)
--> If we want, then we can make ourclass read-only.
--> Code reusability and encapsulation code is better for unit testing. 

INHERITANCE:
When we want to access the properties of one class in some other class, then we can do this by inheriting the properties of one class in the other and 
this is what Inheritance means. The class from which we are inheriting the properties is known as the parent class or super class and the class which
is inheriting those properties is known as the child class or sub class. 
And then comes the important aspect which is the mode of inheritance as it decides how and where we can access the properties we have inherited. 
You can see the entire table in the screenshot section and let's discuss one of is case. 
If the access modifier of the parent class is public and we are trying to inherit its properties in public mode, then the properties which will get 
inherited in the child class will also be of access modifier type public. And similarly we can have a look on all other possible cases. 
Important Conclusion : private data members of a class cannot be inherited. 

Important : protected access modifier means that we can access the members of a class within that class only and there's a condition as well that if
we inherit those members in a child class, then we can use them inside this child class also. And this further means that we can access them outside the
class using getter/setter which we have discussed earlier. 

Now there are various types of inheritance : 
Single, multi-level, multiple, hybrid and hierarchical. 
For example, consider the classes A,B,C. 
--> B inherits A is "single inheritance". 
--> B inheriting A and then C inheriting B is "multi-level inheritance".
--> C inheriting both A and B is "multiple inheritance" and its syntx is class C : (mode in which you want to inherit) B, (mode in which you want to inherit) A
--> When one class serves as a parent class for more than 1 child classes, that is A serving as a parent class for both B and C is "hierarchical inheritance".
--> Combination of more than one type of inheritance is known as "hybrid inheritance". 

INHERITANCE AMBIGUITY:
So now comes the case when there are let's say three classes A, B and C such that class A has a function named abc and class B also has a function named abc
and class C is inheriting both the classes. Then we create an object for class C and call this function abc, but now we don't know which function will 
get called as both class A and B have the same functions. This situation is known as "INHERITANCE AMBIGUITY" and in order to resolve this issue, we will be 
making use of the scope resolution operator (::) such that if we want to access the function abc of class A, then we will write : 
objectName.A (or the className) :: abc (or the functionName) and if we want to access the function abc of class B, then we will write : 
objectName.B (or the className) :: abc (or the functionName). 

POLYMORPHISM:
Now comes the concept of Polymorphism which basically means existing in multiple forms or we can say when a single thing is existing in multiple forms, then
polymorphism is occurring there. Polymorphism is a concept that allows you to perform a single action in different ways.
And there are two types of polymorphism : 
--> Compile-time polymorphism (can be achieved through function overloading or operator overloading)
--> Run-time polymorphism (method overriding is a way to implement runtime polymorphism) and it is also known as dynamic polymorphism. 

--> Function overloading : 
When there are multiple functions in a class with the same name but different parameters, these functions are overloaded. 
The main advantage of function overloading is that it increases the program’s readability. 
Functions can be overloaded by using different numbers of arguments or by using different types of arguments. 
Also functions that differ ONLY in their return type cannot be overloaded. 

--> Operator Overloading : 
C++ also provides options to overload operators. For example, we can make the operator (‘+’) for the string class to concatenate two strings. 
We know that this is the addition operator whose task is to add two operands. 
When placed between integer operands, a single operator, ‘+,’ adds them and concatenates them when placed between string operands.

Syntax for operator overloading is : 
returnType the word operator then the operator to overoad (here will be our input parameters) {statemnts through which overloading will be shown}

Important : operators that cannot be overloaded are :
--> Conditional or Ternary Operator (?:) 
--> Size of Operator (sizeof) 
--> Scope Resolution Operator (::) 
--> Class member selector Operator (.) 
--> Member pointer selector Operator (.*) 
--> Object type Operator (typeid) 

--> Method overriding :
Method overriding is a feature that allows you to redefine the parent class method in the child class based on its requirement. 
In other words, whatever methods the parent class has by default are available in the child class. 
But, sometimes, a child class may not be satisfied with parent class method implementation. 
The child class is allowed to redefine that method based on its requirement. This process is called method overriding. 

Rules for method overriding :
--> The parent class method and the method of the child class must have the same name.
--> The parent class method and the method of the child class must have the same parameters.
--> It is possible through inheritance only. 

ABSTRACTION:
A synonym for abstraction would be implementation hiding. This means displaying only the essential information and hiding the details. 
Data abstraction refers to providing only necessary information about outside world's data, hiding the background details or implementation. 
We just need to know about the methods of the objects that we need to call and the input parameters needed to trigger a specific operation, 
excluding the details of implementation and type of action performed to get the result. 

Real-life example: When you send an email to someone, you just click send, and you get the success message; 
what happens when you click send, how data is transmitted over the network to the recipient is hidden from you (because it is irrelevant to you).

We can implement Abstraction in C++ using classes. The class helps us to group data members and member functions using available access specifiers. 
A Class can decide which data members will be visible to the outside world and not. 
Access specifiers are the main pillar of implementing abstraction in C++. We can use access specifiers to enforce restrictions on class members. 

Advantages Of Abstraction :
--> Only you can make changes to your data or function, and no one else can.
--> It makes the application secure by not allowing anyone else to see the background details.
--> Increases the reusability of the code.
--> Avoids duplication of your code. */

class Human {
    public:
    int weight = 70;
    int age = 18;
    float height = 6.3;

    public:
    int getAge() {
        return this->age;
    }

    void setWeight(int w){
        this->weight = w;
    }
};

class Male : public Human { //this line shows that Male class is inheriting Human class in public mode. 
    public:
    string color;

    void sleep(){
        cout << "Male is sleeping right now....." << endl;
    }
};

//This class is created for showing and understanding operator overloading. 
class operators {
    public:
    int a;
    int b;

    void operator+ (operators &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout << "+ operator is overloaded to perform subtraction and result is : " << value2 -value1 << endl;
    }
};

int main(){
    Male object1;
    cout << endl;
    cout << "Accessing the properties of parent class with an object created for the child class using INHERITANCE....." << endl << endl;
    cout << "Age : " << object1.age << endl;
    cout << "Weight : " << object1.weight << endl;
    cout << "Height : " << object1.height << endl << endl;

    cout << "Understanding operator overloading....." << endl << endl;
    operators obj1, obj2;
    obj1.a = 4;
    obj2.a = 7;
    obj1 + obj2;

    return 0;
}