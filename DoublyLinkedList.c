#include<stdio.h>
#include<stdlib.h>
typedef struct DLL Node;
struct DLL
{	int data;
	DLL *next;
	DLL *prev;
	
};
int len(Node *head){
	int counter=0;
	while(head!=NULL){
		counter++;
		head=head->next;
	}
	return counter++; 
}
void InsertInSortedList(Node **headref,int data){
	Node *slow=*headref;Node *fast=*headref;Node *newNode;
	if(*headref==NULL){//EMpty linked List
			newNode=(Node*)malloc(sizeof(struct DLL));
			newNode->data=data;
			*headref=newNode;
			newNode->next=NULL;
			newNode->prev=NULL;
			return;
	}
	if(data<slow->data){
		// Insertion at the beginning
		
		newNode=(Node*)malloc(sizeof(struct DLL));
		newNode->data=data;
		newNode->next=*headref;
		newNode->prev=NULL;
		*headref=newNode;
		return;
	}
	while(fast!=NULL){
		//Insertion at the middle
		slow=fast;
		fast=fast->next;
		if( fast &&(slow->data<data) && (fast->data>data) ){
			newNode=(Node*)malloc(sizeof(struct DLL));
			newNode->data=data;
			newNode->prev=slow;
			newNode->next=fast;
			slow->next=newNode;
			fast->prev=newNode;
			return;
		}
	}
						//Implies insertion is at the end
						newNode=(Node*)malloc(sizeof(struct DLL));
						newNode->data=data;
						slow->next=newNode;
						newNode->next=NULL;
						return;
}

void DLLInsert( DLL **headref,int data,int pos ){
	int num=0,counter=0;
	Node *temp,*newNode;
	newNode=(Node*)malloc(sizeof(struct DLL));
	if(!newNode){
		//No node available in the avail list
		printf("No dynamic memory available\n");
		return;
	}
		//Calculating the lenght of the linkedlist
		temp=*headref;
		while(temp!=NULL){
			num++;
			temp=temp->next;
		}
		newNode->data=data;
	if(pos==1){//insertion at the beginning of the first node
		newNode->next=*headref;
		newNode->prev=NULL;
		if(*headref)//No modification is needed if mine linkedlist is empty
			(*headref)->prev=newNode;
		//Now update mine head
		*headref=newNode;
		return;
	}else if(pos<=num){//This implies insertion at somewhere in the interior of the linked list
			temp=*headref;
			for(int i=0;i<pos-2;i++){
				if(temp->next==NULL){
					break;
				}
				temp=temp->next;
			}
			newNode->next=temp->next;
			newNode->prev=temp;
			if(temp->next)
			((temp->next)->prev)=newNode;
				temp->next=newNode;
				
	}else{
		//Insertion is at the end of the linked list
		temp=*headref;
		while(temp->next){
			temp=temp->next;
		}
		temp->next=newNode;
		newNode->prev=temp;
		newNode->next=NULL;
	}

}
void DLLdelete(Node **headref,int pos){
Node *temp=*headref;Node *temp2;
if(*headref==NULL) return;//Empty linkedList
int length=len(*headref);
if(pos==1){//first node of the linked list
	*headref=temp->next;
	free(temp);
}else if(pos==length){
	
	temp2=temp;
	while(temp->next){
		temp2=temp;
		temp=temp->next;
	}
	temp2->next=NULL;
	free(temp);
	temp=NULL;
}else{//deletion  in the middle of the linked list
	// temp2=temp;
	// printf(" %d %d",pos,length );
	if(pos>length){return;}
	for(int i=0;i<pos-1;i++){
			temp2=temp;
			temp=temp->next;
	}
	((temp->next)->prev)=temp2;
	temp2->next=temp->next;
	
	 free(temp);
	temp2=NULL;
	}
}
void print(DLL *head){
	while(head!=NULL){
		printf("%d ",head->data );
		head=head->next;
	}
}
void ReverseDLL(Node **headref){
	Node *swap;Node *temp=*headref;Node *keep;
	if(*headref==NULL){
		return;
	}else if(temp->next==NULL){
		return;
	}else{
		//Now the real logic starts
			while(temp!=NULL){
				swap=(temp->next);
				(temp->next)=(temp->prev);
				(temp->prev)=swap;
				keep=temp;
				temp=temp->prev;
		}
			    *headref=keep;
	}
}

int main(){
	Node *head=NULL;
	DLLInsert(&head,10,1);
	DLLInsert(&head,20,2);
	// DLLInsert(&head,30,3);
	// DLLInsert(&head,40,4);
	// DLLInsert(&head,50,5);
	// InsertInSortedList(&head,55);
	ReverseDLL(&head);
	 // DLLdelete(&head,3);
	  print(head);
return 0;}