#include <iostream>
#include <string>
#include <iomanip>

// a password verifier
using namespace std;
class Password{
private:
    // anything defined here will not be accessible by clients
    string key = "abcdefgh";
public:
    string typepas;

    //constructor
    Password(string Password){
        typepas = Password;
    }

    bool check(){
        if(typepas == key){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    string input;
    int Tries = 1, MAx_attempt = 4;

   
    cout<<"Enter your password: ";
    cin>> input;

    Password  pas =Password(input);

    if(pas.check()){
        cout<<"Login credentials are Okay!"<<endl;
    }
    
    while(!pas.check())
    {
    cout<<"Wrong password"<<endl;
    cout<<"Enter your password: ";
    cin>> input;
    pas =Password(input);

    if(pas.check()){
        cout<<"Login credentials are Okay!"<<endl;
        break;
    }

    Tries+=1;
    if(Tries == MAx_attempt){
        cout<<"You are temporarily blocked from signing in!"<<endl;
        break;
    }

    }
  

}