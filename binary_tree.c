//19001215
//binary tree

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node node;

node* newnode(int x)
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	p->left=NULL;
	p->right=NULL;
	return(p);
}

node* insert(node *root,int x)
{
	if(root==NULL)
	{
		return newnode(x);
	}
	else if(x>root->data)
	{
		return insert(root->right,x);
	}
	else
	{
		return insert(root->left,x);
	}
	return root;
}

node* search(node *root,int x)
{
	if(root->data== x || root==NULL)
	{
		return root;
	}
	if(x<root->data)
	{
		return search(root->left, x);
	}
	else
	{
		return search(root->right, x);
	}
	
}

node* fineMin(node* root)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->left!=NULL)
	{
		return fineMin(root->left);
	}
	return root;
}

node *deleteN(node *root,int x)
{
	node *temp;
	if(root==NULL)
	{
		return NULL;
	}
	else if(x<root->data)
	{
		deleteN(root->left,x);
	}
	else if(x>root->data)
	{
		deleteN(root->right,x);
	}
	else
	{
		temp=root;
		if(root->left==NULL && root->right==NULL)
		{
			free(root);
			return NULL;
		}
		else if(root->left==NULL || root->left==NULL)
		{
			if(root->left==NULL)
			{
				temp=root->right;
			}
			else
			{
				temp=root->left;
			}
			return temp;
		}
		else
		{
			temp=fineMin(root->right);
			root->data=temp->data;
			root->right=deleteN(root->right,temp->data);
		}
	}
	return root;
}

void main()
{
	int ch,n;
	
	node *root;
	root =newnode(10);
	insert(root,6);
	insert(root,15);
	insert(root,3);
	insert(root,2);
	root = deleteN(root,2);
	
	while(1)
	{
		printf("\n 1.Create new node\n 2.Insert data to binary tree\n 3.Search\n 4.Delete\n 5.Find minimum\n 6.Exit");
		printf("\n Enter choice- ");
		scanf("%d",&ch);
	
		switch(ch)
		{
			case 1: printf("\n Enter data value- ");
					scanf("%d",&n);
					printf(" Created node address- %d",newnode(n)); break;
			case 2: printf("\n Enter data value- ");
					scanf("%d",&n);
					printf(" Inserted value node address- %d",insert(root,n)); break;
			case 3: printf("\n Enter search value- ");
					scanf("%d",&n);
					printf(" Found value node address- %d",search(root,n)); break;
			case 4: printf("\n Enter delete value- ");
					scanf("%d",&n);
					printf(" Deleted value node address- %d",deleteN(root,n)); break;
			case 5: printf(" Min value node address- %d",fineMin(root)); break;
			case 6: return;
		}
    }
}
