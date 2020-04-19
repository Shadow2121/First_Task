#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box


// The class should have the following functions : 

// Constructors: 
// Box();
// Box(int,int,int);
// Box(Box);


// int getLength(); // Return box's length
// int getBreadth (); // Return box's breadth
// int getHeight ();  //Return box's height
// long long CalculateVolume(); // Return the volume of the box

//Overload operator < as specified
//bool operator<(Box& b)

class Box
{
    public:
        int l,b,h;
    
        Box()
        {
            l=b=h=0;
        }
        Box(int a,int d,int c)
        {
            l=a;
            b=d;
            h=c;
        }
        Box(Box & a)
        {
            l=a.l;
            b=a.b;
            h=a.h;
        }
        int getLength()
        {
            return l;
        }
        int getBreadth()
        {
            return b;
        }
        int getHight()
        {
            return h;
        }
        long long CalculateVolume()
        {
            unsigned long long v;
            v=l*b*h;
            return v;
        }
        bool operator<(Box b)
        {
            long long v1,v2;
            v1=this->CalculateVolume();
            v2=b.CalculateVolume();
            if(v1<v2)
                return 1;
            return 0 ;
        }
};

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

ostream& operator<<(ostream& out, Box& B)
{
    out << B.l << " " << B.b << " " << B.h;
    return out;
}



void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}