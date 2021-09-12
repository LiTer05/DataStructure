#include <iostream>
#include <queue>

int main()
{
    const int n = 4;
    const int m = 4;
    int grid[n][m] =   {{0, 0, 0, 1},
                        {0, 1, 1, 0},
                        {0, 0, 0, 0},
                        {0, 1, 1, 0}};

    bool visited[n][m] = {};
    int dist[n][m];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            dist[i][j] = -1;

            if (grid[i][j] == 1)
            {
                visited[i][j] = true;
            }
        }
    }

    std::pair<int, int> source(0, 0);
    std::pair<int, int> dest(3, 3);

    std::queue<std::pair<int, int>> q;

    dist[source.first][source.second] = 0;
    visited[source.first][source.second] = true;
 

    q.push(source);
    while(!q.empty())
    {
        const std::pair<int, int> p = q.front();
        q.pop();
       
        if (p == dest)
        {
            break;
        }
        int i = p.first;
        int j = p.second;

        //upper neighbour
        if (i - 1 >= 0 && !visited[i - 1][j])
        {
            q.push(std::make_pair(i -1, j));
            visited[i - 1][j] = true;  
            dist[i - 1][j] = dist[i][j] + 1;
        }

        //lower neighbour
        if (i + 1 < n && !visited[i + 1][j])
        {
            q.push(std::make_pair(i + 1, j));
            visited[i + 1][j] = true;  
            dist[i + 1][j] = dist[i][j] + 1;
        }

        //left neigjbour
        if (j - 1 >= 0 && !visited[i][j - 1])
        {
            q.push(std::make_pair(i, j - 1));
            visited[i][j - 1] = true;  
            dist[i][j - 1] = dist[i][j] + 1;
        }

        //right neighbour
        if (j + 1 < m && !visited[i][j + 1])
        {
            q.push(std::make_pair(i, j + 1));
            visited[i][j + 1] = true;  
            dist[i][j + 1] = dist[i][j] + 1;
        }
        
    }

    std::cout   << "Shortest distance from point ["
                << source.first << ", " 
                << source.second << "] to point [" 
                << dest.first << ", " 
                << dest.second << "] is: " 
                << dist[dest.first][dest.second] 
                << std::endl;

    return 0;
}
