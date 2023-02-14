#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
vector<double> arrange(float a,float b,double h){
    vector<double> vec;
    int N = (b-a)/h;
    for(int i=0;i<=N;i++){
        vec.push_back(a+i*h);
    }

    return vec;
}
vector<double> linspace(float a,float b,int N){
    vector<double> vec;
    double h = (b-a)/N;
    for(int i=0;i<=N;i++){
        vec.push_back(a+i*h);
    }
    return vec;

}
const int c=1;
int main(){
    float dx=0.1, T=1, m_u = 0.2;
    float dt = (dx*m_u)/c;
    vector<double> t,x,BC;
    ofstream outfile,t_axis,x_axis;

    x=arrange(-2,3+dx,dx);
    t=arrange(0,T,dt);

    double matrix[t.size()][x.size()];
    
    //Boundary condition
    for(int j=0;j<t.size();j++){
            matrix[j][0]=0;
            matrix[j][x.size()-1]=0;

        }
   

    // initial condition
    for(int i=0;i<t.size();i++){
        if(abs(x[i])<=1){
            matrix[0][i]=1-abs(x[i]);
        }
        else{
            matrix[0][i]=0;
        }
    }

    for(int i=0;i<t.size()-2;i++){
        for(int j=1;j<=x.size();j++){
            matrix[i+1][j]= matrix[i][j]-m_u*matrix[i][j]+m_u*matrix[i][j-1];
        }
    }


    outfile.open("1d-advection2.txt");
    
    for(int i=0;i<t.size();i++){
        for(int j=0;j<x.size();j++){
            outfile<<matrix[i][j]<<" ";    
      }
       outfile<<endl;
    } 

    t_axis.open("t-axis.txt");
    for(int i=0;i<t.size();i++){  
      t_axis<<t[i]<<" ";
    }   

    x_axis.open("x-axis.txt");
    for(int j=0;j<x.size();j++){
        x_axis<<x[j]<<" ";           
      }
   
    return 0;
}