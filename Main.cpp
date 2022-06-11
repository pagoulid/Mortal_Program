#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <stdlib.h> 
#include "Tournament.cpp"


using namespace std;

int main(int argc , char *argv[]){
   

   
    List MyList;
    
    MyList.Create_List(argc-1,argv);
   
    Tournament* T = new Tournament(MyList);// why tournament*??
    int phase = 1;
    while(T->Max_Lang.empty()||T->Max_Lang.size()>1){
        
        cout<<"                 PHASE  "<<phase<<" OF TOURNAMENT"<<endl;
        
        //cout<<"start of List  :  "<<T->start->nxt->res<<endl;
        T->SetKombats();
        T->Display();
        cout<<'\n';
        // define new list according to max lang
        if(T->Max_Lang.size()>1){
             List newList;
            newList.Create_List(T->Max_Lang.size(),T->Max_Lang);


            // destroy current tournament and save new
            //destroy
            delete T;
            T = new Tournament(newList);
            phase++;

        }
       

    }
    
    
   
}

