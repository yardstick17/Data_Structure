			/* AK_47*/
#include<iostream>
#include<stdio.h>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<string.h>
#include<queue>
#include<stdlib.h>
using namespace std;
#define S(x) scanf("%d",&x)
#define pb(x) push_back(x)
#define V(x) vector<x>
#define F(i,a,n) for(int i=(a);i<(n);++i)
#define REP(i,a,n) for(i=(a);i<(n);++i)
struct node {
	 int data;
	 struct node *left;
	 struct node *right;
};

struct node *NewNode(int data)
 {
 	 struct node *New = (struct node *)malloc(sizeof(struct node));
 	 New->left = NULL;
 	 New->right = NULL;
 	 New->data = data;
 	 return New;
 }
int Height(struct node *Root)
  {
  	  if(Root==NULL)
  	  return 0;
  	  
  	  int lheight = Height(Root->left);
  	  int rheight = Height(Root->right);
  	  
	 if(lheight>rheight)
  	    return lheight+1;
     else
  	    return rheight+1;
  	  
  }
  
void TraverseLevel(struct node *Root, int Level)
   {
   	   if(Root==NULL)
   	   return;
		if(Level==0)
		 cout<<Root->data<<" ";
		else
		   TraverseLevel(Root->left, Level-1);
		   TraverseLevel(Root->right,Level-1);
  }
void LevelOrder(struct node *Root)
  {
  	  int height = Height(Root);
  	  for(int i = 0 ; i<height; i++)
  	    {
  	    	  TraverseLevel(Root,i);
  	    }
  }
  
  
void Inorder(struct node *Root)
   {
   	 if(Root==NULL)
   	 return;
   	 
   	 Inorder(Root->left);
   	 cout<<Root->data<<" ";
   	 Inorder(Root->right);
   	 
   }
void Preorder(struct node *Root)
    {
    	 if(Root==NULL)
    	 return ;
    	 cout<<Root->data<<" ";
   	     Preorder(Root->left); 
    	 Preorder(Root->right);
    	 
    	 
    	 
    }
void Postorder(struct node *Root)
     {
     	 if(Root==NULL)
     	 return;
     	 
     	 Postorder(Root->left);
     	 Postorder(Root->right);
     	 cout<<Root->data<<" ";
	 }
	 

void leftBoundary(struct node *Root)
 {
    if(Root)
       {
           if(Root->left)//Root->left && !Root->right)
            {
              
                cout<<Root->data<<" ";
                leftBoundary(Root->left);
            }
            else if(Root->right)
               {
                  cout<<Root->data<<" ";
                  leftBoundary(Root->right);
               }

       }
 }

 void leavesleft(struct node *Root)
 {
   if(Root)
   {
     if(!Root->left && !Root->right)
       cout<<Root->data<<" ";
      leavesleft(Root->left);
      leavesleft(Root->right);
     //leavesleft(Root->left)
   }
 }
 void leavesright(struct node *Root)
  {
      if(Root)
   {
     if(!Root->left && !Root->right)
       cout<<Root->data<<" ";
      leavesright(Root->left);
      leavesright(Root->right);
   
   }  //leavesleft(Root->left)  
  } 
  void rightBoundary(struct node *Root)
   {
     if(Root)
       {
         if(Root->right)
         {
            rightBoundary(Root->right);
            cout<<Root->data<<" ";
         }
         else if(Root->left)
         {
           rightBoundary(Root->left);
           cout<<Root->data<<" ";
         }
       }
   }
void BoundaryTraversal(struct node *Root)
 {
   if(Root)
     {
       cout<<Root->data<<" ";
       leftBoundary(Root->left);
       leavesleft(Root->left);
       leavesright(Root->right);

       rightBoundary(Root->right);

     }
 }
int main()
{
  struct node *Root = NewNode(4);
 
  Root->left = NewNode(2);
  Root->right = NewNode(5);

  Root->left->left = NewNode(1);
  Root->left->right = NewNode(3); 
  
  Root->right->left = NewNode(6);
  Root->right->right = NewNode(7);

  Root->right->right->right = NewNode(4);
  Root->right->right->left = NewNode(5);
  Root->right->right->left->left = NewNode(91);
  LevelOrder(Root); 
  cout<<"\n";
  Preorder(Root);
  cout<<"\n";
  Inorder(Root);
  cout<<"\n";
  Postorder(Root);
  cout<<"\n";
  cout<<" Boundarry traversal is: ";
  BoundaryTraversal(Root);

return 0;
}

