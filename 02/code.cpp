#include <iostream>

class A
{
private:
    int x;
public:
    A(int x): x(x) {}
    void Foo() { std::cout << "x = " << x << std::endl; }
};

/*
This is unsafe because the param pointer comes from outer scope and could be null,
so dereferencing + calling Foo could produce a seg fault.
*/
void Func(A* param)
{
    A& a = *param;
    a.Foo();
}

/*
A better way to implement the function would be to check the pointer before
dereferencing + calling the Foo function.
*/
void BetterFunc(A* param)
{
    if (param != nullptr) param->Foo();
}

int main()
{
    A* param = new A(5);
    A* nullParam = nullptr;

    //Func(param);
    //Func(nullParam);

    BetterFunc(param);
    BetterFunc(nullParam);

    delete param;
    return 0;
}

/*
Output:
--
With Func:
x = 5
Segmentation fault: 11
--
With BetterFunc:
x = 5
--
*/
