#include<iostream>
using namespace std;

int main(){

    // 5 students, store the marks of 5 students
    // 100 students ke marks ko store karna hai, average of all students marks??

    // int marks1 = 70, marks2 = 80, marks3 = 40, marks4 = 50, marks5 = 90;

    // cout<<marks1<<endl;
    // cout<<marks2<<endl;
    // cout<<marks3<<endl;
    // cout<<marks4<<endl;
    // cout<<marks5<<endl;

    
    // // int sum = 0;
    // // for(int i=0;i<5;i++){
    // //     sum+=marks1;
    // // }

    // cout<<(marks1+marks2+marks3+marks4+marks5)/5<<endl;
    
    // array size ko declare, type
    // int marks[5] = {70,80,40,50,90};

    // // cout<<marks[2]<<endl;
    // cout<<marks[0]<<endl;
    // cout<<marks[1]<<endl;
    // cout<<marks[2]<<endl;
    // cout<<marks[3]<<endl;
    // cout<<marks[4]<<endl;



    // for(int i=0;i<5;i++){
    // cout<<marks[i]<<endl;
    // }
    
    // array ko declare kar sakte
    // int arr[3];

    // arr[0] = 5;
    // arr[1] = 7;
    // arr[2] = 2;


    // for(int i=0;i<3;i++){
    //     cout<<arr[i]<<endl;
    // }

    // first value hi insert kari, baaki sab zero ban jaayenge
    // int arr[4] = {12};

    // for(int i=0;i<4;i++){
    //     cout<<arr[i]<<endl;
    // }


    // array, index zero se start kyon hota hai?
    // int arr[10]
    // int n;
    // cin>>n;
    // int arr[n];
    

    // int n;
    // cout<<"Tell me the size of an array\n";
    // cin>>n;

    // int arr[8];

    // cout<<"Enter the value in array";
    // for(int i=0;i<8;i++){
    //     cin>>arr[i];
    // }


    // for(int i=0;i<8;i++){
    //     cout<<arr[i]<<endl;
    // }


    // int a = 10;
    // int b = 10;

    // b = 20;
    // a = 50;

    // cout<<&a<<endl;
    // cout<<&b<<endl;
//    Linear search
    int marks[5] = {70,80,40,30,20};
    
    int student_mark = 10;

    // for(int i=0;i<5;i++){
    //     if(student_mark==marks[i]){
    //         cout<<"YES";
    //         return 0;
    //     }
    // }


    

    // cout<<"No"<<endl;
//     found= true??
   bool found = false;

   for(int i=0;i<5;i++){
    if(marks[i]==student_mark){
        found = true;
        break;
    }
   }


   if(found){
    cout<<"Yes";
   }
   else
   {
    cout<<"No";
   }





    // 
    // int heightest = marks[0];
    // int index = 0;

    // for(int i=1;i<5;i++){
    //     if(marks[i]>heightest){
    //         heightest = marks[i];
    //         index = i;
    //     }
    // }

    // cout<<heightest<<endl<<index<<endl;


    // search

    // Heighest marks class mein kiske hai?

    // int sum = 0;

    // for(int i=0;i<5;i++){
    //     sum+=marks[i];
    // }

    // cout<<sum/5<<endl;

    // int a = 10;
    // cout<<&a;

    // for(int i=0;i<5;i++){
    //     cout<<&marks[i]<<endl;
    // }

    return 0;
}


// Find minimum element in an array
// Reverse the array