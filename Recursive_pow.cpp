#include<iostream>
#include<typeinfo>
using std::cout;
using std::cin;
using std::endl;

/*
This function calculate the power method recursively.
The input:
q: an interger number, which represent the base.
n: an integer number, which represent the power.


The output:
an intger number q^n.


The cost of this approach is O(n).

 */

int pow_recursive(int q,int n)
{
    if (n==0) return 1;
    else
        return  q*pow_recursive(q,n-1);

}

int main()
{
    int q,n;
    cout<<"Please enter a number:\n";
    cin>>q;
    cout<<"Please enter a power:\n";
    cin>>n;
    if (n <0)
    {
        cout<<"Error, the exponent must be positive!\n";
        return -1;
    }

    cout<<q<<"^"<<n<<"="<<pow_recursive(q,n)<<endl;
    return 0;
}
