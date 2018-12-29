#include <iostream>
#include <stack>
#include<array>
#include <stdlib.h>
#include<vector>
#include<fstream>
#include <sstream>
#include<tuple>
#include<string>
#include<math.h>
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std:: string;


//----------------------------------------------------

std::fstream file;

array<double,2> read_point(string a)
{
    std::stringstream ss;
    ss<<a;
    array<double,2> A;
    string x;
    int i=0;
    while(!ss.eof())
    {
        ss>>a;
        A[i]=stod(a);
        i++;
    }
    return A;
}



std::tuple<std::vector<array<double,2>>,int> read_problem(string file_name)
{
    file.open(file_name);
    int length;
    std::vector<array<double,2>> v;
    if (file.is_open())
    {
        std::string a,b;

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

    return {v,length};
}
//----------------------------------------------------


// A global point p0 needed be as reference point  to sort the points
// by  using compare function in qsort()
array<double,2> p0;

// Function to return the point next to top in a stack
array<double,2> next_to_top(std::stack<std::array<double,2>> S)
{
    array<double,2> p = S.top();
    S.pop();
    array<double,2> temp = S.top();
    S.push(p);
    return temp;
}

//The euclidean distance
int equilidian_distance(array<double,2> p1, array<double,2> p2)
{
    return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) +
                (p1[1] - p2[1])*(p1[1] - p2[1]));
}

/* ccw of ordered triplet points.
If ccw==0 : the point3 colinear
if ccw>0 :the point3 is counter clock wise.
else is clock wise

*/
string ccw(array<double,2> point_1, array<double,2> point_2, array<double,2> point_3)
{
    double test = (point_2[1] - point_1[1]) * (point_3[0] - point_2[0]) -(point_2[0] - point_1[0]) * (point_3[1] - point_2[1]);

    if (test == 0) return "colinear";
    if (test > 0)
        return "counter-clockwise";
    else return "clockwise";
}


int compare(const void *vp1, const void *vp2)
{
    array<double,2> *p1 = (array<double,2> *)vp1;
    array<double,2> *p2 = (array<double,2> *)vp2;

    // Find ccw
    string o = ccw(p0, *p1, *p2);
    if (o == "coliear")
        return (equilidian_distance(p0, *p2) >= equilidian_distance(p0, *p1))? -1 : 1;

    return (o == "clockwise")? -1: 1;
}


void convex_hull(std::vector<array<double,2>> points, int n)

{

   // Find the point has smallest y coordinate
    double ymin =points[0][1];
    int min = 0;
    for (int i = 1; i < n; i++)
    {
        double y = points[i][1];

        if ((y < ymin) || (ymin == y &&
                           points[i][0] < points[min][0]))
            ymin = points[i][1], min = i;
    }

    // Swap pint0 with smallest point
    swap(points[0], points[min]);

    // Sort the points respect to p0
    p0 = points[0];
    qsort(&points[1], n-1, sizeof(array<double,2>), compare);

    //  keeping the farthest point  from p0

    int m = 1;
    for (int i=1; i<n; i++)
    {

        while (i < n-1 && ccw(p0, points[i],points[i+1]) == "coliear")
            i++;


        points[m] = points[i];
        m++;
    }


    if (m < 3) return;
    std::stack<array<double,2>> S;
    S.push(points[0]);
    S.push(points[1]);
    S.push(points[2]);

    for (int i = 3; i < m; i++)
    {

        while (ccw(next_to_top(S), S.top(), points[i]) != "clockwise")
            S.pop();
        S.push(points[i]);
    }

    //Creating a file to store the indices of the convex hull points.
    int index=0;
    std::fstream new_file;
    new_file.open("indices_of_the_points.txt",std::ios::out);
    new_file<<"Index:\t x coordinate\t ycoordinate\n";
    new_file<<"-------------------------------------\n";
    while (!S.empty())
    {


        array<double,2> p = S.top();
        new_file<<index<<":\t"<< p[0] << "\t " << p[1]<< endl;
        cout << p[0] << "\t " << p[1]<< endl;
        S.pop();
        index++;
    }
    new_file.close();
}


int main(int argc, char *argv[])
{

    std::vector<std::array<double,2>> v;
    int length;

    string filename;
    if (argv[1]!=NULL)
    {

        filename=argv[1];
    }
    else
    {
        filename="convex-hull-points.txt";
    }
    std::tie( v,length)=read_problem(filename);

    convex_hull(v,length);

    return 0;
}
