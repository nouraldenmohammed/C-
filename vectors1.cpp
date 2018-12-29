#include<iostream>
#include<vector>
#include<tuple>
using std::cout;
using std::cin;
using std::endl;

std::tuple<double,double> max_min(std::vector<double> v)
{

    double max1=-10000000,min1=100000000;
    for (double c:v)
    {
        if (c<min1) min1=c;
        if(c>max1) max1=c;

    }



    return {max1,min1};
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

    double m,l;

    std::tie(m,l)=max_min(v);
    cout<<"The maximum number in the vector is :"<<m<<"\nand the minimum one  is :"<<l<<"\n";

    return 0;
}
