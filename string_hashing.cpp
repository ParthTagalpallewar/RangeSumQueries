#include <iostream>
#include <vector>
#include <string>

//Reference:- https://www.youtube.com/watch?v=dfibaLGTcrY
//Question:- cses finding periods (strings)

using namespace std;

long long get_hash(int l, int r, const vector<long long> &hash, const vector<long long> &power, long long M)
{
    long long h = hash[r + 1] - (power[r - l + 1] * hash[l] % M + M) % M;
    return h < 0 ? h + M : h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int n = s.length();

    long long P = 31;
    long long M = 1000000007;

    vector<long long> power(n + 5, 1);

    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * P) % M;
    }

    vector<long long> hash(n + 10, 0);

    for (int i = 1; i <= n; i++)
    {
        hash[i] = (hash[i - 1] * P + s[i - 1]) % M;
    }

    for (int i = 0; i < n; i++)
    {
        int runIdx = 0;
        bool ok = true;
        while (runIdx < n)
        {
            int len = min(i + 1, n - runIdx);
            ok &= (get_hash(0, len - 1, hash, power, M) == get_hash(runIdx, runIdx + len - 1, hash, power, M));
            runIdx += len;
        }
        if (ok)
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}
