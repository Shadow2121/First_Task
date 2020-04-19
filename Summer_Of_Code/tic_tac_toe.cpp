#include<iostream>
#include<conio.h>

using namespace std;

void show(int a[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << a[i][j] << "|" ;
        }
        cout << endl;
    }
}

bool finish(int a[3][3])
{
    
    for(int j=0;j<3;j++)
    {
        if((a[0][j]==0&&a[1][j]==0&&a[2][j]==0)||(a[0][j]==1&&a[1][j]==1&&a[2][j]==1))
            return true;
        if((a[j][0]==0&&a[j][1]==0&&a[j][2]==0)||(a[j][0]==1&&a[j][1]==1&&a[j][2]==1))
            return true;
    }
    
    //if(a[0][1]==a[1][1]==a[2][1])
      //  {return true;}
 //   if(a[0][2]==a[1][2]==a[2][2])
   //     {return true;}
    /*if(a[0][0]==a[1][0]==a[2][0]==0||a[0][0]==a[1][0]==a[2][0]==1)
        return false;
    if(a[0][0]==a[0][1]==a[0][2]==0||a[0][0]==a[0][1]==a[0][2]==1)
        return false;
    if(a[1][0]==a[1][1]==a[1][2]==0||a[1][0]==a[1][1]==a[1][2]==1)
        return false;
    if(a[2][0]==a[2][1]==a[2][2]==0||a[2][0]==a[2][1]==a[2][2]==1)
        return false;*/
    if(a[0][0]==a[1][1]==a[2][2])
        return true;
    if(a[0][2]==a[1][1]==a[2][0])
        return true;
    return false;
}

int change(int a[3][3],int x,int s)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i][j]==x&&x!=1&&x!=0)
            {
                a[i][j]=s;
                return 1;
            }
        }
    }
    cout << "Incorect input!!\n\n";
    return 0;
}

int main()
{
    int a[3][3];
    int z;
    int s;
    int q,c,b;
   // do{
        z=11;
        s=0;
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                a[i][j]=z;
                z++;
            }
        }           
        cout << "Player 1: 0\nPlayer 2: 1\n";
            show(a); 
        while(!finish(a))
        {
            clrscr();
            cout << "Enter the no. of location : ";
            cin >> q;
            c=change(a,q,s);
            if(c==1)
            {
                if(s==0)
                    s++;
                else
                    s--;
            }
            show(a);
        }
      //  if(finish(a)==true)
     //  cout << "Game complite\n\n";
    //    cout << "If you want to play again then press 1 or 0 to exit.";
   //     cin >> b;
  //  }while(b!=0);
    if(finish(a)==true)
        cout << "Game complite";
    getch();
    return 0;
}