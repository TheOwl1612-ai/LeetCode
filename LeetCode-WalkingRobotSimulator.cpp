#include "Debug.cpp"
class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<vector<int>> obs (obstacles.begin(), obstacles.end());
        int x = 0;
        int y = 0;
        int degree = 0;
        string axis = "y+";

        for (int command : commands){
            if (command > 0){
                while (true){
                    move(x,y,axis,1)
                }

            }
        }

    }

    string calcAxis(int degree){
        if (degree % 360 == 0) return "y+";
        else if ((degree - 90) % 360 == 0) return "-x";
        else if ((degree - 180)% 360 == 0) return "-y";
        else return "+x";
    }
    void move(int& x, int& y, string axis, int distance){
        if (axis == "+x"){
            x += distance;
        }

        else if (axis == "-x"){
            x -= distance;
        }

        else if (axis == "+y"){
            y += distance;
        }

        else if (axis == "-y"){
            y-= distance;
        }
    }


};

int main(){


}