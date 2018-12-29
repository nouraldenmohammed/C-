#include<iostream>
#include<typeinfo>
using std::cout;
using std::cin;
using std::endl;


double tend_map1(double x)
{
    if (x<0 || x>1)
    {
        cout<<"The number must be in the interval[0,1].\n";
        return -1;
    }


    if (x>=0 && x<0.5) return 1.999999 *x;
    else return 1.999999 *(1 -x);

}


int main()
{
    double x=0.01401,y;
    for (int i=1; i<=100; i++)
    {
        y=tend_map1(x);
        cout<<x<<endl;
        x=y;
    }

    return 0;
}
