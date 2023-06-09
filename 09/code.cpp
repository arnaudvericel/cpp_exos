#include <iostream>

/*
What was wrong in the code?
- [Actual bug] the Object destructor was not virtual, so the line "delete pA" was not calling ~Thing() (only ~Object()), thus the instance was not removed from the thingCollection after its destruction.
- [Better practice/debatable] pB was created with a static cast while going from a base class to a derived one, which is unsafe in general (although it works in this case).
    * It's better practice to use dynamic_cast when performing an up cast (base class to child class) because the pA pointer might not have pointed to a Thing object, especially if the pointer came from outer scope.
    * After a dynamic cast to pointer, which can fail and return nullptr, it's also good practice to test the pointer before dereferencing and calling the Print() function.

My corrected code is below.
*/

class Object
{
public:
    Object() {std::cout << "Register in Manager" << std::endl;}
    virtual ~Object() {std::cout << "Unregister from Manager" << std::endl;}
    virtual void Print() { printf( "Hello!\n" ); }
};

class Thing : public Object
{
public:
    Thing() {std::cout << "Append to Collection" << std::endl;}
    virtual ~Thing() {std::cout << "Remove from Collection" << std::endl;}
    virtual void Print() override { printf( "I'm a Thing!\n" ); }
};

void Func()
{
Object * pA = new Thing;
Thing * pB = dynamic_cast<Thing*>(pA);
pA->Print();
if (pB != nullptr) pB->Print();
delete pA;
};


int main()
{
    Func();
    return 0;
}

/*
Output:
--
Register in Manager
Append to Collection
I'm a Thing!
I'm a Thing!
Remove from Collection
Unregister from Manager
--
*/
