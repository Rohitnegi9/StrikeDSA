#include<iostream>
using namespace std;

void findGrade(int marks){
    
    if(marks>90){
        cout<<"Grade: A+"<<endl;
    }
    else if(marks>80){
        cout<<"Grade: A"<<endl;
    }
    else if(marks>70){
        cout<<"Grade: B+"<<endl;
    }
    else if(marks>60){
        cout<<"Grade: B"<<endl;
    }
    else{
        cout<<"Grade: C"<<endl;
    }

}


int main(){
   
    int student1 = 78, student2 = 93, student3 = 40;


    findGrade(student1);
    findGrade(student2);
    findGrade(student3);

    // same code
    // same code 
    // same code


    return 0;
}