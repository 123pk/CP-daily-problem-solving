/*
Platform :- Leetcode
Contest :- Leetcode Weekly contest 65
Approach :- We can always move num % (h+w-2)*2 values , because after (h+w-2)*2 operation we came back to same place where we started , take care when we start from 0,0 and came 
            back to 0,0 here the direction changes from east to south
*/
class Robot {
public:
    int dir=0;
    int w,h;
    vector<int>pos;
    Robot(int width, int height) {
        w=width-1;
        h=height-1;
        pos={0,0};
    }
    
    void move(int num) {
        int d = (w+h)*2;
        num=num%d;
        if(num==0){
            if(pos[0]==0 && pos[1]==0){
              if(dir==0)dir=3;   
            }
        }
        else{
        int x=pos[0],y=pos[1];
       // cout<<x<<" "<<y<<" --> "<<num<<"\n";
        while(num--){
            if(dir==0){
                if(x==w){
                   dir++;
                    y=1;
                }
                else x++;
            }
            else if(dir==1){
                if(y==h){
                    x=w-1;
                    dir++;
                }
                else y++;
            }
            else if(dir==2){
                if(x==0){
                    dir++;
                    y=h-1;
                }
                else x--;
            }
            else{
                if(y==0){
                    dir=0;
                    x=1;
                }
                else y--;
            }
        }
        //cout<<x<<" ,"<<y<<endl;
        pos={x,y};
            
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        if(dir==0)return "East";
        else if(dir==1)return "North";
        else if(dir==2)return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
