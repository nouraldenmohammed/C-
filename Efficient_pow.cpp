#include<iostream>
using std::cout;
using std::cin;
using std::endl;


/*
This function calculate the power method recursively and recursively.
The input:
q: an interger number, which represent the base.
n: an integer number, which represent the power.


The output:
an intger number q^n.


The cost of this approach is O(log n).

 */


int recursive(int q,int n)
{
    if (n==0) return 1;

    if (n%2==0)
    {

        return recursive(q,n/2)*recursive(q,n/2);
    }
    else
    {
        return recursive(q,(n-1)/2)*recursive(q,(n-1)/2)*q;


    }

}



int iterative(int q,int n)
{
    int s=1;

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

int main()
{
    int q,n;
    cout<<"Please enter a number :\n";
    cin>>q;
    cout<<"Please enter a power:\n";
    cin>>n;
    if (n <0)
    {
        cout<<"Error, the exponent must be positive!\n";
        return -1;
    }
    cout<<"using recursive method: "<<q<<"^"<<n<<"="<<recursive(q,n)<<endl;
    cout<<"using iterative method : "<<q<<"^"<<n<<"="<<iterative(q,n)<<endl;

    return 0;
}

