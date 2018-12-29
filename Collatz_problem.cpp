#include<iostream>
#include<tuple>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;
using std::tuple;
using std::pair;
/*This program calculate Collatz problem using an iterative way,
because the recursion way it fails for large number when the recursion
execeed the maximum depeth.

The input to the collatz function is an interger number n, which we need to calculate
its collatz. Whilst the output is the number of iteration the fuction run and
the collatz of n.
 */

std::tuple <int,int> collatz(int n)
{
    int r;
	
    if (n==1) return {1,1};
    else while(n>1)
        {
            if (n%2==0)
            {
                n/=2;
                r++;
            }
            else
            {
                n=3*n+1;
                r++;
            }
        }
    return {r,n};
}


int main()
{

    int x;
    cout<<"Please enter an integer number:\n";
    cin>>x;
    int r,n;
    std::tie( r,n)=collatz(x);
    cout<<"The Collatz number of "<<x<<" is :"<<n<<"\nThe number of repitions is: "<<r<<endl;

    return 0;
}
