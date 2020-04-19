#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int k,a;
    for(int i=0;i<n;i++)
    {
        k=(i+1);
        a=2;
        for(int j=0;j<((2*n)-(2*i)-1);j++)
        {
            if(k<=n)
            {
                cout << k;
                k++;
            }
            else
            {
                cout << (k-a);
                a++;
            }
            
        }
        cout << endl;
    }
    return 0;
}