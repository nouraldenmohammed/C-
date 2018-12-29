#include<iostream>
#include<iomanip>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;

/*
This program calculates the nth root for the number given the number of steps.

*/

double root_iterative1(double q, int n, int steps)
{

    double a=1;
    int i=0;


    while ( i<steps)
    {
        a=a+(1/(double)n)*((q/pow(a,n-1)) -a) ;
        i++;
    }
    return a;
}

int main()
{

    int n,steps;
    double q,res;

    cout<<"Please enter a number :\n";
    cin>>q;
    cout<<"Please nth root :\n";
    cin>>n;
    cout<<"Please enter the number of steps :\n";
    cin>>steps;

    cout<<"---------------------------------------------"<<endl;
    res=root_iterative1(q,n,steps);
    cout<<"The "<<n<<" th root of "<<q<<" is equal: "<<std::setprecision(7)<<res<<endl;


    return 0;
}
