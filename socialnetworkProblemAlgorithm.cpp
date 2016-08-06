#include <iostream>
#include<string>
#include<vector>
using namespace std;
char user[5] = {'a','b','c','d','e'};
vector< vector<int> >  eL;
  vector<int> eLrow;
int pos(char t)
{
    int i;
    int p = 999;
    
    for(i=0;i<5;i++)
    {
        cout<<i<<"::p  = "<<p<<endl;
        if(t == user[i]){
            p = i;
            break;
        }
        else{
        p = 0;
        }
    }
    return p ;
}
int isOldUser(int u,int n ,vector<int> oldUser)
{
    int r =0;
    for(int i=0;i<oldUser.size();i++)
    {
    if(u==oldUser[i])
    r = 1;
    else if(n==oldUser[i])
    r=1;
    }
    return r;
    
}
void generate(int curr, vector<int> oldUser,int next = 999)
{
    
    
    //cout<<curr<<" :: "<<next<<endl;
    if(isOldUser(curr,next,oldUser) || next ==999)
    {
    //cout<<"oldUser ::";
    /*for(int k =0;k<oldUser.size();k++)
    cout<<oldUser[k]<<"  ";
    cout<<endl;*/
    return;
    }
    int count = 0;
    oldUser.push_back(curr);
   
    vector<int> final;
    while(count != eL[next].size()){
        
   // cout<<curr<<" :: "<<next<<endl;
    generate(next,oldUser,eL[next][count]);
    final.push_back(next);
    
    count ++ ;
    }
    cout<<"final:: ";
    for(int o =0;o<final.size();o++)
    {
        
        cout<<final[o]<<"  ";
    }
    cout<<endl;
    
}
 
int main() {
    
    int size;
    int matrix[5][5] = {0};
    int i,j;
    vector<int> listL;
   
   
     
    
    
    for(i=0;i<5;i++)
    {
        cout<<"Enter size of contact list of "<<user[i]<<"::"<<endl;
        cin>>size;
        listL.push_back(size);
        for(j=0;j<size;j++)
        {
            char temp;
            cin>>temp;
            matrix[i][pos(temp)] = 1;
        }
        
    }
    int k ;
    for(i=0;i<5;i++)
    {

        //cout<<"User :: "<<user[i]<<endl<<"Contactlist:: "<<endl;
        /*for(j=0;j<5;j++)
        {
            cout<<matrix[i][j]<<"  ";
            
        }
        cout<<endl;*/
        //listL[i] +=listL[i-1];
        //k=listL[i];
    }
    for(i=0;i<5;i++)
    {
        
        for(j=0;j<5;j++)
        {
             eL.push_back(eLrow);
            if(matrix[i][j] == 1)
            {
                eL[i].push_back(j);
                
            }
           
        }
    }
    /*for(i = 0;i<5;i++)
    {   cout<<i<<" ";
        for(j =0 ;j<eL[i].size();j++)
        cout<<"  : "<<eL[i][j];
        cout<<endl;
    }*/
    
    vector<int> oldUser;
    
    for(i=0;i<5;i++)
    {
        int count = 0;
        cout<<"user = "<<i<<endl;
        
        while(count != eL[i].size()){
        generate(i,oldUser,eL[i][count]);
        //cout<<i<<" :: "<<eL[i][count]<<endl;
        count++;
        }
    }
    
	// your code goes here
	return 0;
}
