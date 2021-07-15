#include<iostream>

class heatGainWalls{
    private:
    float heatWalls;

    protected:
    void setHeatWalls(float x) { heatWalls = x; }

    float getHeatWalls() { return heatWalls ; }
};

class heatGainRoof{
    private:
    float heatRoof;

    protected:
    void setHeatRoof(float y) { heatRoof = y; }
    float getHeatRoof() { return heatRoof ; }
};

class calc:public heatGainRoof, heatGainWalls{
    
    private:
    float totalHeat;
    
    public:
    

    calc(float x, float y){
        setHeatWalls(x);
        setHeatRoof(y);
    }

    void add() {
        totalHeat = getHeatRoof() + getHeatWalls(); 
    }

    float getToatlHeat() { return totalHeat;}
};


int main(){ 

    float x =0.f, y =0.f ;
    std::cin >> x >> y; //get values


    calc c(x,y);

    c.add();

    std::cout << c.getToatlHeat(); //get total heat
    return 0;
}

