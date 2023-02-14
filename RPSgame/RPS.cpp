#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;
class Contestant{

public:
    string Name;
    int score ;
    Contestant(string name){
        Name = name;
          
    }

    
    void setScore(){
        score=0;
    }

    void Win(){
        score = score+1;
    }
    int getScore(){
        return score;
    }

    void setName(string name){
        Name = name;
    }

    string getName(){
        return Name;
    }


};

class Human: public Contestant{
public:
    string Choice;
    
    Human(string name,string choice):
     Contestant(name){
        Choice = choice;

     }



};

class Computer: public Contestant{
public:
    vector< string >  arr;
    Computer(string name):
     Contestant(name){

        arr.push_back("rock");
        arr.push_back("scissors");
        arr.push_back("paper");
     }


     string randy(){
        srand((unsigned) time(0));
        int randomNumber = rand()%3;
        
        return arr[randomNumber];

     }




};



string checker(string x,string y);
int main(){

    int Tries = 0;

    string man,pc,mchoice,pchoice,cond;

    cout<<"Enter the name of human: ";
    cin>> man;

    

    cout<<"Enter the name of computer: ";
    cin>> pc;
    

    //////

    Human human = Human(man,mchoice);

    Computer comp = Computer(pc);

     // initialize scores
    comp.setScore();
    human.setScore();


    while(true){
        cout<<endl;
        cout<<human.getName()<<","<<" enter you choice: ";
        cin>>mchoice;
        pchoice = comp.randy();

        cout<<comp.getName()<<","<<" chooses "<<pchoice<<endl;

        cond = checker(mchoice,pchoice);

        if(cond=="T"){
            human.Win();
        }
        else if(cond=="F"){
            comp.Win();
        }
        
        cout<<human.getName()<<": "<<human.getScore()<<" "<<comp.getName()<<" :"<<comp.getScore()<<endl;

        Tries+=1;

        if(Tries>2){
            break;
        }
        

    }


    cout<<endl;
    if (human.getScore() == comp.getScore()){
        cout<<human.getName()<<" and "<<comp.getName()<<" TIE"<<endl;
    }
    else if (human.getScore()>comp.getScore()){
        cout<<human.getName()<<" WINS"<<endl;
    }
    else{
        cout<<comp.getName()<<" WINS"<<endl;
    }


    return 0;

}


string checker(string x,string y){
    string Tru= "T",Fals= "F",Non= "N";
    if(x==y){
        return Non;
    }
    else if((x=="rock" && y == "scissors")||(x=="scissors" && y=="paper")|| (x=="paper"&& y=="rock")){
        return Tru;
    }
    else{
        return Fals;
    }
}
