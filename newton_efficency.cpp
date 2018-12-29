#include<iostream>
#include<math.h>

using std::cout;
using std::cin;
using std::endl;




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


void test_root(double q, int n, int steps)
{
    double a=1,b;
    int i=0;
    b=a+(1/double(n))*((q/iterative_pow(a,n-1)) -a);

    double tol=0.000001;

    while (i<steps && abs(a-b)>tol )
    {
        a=b;
        b=a+(1/double(n))*((q/iterative_pow(a,n-1)) -a) ;
        i++;
    }
    cout<<"The original number q is:\t"<<q<<endl;
    cout<<"The the number n is:\t"<<n<<endl;
    cout<<"The approximated root is :\t"<<a<<endl;
    cout<<"The root to power n is :\t"<<iterative_pow(a,n)<<endl;
    cout<<"The estimated error is:\t"<<abs(q-iterative_pow(a,n))<<endl;

    cout<<"The maximum number of iteration the user entered is :\t"<<steps<<endl;

    cout<<"The actual number of iteration the program needs to be identical with solution up to 6 digits is :\t"<<i<<endl;

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


    test_root(q,n,steps);

    return 0;
}
