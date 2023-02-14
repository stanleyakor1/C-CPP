#include<iostream>
#include<cmath>
#include<limits>


//Potential energy due to a system of charges

using namespace std;

const double e_o = 8.854187817*1e-12;
class Potential{
public:
    // charge at origin
    float Posx,Posy;
    float Inf;
    float c1,px,py;
    double potential,dist;
    
    // reference point charge
    Potential(float pos1,float pos2){
        Posx = pos1;
        Posy = pos2;
        potential = 0;
        Inf = numeric_limits<float>::infinity();


    }

    //surounding charges
    void NewCharge(float charge,float npos1,float npos2){
        c1 = charge;
        px=npos1;
        py= npos2;

        dist = sqrt(abs((Posx-px)*(Posx-px)- (Posy-py)*(Posy-py)));
        if(dist ==0){
           if(c1>=0){
            potential+=Inf;
           }

           else{
            potential+=Inf*-1;
           }

        }
        potential+=(c1/dist)*1.0/(4*3.142*e_o);

    }

    double getPotential(){
        return potential;
    }


};

int main(){
   double q,x,y;
   string ans;
   cout<<"Enter the distance (x) and distance(y) of the reference charge: ";
   cin>>x>>y;

   Potential potential = Potential(x,y);
   Potential* ths=&potential;

    //calculate the potential of charges due to the origin or reference charge
   cout<<"Enter the neighbouring charge magnitude (q), distance (x) and distance(y): ";
   cin>>q>>x>>y;

   ths->NewCharge(q,x,y);

   cout<<"Do you wish to continue? (yes/no): ";
   cin>>ans;

   while(ans=="yes"){
    cout<<"Enter the neighbouring charge magnitude (q), distance (x) and distance(y): ";
    cin>>q>>x>>y;

    ths->NewCharge(q,x,y);

    cout<<"Do you wish to continue? (yes/no): ";
    cin>>ans;

   }

cout<<"The electric potential due to the system of charges is: "<<ths->getPotential()<<endl;
    return 0;
}