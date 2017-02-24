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
void addend(node **headref,int data){
    node* temp1=*headref;
    /*node* temp=(node*)malloc(sizeof(struct nodes));
    temp=*headref;
    while(temp!=NULL&&temp->next!=NULL){
        temp=temp->next;
    }
        if(temp==NULL){
            *headref=(createnewnode(data,NULL));}
    */
    if(*headref==NULL){//LinkedList is empty
        *headref=(node*)malloc(sizeof(node));
        ((*headref)->data)=data;
        ((*headref)->next)=NULL;
    }else{
        //Traverse till the end of the linked list
        node* temp=*headref;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=createnewnode(data,NULL);
        // temp->next=createnewnode(data,temp1->next);//Just for testing purpose making the linked list circular

    }

}
int MiddleElement(node *head){
    node *slow=head;node *fast=head;
    if( slow==NULL ){//This is the 0 node
        return -1;//Empty LinkedList
    }
    // slow=fast=head;
    
    while(slow && fast && fast->next && fast->next->next ){
        slow=slow->next;
        fast=(fast->next)->next;
    }
    return slow->data;
}
void print(node* head){//Base case is handled if head is null
if(head==NULL){return;}
while(head!=NULL){
    printf("%d ",head->data);
    head=head->next;//changing pointer so as to point to next node;
    }
    printf("\n");
}
int length(node *head){
int counter=0;
    while(head!=NULL){
   counter++;
    head=head->next;//changing pointer so as to point to next node;
    }
    return counter;
}
void removefront(node **headref){
    if(*headref==NULL){
        return;
    }
    node* temp1=*headref;
    node* temp2=temp1->next;
    *headref=temp2;
    free(temp1);
    temp1=NULL;
}
void removeend(node **headref){
   // Always try to free the dynamically allocated memory so as to prevent the momory leak;
   if(*headref==NULL){
    return;
   }
   node* temp1;node* temp2;
   temp1=*headref;
   temp2=*headref;
   temp2=temp2->next;
   while(temp2->next!=NULL){
        temp1=temp1->next;
        temp2=temp2->next;
   }
   temp1->next=NULL;
   free(temp2);
   temp2=NULL;
}
void deleteNnode(node **headref,int position){
 node* temp1;node* temp2;
 int len=length(*headref);
 if( (position>len) || ( position==0) ){
    printf("Outside specified list\n");
    return;
 }
 if(position==1){
     if(*headref==NULL){
        return;
    }
    node* temp1=*headref;
    node* temp2=temp1->next;
    *headref=temp2;
    free(temp1);
    temp1=NULL;     
 }else{
        temp1=*headref;
        temp2=*headref;
        temp2=*headref;
        temp2=temp2->next;
        for(int i=0;i<position-2;i++){
        temp1=temp1->next;
        temp2=temp2->next;
    }
    (temp1->next)=(temp2->next);//
    free(temp2);
    temp2=NULL;

 }
}
int IsCircular(node *head){
    node *slow=head,*fast=head;
    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            return 1;//Yes circular
        }
    }
    return 0;//No,not  Circular
}
int FindCircularNode(node *head){
        if(IsCircular(head)){
    node *slow=head,*fast=head;
    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            break;
        }
    }
    slow=head;
    while(slow&&fast){
        slow=slow->next;
        fast=(fast->next);
        if(slow==fast){
            // flag=1;
            return slow->data;
            break;
        }
    }           
        }else{
            return -1;
            // No comman node
        }
}
void EvenOdd(node *head){
    // To Find weather a linkedList is odd or even
    node *slow=head;node *fast=head;
    while(slow && fast && fast->next ){
        slow=slow->next;
        fast=fast->next;
        fast=fast->next;
    }
    if(fast==NULL){
        printf("Even Linked List\n");
    }else{
        printf("Odd LinkedList\n");
    }
}
int FindLenghtofNode(node *head){
int counter=0;
    if(IsCircular(head)){
    node *slow=head,*fast=head;
    while(slow&&fast&&fast->next){
        slow=slow->next;
        fast=(fast->next)->next;
        if(slow==fast){
            break;//Slow and fast overlaps here
        }
    }
    // slow=head;
    slow=slow->next;
    while(slow){
        slow=slow->next;
        counter++;
        if(slow==fast){
            
            break;
        }
            }
            return counter+1;
    }else{
        return -1;//No possible answer
    }
}
//void deletebyvalue(node *head,int datpa){
//    if(head->next==NULL){printf("\ncant handle this situation using present scenario\n");return;}
//while(  ( (head->next )->data )==data  ){
//    head=head->next;//pointer pointing to next node
//}
//head->next=((head->next))->next;
//}
void deletebyvalue(node **headref,int data){
    if(*headref==NULL){return;}
    node *temp=*headref;
if( (temp)->data==data){
    //First node matches itself then
    (*headref)=((*headref)->next);return;}
while( (((temp)->next)->data)!=data){  
    (temp)=(temp)->next;
    if( (temp)->next==NULL){
            printf("Not found any node to be deleted\n");
      return;}
    }
    (temp)->next=((temp)->next)->next;//address of third node is contained in the second node

}
void replacevalue(node *head,int data,int newdata){
if(head==NULL){return;}
    node *temp;
    temp=head;
    while(temp->data!=data){
        temp=temp->next;//pointer moving to next node
        if(temp->next==NULL){printf("\nNot found any value to be deleted\n");return;}//not found any element to be replaced
    }
    temp->data=newdata;
}
void InsertElementInSortedList(node **headref,int data){
    node *temp=*headref;node *current=*headref;
    if(*headref==NULL){
        *headref=createnewnode(data,NULL);//Empty linked list case
    }
    if(current->data>=data){
     *headref=createnewnode(data,temp);//Empty linked list case   
        return;
    }
    while(current!=NULL&&current->data<data  ){
        temp=current;
        current=current->next;
    }
    temp->next=createnewnode(data,current);//
}
// void reverseList(node **headref){
//     if(*headref==NULL){return;}//empty linked list
//     node *current,*prev,*nexted;
//     prev=*headref;
//     current=prev->next;
//     if(current==NULL){return;}// Single node linked list  .Its reverse is same as the orignal linked list
//     nexted=current->next;
//     while(nexted!=NULL){
//         current->next=prev;
//         prev=current;
//         current=nexted;
//         nexted=nexted->next;
//     }
//     current->next=prev;//Remember nexted has turned null
//     (*headref)->next=NULL;//first node null
//     *headref=current;//head must point to last element of the linked list
// }
node* reverseList(node *head){//Since this is pass by value I need to return the new value of the head
    if(head==NULL) return NULL;//already empty linked list cannot reverse this
    node *current,*prev,*next;
    current=head;
    prev=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
    return head;
}
int NumberOFNodes(node *head){
    int counter=0;
    node *temp=head;
    while(temp!=NULL){
        counter++;
        temp=temp->next;
    }
    return counter;
}
node* InsertNth(node *head, int data, int position){   //Now the base case i:e head==null
    if(head==NULL&&position==0){
        head=(node*)malloc(sizeof(node));//first element of the linked list
        head->data=data;
    }else if(position==0){
        //I need to modify the head
        node *temp,*ptr;
        temp=head;
        ptr=(node*)malloc(sizeof(node));//
        head=ptr;
        ptr->data=data;
        ptr->next=temp;
    }
    else{
        if(position>NumberOFNodes(head)){
            position=NumberOFNodes(head);//i:e insertion at the end
        }
        //Assuming head!=NULL
    node *ptr=head;
    for(int i=0;i<position-1;i++){
        ptr=ptr->next;
    }
    node *temp=ptr->next;
    ptr->next=(node*)malloc(sizeof(node));
    ptr=ptr->next;
    ptr->next=temp;
    ptr->data=data;
    }
    return head;
}
int FindMergePoint(node *headA,node *headB){
    
}
void DeletingSinglyLinkedList(node **headref){
if(*headref==NULL){
    return;
}
node* temp1;node* temp2;
temp1=*headref;
temp2=temp1->next;
while(1){
        free(temp1);
        temp1=NULL;
        temp1=temp2;
        if(temp2==NULL){
            break;//Simply come out of this loop
        }
        temp2=temp2->next;
    }
    *headref=NULL;
}
void RemoveDuplicates(node **headref){
    // There is memory leak in this function
    if(*headref==NULL){
        return;
    }
    node* pr=*headref;node* ne=*headref;
    ne=ne->next;
    while(ne!=NULL){//Both does not point to the same memory location
        if(pr->data==ne->data){
            pr->next=ne->next;
            ne=ne->next;
        }else{
            pr=pr->next;
            ne=ne->next;
        }
    }

}

