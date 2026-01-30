class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int count[128] = {0};
        int front = 0;
        int tail = -1;
        int ans = 0;
        int windowlen;
        for (auto p = s.begin(); p != s.end(); p++)
        {
            while (count[*p] != 0)
            {
                count[s[front]] -= 1;
                front++;
            }
            tail += 1;
            if (tail - front + 1 > ans)
            {
                ans = tail - front + 1;
            }
            count[*p] += 1;
        }
        return ans;
    }
};