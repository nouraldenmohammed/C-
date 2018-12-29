#include <iostream>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;

/*
This program tesing either the integer number is prime or not,
also print the prime numbers up to specified number.

-----------------------------------------------------------------------

The method isPrime is boolean method, it take an intger number as input
and return boolean value, if the number is prime it return true else return false.
In this method we will use fermat theorem to check if the number is prime.
Just we need to check the numbers up to sqrt(n).

------------------------------------------------------

The void function printPrimes it just take an intger input and
retrun the prime numbers up to that number using isPrime method.



*/





bool isPrime(int n)
{

    for (int i=2; i<=sqrt(n); i++)
    {
        if (n%i==0) return false;

    }
    return true;
}




void printPrimes(int upto)
{

    for (int i=2; i<=upto; i++)
    {
        if (isPrime(i))
        {
            cout<<i<<endl;
        }
    }

}

int main()
{
    int x;
    char c;
h:
    cout<<"Press    1 to check the primeality of a number\n\
	 2  to print primes numbers up to specific number\n";
    cin>>x;

    if (x!=1 and x!=2)
    {
        cout<<"What you entered is incorrect\n\
	press 'y' to retry or something else to exit\n";
        cin>>c;
        if (c=='y')
            goto h;
        else return 0;
    }
    else
    {
        switch(x)
        {
            int y;
        case 1:
        {
            cout<<"Please enter a number:\n";
            cin>>y;
            if(y<2)
            {
                cout<<"The number must be greater then 1\n";
                return 0;
            }
            isPrime(y)?  cout << y <<" is prime number\n": cout << y <<" is not prime.\n";
            break;
        }
        case 2:
        {

            cout<<"Please enter a number:\n";
            cin>>y;
            cout<<"The prime number up to: "<<y<<" they are/is:\n";
            printPrimes(y);
            break;

        }

        }
        cout<<"If you want to continue press y\n";
        cin>>c;
        if (c=='y')
        {
            goto h;
        }
    }
    cout<<"Your reached the end of the program.\n";

    return 0;
}
