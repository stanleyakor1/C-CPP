#ifndef MAIN_H
#define MAIN_H

#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
// does the same thing as a python linspace function
vector<double> linspace(float a,float b,int N){
    vector<double> vec;
    double h = (b-a)/N;
    for(int i=0;i<=N;i++){
        vec.push_back(a+i*h);
    }
    return vec;

}

// does the same thing as a python arrange function
vector<double> arrange(float a,float b,double h){
    vector<double> vec;
    int N = (b-a)/h;
    for(int i=0;i<=N;i++){
        vec.push_back(a+i*h);
    }

    return vec;
}

// computes the maximum error for each row and saves it in a vector
vector<double>  Infnorm(double *a,double *b,int nrows,int ncols){
    vector<double> error;
    double max_colerror;
   
    for(int i=0;i<nrows;i++){
        max_colerror = 0;

        for(int j=0;j<ncols;j++){

       
      if(abs(*((a+i*ncols) + j)-*((b+i*ncols) + j))>max_colerror)
      {
         max_colerror =abs(*((a+i*ncols) + j)-*((b+i*ncols) + j));      
      }
       

    }
    error.push_back(max_colerror);
    }
    return error;
}


//computes the max value in a vector
double MaxinArray(vector<double> &vec){
    int N =vec.size();
    double maxx = vec[0];
    for(int i=1;i<N;i++){
        if(vec[i]>maxx){
            maxx=vec[i];
        }
    }
    return maxx;
}
#endif  // MAIN_H
