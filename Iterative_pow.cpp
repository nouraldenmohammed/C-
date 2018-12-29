#include<iostream>
#include<typeinfo>
using std::cout;
using std::cin;
using std::endl;


/*
This function calculate the power method Iteratively.
The input:
q: an interger number, which represent the base.
n: an integer number, which represent the power.


The output:
an intger number q^n.


The cost of this approach is O(n).
 */

int pow_iteration(int q, int n)
{

    int s=1;

    for (int i=1; i<=n; i++) s*=q;



    return s;
}

int main()
{
    int q,n;
    cout<<"Please enter a number:\n";
    cin>>q;
    cout<<"Please enter the power:\n";
    cin>>n;
    if (n <0)
    {
        cout<<"Error, the exponent must be positive!\n";
        return -1;
    }

    cout<<q<<"^"<<n<<"="<<pow_iteration(q,n)<<endl;
    return 0;
}

