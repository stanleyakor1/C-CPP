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


    string calcGrade(){
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
//int stlen(string arr[],int sz);
int main(){
    //const int Max_Size = 10;
    string name,ask;
    int max_size;
    
    vector< string > arr_name;
    vector< double > arr_mid;
    vector< double > arr_final;
    double mid,fin;
    cout<<"Enter the student's name: "<<endl;
    cin>>name;
    cout<<"Enter the student's grade on midterm: "<<endl;
    cin>>mid;
    cout<<"Enter the student's grade on final: "<<endl;
    cin>>fin;
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
    cout<<"Do you want to continue?(Y/N): "<<endl;
    cin>>ask;
    arr_name.push_back(name);
    arr_mid.push_back(mid);
    arr_final.push_back(fin);
    }

   // max_size = stlen(arr_name,arr_name.size());
    cout<<"NAME"<<setw(7)<<" GRADE"<<endl;
    for(int i=0;i<arr_name.size();i++){
        Igstudent student = Igstudent(arr_name[i],arr_mid[i],arr_final[i]);
        cout<<student.getName()<<setw(7)<<student.calcGrade()<<endl;

    }
    
}

// int stlen(string arr[],int sz){
//     int  max_s = arr[0].length();
//     for(int i=1;i<sz;i++){
//         if(arr[i].length()>max_s){
//             max_s = arr[i].length();
//         }

//     }
//     return max_s;
// }