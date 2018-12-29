#include<iostream>
#include<typeinfo>
using std::cout;
using std::cin;
using std::endl;

double tend_map(double x)
{
    if (x<0 || x>1)
    {
        cout<<"The number must be in the interval[0,1].\n";
        return -1;
    }


    if (x>=0 && x<0.5) return 2*x;
    else return 2-2*x;

}


int main()
{
    double x=0.01401,y;
    for (int i=1; i<=100; i++)
    {
        y=tend_map(x);
        cout<<x<<endl;
        x=y;
    }

    return 0;
}
