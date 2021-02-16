#include<graphics.h>
#include<time.h>
#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

int EndSnake(int e)
{
    setfillstyle(1,5);
    e=e-2;
    bar(0,0,640,480);
    system("cls");
    cout<<"you died your score is: "<<e;
    getch();
    return 0;

}

int main(){
    int gd=DETECT;
    int gm;
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    int /*coordinates of food*/rx=200,ry=200,/*co ordinates of snake*/x[200],y[200],d=1,f=1,check=700,length=1,dir=1;
    for(int i = 0;i < 200 ; i++){
        x[i]=0;
        y[i]=0;
    }
    x[0]=200,y[0]=200;

    while(1){
    setfillstyle(1,0);
    bar(0,0,640,480);
    setfillstyle(1,2);
    bar(0,0,640,10);
    bar(0,0,10,480);
    bar(0,480,640,470);
    bar(630,10,640,480);
       // food eaten
   if(x[0]==rx && y[0]==ry ){
    length += 1;
    f=f+1;
    setfillstyle(1,0);
    bar(rx,ry,rx+10,ry+10);

    //make food
    while(getpixel(rx,ry)!=0 && rx > 10 && ry > 10);
    {
    rx = (1+rand()%630);
	ry = (1+rand()%470);
    }

    rx=rx/10;
    rx=rx*10;
    ry=ry/10;
    ry=ry*10;
    setfillstyle(1,2);
     }
    bar(rx,ry,rx+10,ry+10);
    if(GetAsyncKeyState(VK_RIGHT)){d=1;}
    else if(GetAsyncKeyState(VK_LEFT)){ d=2;}
    else if(GetAsyncKeyState(VK_UP)){ d=3;}
    else if(GetAsyncKeyState(VK_DOWN)) {d=4;}
    else{d=0;}
    switch(d){
    case 0: if(dir==1){x[0]=x[0]+10;}
            else if(dir==2){x[0]=x[0]-10;}
            else if(dir==3){ y[0]=y[0]-10;}
            else if(dir==4) {y[0]=y[0]+10;}
            else{d=0;}
            break;
    case 1:x[0]=x[0]+10;
           dir=1;
           break;
    case 2:x[0]= x[0]-10;
         dir=2;
          break;
    case 3:dir=3;
        y[0]=y[0]-10;
        break;
    case 4:dir=4;
       y[0]= y[0]+10;
        break;
    }
    for(int i = 0; i < length;i++)//move the head
    {
        bar(x[i],y[i],x[i]+10,y[i]+10);
    }
    for(int i=199; i>0; i--)//for body
    {
       x[i]=x[i-1];
       y[i]=y[i-1];
    }
    delay(100);

  if(x[0] >= 640 || x[0]<=0|| y[0]<=0 || y[0]>=480){
    EndSnake(f);
    break;
    }

    for(int i = 2; i < length;i++)
        {
            if(x[0] == x[i] && y[0] == y[i])
                {
                 check = i;
                 break;
                }
        }
    if(x[0] == x[check] && y[0] == y[check]){
    EndSnake(f);
    break;
    }

}
getch();
closegraph();
}
