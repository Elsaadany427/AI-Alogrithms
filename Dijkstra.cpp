/*

وَمَا رَمَيْتَ إِذْ رَمَيْتَ وَلَٰكِنَّ اللَّهَ رَمَىٰ ۚ

*/

#include<bits/stdc++.h>
using namespace std;
     
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define sz(x) (int) (x).size()
#define endl "\n"	
  
typedef long long ll; 
const int MAX_N = 1e5 + 12;
const int N = 2e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 1e9;

vector< int > Dist, myParent;
 
struct edge{
	int from, to, w;
	edge(int from, int to, int w): from(from), to(to), w(w){}
	bool operator < (const edge & e) const{
		return w > e.w;
	}
};

void Dijkstra(vector< vector< edge > >& adjList, int src, int dist = -1){
	
	int n = sz(adjList);
	
	Dist.assign(n, INF);
	myParent.assign(n, -1);
	
	Dist[src] = 0;
	
	priority_queue< edge > frontier;
	frontier.push(edge(-1, src, 0));
	
	while(!frontier.empty()){
		edge node = frontier.top(); frontier.pop();
		
		if(node.w > Dist[node.to])
			continue;
		myParent[node.to] = node.from; 
		
		for(int child = 0; child < sz(adjList[node.to]); ++child){
			
			edge newNode = adjList[node.to][child];
			
			if(Dist[newNode.to] > Dist[newNode.from] + newNode.w){
				
				newNode.w = Dist[newNode.to] = Dist[newNode.from] + newNode.w;
				
				frontier.push(newNode);
			}
		}
	}
}

void print(int node){
	if(node == 1){
		cout << node << " ";
		return;
	}
	print(myParent[node]);
	cout << node << " ";
}
void solve(){
	ll nodes, edges; cin >> nodes >> edges;
	vector< vector< edge > > adjList(edges);
	while(edges--){
		ll u, v, w; 
		cin >> u >> v >> w;
		adjList[u].push_back(edge(u, v, w));
		adjList[v].push_back(edge(v, u, w));
	}
	
	ll node; cin >> node;
	
	Dijkstra(adjList, 1);
	
	print(node);
	cout << endl;
}
int main(){
    	
   	fast_io ;
   	solve();
       
}


