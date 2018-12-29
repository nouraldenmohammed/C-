#include<iostream>
#include<vector>
#include<tuple>
using std::cout;
using std::cin;
using std::endl;

std::vector<int> reverse1(std::vector<int> v)
{
    //Storing the reversed vector in the vector itself

    for (int i=0,j=v.size()-1; i<v.size()/2,j>v.size()/2; i++,j--)
    {
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
    }



    return v;
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
