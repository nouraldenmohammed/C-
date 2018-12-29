/*
This solution consist of the parts a ,b and c.
*/


#include<iostream>
#include<vector>
#include<fstream>
#include <sstream>
#include<string>
#include<array>
using std::cout;
using std::cin;
using std::endl;

/*
This program read the data from the user using terminal or it has default input source
which is convex-hull-points.txt .

*/

//Defining an object from fstream to deal with the file

std::fstream file;


/*
read_point() is function that return an array of size 2 of type double.
It receive string and extract the points from the string.
*/

std::array<double,2> read_point(std::string a)
{

    std::stringstream ss;
    ss<<a;

    std::array<double,2> A;
    std::string x;
    int i=0;
    while(!ss.eof())
    {

        //Solution of part each, since  each point stored in array of size 2
        ss>>a;
        A[i]=stod(a);
        i++;
    }
    return A;
}

/*

The function read_problem it reads the points from a file.
the first line in the file represent the number of the points,
so we will use this length to create vector of array of this length.
*/

std::vector<std::array<double,2>> read_problem(std::string file_name)
{
    file.open(file_name);
    std::vector<std::array<double,2>> v;
    if (file.is_open())
    {
        std::string a,b;
        int length;
        //while(!file.eof())
        //int c=0;
        getline(file,a);

        length=stoi(a);




        for (int i=0; i<length; i++)
        {
            getline(file,a);
            v.push_back(read_point(a));
        }


    }
    else cout<<"Unable to open the file or the file does not exit.\n";
    file.close();

    return v;

}


int main(int argc, char *argv[])
{

    std::string filename;
    if (argv[1]!=NULL)
    {
        //if the user give the name of the file from the terminal

        filename=argv[1];
    }
    else
    {
        //The default file name.
        filename="convex-hull-points.txt";
    }
     std::vector<std::array<double,2>> v=read_problem(filename);


    //Print the points inside the vector v

    cout<<"The points are:\n";
    cout<<"x\t\ty\n";
    cout<<"-------------------\n";
    for(auto c:v)
    {
        for (auto j:c)
        {
            cout<<j<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
