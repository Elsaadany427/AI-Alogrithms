#include<bits/stdc++.h>
using namespace std;
     
map < string, vector < string > > adj ;
map < string, string > parent ;
map < string, bool > visited;
map < string, long long > level;

/*
 * Time Complexity (O(b^d))
 * Space Complexity (O(b^d))
 * Characteristics of BFS
 * 		* Complete
 * 		* Optimal solution (if step cost are identical)
 * */
void BFS(string from, string to){
	
	queue < string > q;
	
	q.push(from);
	
	visited[from] = true;
	
	parent[from] = from;
	
	level[from] = 1;
	
	while(!q.empty()){
		
		string currentNode = q.front(); q.pop();
			
		// goal
		if(currentNode == to)
			return;
		for(auto child: adj[currentNode]){
			
			if(visited[child] == false){
				
				q.push(child);
		
				visited[child] = true;

				parent[child] = currentNode;

				level[child] = level[currentNode] + 1;
				
			}
		}
	}
}
void print(string from, string to){
	
	if(to == from){
		cout << to << " ";
		return;
	}
		
	print(from, parent[to]);
	
	cout << to << " ";
	
}

void addEdges(string u, string v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void solve(){
	long long nodes, edges;
	cin >> nodes >> edges;
	
	string u, v; 
	long long weight;
	while(edges--){
		
		cin >> u >> v >> weight;
		
		addEdges(u, v);

	}
	
	string startCity, endCity;
	cin >> startCity >> endCity;
	
	BFS(startCity , endCity) ;
	
	cout << "The Bfs from " << startCity << " To " <<  endCity << "Is : "<< endl;
	print(startCity, endCity) ;
	
}
int main(){

   	solve();
       
}


