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
