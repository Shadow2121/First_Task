#include<iostream>
#include<conio.h>

using namespace std;

class chess
{
    private:
        int a[9][9];
        int q1=12,q11=14,q2=22,q22=24;
    public:
        chess()
        {
            for(int i=0;i<=8;i++)
            {
                for(int j=0;j<=8;j++)
                {
                    if (i==0)
                    {
                        a[i][j]=j;
                    }
                    
                    else if(i==1)
                    {
                        if(j==0)
                            a[i][j]=i;
                        else if(j<5)
                        {

                            a[i][j]=q1;
                            q1++;
                        }
                        else 
                        {
                            a[i][j]=q11;
                            q11--;
                        }
                        
                    }
                    else if(i==2)
                    {
                        if(j==0)
                            a[i][j]=i;
                        else
                        a[i][j]=11;
                    }
                    else if(i==7){
                        if(j==0)
                            a[i][j]=i;
                        else
                        a[i][j]=21;
                    }
                    else if(i==8)
                    {
                        if(j==0)
                            a[i][j]=i;
                        else if(j<5)
                        {
                            a[i][j]=q2;
                            q2++;
                        }
                        else
                        {
                            a[i][j]=q22;
                            q22--;
                        }
                    }
                    else
                    {
                        if(j==0)
                        {
                            a[i][j]=i;
                        }
                        else
                        a[i][j]=99;
                    }            
                }
            }
        }
        void show()
        {
            for(int i=0;i<=8;i++)
            {
                for(int j=0;j<=8;j++)
                {
                        if(i==0)
                        cout  <<a[i][j] << "   ";
                        else
                        {
                            if(j==0)
                                cout << a[i][j] << " ";
                            else 
                            cout << " |" << a[i][j] ;
                        }
                    
                }
                cout << endl;
            }
        }
        void move()
        {
            int x,y,m;
            cout << "enter the location: ";
            cin >> x >> y;
            if(a[x][y]==11)
            {
                cout << "You can go in following blocks :\npress 1 to go at location("<< x+1 <<","<<y<<").\nPress 2 to go at location("<<x+2<<","<<y<<").\nEnter your choice: ";
                cin >> m; 
                if(m==1)
                {
                    a[x+1][y]=11;
                    a[x][y]=99;
                }
                else if(m==2)
                {
                    a[x+2][y]=11;
                    a[x][y]=99;
                }
                else
                    cout << "Incorect input!";
            }
            else if(a[x][y]==21)
            {
                cout << "You can go in following blocks :\npress 1 to go at location("<< x-1 <<","<<y<<").\nPress 2 to go at location("<<x-2<<","<<y<<").\nEnter your choice: ";
                cin >> m; 
                if(m==1)
                {
                    a[x-1][y]=21;
                    a[x][y]=99;
                }
                else if(m==2)
                {
                    a[x-2][y]=21;
                    a[x][y]=99;
                }
                else
                    cout << "Incorect input!";
            }
            else if(a[x][y]==12)
            {
                int tempx=x,tempy=y,i=1;
                x++;
                while(a[x][y]==99)
                {
                    cout << "You can go in following blocks :\npress " << i << " to go at location("<< x <<","<<y<<").\n";
                    x++;
                    i++;
                }
                int i1=i;
                x=tempx-1;
                while(a[x][y]==99)
                {
                    cout << "You can go in following blocks :\npress " << i << " to go at location("<< x <<","<<y<<").\n";
                    x--;
                    i++;
                }
                int i2=i;
                x=tempx;
                y++;
                while(a[x][y]==99)
                {
                    cout << "You can go in following blocks :\npress " << i << " to go at location("<< x <<","<<y<<").\n";
                    y++;
                    i++;
                }
                int i3=i;
                y=tempy-1;
                while(a[x][y]==99)
                {
                    cout << "You can go in following blocks :\npress " << i << " to go at location("<< x <<","<<y<<").\n";
                    y--;
                    i++;
                }
                int i4=i;
                cin >> m;
                x=tempx;
                y=tempy;
                if(m<=i1)
                {
                    a[x][y]=99;
                    a[x+m][y]=12;
                }
                else if(m<=i2)
                {
                    a[x][y]=99;
                    a[x-m][y]=12;
                }
                else if(m<=i3)
                {
                    a[x][y]=99;
                    a[x][y+m]==12;
                }
                else if(m<=i4)
                {
                    a[x][y]=99;
                    a[x][y-m]==12;
                }
                else
                    cout << "Incorect input!";
            }
        }
};


int main()
{
    chess c;
    c.show();
    while(1)
    {
        c.move();
        c.show();
    }
    return 0;
}