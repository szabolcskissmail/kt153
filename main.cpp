#include <iostream>
#include <bitset>

using namespace std;

#define KT153_BITS 360

class kt153 {
private:
    std::bitset<KT153_BITS> bits;
public:
    typedef unsigned char kt153_type;
    kt153(const kt153_type init) : bits(){
        std::bitset<8> init_bitset (init);
        for(unsigned int i = 0; i < init_bitset.size(); i++){
            bits[i] = init_bitset[i];
        }
    }
};

int main()
{
    std::cout << "kt153" << endl;
    return 0;
}
