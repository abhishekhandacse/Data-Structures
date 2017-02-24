#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>
using namespace std;
struct BstNode
{	BstNode* left;
	int data;
	BstNode* right;
};
//Returning base address of newly created structure
BstNode* GetNewNode(int data){//any newnode will be created by this function only
	BstNode* node =(BstNode*)malloc(sizeof(BstNode));//new node created
	node->left=NULL;
	node->right=NULL;
	node->data=data;
	return node;//baseAddress of newly allocated node
}
void insert(BstNode** node,int data){
	//what all I need to cover....
	//1)when the root is empty
	//2)when the data<root.data
	//3)when the data>root.data
	if(*node==NULL){
		//GetNewNode fuction will be called
		*node=GetNewNode(data);//Root got updated
	}
	else if( data<(*node)->data ){//10<15
	//left of previous node will get updated
		insert(&((*node)->left),data);//			
	}
	else if(data>(*node)->data){//20>15
	//right of previous node will get updated
		insert(&((*node)->right),data);
	}

}
//This is O(n)
void inorder_tree_walk(BstNode* ptr){//ascending order
	if(ptr==NULL){
		return;//base condition
	}
	inorder_tree_walk(ptr->left);
	cout<<" "<<ptr->data;
	inorder_tree_walk(ptr->right);		
}
//Non recursive implementation of binary search tree
void preorder_tree_walk_non_recursive(BstNode* ptr){
	if(ptr==NULL){
		return;//base condition
	}
	cout<<" "<<ptr->data;
	inorder_tree_walk(ptr->left);
	inorder_tree_walk(ptr->right);
}
//post order traversal
void post_order_tree_walk_non_recursive(BstNode* ptr){
if(ptr==NULL){
		return;//base condition
	}
	inorder_tree_walk(ptr->left);
	inorder_tree_walk(ptr->right);
	cout<<" "<<ptr->data;
}
BstNode* Search(BstNode* ptr ,int key){
	if( ( ptr==NULL ) || (key==( ptr->data)) ){
		//If key not found then this will return null 
		//else if found then this will return the key's address
		return  ptr;
	}
		if(key<( ptr->data)){
			//MoveLeft in Binary Search Tree
			return Search( ptr->left,key);
		}
		else {
			//Move right in binary search tree
			return Search( ptr->right,key);
		}
	
}
int Search_Recursive(BstNode* ptr,int key){
	if(ptr==NULL){
		return 0;
	}
	int t1=Search_Recursive(ptr->left,key);
	int t2=Search_Recursive(ptr->right,key);
	if(t1 || t2 || (ptr->data==key) ){
		return 1;
	}else{
		return 0;
	}
}
int Search_non_recursive(BstNode* ptr,int key){
	while((ptr!=NULL) && (key!=ptr->data)){
		if(key< (ptr->data )){
			ptr=ptr->left;}
		else{
			ptr=ptr->right;}
		}
		if(ptr==NULL){
			return 0;
		}
		else{
			return 1;
		}
}
int Tree_max(BstNode* ptr){
	if(ptr==NULL){return -1;}
	//this will return the maximum element of the tree
	if(ptr->right==NULL){
		return ptr->data;//base case of recursion
	}
	return Tree_max(ptr->right);
}
int Tree_min(BstNode* ptr){
	if(ptr==NULL){return -1;}
	//this will return the maximum element of the tree
	if(ptr->left==NULL){
		return ptr->data;//base case of recursion
	}
	return Tree_min(ptr->left);
}
int Successor(BstNode* ptr,int key){
	//If There is right sub-tree then the leftmost number of that subtree is going to be my ans
	
}
int height(BstNode* Ptr){//height of bst
if(Ptr==NULL){return 0;}
int left_height=height(Ptr->left);
int right_height=height(Ptr->right);
	if(left_height>right_height){
		return left_height+1;
	}
	else{
		return right_height+1;
	}
}
void LevelOrderTraversal(BstNode *root){
	if(root==NULL){return;}//empty tree
queue<BstNode *> q;
 q.push(root);
while(!q.empty()){
		BstNode *current=q.front();
		cout<<current->data<<" ";
		if(current->left!=NULL){
			q.push(current->left);
			}
		if(current->right!=NULL){
			q.push(current->right);
		}
		q.pop();
	}
}
void LevelOrderTraversalInReverse(BstNode *root){
	stack<BstNode*> mystack;
	queue<BstNode*> myqueue;
	BstNode* temp;
	if(root==NULL){return;}
	myqueue.push(root);
	while(!myqueue.empty()){
		temp=myqueue.front();//Front is towards the Left hand side of the queue
		myqueue.pop();
		if(temp->right){
			myqueue.push(temp->right);
		}
		if(temp->left){
			myqueue.push(temp->left);

		}
		mystack.push(temp);
	}
	cout<<endl;
	while(!mystack.empty()){
		temp=mystack.top();
		cout<<temp->data<<" ";
		mystack.pop();
		
	}
}
BstNode* lca(BstNode *root, int v1,int v2){
		if(root==NULL){return NULL;}//Base conditon of the recursion
		if(root->data==v1||root->data==v2){
			return root;
		}
		BstNode* left=lca(root->left,v1,v2);
		BstNode* right=lca(root->right,v1,v2);
		if(left!=NULL && right!=NULL){//Both are on the same side of the subtree
			return root;
		}
		if(left==NULL && right==NULL ){
			return NULL;
		}
		return (left!=NULL?left:right);
}
int AreStructurallyIdentical(BstNode* r1,BstNode* r2){
	if(r1==NULL && r2==NULL){//Both trees finished
		return 1;
	}else if(r1==NULL || r2==NULL){//One of the trees becomes empty
		return 0;
	}
	return (r1->data==r2->data)&&(AreStructurallyIdentical(r1->left,r2->left)&&(AreStructurallyIdentical(r1->right,r2->right)) );
}
int NumberOfLeaves(BstNode* root){
	if(root==NULL){//This base condition will never run until the tree is empty
		return 0;
	}else if(root->left==NULL && root->right==NULL){//Leaves of the tree
		return 1;
	}else{


		return NumberOfLeaves(root->left)+NumberOfLeaves(root->right);
	}
}
int total_no_of_nodes(BstNode* root){
	int counter=1;
	if(root==NULL){
		return 0;
	}
	counter=counter+total_no_of_nodes(root->left);
	counter=counter+total_no_of_nodes(root->right);
	return counter;
}
int total_no_of_parents(BstNode* root){
	int total=total_no_of_nodes(root)-NumberOfLeaves(root);
	return total;
}
//---->Now I am trying to compute number of parents in a binary search tree using Auxillary function
void total_parents_aux(BstNode* root,int* count){
	if(root==NULL){return;}
	if(root->left!=NULL && root->right !=NULL){
		(*count)++;
	}
	total_parents_aux(root->left,count);
	total_parents_aux(root->right,count);
}
int total_parents(BstNode* root){
	int count=0;
	total_parents_aux(root,&count);
	return count;
}

