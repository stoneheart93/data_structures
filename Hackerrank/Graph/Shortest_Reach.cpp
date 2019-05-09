#include<iostream>
#include<queue>
using namespace std;
int N, E;
int adj[1005][1005];
int E1[100000], E2[100000];
int visited[1005];
int countArr[1005];

class Queue
{
      
public:
    struct queue_struct
    {
        int x;
        int count;
    }queue[10000];
    int size;
    int rear;
    int front;
    Queue()
    {
		size = 0;
        front = 0;
        rear = -1;
    }
    void enqueue(int x, int count)
    {
        size++;
        rear++;
        queue[rear].x = x;
        queue[rear].count = count;
    }
    queue_struct frontanddequeue()
    {
        size--;
        return queue[front++];
    }
    int isEmpty()
    {
        if (size == 0)
            return 1;
        else
            return 0;
    }
};

void BFS(int src)
{
    Queue q;
    visited[src] = 1;
    q.enqueue(src,0);
   
    while (!q.isEmpty())
    {
        Queue::queue_struct U = q.frontanddequeue();
        
        int u = U.x;
        int count = U.count;

        countArr[u] = count;

        for (int v = 1; v <= N; v++)
        {
            if (adj[u][v])
            {
                if (!visited[v])
                {
                    int new_count = count + adj[u][v];
                    visited[v] = 1;
                    q.enqueue(v,new_count);
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (i == src)
            continue;
        if (countArr[i] == 0)
        {
            countArr[i] = -1;
            cout << countArr[i] << " ";
        }
        else
            cout << countArr[i] << " ";
    }
    cout << endl;
    
}
int main()
{
    int T,src;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        scanf("%d%d", &N, &E);

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                adj[i][j] = 0;
            }
        }
        for (int i = 1; i <= N; i++)
        {
            visited[i] = 0;
            countArr[i] = 0;
        }
   
        for (int i = 1; i <= E; i++)
        {
            scanf("%d%d", &E1[i], &E2[i]);
            adj[E1[i]][E2[i]] = 6;
            adj[E2[i]][E1[i]] = 6;
        }
        
        scanf("%d", &src);
        BFS(src);
    }
    return 0;
}
