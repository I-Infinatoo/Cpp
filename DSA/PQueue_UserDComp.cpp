//Priority Queue ---> using user defined Comparator 

//Problem Statement: Given the 2-D Coordinates of Cars find the nearest K cars to the given coordinate(0,0)

/*
 *For this we have to make a *functor -- if we wnat to solve the question
 *
 *
 * Functors: These are functional Objects(i.e Function behaving as objects) 
 */
#include<iostream>
#include<queue>
#include<vector>

using namespace std;

class car{
    public:
    
    int id;
    int x;
    int y;
    
    car(int x, int y, int id) {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist(){
        return x*x + y*y;
    }

    void print(){
        cout << "Id: "<< id << ": [" << x << ", " << y << "]\n" ;
    }
};

class carCompare{
    public:
    //method to overload () operator
    bool operator()(car a, car b){
        return a.dist() > b.dist();
    }
};

int main () {
    
    priority_queue<car, vector<car>, carCompare>pq;
//  priority_queue<_type, vector<_type>, _functor>pq;

    int x[10] = {5,6,17,18,9,11,0,3};
    int y[10] = {1,-2,8,9,10,91,1,2};

    for(int i=0; i<8; i++) {
        car c (x[i], y[i], i);
        pq.push(c);
    }

    while (!pq.empty())
    {
        car p = pq.top();
        p.print();
        pq.pop();
    }
    
    return 0;
}