//---->
int main()
{	BstNode* root=NULL;//tree empty initially
	insert(&root,15);
	insert(&root,6);
	insert(&root,18);
	insert(&root,3);
	insert(&root,7);
	insert(&root,17);
	BstNode* root1=NULL;//tree empty initially
	insert(&root1,15);
	insert(&root1,6);
	insert(&root1,18);
	insert(&root1,3);
	insert(&root1,7);
	// insert(&root1,17);
	cout<<endl<<"Both the trees are AreStructurallyIdenticall->"<<AreStructurallyIdentical(root,root1)<<endl;
	// insert(&root,20);
	// insert(&root,2);
	// insert(&root,4);
	// insert(&root,13);
	// insert(&root,9);
	// insert(&root,2);
	// insert(&root,1);
	// insert(&root,3);
	// insert(&root,4);
	cout<<endl<<"inorder_tree_walk";
	inorder_tree_walk(root);
	cout<<endl<<"Preorder_tree_walk";
	preorder_tree_walk_non_recursive(root);
	cout<<endl<<"post_order_tree_walk_non_recursive";
	post_order_tree_walk_non_recursive(root);
	int key=10;
	cout<<"Ptr to structure is"<<Search(root,13);
	cout<<endl<<Search_non_recursive(root,20);
	cout<<endl<<"Tree-Max "<<Tree_max(root);
	cout<<endl<<"Tree-Min "<<Tree_min(root);
	cout<<endl<<"height of the tree is->"<<height(root);
	 LevelOrderTraversal(root);
	 LevelOrderTraversalInReverse(root);
	 BstNode* element= lca(root,0,27);
	 if(element)
	 cout<<endl<<"The least comman ancestor is "<<element->data;
	cout<<endl<<Search_Recursive(root,100);
	cout<<endl<<"Total nodes in the tree"<<total_no_of_nodes(root);
	cout<<endl<<"Total parents in the tree"<<total_no_of_parents(root);
	cout<<endl<<"Total children in the tree"<<NumberOfLeaves(root);
	cout<<endl<<"The total number of parents are"<<total_parents(root);
	return 0;
}

//Recursion is reducing something in a self similer manner;