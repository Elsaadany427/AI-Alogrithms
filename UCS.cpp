#include<bits/stdc++.h>
using namespace std; 

map < string, bool > visited;
map < string, vector < pair<string,  int> > > adj;
map< string, string > parent;

void UCS(string start, string end){
	multiset< pair< int, string> > q;
	q.insert({0, start});
	
	while(!q.empty()){
		auto [weight, currentNode] = *q.begin();
		q.erase(q.begin());
		
		if(currentNode == end)
			return;
		
		if(visited[currentNode])
			continue;
			
		for(auto child: adj[currentNode]){
			if(!visited[child.first]){
				q.insert({weight + child.second, child.first});
				parent[child.first] = currentNode;
			}
		}
	}
}
void addEdges(string u, string v, int weight){
	adj[u].push_back({v, weight});
	adj[v].push_back({u, weight});
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
	int weight;
	for (int i = 0; i < edges; i++){
		cin >> u >> v >> weight;
		addEdges(u, v, weight);
	}
	string startCity, endCity;
	cin >> startCity >> endCity;
	UCS(startCity, endCity);
	cout << "The UCS from " << startCity << " To " <<  endCity << "Is : "<< endl;
	print(startCity, endCity);
}
int main(){

   	solve();
       
}


