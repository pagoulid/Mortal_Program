#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <map>
#include <stdlib.h> // for rand
#include "List.cpp"

using namespace std;

class Tournament{

    public:
        Tournament(List LangList);
        ~Tournament();
        void SetKombats();
        void Display();
        Node* start;
        vector<string> Max_Lang;
        
    private:
        string Get_Expr(string str1,string str2);
        void SwitchCase(int Kombat_res,string lang1,string lang2); // call checkscore due to winner/loser
        void CheckScore(string winner, string loser); // manage scores , find temp max score/langs until final
        void DisplayScores();
        void DisplayKombats();
        void DisplayMax();
        List thisList;
        map<string,int> Kombats; // stores {kombat_i:winner_i(0/1)}
        map<string,int> Scores;  // stores total score for each language
        int Max_Score;
        

        
        

        
        
        
};

Tournament::Tournament(List LangList){
    Max_Score = -1;
    thisList = LangList;
    start = LangList.GetHead();
        
}

Tournament::~Tournament(){
    thisList.DelList();
    Kombats.clear();
    Scores.clear();

}




string Tournament::Get_Expr(string str1,string str2 ){

    
    return "Kombat : "+str1+"/"+str2;
}

void Tournament::DisplayScores(){
    cout<<"SCORE BOARD"<<endl;
    for(auto el:Scores){
        cout<<el.first<<" : "<<el.second<<endl;
        cout<<"\n";
    }

}
void Tournament::DisplayKombats(){
    for(auto el:Kombats){
        cout<<"##############"<<endl;
        cout<<"Kombat : "<<el.first<<endl;
        cout<< "    Winner : "<<el.second<<endl;
        cout<<"##############"<<endl;
        cout<<"\n";
    }
}

void Tournament::DisplayMax(){
    cout<<"         Final Score : "<<Max_Score<<endl;
    cout<<"WINNER(S) OF TOURNAMENT : ";

    for(auto el:Max_Lang){
        cout<<el<<"  ";
    }

}

void Tournament::Display(){
    this->DisplayKombats();
    this->DisplayScores();
    this->DisplayMax();
}
void Tournament::SwitchCase(int Kombat_res,string lang1,string lang2){
     switch(Kombat_res){

                case 0:
                 this->CheckScore(lang1,lang2);
                 break;

                case 1:
                 this->CheckScore(lang2,lang1);
                 break;
            }



}


void Tournament::CheckScore(string winner ,string loser){

    if(Scores.empty()){

        Scores[winner]=3;
        Scores[loser]=0; // if empty init with winner loser score

        // INIT PHASE
        if(Scores[winner]>Max_Score){
            Max_Score=Scores[winner];
            Max_Lang.push_back(winner);
        }


    }else{

        if(Scores.count(winner)>0){
            Scores[winner]+=3;

        }else{
            Scores[winner]=3;


        }

        if(Scores.count(loser)==0){ // (INIT)loser may contest for the first time
            Scores[loser]=0; 

        }

        if(Scores[winner] == Max_Score){ // while winners onn each round has same score it
            //is considered max until a winner succeds greater score
            Max_Lang.push_back(winner);
        }
        else if(Scores[winner] > Max_Score){

            Max_Lang.clear();
            Max_Score=Scores[winner];
            Max_Lang.push_back(winner);

        }

       

    }
}



void Tournament::SetKombats(){

    Node* curr = NULL;
    Node* newstart = NULL;
    string expr;
    string revexpr;
    bool nestcheck = false;

    while(true){

        if(curr == NULL){
            
            curr = start;

             // first kombat
            expr = this->Get_Expr(curr->res,curr->nxt->res); 
            Kombats[expr] = rand() % 2; 

           this->SwitchCase(Kombats[expr],curr->res,curr->nxt->res);

            curr = curr->nxt;
        }
        else{ // if curr1 not null3 cases kombat does not exist , exists , 
            //its reverse expr of exists
     
            expr = this->Get_Expr(curr->res,curr->nxt->res); 
            revexpr = this->Get_Expr(curr->nxt->res,curr->res); 
            
            if(Kombats.count(expr)>0){// (if kombat already exists)
                            //count returns 1 if key exists else 0
                newstart=curr->nxt;
                do{
 
                    newstart = newstart->nxt;//curr1->nxt->nxt->...

                    expr = this->Get_Expr(curr->res,newstart->res);
                    revexpr = this->Get_Expr(newstart->res,curr->res);


                     if(Kombats.count(revexpr)>0){ //(collision)nxt comb , its reverse exists
                        nestcheck=true;
                        break;
                    }

                }while(Kombats.count(expr)>0);// do while  nxt comb also exists

                if(nestcheck){
                    break;
                }
              

                Kombats[expr] = rand() % 2; 

                this->SwitchCase(Kombats[expr],curr->res,newstart->res);
 
                curr=newstart;


            }else if(Kombats.count(revexpr)>0){// if reverse expr exists we meet collision
                
                break;

            }else{ // if kombat does not exist create kombat
                Kombats[expr] = rand() % 2; 

                this->SwitchCase(Kombats[expr],curr->res,curr->nxt->res);
  
                curr = curr->nxt;

            }
            
        }   
    }// end of for
}









