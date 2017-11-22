#include <iostream>
#include <bitset>

using namespace std;

#define KT153_BITS 360
#define KT153_VALUE_BITS 8

class kt153
{
private:
    typedef unsigned int pointer_type;
    std::bitset<KT153_BITS> bits;
    pointer_type pointer;
public:
    typedef unsigned char kt153_type;
    kt153(const kt153_type init) : bits()
    {
        pointer = 0;
        std::bitset<KT153_VALUE_BITS> init_bitset (init);
        unsigned int j = 0;
        for(unsigned int i = 0; i < bits.size(); i++)
        {
            bits[i] = init_bitset[j++];
            if(j == KT153_VALUE_BITS - 1)
            {
                j = 0;
            }
        }
    }
    void operator++()
    {
        pointer++;
    }
    void operator++(int)
    {
        operator++();
    }
};

int main()
{
    std::cout << "kt153" << endl;
    kt153 k (255);
    k++;
    return 0;
}
