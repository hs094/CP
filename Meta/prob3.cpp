#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; ++tc)
    {
        int N, A, B;
        cin >> N >> A >> B;
        cout << "Case #" << tc << ": ";
        for (int i = 1; i <= 2 * N; i++)
        {
            if (i < 2 * N)
                cout << (i == 2 * N ? B : 1) << " ";
            else
                cout << B;
        }
        cout << "\n";
    }
    return 0;
}