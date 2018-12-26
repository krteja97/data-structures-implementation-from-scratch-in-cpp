#include<bits/stdc++.h>
using namespace std;

void dfs(vector <int> adj[], int src, bool visited[])
{
	if(visited[src] == false)
		visited[src] = true;
	cout<<src<<" ";

	vector <int> :: iterator itr;
	for(itr = adj[src].begin(); itr != adj[src].end(); itr++)
	{
		if(visited[*itr] == false)
			dfs(adj,*itr,visited);
	}
}

void Dfs(vector <int> adj[], int v)
{
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i] = false;

	dfs(adj,0,visited);
}

void dfs_with_stack(vector <int> adj[], int v)
{
	stack <int> s;
	s.push(0);

	bool visited[v];
	cout<<"0"<<" ";
	for(int i=0;i<v;i++)
		visited[i] = false;
	visited[0] = true;

	while(!s.empty())
	{
		int x = s.top();
		vector <int> :: iterator itr;
		for(itr = adj[x].begin() ; itr != adj[x].end(); itr++)
		{
			if(visited[*itr] == false)
			{
				visited[*itr] = true;
				cout<<*itr<<" ";
				s.push(*itr);
				break;
			}
		}

		if(itr == adj[x].end())
		{
			s.pop();
		}

	}
}

void bfs(vector <int> adj[], int v)
{
	queue <int> q;
	bool visited[v];
	for(int i=0;i<v;i++)
		visited[i] = false;

	cout<<endl;
	q.push(0);
	visited[0] = true;
	cout<<"0"<<" ";

	while(!q.empty())
	{
		int x  = q.front();
		vector <int> :: iterator itr;
		for(itr = adj[x].begin(); itr != adj[x].end(); itr++)
		{
			if(visited[*itr] == false)
			{
				visited[*itr] = true;
				q.push(*itr);
				cout<<*itr<<" ";
			}
		}
		q.pop();
	}
}

int main()
{	
	int v;
	cout<<"enter no of vertices"<<endl;
	cin>>v;
	cout<<"enter the count and info of edges"<<endl;
	int e;
	cin>>e;

	vector <int> adj[v];

	for(int i=0;i<e;i++)
	{
		int s,d;
		cin>>s>>d;
		adj[s].push_back(d);
		adj[d].push_back(s);
	}

	//Dfs(adj,v);
	dfs_with_stack(adj,v);
	bfs(adj,v);
}