class Solution
{
public:
    bool isHappy(int n)
    {
        // algorithm cycle
        int slow = n;
        int fast = findInt(n); // finna use a func

        while (fast != 1 && slow != fast)
        {
            slow = findInt(slow);
            fast = findInt(findInt(fast));
        }

        return fast == 1;
    }

    int findInt(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};