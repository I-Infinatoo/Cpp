#include<iostream>
#include<queue>

struct node
{
    int timeFrame;
    int i, j;
};


int sol(std::vector<std::vector<int>> & grid)
{   
    int totalCount =0, queueCount =0, timeCount =0;
    std::queue<struct node>qu;

    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            if(grid[i][j] == 2 or grid[i][j] == 1) 
            {
                totalCount++;
            }
            if(grid[i][j] == 2)
            {
                struct node n{0,i,j};   //init the node with timeFrame and the coordinates
                qu.push(n);             //pushing in queue  
            }
        }
    }
    
    while (not qu.empty())
    {
        struct node tempNode = qu.front();
        timeCount = tempNode.timeFrame;

        //down
        if ( (tempNode.i)+1 < grid.size() and grid[tempNode.i+1][tempNode.j] == 1 ) //down should be in the boundary
        {   struct node newNode{tempNode.timeFrame+1, tempNode.i+1, tempNode.j};
            qu.push(newNode);
            grid[tempNode.i+1][tempNode.j]=2;
        }
        
        //up
        if( (tempNode.i)-1 > -1 and grid[tempNode.i-1][tempNode.j] == 1 )         //up should be in the boundary
        {   struct node newNode{tempNode.timeFrame+1, tempNode.i-1, tempNode.j};
            qu.push(newNode);
            grid[tempNode.i-1][tempNode.j] = 2;
        }

        //right
        if( (tempNode.j)+1 < grid[tempNode.i].size() and grid[tempNode.i][tempNode.j+1] == 1 ) //right should be in the boundary
        {   struct node newNode{tempNode.timeFrame+1, tempNode.i, tempNode.j+1};
            qu.push(newNode);
            grid[tempNode.i][tempNode.j+1] = 2;
        }

        //left
        if( (tempNode.j)-1 > -1 and grid[tempNode.i][tempNode.j-1] == 1 ) //down should be in the boundary
        {   struct node newNode{tempNode.timeFrame+1, tempNode.i, tempNode.j-1};
            qu.push(newNode);
            grid[tempNode.i][tempNode.j-1] = 2;
        }


        qu.pop();
        ++queueCount;
    }
    // std::cout << queueCount << "\n" ;
    return queueCount==totalCount ? timeCount : -1 ;
}

int main ()
{
    std::vector<std::vector<int>>grid
    {
        {2,1,0,2,1},
        {1,0,1,2,1},
        {1,0,0,2,1}
    };

    int ans = sol(grid);
    std::cout << ans << "\n" ;

    return 0;
}