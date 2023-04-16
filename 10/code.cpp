#include <cstdlib>
#include <ctime>
#include <iostream>

unsigned int Rand32()
{
    unsigned int value = rand() % 155 + 1;
    std::cout << value << std::endl;
    return value;
}

int main()
{
    srand(time(NULL));
    char buffer[12];

    std::cout << sizeof(char) << " " << sizeof(unsigned int) << std::endl;

    for (int i=0; i<12; i+=4)
    {
        buffer[i] = Rand32();
    }

    for (int i=0; i<12; i++)
    {
        std::cout << i << " -> <" << buffer[i] << ">" << std::endl;
    }

    return 0;
}
