class Solution {
private:    
    int* primes;
    
public:
    void setPrime(int index, bool value)
    {
            int pos = index / 32;
            int bit = index % 32;
            if (value)
                primes[pos] = primes[pos] | (1 << bit);
            else
                primes[pos] = primes[pos] & ~(1 << bit);
    }
    
    bool getPrime(int index)
    {
            int pos = index / 32;
            int bit = index % 32;
            return (primes[pos] >> bit) & 1;
    }
    
    int countPrimes(int n)
    {
        if (n > 2)
        {
            int size = n/32 + 1, extra = n % 32, count = 0;
            primes = new int[size];
            for (int i = 0; i < size; i++)
                primes[i] = 0xffffffff;
            setPrime(0, false);
            setPrime(1, false);
            for (int i = 2; i*i < n; i++)
            {
                if (!getPrime(i)) continue;
                for (int j = i*i; j < n; j+=i)
                    setPrime(j, false);
            }
            for (int i = 0; i < size-1; i++)
            {
                int val = primes[i];
                for (int j = 0; j < 32; j++)
                {
                    count += (val >> j) & 1;
                }
            }
            for (int i = 0; i < extra; i++)
            {
                count += (primes[size-1] >> i) & 1;
            }
            delete[] primes;
            return count;
        }
        return 0;
    }
};