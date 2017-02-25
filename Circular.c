#include<stdio.h>
#include<stdlib.h>
struct nodes{
    int data;
    struct nodes* next;//Pointer to structure for storing address of next node
};
typedef struct nodes node;
//initially head taken as a global variable we will make it local after some time
//void insert(int x);
//void print();
//pointer to a structure will simply be node*
node* createnewnode(int data,node *next){
node* temp=(node*)malloc(sizeof(struct nodes));
temp->data=data;
temp->next=next;
return temp;
}
void addfront(node **headref,int data){//till now we have inserted the element in the beginning
    //node temp=(node)malloc(sizeof(struct nodes));
    //temp->data=x;
    //temp->next=*headref;//if first element head will contain null
    //*headref=createnewnode(data,*headref);
    node* temp=createnewnode(data,NULL);
    temp->next=*headref;
    *headref=temp;
}
void makeCircular(node *headA){
	node *temp=headA;
	while(temp->next!=NULL){
		temp=temp->next;
	}
		temp->next=headA;
}
void print(node* head){//Base case is handled if head is null
if(head==NULL){return;}
node* ptr=head;
	do{
		printf("%d ",ptr->data );
		ptr=ptr->next;
	}while(ptr!=head);
	
}
void deleteCicular(node **headref){
	if(*headref==NULL){return;}//What if my linked list is empty
	if( ( (*headref)->next)==(*headref)){
			free(*headref);
			*headref=NULL;
			return;
	}
	node *prev=*headref;node *nexted=*headref;
	while(nexted->next!=*headref){
		nexted=nexted->next;
	}
	(*headref)=prev->next;
	free(prev);
	(nexted->next)=*headref;
}
int main(){
	node* head1=NULL;
	addfront(&head1,10);
	// addfront(&head1,20);
	// addfront(&head1,30);
	// addfront(&head1,40);
	makeCircular(head1);
	
	deleteCicular(&head1);
	print(head1);
return 0;}
