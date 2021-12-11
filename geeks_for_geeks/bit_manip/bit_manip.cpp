#include <bits/stdc++.h>
using namespace std;
class BitManip
{
public:
    /**
     * @brief Get the bit at the ith position
     * 
     * @param number 
     * @param i
     * @return int 
     */
    int get_bit(int number, int i)
    {
        return ((number & (1 << i)) != 0);
    }
    int set_bit(int number, int i)
    {
        return (number | (1 << i));
    }
    int unset_bit(int number, int i)
    {
        int mask = ~(1 << i);
        return (number & mask);
    }
    int update_bit(int number, int i, int bit)
    {
        number = unset_bit(number, i);
        return (number | bit << i);
    }
    bool is_power_of_2(int number)
    {
        return (number & (number - 1)) == 0;
    }
    int count_set_bits(int number)
    {
        int count = 0;
        while (number)
        {
            number &= (number - 1);
            count++;
        }
        return count;
    }
    int mult_2(int number)
    {
        return number << 1;
    }
};
int main()
{
    BitManip b = BitManip();
    cout << b.get_bit(3, 0) << endl;
    cout << b.is_power_of_2(7) << endl;
    cout << b.is_power_of_2(32) << endl;
    cout << b.count_set_bits(3) << endl;
    return 0;
}