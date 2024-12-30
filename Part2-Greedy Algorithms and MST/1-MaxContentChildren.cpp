#include <bits/stdc++.h>
using namespace std;

int maxContentChildren(vector<int> children, vector<int> cookies)
{
    int g = children.size(), s = cookies.size();
    sort(children.begin(), children.end());
    sort(cookies.begin(), cookies.end());
    int i = 0, j = 0, ans = 0;
    while (i < s && j < g)
    {
        if (cookies[i] >= children[j])
        {
            ans++;
            j++;
        }
        i++;
    }
    return ans;
}

int main()
{
    int g, s;
    cout << "Input number of children: \n";
    cin >> g;
    cout << "Input number of cookies: \n";
    cin >> s;

    vector<int> children(g), cookies(s);
    cout << "Input greed factors of children: (On one line)\n";
    for (int i = 0; i < g; i++)
        cin >> children[i];
    cout << "Input cookie sizes: (On one line)\n";
    for (int i = 0; i < s; i++)
        cin >> cookies[i];
    cout << maxContentChildren(children, cookies) << '\n';
}