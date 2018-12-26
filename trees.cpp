#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

node * new_node(int data)
{
	node * p = new node;
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	return p;
}

node * insertNode(node * root,int data)
{
	if(root == NULL)
	{
		root =  new_node(data);
		return root;	
	}

	if(data < root->data)
	{
		( root->left = insertNode(root->left,data) );
		return root;
	}
	( root->right  = insertNode(root->right,data) );
	return root;
}

node * find_successor(node * root)
{
	while(root->left != NULL)
		root = root->left;
	return root;
}

node * deleteNode(node * root,int data)
{
	if(root == NULL)
	{
		cout<<"node not found!! error ";
		return root;
	}

	if(data < root->data)
	{
		root->left = deleteNode(root->left,data);
		return root;
	}

	if(data > root->data )
	{
		root->right = deleteNode(root->right,data);
		return root;
	}

	//final case what happens when root->data is data
	if(root->data  == data)
	{
		if(root->left == NULL && root->right == NULL)
			return NULL;
		if(root->left == NULL)
			return root->right;
		if(root->right == NULL)
			return root->left;
		node * successor = find_successor(root->right);
		root->data = successor->data;
		root->right = deleteNode(root->right,successor->data);
	}

}

void Inorder(node * root)
{
	if(root->left)
		Inorder(root->left);
	cout<<root->data<<" ";
	if(root->right)
		Inorder(root->right);
}

void Inorder1(node * root)
{
	if(root == NULL)
		return ;
	stack <node *> s;
	node * p = root;
	while(p != NULL)
	{
		s.push(p);
		p = p->left;
	}

	while(!s.empty())
	{
		p = s.top();
		cout<<p->data<<" ";
		s.pop();
		p = p->right;

		while(p != NULL)
		{
			s.push(p);
			p = p->left;
		}
	}
}

void levelOrder(node * root)
{
	queue <node *> q;
	q.push(root);

	while(!q.empty())
	{
		node * p = q.front();
		q.pop();
		if(p->left != NULL)
		q.push(p->left);
		if(p->right != NULL)
		q.push(p->right);
		cout<<p->data<<" ";
	}
}

int main()
{
	node * root = NULL;
	root = insertNode(root,41);
	root = insertNode(root,23);
	root = insertNode(root,56);
	root = deleteNode(root,41);
	root = insertNode(root,7);
	root = insertNode(root,-3);
	root = insertNode(root,98);
	root = insertNode(root,134);
	root = insertNode(root,39);

	Inorder(root);
	cout<<endl;
	levelOrder(root);
	return 0;
}