#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    for(int i=1;i<=n;i++)
    {
        a=n-i+1;
        for(int j=0;j<i;j++)
        {
            cout << a << " ";
            a++;
        }
        cout << endl;
    }
    return 0;
}