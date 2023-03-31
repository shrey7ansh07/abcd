#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
}
};
void push(node* &head,int data){
    node* temp = head;
    node* jhol = new node(data);
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = jhol;
    jhol->prev = temp;

}
void print(node* &head){
    node* temp = head;
    while(temp->next!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<endl;

}
void inertion(node* &head,node* ptr,node* start){
    if(start->next==NULL){
        if(start->data<ptr->data){
            while(ptr->data>start->data){
                if(ptr==head){
                    break;
                }
                

                ptr = ptr->prev;
            }
                if(ptr==head){
                    start->prev->next=NULL;
                    start->prev = NULL;
                    start->next = head;
                    head -> prev = start;
                    head = start;
                }
                else{
                    start->prev->next=NULL;
                    start->prev = ptr;
                    start->next =ptr->next;
                    ptr->next->prev = start;
                    ptr->next = start;
                    
                }
            
        }
        return;
    }
    if(ptr->data>start->data){
    while(ptr->data>start->data){
        if(ptr==head){
            break;
        }
        ptr = ptr ->prev;

}
    node* temp = start;
    start= start->next;
        if(ptr==head){
            temp->prev->next=start;
            start->prev = temp->prev;
            temp->next = head;
            head -> prev = temp;
            head = temp;
            ptr = start->prev;
                }
        else{
            temp->prev->next=start;
            start->prev = temp->prev;
            temp->next = ptr->next;
            temp->prev = ptr;
            ptr->next->prev = temp;
            ptr->next = temp;
            ptr= start->prev;


        }
    }
    else{
        ptr = start;
        start=start->next;
    }
    inertion(head,ptr,start);

        
    
}
// now once we have got this now for the insertion sort we must be using the recursion function
int main(){
    node* initiate = new node(15);
    print(initiate);
    push(initiate,13);
    print(initiate);
    push(initiate,17);
    print(initiate);
    push(initiate,10);
    print(initiate);
    push(initiate,13);
    print(initiate);
    inertion(initiate,initiate,initiate->next);
    print(initiate);

    // hey the code works really well for the case where similar intgers are also present 



}

