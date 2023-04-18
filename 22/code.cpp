#include <iostream>

/*
unsigned char has a 0 -> 2^7-1(255) value range (8 bits).
So count = 150*2 gives 300 - 255 = 45, thus the for loop executes 45 times.
*/
int main()
{
    unsigned char count=150;
    count *= 2;
    unsigned char i = 50;

    for (i = 0; i<= count; i++)
    {
        std::cout << "# " << static_cast<int>(i) << " Some operation" << std::endl;
    }

    return 0;
}

/*
Output:
--
# 0 Some operation
# 1 Some operation
# 2 Some operation
# 3 Some operation
# 4 Some operation
# 5 Some operation
# 6 Some operation
# 7 Some operation
# 8 Some operation
# 9 Some operation
# 10 Some operation
# 11 Some operation
# 12 Some operation
# 13 Some operation
# 14 Some operation
# 15 Some operation
# 16 Some operation
# 17 Some operation
# 18 Some operation
# 19 Some operation
# 20 Some operation
# 21 Some operation
# 22 Some operation
# 23 Some operation
# 24 Some operation
# 25 Some operation
# 26 Some operation
# 27 Some operation
# 28 Some operation
# 29 Some operation
# 30 Some operation
# 31 Some operation
# 32 Some operation
# 33 Some operation
# 34 Some operation
# 35 Some operation
# 36 Some operation
# 37 Some operation
# 38 Some operation
# 39 Some operation
# 40 Some operation
# 41 Some operation
# 42 Some operation
# 43 Some operation
# 44 Some operation
--
*/
