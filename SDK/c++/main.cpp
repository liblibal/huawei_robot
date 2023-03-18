#include <iostream>
#include <bits/stdc++.h>
using namespace std;


const int maxn=1024;
const double pi=acos(-1);




bool initreadUntilOK() {
    char line[1024];
    int now=0;
    while (fgets(line, sizeof line, stdin)) {
        if (line[0] == 'O' && line[1] == 'K') {
            return true;
        }
    }
    return false;
}

bool readUntilOK() {
    char line[1024];
    while (fgets(line, sizeof line, stdin)) {
        if (line[0] == 'O' && line[1] == 'K') {
            return true;
        }
        //do something
        
    }
    return false;
}

int frameID;
int money;
int bench_cnt;
struct bench{
    int type;
    double x,y;
    int last;
    int instatus;
    int outstatus;
};
bench benchs[55];

string command[5]={
    "forward",
    "rotate",
    "buy",
    "sell",
    "destroy"
};
struct robot{
    int benchid;
    int carry;
    double time_factor;
    double bump_factor;
    double rotate_speed;
    double line_speed;
    double direction;
    double x,y;
    struct task{
        int target;
        int time_last;//剩余时间（未实装）
    };
    vector<pair<int,int>> commands; 
};
robot robots[4];    
const int robot_cnt=4;
bool readframe()
{
    scanf("%d",&frameID);
    scanf("%d",&money);
    scanf("%d",&bench_cnt);
    for(int i=0;i<bench_cnt;i++)
    {
        scanf("%d",&benchs[i].type);
        scanf("%lf",&benchs[i].x);
        scanf("%lf",&benchs[i].y);
        scanf("%d",&benchs[i].last);
        scanf("%d",&benchs[i].instatus);
        scanf("%d",&benchs[i].outstatus);
    }
    for(int i=0;i<robot_cnt;i++)
    {
        scanf("%d",&robots[i].benchid);
        scanf("%d",&robots[i].carry);
        scanf("%lf",&robots[i].time_factor);
        scanf("%lf",&robots[i].bump_factor);
        scanf("%lf",&robots[i].rotate_speed);
        scanf("%lf",&robots[i].line_speed);
        scanf("%lf",&robots[i].direction);
        scanf("%lf",&robots[i].x);
        scanf("%lf",&robots[i].y);
    }

    return true;
}

bool move_to_bench(int robotid,int benchid)
{
    double x=benchs[benchid].x;
    double y=benchs[benchid].y;
    double dx=x-robots[robotid].x;
    double dy=y-robots[robotid].y;
    double angle=atan2(dy,dx);
    double delta=angle-robots[robotid].direction;
    if(delta>3.1415926)delta-=2*3.1415926;
    if(delta<-3.1415926)delta+=2*3.1415926;
    if(delta>0.1)
    {
        robots[robotid].commands.push_back(make_pair(1,delta*180/3.1415926));
    }
    else if(delta<-0.1)
    {
        robots[robotid].commands.push_back(make_pair(1,delta*180/3.1415926));
    }
    else
    {
        robots[robotid].commands.push_back(make_pair(0,3));
    }
    return true;
}

guzhi[bench]//估值
guzhi2[type]//辅助估值 0~1
int solve(){
    
    int rp5=0,rp6=0,rp4=0,rp1=0,rp2=0,rp3=0;
    for(int i=0;i<=50;i++){
        if(benchs[i].out)guzhi[i]+++//劲增，猛增,霸霸霸霸霸
        if(benchs[i].type==7){
            if(((benchs[i].instatus>>3)&1)==0)guzhi2[4]++;//缺货
            if(((benchs[i].instatus>>4)&1)==0)guzhi2[5]++;
            if(((benchs[i].instatus>>5)&1)==0)guzhi2[6]++;
        }
        if(benchs[i].type==4){
            if(((benchs[i].instatus)&1)==0)guzhi2[1]++;
            if(((benchs[i].instatus>>1)&1)==0)guzhi2[2]++;
        }
        if(benchs[i].type==5){
            if(((benchs[i].instatus)&1)==0)guzhi2[1]++;
            if(((benchs[i].instatus>>2)&1)==0)guzhi2[3]++;
        }
        if(benchs[i].type==6){
            if(((benchs[i].instatus>>1)&1)==0)guzhi2[1]++;
            if(((benchs[i].instatus>>2)&1)==0)guzhi2[3]++;
        }
    }
    int mx=0;
    for(int i=1;i<=7;i++){
        guzhi2[i]/=benchi_count;
    }
    mx=max(mx,guzhi2[i]);
    for(int i=1;i<=7;i++)guzhi2[i]/=mx//限制在0~1间
    guzhi2[1]=guzhi2[1]/3+guzhi2[4]/3+guzhi2[5]/3;
    guzhi2[2]=guzhi2[2]/3+guzhi2[4]/3+guzhi2[6]/3;
    guzhi2[3]=guzhi2[3]/3+guzhi2[5]/3+guzhi2[6]/3;
    for(int i=0;i<50;i++)guzhi[i]=guzhi[i]+guzhi2[bench[i].type]*C;

    int id=0;
    for(int i in allpossible task ){
        if(function(i)>function(id)||id==0)id=i;
    }
}

int main() {
    initreadUntilOK();
    puts("OK");
    fflush(stdout);
    int frameID;
    while (scanf("%d", &frameID) != EOF) {
        readUntilOK();
        printf("%d\n", frameID);
        int lineSpeed = 3;
        double angleSpeed = 1.5;
        for(int robotId = 0; robotId < 4; robotId++){
            printf("forward %d %d\n", robotId, lineSpeed);
            printf("rotate %d %f\n", robotId, angleSpeed);
        }
        printf("OK\n", frameID);
        fflush(stdout);
    }
    return 0;
}
