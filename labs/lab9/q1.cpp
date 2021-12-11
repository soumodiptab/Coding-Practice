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
int checker(int a, int b, int c)
{
    BitManip bm = BitManip();
    bool val_a, val_b, val_c;
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        val_a = false;
        val_b = false;
        val_c = false;
        if (bm.get_bit(a, i))
            val_a = true;
        if (bm.get_bit(b, i))
            val_b = true;
        if (bm.get_bit(c, i))
            val_c = true;
        if (val_c)
        {
            if (!val_a && !val_b)
                count += 1;
        }
        else
        {
            if (val_a && val_b)
                count += 2;
            else if (val_a || val_b)
                count += 1;
        }
    }
    return count;
}
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << checker(a, b, c);
    return 0;
}