#include<iostream>
#include<conio.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char a;
    char z;
    for(int i=1;i<=n;i++)
    {
        a='A';
        z='Z';
        for(int j=0;j<(n-((n+i+1)/2)+1);j++)
        {
            if(i%2!=0)
            {
                cout << a << " ";
                a++;
            }
            else
            {
                cout << " " << z;
                z--;
            }
        }
        cout << endl;
    }
    for(int i=1;i<n;i++)
    {
        a='A';
        z='Z';
        for(int j=0;j<(i/2)+1;j++)
        {
            if(i%2!=0)
            {
                cout << " " << z;
                z--;
            }
            else
            {
                cout << a << " ";
                a++;
            }
            
        }
        cout << endl;
    }
    getch();
    return 0;
}