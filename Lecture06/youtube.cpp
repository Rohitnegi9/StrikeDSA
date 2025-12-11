#include<iostream>
using namespace std;


void youtube(string photo, string title, int views, int time){
    cout<<"Print the thumbnail "<<photo<<endl;
    cout<<"Print the title "<<title<<endl;;
    cout<<"Print the views "<<views<<endl;
    cout<<"Print the Upload time "<<time<<endl;
}

int main(){ 
    
    string photo1= "phot.jpg", title1 = "Hook1", photo2 = "phot2.jpg", title2 = "React";
    int views1 = 420, time1 = 3, views2 = 500, time2 = 7;
     
    youtube(photo1,title1,views1,time1);
    youtube(photo2,title2,views2,time2);

    // cout<<"Print the thumbnail "<<photo1<<endl;
    // cout<<"Print the title "<<title1<<endl;;
    // cout<<"Print the views "<<views1<<endl;
    // cout<<"Print the Upload time "<<time1<<endl;





}