node* MergeTwoSortedLinkedList(node *ha,node *hb){
        if(ha==NULL && hb==NULL){return NULL;}
    node *hc=NULL;node *ll1=ha;node *ll2=hb;node *temp;
        while(ll1!=NULL || ll2!=NULL ){
                if(ll1 && ll2 && (ll1->data < ll2->data) ){
                    if(hc==NULL){
                        // First element of the new linkedllist
                       hc=createnewnode(ll1->data,NULL);
                       temp=hc;
                       ll1=ll1->next;
                    }else{
                        temp->next=createnewnode(ll1->data,NULL);
                        ll1=ll1->next;
                        temp=temp->next;
                    }

                }else if(ll1 && ll2 && (ll1->data >= ll2->data) ){
                    if(hc==NULL){
                        hc=createnewnode(ll2->data,NULL);
                        temp=hc;
                       ll2=ll2->next;
                    }else{
                        temp->next=createnewnode(ll2->data,NULL);
                        ll2=ll2->next;
                        temp=temp->next;
                    }
                }else{
                    if(ll1==NULL){
                        // printf("Hello\n");
                            if(hc==NULL){
                        hc=createnewnode(ll2->data,NULL);
                        temp=hc;
                       ll2=ll2->next;
                        }else{
                        temp->next=createnewnode(ll2->data,NULL);
                        ll2=ll2->next;
                        temp=temp->next;
                        }      
                    }else{
                            if(hc==NULL){
                        // First element of the new linkedllist
                       hc=createnewnode(ll1->data,NULL);
                       temp=hc;
                       ll1=ll1->next;
                    }else{
                        temp->next=createnewnode(ll1->data,NULL);
                        ll1=ll1->next;
                        temp=temp->next;
                        }
                    }
                }
        }
        temp->next=NULL;
                return hc;
}
void ReverseInPairs(node **headref){
        node *prev=NULL;node *nexted=((*headref)->next);node *current=*headref;
        if(*headref==NULL){
            return;//Empty linked list
        }
        if(nexted==NULL){
            return;//Single membered linked list
        }

        *headref=nexted;
        current->next=nexted->next;
        nexted->next=current;
        while( current && current->next ){
            prev=current;
            current=( (current->next));
            nexted=( current->next);

            current->next=nexted->next;
            nexted->next=current;
            prev->next=nexted;
            
        }
}
void SplitLinkedList(node *head,node *head1,node *head2){
    int len=0;
    node *temp;
    while(temp!=head){
        len++;
        temp=temp->next;
    }
}
int isPalindrome(node *head){
    
}
void RemoveDuplicates(node *head){
    if(head==NULL||head->next==NULL){
        return;//The linked list is already empty
    }
    node *current=head;
    node *next_next;
    while(current->next!=NULL){
        if(current->data==(current->next)->data ){
            next_next=current->next;
            current->next=(current->next)->next;
            free(next_next);
        }else{
            current=current->next;
        }
    }
}
void SwapContentsOffirstandLastnode(node *headA){
        node *tempA=headA;
        node *tempB=headA;
        int data;
        while(tempB->next!=NULL){
            tempB=tempB->next;
        }
        data=(tempA->data);
        (tempA->data)=(tempB->data);
        (tempB->data)=data;
}
void concatenate(node *headA,node *headB){
         node *tempA=headA;
         while(tempA->next!=NULL){
            tempA=tempA->next;
         }
         tempA->next=headB;
}
node* exchangeEvenandOdd(node *head){
    node* itr=head;
    node* Even=NULL;
    node* Odd=NULL;
    node* Eventail;node * Oddtail;
    while(itr!=NULL){
        if( ((itr->data)%2)==0){
            if(Even==NULL){
                Even=createnewnode(itr->data,NULL);
                Eventail=Even;
            }else{
                (Eventail->next)=createnewnode(itr->data,NULL);
                Eventail=(Eventail->next);
            }
        }else{
            if(Odd==NULL){
                Odd=createnewnode(itr->data,NULL);
                Oddtail=Odd;
            }else{
                (Oddtail->next)=createnewnode(itr->data,NULL);
                Oddtail=(Oddtail->next);
            }
        }
        itr=itr->next;
    }
    Eventail->next=Odd;
    return Even;
}

