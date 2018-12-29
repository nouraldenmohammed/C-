#include<iostream>

using std::cout;
using std::cin;
using std::endl;



/*
This program calculates the nth root for the number given the number of steps.
In this program instead of using the pow function from math lib, we use our defined pow method
which we calcuated in Question 1.

*/


double iterative_pow(double q,int n)
{
    double s=1;

    while(n>0)
    {
        if (n%2==1)
        {
            s*=q;
            n--;
        }
        else
        {
            q*=q;
            n/=2;
        }
    }

    return s;
}
double root_iterative(double q, int n, int steps)
{

    double a=1;


    for (int i=0; i<steps;i++)
    {

        a=a+(1/(double)n)*((q/iterative_pow(a,n-1)) -a) ;

    }
    return a;
}

int main()
{
    int n,steps;
    double q,res;

    //cout<<"------------:"<<iterative_pow(.5,4)<<endl;

    cout<<"Please enter a number :\n";
    cin>>q;
    cout<<"Please nth root :\n";
    cin>>n;
    cout<<"Please enter the number of steps :\n";
    cin>>steps;

    cout<<"---------------------------------------------"<<endl;
    res=root_iterative(q,n,steps);
    cout<<"The "<<n<<" th root of "<<q<<" is equal: "<<res<<endl;

    return 0;
}
