#include <iostream>

/*
The code was inefficient because we had to go through the linked list twice : once for the instantiation and once for the coordinates transformation.
We can merge the Init() and Transform() methods into one by overloading the Foo constructor :
- Foo(Foo* _nextItem, const Matrix& transform) randomizes the coordinates and then performs the transformation.
- Foo(Foo* _nextItem) only randomizes the coordinates.
This gives us a wiggle room to turn on the matrix transformation or not, without the need to loop through the linked list several times.

The corrected code is below:
*/

void RandomizeCoords(float* coords)
{
    std::cout << "Randomizing coords" << std::endl;
}

struct Matrix
{
    void ApplyTo(float* coords) const { std::cout << "Applying transform to coords" << std::endl; }
};

struct Foo
{
    Foo(Foo* _nextItem);
    Foo(Foo* _nextItem, const Matrix& transform);
    void InitializeSomeThings(Foo* _nextItem);
    Foo* nextItem;
    float coords[3];
};

void Foo::InitializeSomeThings(Foo* _nextItem)
{
    nextItem = _nextItem;
    RandomizeCoords(coords);
}

Foo::Foo(Foo* _nextItem)
{
    InitializeSomeThings(_nextItem);
}

Foo::Foo(Foo* _nextItem, const Matrix& transform)
{
    InitializeSomeThings(_nextItem);
    transform.ApplyTo(coords);
}

int main()
{
    Foo* first = nullptr;
    Matrix transform;
    for (int i=0; i<1000; i++)
    {
        std::cout << i << " - ";
        first = new Foo(first, transform);
        std::cout << std::endl;
    }

    return 0;
}

/*
Output:
--
1 - Randomizing coords
Applying transform to coords
.
.
.
999 - Randomizing coords
Applying transform to coords
--
*/
