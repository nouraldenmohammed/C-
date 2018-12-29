#include<iostream>
#include<typeinfo>
#include<iomanip>
using std::cout;
using std::cin;
using std::endl;


//4.b as we will see the smallest representable number is of type double
template <class T>
T func()
{
    T x=1;
    while(1+x!=1)
    {
        cout<<"Please try a small number\n";
        cin>>x;
    }
    return x;
}



int main()
{
    ///For number 4.a
    cout<<"Using the double:\n";
    cout<<std::setprecision(20)<< func<double>()  <<endl;
    cout<<"Using the float:\n";
    cout<<std::setprecision(20)<< func<float>()  <<endl;
    return 0;
}

