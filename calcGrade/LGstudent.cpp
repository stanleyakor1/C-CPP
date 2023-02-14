#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

using namespace std;

class Igstudent{
public:
    string Name;
    double Midterm,Final;

    // constructor
    Igstudent(string name,double midterm,double finals){
        Name = name;
        Midterm = midterm;
        Final = finals;
    }

    // Methods

    void setName(string name){
        Name = name;
    }

    string getName(){
        return Name;
    }

    void setMidterm(double midterm){
        Midterm = midterm;
    }

    double getMidterm(){
        return Midterm;
    }

    void setFinal(double final){
        Final = final;
    }

    double getFinal(){
        return Final;
    }


    virtual string calcGrade(){
        string A="A",B="B",C="C",D="D",F="F";
        double grade = (Midterm+Final)/2.0;
        if(grade>=90.0){
            return A;
        }
        else if(grade<90.0 && grade >=80.0){
            return B;
        }
        else if(grade<80.0 && grade>=70.0){
            return C;
        }
        else{
            return D;
        }
    
    }
};

class PFstudent: public Igstudent{
    public:
        PFstudent(string name,double midterm,double final):
         Igstudent(name,midterm,final){
         }
         

         string calcGrade(){
            string pass = "Pass", fail = "Fail";
            double grade;
            grade = (Midterm+Final)/2.0;

            if(grade>=60){
                return pass;
            }
            else{
                return fail;
            }
         }

};


// WE ARE NOT ADDING ANY NEW FEATURES NOR CHANGING THE EXISTING ONES!
class LGstudent: public Igstudent{
    public:
        LGstudent(string name,double midterm,double final):
         Igstudent(name,midterm,final){
         }
};

int main(){
  
    string name,ask,category,LG="LG",PF="PF",cat,space=" ";
    int max_size,pf_count=0,lg_count=0;
    double mid,fin;
    
    vector< string > arr_name;
    vector< double > arr_mid;
    vector< double > arr_final;
    vector<string> arr_cat;
    vector<string> result;
    
    

    cout<<"Enter the student's name: "<<endl;
    cin>>name;
    cout<<"Enter the student's grade on midterm: "<<endl;
    cin>>mid;

    cout<<"Enter the student's grade on final: "<<endl;
    cin>>fin;

    cout<<"Enter category (LG or PF): ";
    cin>>cat;

    if(cat==LG){
        arr_cat.push_back(LG);

    }
    else{
        arr_cat.push_back(PF);
    }

    cout<<"Do you want to continue?(Y/N): "<<endl;
    cin>>ask;
    //Igstudent student = Igstudent("name",mid,fin);
    arr_name.push_back(name);
    arr_mid.push_back(mid);
    arr_final.push_back(fin);

    while (ask=="Y")
    {
    cout<<"Enter the student's name: "<<endl;
    cin>>name;

    cout<<"Enter the student's grade on midterm: "<<endl;
    cin>>mid;

    cout<<"Enter the student's grade on final: "<<endl;
    cin>>fin;

    cout<<"Enter category (LG or PF): ";
    cin>>cat;

    cout<<"Do you want to continue?(Y/N): "<<endl;
    cin>>ask;

    arr_name.push_back(name);
    arr_mid.push_back(mid);
    arr_final.push_back(fin);

    if(cat==LG){
        arr_cat.push_back(LG);

    }
    else{
        arr_cat.push_back(PF);
    }

    }

   
    
    //IMPLEMENTATION

    for(int i=0;i<arr_name.size();i++){
        if(arr_cat[i]==LG){
            lg_count+=1;
            LGstudent lgstudent = LGstudent(arr_name[i],arr_mid[i],arr_final[i]);
            result.push_back(lgstudent.getName() + space + lgstudent.calcGrade());
            //cout<<student.getName()<<setw(7)<<student.calcGrade()<<endl;
        }
        else{
            pf_count+=1;
            PFstudent pfstudnet = PFstudent(arr_name[i],arr_mid[i],arr_final[i]);
            result.push_back(pfstudnet.getName() + space+ pfstudnet.calcGrade());

        }
        
        

    }
    cout<<"NAME"<<setw(7)<<"GRADE"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    cout<<"Number of letter-grade students: "<<pf_count<<endl;
    cout<<"Number of pass-fail students: "<<lg_count<<endl;
    

    
}

