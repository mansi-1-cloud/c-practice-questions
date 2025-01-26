#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Function to add a node to the adjacency list
void addNode(int s, int d, Node* adj[]) {
    Node* dest = (Node*)malloc(sizeof(Node));
    dest->vertex = d;
    dest->next = adj[s];  // Add the new node at the beginning
    adj[s] = dest;  // Update the head of the adjacency list
}

// Function to print the adjacency list of the graph
void print(int n, Node* adj[]) {
    for (int i = 0; i < n; i++) {
        Node* p = adj[i];
        printf("%d: ", i);
        while (p) {
            printf("%d -> ", p->vertex);
            p = p->next;
        }
        printf("NULL\n");
    }
}

// DFS function to traverse the graph recursively
void dfs(int i, int vis[], Node* adj[]) {
    Node* p;
    vis[i] = 1;  // Mark current vertex as visited
    printf("%d ", i);  // Process the vertex
    p = adj[i];  // Get the adjacency list for vertex i
    while (p != NULL) {
        int j = p->vertex;  // Get the connected vertex
        if (!vis[j]) {  // If not visited, recursively visit
            dfs(j, vis, adj);
        }
        p = p->next;  // Move to the next node in the adjacency list
    }
}

// BFS function to traverse the graph level by level
void bfs(int start, int n, Node* adj[]) {
    int queue[10], front = 0, rear = 0;
    int vis[10] = {0};  // Initialize visited array to 0

    queue[rear++] = start;  // Enqueue the starting vertex
    vis[start] = 1;  // Mark it as visited

    while (front < rear) {
        int curr = queue[front++];  // Dequeue a vertex
        printf("%d ", curr);  // Process the vertex

        Node* p = adj[curr];  // Traverse the adjacency list of the current vertex
        while (p != NULL) {
            int j = p->vertex;
            if (!vis[j]) {
                queue[rear++] = j;  // Enqueue the unvisited vertex
                vis[j] = 1;  // Mark it as visited
            }
            p = p->next;
        }
    }
}

int main() {
    int n, src, dest, ch;
    int vis[10];
    Node* adj[10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency list with NULL pointers
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;  // Set each adjacency list head to NULL
    }

    // Input edges
    while (1) {
        printf("Enter source and destination: ");
        scanf("%d%d", &src, &dest);
        addNode(src, dest, adj);
        printf("Enter 1 to continue, 0 to exit: ");
        scanf("%d", &ch);
        if (ch == 0)
            break;
    }

    printf("\nAdjacency List Representation:\n");
    print(n, adj);  // Print the adjacency list for all vertices

    // DFS Traversal
    for (int i = 0; i < n; i++) {
        vis[i] = 0;  // Reset visited array before DFS
    }
    
    // Find a vertex with at least one edge to start DFS
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (adj[i] != NULL) {  // Find a vertex that has neighbors
            start = i;
            break;
        }
    }
    
    printf("DFS Traversal starting from vertex %d: ", start);
    dfs(start, vis, adj);
    printf("\n");

    // BFS Traversal
    for (int i = 0; i < n; i++) {
        vis[i] = 0;  // Reset visited array before BFS
    }

    printf("BFS Traversal starting from vertex %d: ", start);
    bfs(start, n, adj);
    printf("\n");

    return 0;
}