int main(){
node *head1=NULL;
node *head2=NULL;
addend(&head1,11);
addend(&head1,12);
addend(&head1,13);
addend(&head1,14);
addend(&head1,15);
// addend(&head2,16);
// addend(&head2,17);
// addend(&head2,18);
// addend(&head2,19);
// addend(&head2,20);
head2=exchangeEvenandOdd(head1);
// SwapContentsOffirstandLastnode(head1);
// concatenate(head1,head2);
// addend(&head2,10);
// addend(&head2,10);
// addend(&head2,20);
// addend(&head2,20);
// addend(&head2,30);
// addend(&head2,30);
// RemoveDuplicates(head2);
// addfront(&head1,40);
//addfront(&head,60);
// addend(&head1,40);
// addend(&head1,50);
// addend(&head1,30);
// addend(&head1,40);
// addend(&head1,50);
// InsertElementInSortedList(&head1,95);

// printf("%d\n",MiddleElement(head1));
// node *mergedList=MergeTwoSortedLinkedList(head1,head2);
// printf("%d",EvenOdd(head1));
// --To check weather a linked list is circular or not
// printf("%d\n",IsCircular(head1) );
// printf("%d\n",FindCircularNode(head1) );
// printf("%d",FindLenghtofNode(head1));

// deleteNnode(&head1,0);
// addend(&head1,40);
// addend(&head1,50);
// addend(&head1,60);
// addend(&head2,1);
// addend(&head2,2);
// addend(&head2,3);
// // addend(&head2,50);
// // addend(&head2,60);
// printf("%d\n",FindMergePoint( head1,head2 ));
// removefront(&head1);
// removeend(&head1);
 // RemoveDuplicates(&head1);
// DeletingSinglyLinkedList(&head1);
// ReverseInPairs(&head2);
print(head2);

//head=reverseList(head);
//print(head);
//removefront(&head);

//deletebyvalue(&head,10);

//replacevalue(head,80,99);
//print(head);
//head=InsertNth(head,3,10);
//print(head);
//printf("%d\n",length(head));
return 0;}
