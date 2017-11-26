#include <iostream>
#include <bitset>

using namespace std;

#define KT153_BITS 360
#define KT153_VALUE_BITS 8

class kt153 {
private:
    typedef unsigned int pointer_type;
    std::bitset<KT153_BITS> bits;
    pointer_type pointer;
    unsigned long circle;
public:
    typedef unsigned char kt153_type;
    kt153(const kt153_type init) : bits()
    {
        pointer = 0;
        circle = 0;
        std::bitset<KT153_VALUE_BITS> init_bitset (init);
        unsigned int j = 0;
        for(unsigned int i = 0; i < bits.size(); i++) {
            bits[i] = init_bitset[j++];
            if(j == KT153_VALUE_BITS - 1) {
                j = 0;
            }
        }
    }
    kt153_type value()
    {
        std::bitset<KT153_VALUE_BITS> return_bitset (0);
        unsigned int normalized_pointer = pointer;
        for (unsigned int i = 0; i < KT153_VALUE_BITS; i++) {
            if(normalized_pointer == KT153_BITS) {
                normalized_pointer = 0;
            }
            return_bitset[i] = bits[normalized_pointer];
            normalized_pointer++;
        }
        const unsigned long i = return_bitset.to_ulong();
        return static_cast<kt153_type>(i);
    }
    pointer_type get_pointer()
    {
        return pointer;
    }
    unsigned long get_circle()
    {
        return circle;
    }
    void operator++()
    {
        pointer++;
        if(pointer == KT153_BITS) {
            pointer = 0;
            circle++;
        }
    }
    void operator++(int)
    {
        operator++();
    }
};

int main()
{
    std::cout << "kt153" << endl;
    kt153 k (135);
    for (int i = 0; i < 500; i++) {
        std::cout << "circle: " << static_cast<unsigned>(k.get_circle()) <<
        "; pointer: " << static_cast<unsigned>(k.get_pointer()) <<
        "; value: " << static_cast<unsigned>(k.value()) << endl;
        k++;
    }
    return 0;
}
