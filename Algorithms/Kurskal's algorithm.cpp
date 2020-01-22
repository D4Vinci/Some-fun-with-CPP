#include <iostream> 
#include <string.h> 
using namespace std;
// Written at 25/12/2018
  
struct Edge { 
    int src, dest, weight; 
}; 
  
// a structure to represent a connected, undirected and weighted graph 
struct Graph { 
    // V-> Number of vertices, E-> Number of edges 
    int V, E; 
    struct Edge* edge; 
}; 
  
// Creates a graph with V vertices and E edges 
struct Graph* createGraph(int V, int E) { 
    struct Graph* graph = new Graph; 
    graph->V = V; 
    graph->E = E; 
    graph->edge = new Edge[E]; 
    return graph; 
} 
  
// A structure to represent a subset for union-find 
struct subset { 
    int parent; 
    int rank; 
}; 
  
// A utility function to find set of an element i 
// (uses path compression technique) 
int find(struct subset subsets[], int i) { 
    // find root and make root as parent of i  
    // (path compression) 
    if (subsets[i].parent != i) subsets[i].parent = find(subsets, subsets[i].parent); 
    return subsets[i].parent; 
} 
  
// A function that does union of two sets of x and y (uses union by rank) 
void Union(struct subset subsets[], int x, int y) { 
    int xroot = find(subsets, x); 
    int yroot = find(subsets, y); 
  
    // Attach smaller rank tree under root of high rank tree (Union by Rank) 
    if (subsets[xroot].rank < subsets[yroot].rank) subsets[xroot].parent = yroot; 
    else if (subsets[xroot].rank > subsets[yroot].rank) subsets[yroot].parent = xroot; 
  
    // If ranks are same, then make one as root and increment its rank by one 
    else { 
        subsets[yroot].parent = xroot; 
        subsets[xroot].rank++; 
    } 
} 
  
// Compare two edges according to their weights. 
// Used in qsort() for sorting an array of edges 
int myComp(const void* a, const void* b) { 
    struct Edge* a1 = (struct Edge*)a; 
    struct Edge* b1 = (struct Edge*)b; 
    return a1->weight > b1->weight; 
} 
  
// The main function to construct MST using Kruskal's algorithm 
void KruskalMST(struct Graph* graph) { 
    int V = graph->V; 
    Edge* result = new Edge[V];  // Tnis will store the resultant MST 
    int e = 0;  // An index variable, used for result[] 
    int i = 0;  // An index variable, used for sorted edges 
  
    // Step 1:  Sort all the edges in non-decreasing order of their weight. If we are not allowed to change the given graph, we can create a copy of array of edges 
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
  
    // Allocate memory for creating V ssubsets 
    struct subset *subsets = (struct subset*) malloc( V * sizeof(struct subset) ); 
  
    // Create V subsets with single elements 
    for (int v = 0; v < V; ++v) { 
        subsets[v].parent = v; 
        subsets[v].rank = 0; 
    } 
  
    // Number of edges to be taken is equal to V-1 
    while (e < V - 1) { 
        // Step 2: Pick the smallest edge. And increment the index for next iteration 
        struct Edge next_edge = graph->edge[i++]; 
        int x = find(subsets, next_edge.src); 
        int y = find(subsets, next_edge.dest); 
        // If including this edge does't cause cycle, include it in result and increment the index of result for next edge 
        if (x != y) { 
            result[e++] = next_edge; 
            Union(subsets, x, y); 
        } 
        // Else discard the next_edge 
    } 
  
    printf("\nFollowing are the edges in the constructed MST\n"); 
    for (i = 0; i < e; ++i) printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight); 
    return; 
} 
  
int main() { 
    int length, edges;
	cout << "Enter the length of the graph: ";cin>>length;
	cout << "\nEnter the number of edges: ";cin>>edges;
	struct Graph* graph = createGraph(length, edges); 
	cout << "\nEnter the matrix edges followed with weight:\n";
	int temp,temp2,weight;
	for(int i=0;i<edges;i++){
		cout << "("<<i+1<<")> ";cin >> temp >> temp2 >> weight;
		if(temp>=0 && temp<length && temp2>=0 && temp2<length){
			graph->edge[i].src = temp; 
			graph->edge[i].dest = temp2; 
			graph->edge[i].weight = weight;
		}
		else {
			cout << "\nInvalid edge!\n";
			system("pause");
			exit(0);
		}
	}
    KruskalMST(graph); 
	cout << endl;
	system("pause");
    return 0; 
} 