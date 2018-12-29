#include<iostream>
#include <math.h>
#include<vector>
#include<tuple>
using std::cout;
using std::cin;
using std::endl;

std::vector<int> reverse1(std::vector<int> v)
{
    //creating another vector to store the new resulting vector
    std::vector <int> u;
    for (int i=v.size()-1; i>=0; i--)
    {
       
        u.insert(u.end(),v[i]);

    }



    return u;
}



int main()
{
    int length;
    cout<<"Please enter the length of the vector:\n";
    cin>>length;

    cout<<"Please enter an enties for the vector:\n";
    std::vector <int> v(length);
    for (int i=0; i<v.size(); i++)
    {
        cin>>v[i];
    }

    cout<<"The element of the vector is :\n";
    for (int c: v)
        cout<<c<<"\t";

    cout<<"\nThe reverse order of the vector is :\n";
    v=reverse1(v);
    for (int c: v)
        cout<<c<<"\t";

    return 0;
}
