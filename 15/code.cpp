#include <iostream>

/* Requires std=c++11 */

/*
The code was inefficient because we had to go through the linked list twice : once for the instantiation and once for the coordinates transformation.
We can merge the Init() and Transform() methods into one by overloading the Foo constructor :
- Foo(Foo* _nextItem) only randomizes the coordinates (and other elements).
- Foo(Foo* _nextItem, const Matrix& transform) call the base constructor and then performs the matrix transformation.
This gives us a wiggle room to turn on the matrix transformation or not, without the need to loop through the linked list several times.

The proposed corrected code is below:
*/

void RandomizeCoords(float* coords)
{
    std::cout << "Randomizing coords" << std::endl;
    // do some things...
}

struct Matrix
{
    void ApplyTo(float* coords) const { std::cout << "Applying transform to coords" << std::endl; }
};

struct Foo
{
    Foo(Foo* _nextItem);
    Foo(Foo* _nextItem, const Matrix& transform);
    Foo* nextItem;
    float coords[3];
    // and potentially others...
};

Foo::Foo(Foo* _nextItem)
{
    nextItem = _nextItem;
    RandomizeCoords(coords);
    // and more...
}

// c++11 feature : delegating the base constructor to any overloads
Foo::Foo(Foo* _nextItem, const Matrix& transform): Foo(_nextItem)
{
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
