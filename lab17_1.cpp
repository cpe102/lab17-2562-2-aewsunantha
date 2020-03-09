//Write your code here
#include<iostream>
#include<fstream>
#include<string>
#include<cctype>
#include<vector>


using namespace std;
string upper(string d){
   int x=0;
    while(d[x]) 
    {
        d[x]=toupper(d[x]);
        x++;
    }
    return d;
}

int main(){
    vector<string> v_name, v_grade;
    ifstream f("name_score.txt");
    string d;
    char name[100];
    int a,b,c;
    int grade;
    int sum;
    while (getline(f,d)){
        sscanf(d.c_str(),"%[^:]:%d %d %d",name,&a,&b,&c);
      
        v_name.push_back(name);
        
        int t=a+b+c;
        string grade;
        if(t>=80) grade="A";
        else if(t>=70) grade="B";
        else if(t>=60) grade="C";    
        else if(t>=50) grade="D"; 
        else grade="F"; 

         v_grade.push_back(grade);

    }

    while (true)
    {
      
        cout <<"Please input your command :";
        getline(cin,d);
        int idx =d.find_first_of(" ");
        string s1 = upper(d.substr(0,idx));
        string s2 = upper(d.substr(idx+1,d.size()));
        
     int p=0;
    
        if(s1 =="NAME"){
        cout<<"---------------------------------\n";   
        for(int i=0; i<v_name.size() ; i++){
           
           if(s2 == upper(v_name[i])){
            cout<<v_name[i]<< "'s = " <<v_grade[i]<<'\n';
            p++ ;} 
            
            } if(p==0){ cout<<"Connot found\n";} 
             cout<<"---------------------------------\n";
 } 
        else if(s1 == "GRADE"){
 cout<<"---------------------------------\n";
        for(int i=0; i< v_grade.size() ; i++){
            if(s2 == upper(v_grade[i])){
            cout<<v_name[i]<<"\n";
                }
            } cout<<"---------------------------------\n";
        }
        else if(s1 == "EXIT") break;
        
        else cout<<"Invalid command.\n";
}
        
      
return 0;
}
//      hello
///        score A
//         grade A
//           grade f 
// name sanji
//   name NAMI
//  NAME Franky
// name luffy
//  name monkey d luffy
//  name monkey d. luffy
// exit