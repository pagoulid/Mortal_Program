#include <iostream>
#include <string.h>
#include <vector>
#include "Node.cpp"


using namespace std;

// Get kombats
// maps final_score , kombats/winner 
// maybe call list from another class if yes maybe head to public


class List{
    public:
        Node* GetHead();
        int GetSize();
        void  Create_List(int size , char **args); 
        void  Create_List(int size , vector<string> args); 
        void Display();
        //Delete_List();
        List();
        void DelList();
        
    private:

        //Node* head;
        Node* head;
        int length;
        
        void setSize(int size){
            length=size;
        }
        
       
};

List::List(void){
    
    head = NULL;
    length = 0;
    //cout<<"List Init"<<endl;
}

void List::DelList(){
    //Node* curr;
    
    if(head!=NULL){
        Node* tmp;
        
        for(int k=0;k<length-1;k++){// linked list so start del from 2nd node 
        
            tmp = new Node();
            //tmp = head->nxt;
            if(k==length-2){
                head->nxt->nxt = NULL;
                tmp = head->nxt;
                delete tmp;
           
                

           

            
            }else{
            
                tmp = head->nxt;
                head->nxt = head->nxt->nxt;
                //cout<<"DelLoop : "<<head->res<<endl;
        
                delete tmp;
   
            }

        }
        delete head;

    }   
    else{
        cout<<"Nothing to delete!!!!";
    }
    
}

Node* List::GetHead(){
    return head;
}

int List::GetSize(){
    return length;
}
void List::Create_List(int size, char **args){

    //Node* head = NULL;
    this->setSize(size);
    
    Node* curr;
   



     for(int i=1;i<size+1;i++){


        if(head == NULL){
            head = new Node();
            //curr = new Node();


            
            
            head->res=new char(strlen(args[i])+1);
            strcpy(head->res,args[i]);
            curr = head;
            
            
            

        }
        else{
            
            Node* node = new Node();
            curr->nxt = node;
            curr = curr->nxt;
            //curr->res = args[i];
            curr->res=new char(strlen(args[i])+1);
            strcpy(curr->res,args[i]);
            

            if(i == size ){

                curr->nxt=head;
                
            }

        }
         
    }
    

}




void List::Create_List(int size, vector<string> args){

    //Node* head = NULL;
    this->setSize(size);
    
    Node* curr;
     
    char* data[size] ; // in order to copy strings to node->res(char* type)

    for(int i = 0;i<size;i++){
        data[i] = &args[i][0];
    }
   



     for(int i=0;i<size;i++){


        if(head == NULL){
            head = new Node();
            //curr = new Node();


            
            
            head->res=new char(strlen(data[i])+1);
            strcpy(head->res,data[i]);
            
            curr = head;
            
            
            

        }
        else{
            
            Node* node = new Node();
            curr->nxt = node;
            curr = curr->nxt;
            
            curr->res=new char(strlen(data[i])+1);
            strcpy(curr->res,data[i]);
            
            

            if(i == size - 1){

                curr->nxt=head;
                
            }

        }
         
    }
    

}







void List::Display(){
    
    Node* curr;
    
    curr=head;
    
   
    for(int k=0;k<length;k++){
        cout<<curr->res<<endl;
        curr=curr->nxt;
        
       
    }

}


