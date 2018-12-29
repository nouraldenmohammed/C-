#include<iostream>
#include<vector>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;

std::vector<double> rounded_vector(std::vector<double> v)
{

    for (int i=0; i<v.size(); i++)
    {
        v[i]=std::round(v[i]);
    }



    return v;
}



int main()
{
    int length;
    cout<<"Please enter the length of the vector:\n";
    cin>>length;
    cout<<"Please enter an enties for the vector:\n";
    std::vector <double> v(length);
    for (int i=0; i<v.size(); i++)
    {
        cin>>v[i];
    }

    cout<<"The orginal elements of the vector is :\n";
    for (double c: v)
        cout<<c<<"\t";

    cout<<"\nThe rounded elemnets of the vector is :\n";
    v=rounded_vector(v);
    for (double c: v)
        cout<<c<<"\t";

    return 0;
}
