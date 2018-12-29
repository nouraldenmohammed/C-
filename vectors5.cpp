#include<iostream>
#include<vector>
#include<tuple>
using std::cout;
using std::cin;
using std::endl;

std::vector<int> reverse1(std::vector<int> v)
{

    for (int i=0,j=v.size()-1;i<v.size()/2,j>v.size()/2;i++,j--){
std::swap(v[i],v[j]);
}



    return v;
}



int main()
{

    cout<<"Please enter an enties for the vector:\n";
    std::vector <int> v(10);
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
