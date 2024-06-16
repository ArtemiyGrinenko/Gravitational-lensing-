//
//  main.cpp
//  qwertyuiop1
//
//  Created by Artemiy Рр on 10/11/22.
//
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <vector>
#include <time.h>
#include <math.h>
#include <stdio.h>
//#include <omp.h>
#include <unistd.h>
#include <sys/types.h>


using namespace std;
using std::string;
using std::vector;
using std::ifstream;
using std::istringstream;
using std::cout;


vector<vector<double>> set ;
vector<vector<double>> X0 ;
vector<double> sum;

double h = 390000;//(* высота цилиндра *)
double G =6.67430*pow(10,-11)*pow(3.24078e-17,3);//(* гравитационная постоянная *)
double c = 299792458*3.24078e-17;//(* скорость света *)
//double h = 1 ;
//double G = 1 ;
//double c = 1 ;
/*void func(int i, vector <string> *vector1) {
    for(auto el: set[i])
    { vector1->push_back(el);
       }
    }
void func1(int i, vector <string> *vector2) {
    for(auto el: X0[i])
    { vector2->push_back(el);
       }
    }*/

//прицельное расстояние

double d(int i,int l) {
    return sqrt((X0[l][0]*set[i][2]/h -
        set[i][0])*(X0[l][0]*set[i][2]/h - set[i][0]) + (X0[l][1]*set[i][2]/h - set[i][1])*(X0[l][1]*set[i][2]/h - set[i][1]));
}


double alpha (int i , int l ) {
    return  4*G*set[i][3]/(c * c * d(i,l));
}


// кордината после одной звезды
vector<double> Vector1(int i ,int l ) {
    return {X0[l][0] + (set[i][0] - X0[l][0])*alpha(i,1)*set[i][2], X0[l][1] + (set[i][1] - X0[l][1])*alpha(i,1)*set[i][2]};
}


//double
void splitString(const string &fullstr,
                 vector<string> &elements,
                 const string &delimiter) {

    string::size_type lastpos =
        fullstr.find_first_not_of(delimiter, 0);
    string::size_type pos     =
        fullstr.find_first_of(delimiter, lastpos);

    while ( (string::npos != pos) || (string::npos != lastpos) ) {

        elements.push_back(fullstr.substr(lastpos, pos-lastpos));

        lastpos = fullstr.find_first_not_of(delimiter, pos);
        pos = fullstr.find_first_of(delimiter, lastpos);
    }
}

double stringToDouble(const string &str) {

    istringstream stm;
    double val = 0;

    stm.str(str);
    stm >> val;

    return val;
}
//double


void readData(const string &filename,
              const string &csvdelimiter,
              vector< vector<double> > &sarr) {

    ifstream fin(filename.c_str());

    string s;
    vector<string> selements;
    vector<double> delements;

    while ( !fin.eof() ) {

        getline(fin, s);

        if ( !s.empty() ) {

            splitString(s, selements, csvdelimiter);

            for ( size_t i=0; i<selements.size(); i++ ) {

                delements.
                    push_back(stringToDouble(selements[i]));
            }

            sarr.push_back(delements);
            selements.clear();
            delements.clear();
        }
    }

    fin.close();
}


int main(int argc, char** argv)
{
    clock_t tStart = clock();
  
    //fork();
    //vector1.push_back(8);
//string fname;
//string fname1;
//cout<<"Enter the file name: ";
//cin>>fname;
//fname = "/Users/artemiyrr/Desktop/stars.txt";
//fname1 = "/Users/artemiyrr/Desktop/a.csv";
//vector<double> Vector;
//vector<string> row;
//string  word;
//string line;
//vector<string> row1;
//string  word1;
//string line1;
 
    //vector< vector<double> > set;


       readData("/Users/artemiyrr/Desktop/qwertyuiop1/stars2.txt", ",", set);
    

       /*for ( size_t i=0; i<set.size(); i++ ) {

           for ( size_t j=0; j<set[0].size(); j++ ) {

               cout << set[i][j] << "\t";
           }

           cout << "\n";
       }*/
    //vector< vector<double> > X0;
       
    readData("/Users/artemiyrr/Desktop/qwertyuiop1/a2 copy.txt", ",", X0);


/*
    //сумма строк
    double *s;
     int i,j,n;
    n=2;//количество строк
     s=new double [4];
      
       for(j=0;j<=3;j++)
         {s[j]=0;
           for(i=1;i<=n;i++)
               s[j]=s[j]+stod(set[i][j]);
         }
    for(int j=0;j<4;j++)
    {
    cout<<s[j]<<" " ;
    }
 cout<<" \n";
    // вывод
  */
    //Vector = {stod(X0[2][1]) + (stod(set[1][1]) - stod(X0[2][1]))*alpha(1,1)*stod(set[2][3]), stod(X0[2][1]) + (stod(set[2][1]) - stod(X0[2][1]))*alpha(1,1)*stod(set[2][3])
            // };
    
    
    /*
     array = ParallelTable[
       vector[i], {i, 2, k + 1, 1}]; (* List коррдинат после  *)
     CapitalDelta[l_] := {N[Total[array]][[1]],N[Total[array]][[2]]};(* сумма коррдинат после *)
     */
    
    //сумма строк
   /* double *array;
     int i,j,n;
    n=2;//количество строк
     array=new double [4];
      
       for(j=0;j<=3;j++)
         {array[j]=0;
           for(i=1;i<=n;i++)
               array[j]=array[j]+stod(set[i][j]);//array[j]=array[j]+Vector1(a,b)[j]
         }
    for(int j=0;j<=3;j++)
    {
    cout<<array[j]<<" " ;
    }
 cout<<" \n"; */
    int l;
    std::ofstream myfile;
    myfile.open ("/Users/artemiyrr/Desktop/qwertyuiop1/awertyuiop.csv");
    int k = size(X0) - 1;
    double *array ;
    
    cout<<" k : "<<k<<"\n";
    
    for(l = 1; l <= k; l++) {
    //double *array ;
    int i,j;
    int n;
        
    n = size(set) - 1;//количество строк
    array = new double [4];
        
    for(j = 0; j <= 1; j++)
      {array[j]=0;
        for(i=1;i<=n;i++)
        {
            array[j]=array[j]+Vector1(i,l)[j];//array[j]=array[j]+Vector1(a,b)[j]
                    }

          
      }

   //for(int j=0;j<=1;j++)
    //{
    //cout<<array[j]<<" " ;

        //std::ofstream myfile;
              //myfile.open ("/Users/artemiyrr/Desktop/awertyuiop.csv");
              //myfile << array[j]<<",";
        
              //myfile.close();
   //}
        myfile<<array[0]<<","<<array[1]<<"\n";
        //myfile <<"\n";
    cout<<l<<"\n " ;
            
                      
};
    myfile.close();
    
  
    cout<<"\n";
    
    cout<<"vector : "<<Vector1(1,2)[0]<< " " << Vector1(1,2)[1]<<"\n";
    
    cout<<"d(1,1) : " << d(1,1)<<" \n"<< " alpha(1,1) : " <<alpha(1,1)<<"\n" ;

    cout<<"size : "<<" "<<size(set)-1<<"\n";

    cout<< "set : "<<set[1][0]<<" "<<set[1][1]<<"\n";
    
//cout<<content[0][1]<<" \n " ;// строка столбец
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}

