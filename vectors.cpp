#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::endl;




int main()
{
    int length;


    cout<<"Please enter the length of the vector:\n";
    cin>>length;


    std::vector <int> v(length);
    cout<<"The defualt values the entries have when we not specify an explicit value:\n";
    for (int c: v)
        cout<<c<<"\t";

    cout<<endl;


    cout<<"Please enter an enties for the vector:\n";
    for (int i=0; i<v.size(); i++)
    {
        cin>>v[i];
    }
    cout<<"The entries of the vector are:\n";
    for (int c: v)
        cout<<c<<"\t";

    cout<<endl;
    return 0;
}
