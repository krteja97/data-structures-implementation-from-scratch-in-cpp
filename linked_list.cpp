#include<bits/stdc++.h>
using namespace std;

struct node
{
	int data;
	node * next;
};

node * Read(node * head);
node * Delete(node * head, int x);
node * Insert(node * head,int x);
node * create_node(int data);

int main()
{
	node * head = NULL;
	int x ;
	int number;
	while(true)
	{
		cout<<endl<<"1. Insert"<<endl<<"2. Delete"<<endl<<"3. Read"<<endl;
		cin>>x;
		switch(x)
		{
			case 1:
				cout<<"enter number to insert"<<endl;
				cin>>number;
				head = Insert(head,number);
				break;
			case 2:
				cout<<"Enter number to be deleted"<<endl;
				cin>>number;
				head = Delete(head,number);
				break;
			case 3:
				head = Read(head);
				break;
			default:
				cout<<"henlo"<<endl;
		}
	}
	return 0;
}

node * Insert(node * head,int x)
{
	if(head == NULL)
		return create_node(x);

	if(x < head->data)
	{
		node * p = head;
		head = create_node(x);
		head->next = p;
		return head;
	}

	node * p = head;
	while(p->next != NULL)
	{
		if(p->data <= x && x <= p->next->data)
		{
			node * q = create_node(x);
			q->next = p->next;
			p->next = q;
			break;
		}
		p = p->next;
	}

    if(p->next == NULL)
    {
    	node * q = create_node(x);
		p->next = q;
		q->next = NULL;
    }
	return head;
}

node * Delete(node * head, int x)
{
	if(head == NULL)
		return head;
	if(head->data == x)
	{
		node * p = head->next;
		free(head);
		return p;
	}

	node * prev = head;
	node * now = head->next;
	while(now != NULL)
	{
		if(now->data == x)
		{
			prev->next = now->next;
			free(now);
			break;
		}
		prev = prev->next;
		now = now->next;
	}

	return head;

}

node * Read(node * head)
{
	node * p = head;
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	return head;
}

node * create_node(int x)
{
	node * p = new node;
	p->next = NULL;
	p->data = x;
	return p;
}