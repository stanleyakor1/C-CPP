#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;

/////////////////////////////////////////////////////
//                                                  /
// 1-D advection equation using the upwind scheme!  /
//         du/dt(x,t)+(x+1)du/dx(x,t)=0             /
//         u(x,0)=x+1, x \in [0,1]                  /
//         u(0,t) = exp(-t)  t\in [0,1]             /
//                                                  /
//                                                  /
//                                                  /
//     Exact soln:     u(x,t) = (x+1)exp(-t)        /
/////////////////////////////////////////////////////

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
vector<double>  MaxError(double *a,double *b,int nrows,int ncols){
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

int main(){
    float x1=0,x2=1,t1=0,t2=1;
    ofstream outfile;
    double dx,h;
   
    vector<double> x,t,cfl;
   
    cout<<"Enter the spatial and temporal step sizes (dx,h): ";
    cin>>dx>>h;

    x=arrange(x1,x2,dx);
    t=arrange(t1,t2,h);

    int N_t =t.size(), N_x = x.size();
    double Approx[N_t][N_x];
    double Exact[N_t][N_x];

    //vector < vector<int> >

    // Initial condition
    for(int i=0;i<x.size();i++){
        Approx[0][i] = x[i]+1;
        cfl.push_back((1+x[i])*(h/dx));
    }

    // Boundary condition
    for(int i=0;i<t.size();i++){
        Approx[i][0]= exp(-t[i]);
    }

    // CFL Condition
    for(int i=0;i<cfl.size();i++){
        if(cfl[i]>1){
            cout<<"Cannot solve the given upwind scheme with the choosen step sizes"<<endl;
            exit(0);
        }
       
    }
   
    // Approximate soln
    for(int i=0;i<t.size()-1;i++){
        for(int j=1;j<x.size();j++){
        Approx[i+1][j]=Approx[i][j]- cfl[j]*Approx[i][j]+cfl[j]*Approx[i][j-1];
        }
    }

    // Exact soln
    for(int i=0;i<t.size();i++){
        for(int j=0;j<x.size();j++){
        Exact[i][j]=(x[j]+1)*exp(-t[i]);
        }
    }

    //Error
    vector<double> error;
    double Maxx_Error;
   

    error =  MaxError((double*)Approx,(double*)Exact,t.size(),x.size());
    Maxx_Error =MaxinArray(error);

    cout<<"Maximum error in the scheme with the chosen step size is: "<<Maxx_Error<<endl;

    //write solution to a txt file
    outfile.open("1D_advection.txt");
    for(int i=0;i<t.size();i++){
        for(int j=0;j<x.size();j++){
            outfile<<Approx[i][j]<<" ";    
      }
       outfile<<endl;
    }    
}