#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    int corners;

    int j = 2, k = 0, l = 0, i;

    ifstream input;

    input.open("input.txt");

    input >> corners;

    int lines = corners - 3 + corners;

    int triangles = corners - 2;

    int x[corners], y[corners];

    double a, b, c, p, distance[lines], area[triangles], totalArea = 0;

    for(int i = 0; i < lines; i++){

        input >> x[i] >> y[i];

        if(i>0 && k==0){

            distance[i] = sqrt(pow(x[i]-x[i-1],2)+pow(y[i]-y[i-1],2));

            //cout << distance[i] << endl;

        }else if(i>0 && k==1){

            distance[i] = sqrt(pow(x[i]-x[i-1],2)+pow(y[i]-y[i-1],2));

            //cout << distance[i] << endl;

            i++;

            distance[i] = sqrt(pow(x[0]-x[0+j],2)+pow(y[0]-y[0+j],2));

            j+=2;

            //cout << distance[i] << endl;

            a = distance[i-2];

            b = distance[i-1];

            c = distance[i];

            //cout<<a<<endl<<b<<endl<<c<<endl;

            p = (a+b+c)/2;

            area[l] = sqrt(p*(p-a)*(p-b)*(p-c));

            //cout << area[l] << endl;

            totalArea += area[l];

            l++;

        }else if(i>0 && k>1){

            distance[i] = sqrt(pow(x[i]-x[i-2],2)+pow(y[i]-y[i-2],2));

            //cout << distance[i] << endl;

            i++;

            distance[i] = sqrt(pow(x[0]-x[0+j],2)+pow(y[0]-y[0+j],2));

            j+=2;

            //cout << distance[i] << endl;

            a = distance[i-2];

            b = distance[i-1];

            c = distance[i];

            //cout<<a<<endl<<b<<endl<<c<<endl;

            p = (a+b+c)/2;

            area[l] = sqrt(p*(p-a)*(p-b)*(p-c));

            //cout << area[l] << endl;

            totalArea += area[l];

            l++;

        }

        if(i > 0){

            k++;

        }

    }

    ofstream output;

    output.open("output.txt");

    output << totalArea << endl;

    input.close();

    output.close();

    return 0;
}
