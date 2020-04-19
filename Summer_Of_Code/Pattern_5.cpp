#include<iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            cout << " ";
        }
        for(int j=0;j<i+1;j++)
        {
            if(i%2==0)
            {
                cout << "*" << " ";
            }
            else
            {
                a=1;
                cout << a << " ";
                a++;
            }
            
        }
        cout << endl;
    }
    return 0;
}