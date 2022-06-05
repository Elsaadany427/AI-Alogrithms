#include<bits/stdc++.h>
using namespace std; 

map < string, bool > visited;
map < string, vector < string > > adj ;
map< string, string > parent;

void DFS(string start, string end){
	stack< string > st;
	st.push(start);
	
	while(!st.empty()){
		string currentNode = st.top();
		st.pop();
		
		if(currentNode == end)
			return;
		if(!visited[currentNode]){
			visited[currentNode] = true;
			parent[currentNode] = currentNode;
		}
		
		for(auto child: adj[currentNode]){
			if(!visited[child]){
				visited[child] = true;
				parent[child] = currentNode;
				st.push(child);
			}
		}
	}
}
void addEdges(string u, string v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void print(string from, string to){
	
	if(to == from){
		cout << to << " ";
		return;
	}
		
	print(from, parent[to]);
	
	cout << to << " ";
	
}
void solve(){
	long long nodes, edges;
	cin >> nodes >> edges;
	string u, v;
	long long weight;
	for (int i = 0; i < edges; i++){
		cin >> u >> v >> weight;
		addEdges(u, v);
	}
	string startCity, endCity;
	cin >> startCity >> endCity;
	DFS(startCity, endCity);
	cout << "The DFS from " << startCity << " To " <<  endCity << "Is : "<< endl;
	print(startCity, endCity);
}
int main(){

   	solve();
       
}


