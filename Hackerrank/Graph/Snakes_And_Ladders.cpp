#include<iostream>
using namespace std;
int visited[105];
int moves[105];

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

int BFS()
{
    Queue q;
    visited[1] = 1;
    q.enqueue(1,0);
   
    while (!q.isEmpty())
    {
        Queue::queue_struct U = q.frontanddequeue();
        
        int u = U.x;
        int count = U.count;
        if(u == 100)
        	return count;

        for(int v = (u + 1); v <= (u + 6) && v <= 100; v++)
        {
            if (!visited[v])
            {
                int next_u;
                if(moves[v] != -1)
                    next_u = moves[v];
                else
                    next_u = v;
                visited[v] = 1;
                q.enqueue(next_u, count + 1);
            }
        }
    } 
    return -1;
}
int main()
{
    int T, L, M, from, to;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; tc++)
    {
        for(int i = 1; i <= 100; i++)
        {
        	moves[i] = -1;
            visited[i] = 0;
        }
        
        scanf("%d", &L);
        for (int i = 1; i <= L; i++)
        {
            scanf("%d%d", &from, &to);
            moves[from] = to;   
        }
        
        scanf("%d", &M);
        for (int i = 1; i <= M; i++)
        {
            scanf("%d%d", &from, &to);
            moves[from] = to;   
        }
    
        printf("%d\n", BFS());        
    }
    return 0;
}
