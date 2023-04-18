#include <iostream>

/*
A mutable member can be modified, even within a const-defined method
*/
class TwoBit
{
private:
    mutable int counter;
public:
    TwoBit(): counter(0) {}
    void Evacuate() const { std::cout << "2-Bit says: evacuate the building! Try # " << ++counter << std::endl; }
};

/*
A mutable member can be modified even when the struct is instanciated as const
*/
struct Frank
{
    bool isCrazy;
    mutable int NumberOfFireworks;
    Frank(): isCrazy(true), NumberOfFireworks(3) {}
};

int main()
{
    TwoBit twoBit;
    for (int i=0; i<15; i++)
    {
        twoBit.Evacuate();
    }

    const Frank frank;
    // frank.isCrazy = false; // illegal, isCrazy is not mutable
    frank.NumberOfFireworks = 6; // legal, NumberOfFireworks is mutable

    std::cout << frank.isCrazy << " - " << frank.NumberOfFireworks << std::endl;

    return 0;
}

/*
Output:
--
2-Bit says: evacuate the building! Try # 1
2-Bit says: evacuate the building! Try # 2
2-Bit says: evacuate the building! Try # 3
2-Bit says: evacuate the building! Try # 4
2-Bit says: evacuate the building! Try # 5
2-Bit says: evacuate the building! Try # 6
2-Bit says: evacuate the building! Try # 7
2-Bit says: evacuate the building! Try # 8
2-Bit says: evacuate the building! Try # 9
2-Bit says: evacuate the building! Try # 10
2-Bit says: evacuate the building! Try # 11
2-Bit says: evacuate the building! Try # 12
2-Bit says: evacuate the building! Try # 13
2-Bit says: evacuate the building! Try # 14
2-Bit says: evacuate the building! Try # 15
1 - 6
--
*/
