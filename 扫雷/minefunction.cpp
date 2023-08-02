#include "minefunction.h"

//public

bool mine::gamestart()
{
    if(game)return true;
    return 0;
}

void mine::first_backg()
{
    backg();
}

void mine::main_boomnumber()
{
    boomnumber();
}

void mine::main_mousekick()
{
    mousekick();
}

bool mine::main_timemark()
{
    if(timemark)return true;
    return 0;
}

void mine::main_time()
{
    time();
}

//private

void mine::backg()//背景生成
{
    cout<<"backg!"<<endl;
    memset(MineClearing,0,sizeof(MineClearing));//初始化
    memset(MineNumber,0,sizeof(MineNumber));
    memset(MineMark,0,sizeof(MineMark));
    boom=Boom[nd];
    boomleftnumber=Boom[nd];

    setinitmode (INIT_DEFAULT);
    initgraph (l * Boomsize[nd][0], l * (Boomsize[nd][1]+2));//初始化界面

    starttime=fclock();
    timemark=true;

    setbkcolor(EGEGRAY(200));

    setchangereset();
    setchange();

    //时间 重置 剩余炸弹数
    int mx=(l*Boomsize[nd][0]-150)/4;//文字间距
    int jj=mx+l;
    PIMAGE pc=newimage();
    getimage(pc, "H:/game/MC/reset.jpg");
    putimage(2*jj,l,l,l,pc,0,0,getwidth(pc),getheight(pc));
    delimage(pc);
    cout<<"have reset!"<<endl;

    setbk();
    game=false;
    t=0;
    cout<<"have setbk!"<<endl;
}

void mine::setchangereset()//上面两栏底色
{
    PIMAGE pd=newimage();
    getimage(pd, "H:/game/MC/change.jpg");
     for(int i=0;i<2;i++)//铺上方块
    {
        for(int j=0;j<2*l;j++)
        {
            bar(j*l,i*l,j*l+l-1,i*l+l-1);
            putimage(j*l,i*l,l,l,pd,0,0,getwidth(pd),getheight(pd));
        }
    }
    delimage(pd);
}

void mine::setchange()
{
    PIMAGE nd0=newimage();
    PIMAGE nd1=newimage();
    PIMAGE nd2=newimage();
    PIMAGE nd3=newimage();
    PIMAGE nd4=newimage();
    int mx=(l*Boomsize[nd][0]-150)/4;//文字间距
    int jj=mx+l;
    getimage(nd0, "H:/game/MC/nd0.jpg");
    getimage(nd1, "H:/game/MC/nd1.jpg");
    getimage(nd2, "H:/game/MC/nd2.jpg");
    getimage(nd3, "H:/game/MC/nd3.jpg");
    getimage(nd4, "H:/game/MC/nd4.jpg");
    putimage(0,0,l,18,nd0,0,0,getwidth(nd0),getheight(nd0));
    putimage(jj,0,l,18,nd1,0,0,getwidth(nd1),getheight(nd1));
    putimage(2*jj,0,l,18,nd2,0,0,getwidth(nd2),getheight(nd2));
    putimage(3*jj,0,l,18,nd3,0,0,getwidth(nd3),getheight(nd3));
    putimage(4*jj,0,l,18,nd4,0,0,getwidth(nd4),getheight(nd4));
    delimage(nd0);
    delimage(nd1);
    delimage(nd2);
    delimage(nd3);
    delimage(nd4);
    cout<<"nd=="<<nd<<endl;
}

void mine::change(int msgx,int msgy)//改变难度
{
    int mx=(l*Boomsize[nd][0]-150)/4;//文字间距
    int jj=mx+l;
    if(msgx>0&&msgx<l&&msgy>0&&msgy<18)
    {
        nd=0;
        closegraph();
        backg();
    }
    else if(msgx>jj&&msgx<jj+l&&msgy>0&&msgy<18)
    {
        nd=1;
        closegraph();
        backg();
    }
    else if(msgx>2*jj&&msgx<2*jj+l&&msgy>0&&msgy<18)
    {
        nd=2;
        closegraph();
        backg();
    }
    else if(msgx>3*jj&&msgx<3*jj+l&&msgy>0&&msgy<18)
    {
        nd=3;
        closegraph();
        backg();
    }
    else if(msgx>4*jj&&msgx<4*jj+l&&msgy>0&&msgy<18)
    {
        nd=4;
        closegraph();
        backg();
    }
    cout<<"have change nd!"<<endl;

}

void mine::time()//计时
{
    double runtime=fclock();
    double curtime=runtime-starttime;
    setcolor(EGERGB(0,0,200));
    setfont(0.5*l, 0, "宋体");
    setfontbkcolor(EGEGRAY(200));
    settextjustify(LEFT_TEXT, TOP_TEXT);
    xyprintf(0,1.25*l, "Time:%.3lf", curtime);
}

void mine::reset(int rs)//重置 栏
{
    int mx=(l*Boomsize[nd][0]-150)/4;//文字间距
    int jj=mx+l;
    PIMAGE pc=newimage();
    if(rs==0&&resetflag==true)
    {
        resetflag=false;
        cleardevice();
        getimage(pc, "H:/game/MC/reset.jpg");
        putimage(2*jj,l,l,l,pc,0,0,getwidth(pc),getheight(pc));cout<<"have put reset!"<<endl;
        delimage(pc);
        cleardevice();
        backg();
    }
    else if(rs==1)
    {
        getimage(pc, "H:/game/MC/lose.jpg");
        putimage(2*jj,l,l,l,pc,0,0,getwidth(pc),getheight(pc));
        delimage(pc);
    }
    else if(rs==2)
    {
        getimage(pc, "H:/game/MC/win.jpg");
        putimage(2*jj,l,l,l,pc,0,0,getwidth(pc),getheight(pc));
        delimage(pc);
    }
}

void mine::resetmine(int msgx,int msgy)//按下重置按钮
{
    int mx=(l*Boomsize[nd][0]-150)/4;//文字间距
    int jj=mx+l;
    if(msgx>2*jj&&msgx<2*jj+l&&msgy>l&&msgy<2*l)
    {
        resetflag=true;
        cout<<"reset!"<<endl;
        reset(0);
    }
}

void mine::boomnumber()//实时记录剩余炸弹数
{
    PIMAGE bn=newimage();//解决文字覆盖问题
    getimage(bn, "H:/game/MC/change.jpg");
    for(int i=Boomsize[nd][0]-4;i<Boomsize[nd][0];i++)
    {
        bar(i*l,l,i*l+l-1,2*l-1);
        putimage(i*l,l,l,l,bn,0,0,getwidth(bn),getheight(bn));
    }
    delimage(bn);

    setcolor(EGERGB(0,0,200));
    setfont(0.5*l, 0, "宋体");
    setfontbkcolor(EGEGRAY(200));
    settextjustify(RIGHT_TEXT, TOP_TEXT);
    xyprintf(l*Boomsize[nd][0],1.25*l, "Bomb:%d", boomleftnumber);
    hengxian();
}

void mine::hengxian()//两栏之间的横线
{
    setcolor(EGEGRAY(150));
    line(0,l,Boomsize[nd][0]*l-1,l);
    setcolor(EGEGRAY(255));
    line(0,2*l,Boomsize[nd][0]*l-1,2*l);
}

void mine::setbk()//扫雷区域
{
    PIMAGE p0=newimage();
    getimage(p0, "H:/game/MC/00.jpg");
    for(int i=2;i<Boomsize[nd][1]+2;i++)//铺上方块
    {
        for(int j=0;j<Boomsize[nd][0];j++)
        {
            bar(j*l,i*l,j*l+l-1,i*l+l-1);
            putimage(j*l,i*l,l,l,p0,0,0,getwidth(p0),getheight(p0));
        }
    }
    delimage(p0);
}

void mine::minestart(int x,int y)//随机生成炸弹
{
    while(boom>0)
    {
        int xx=random(Boomsize[nd][1]);
        int yy=random(Boomsize[nd][0]);
        if(MineClearing[xx][yy]==1||(xx==x-1&&yy==y-1))continue;//炸弹不会生成在最开始点击的方块周围
        else if(MineClearing[xx][yy]==1||(xx==x-1&&yy==y))continue;
        else if(MineClearing[xx][yy]==1||(xx==x-1&&yy==y+1))continue;
        else if(MineClearing[xx][yy]==1||(xx==x&&yy==y-1))continue;
        else if(MineClearing[xx][yy]==1||(xx==x&&yy==y))continue;
        else if(MineClearing[xx][yy]==1||(xx==x&&yy==y+1))continue;
        else if(MineClearing[xx][yy]==1||(xx==x+1&&yy==y-1))continue;
        else if(MineClearing[xx][yy]==1||(xx==x+1&&yy==y))continue;
        else if(MineClearing[xx][yy]==1||(xx==x+1&&yy==y+1))continue;
        MineClearing[xx][yy]=1;
        boom--;
    }
    boom=Boom[nd];
    for(int i=0;i<Boomsize[nd][1];i++)
        {
            for(int j=0;j<Boomsize[nd][0];j++)
            {
                cout<<MineClearing[i][j]<<" ";
            }
            cout<<endl;
        }
    cout<<endl;

    MineNumberMark();//记录每个格子周围炸弹数
    dfs(x,y);
}

void mine::MineNumberMark()//记录每个格子附近炸弹数
{
    int MNMark[25][51]={0};//设置缓冲区
    for(int i=1;i<Boomsize[nd][1]+1;i++)
    {
        for(int j=1;j<Boomsize[nd][0]+1;j++)
        {
            MNMark[i][j]=MineClearing[i-1][j-1];
        }
    }

    for(int i=1;i<Boomsize[nd][1]+1;i++)//计算每一个格子附近的炸弹数
    {
        for(int j=1;j<Boomsize[nd][0]+1;j++)
        {
            if(MineClearing[i-1][j-1]==0)
            {
                for(int ii=i-1;ii<i+2;ii++)
                {
                    for(int jj=j-1;jj<j+2;jj++)
                    {
                        if(MNMark[ii][jj]==1)MineNumber[i-1][j-1]++;//算出[x,y]附近有几个炸弹
                    }
                }
            }
            else if(MineClearing[i-1][j-1]==1)MineNumber[i-1][j-1]=9;
        }
    }

    for(int i=0;i<Boomsize[nd][1];i++)
    {
        for(int j=0;j<Boomsize[nd][0];j++)
        {
            cout<<MineNumber[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void mine::dfs(int x,int y)//深搜展开
{
    if(MineNumber[x][y]==0)//如果附近没有炸弹，则全部翻开
    {
        MineMark[x][y]=1;//标记为翻开
        for (int i=x-1;i<x+2;i++)
        {
            for(int j=y-1;j<y+2;j++)
            {
                if(i>=0&&i<Boomsize[nd][1]&&j>=0&&j<Boomsize[nd][0])//一个九宫格里面存在0格子，继续展开
                {
                    if(i==x&&j==y)continue;
                    else
                    {
                        if(MineMark[i][j]==0)//标记为1
                        {
                            MineMark[i][j]=1;
                            mark0(i,j);
                        }
                    }
                }
            }
        }
    }
}

void mine::mark0(int x,int y)//第一次翻开一大片区域 或者翻开0的格子自动翻开一片
{
    PIMAGE pp=newimage();
    switch (markp(x,y))
    {
        case 1 : getimage(pp, "H:/game/MC/1.jpg");break;
        case 2 : getimage(pp, "H:/game/MC/2.jpg");break;
        case 3 : getimage(pp, "H:/game/MC/3.jpg");break;
        case 4 : getimage(pp, "H:/game/MC/4.jpg");break;
        case 5 : getimage(pp, "H:/game/MC/5.jpg");break;
        case 0 : getimage(pp, "H:/game/MC/0.jpg");dfs(x,y);break;
        case 9 : gameover(x,y);break;
    }
    bar(y*l,(x+2)*l,y*l+l-1,(x+2)*l+l-1);
    putimage(y*l,(x+2)*l,l,l,pp,0,0,getwidth(pp),getheight(pp));
    delimage(pp);
}

int mine::markp(int x,int y)
{
    if(MineMark[x][y]==1)//被翻开后自动翻开附近空的
    {
        switch (MineNumber[x][y])
        {
            case 1 : return 1;break;
            case 2 : return 2;break;
            case 3 : return 3;break;
            case 4 : return 4;break;
            case 5 : return 5;break;
            case 0 : return 0;break;
            case 9 : return 9;break;
        }
    }
    return 0;
}

void mine::mark(int x,int y,int m)//翻开格子
{
    PIMAGE pp=newimage();
    PIMAGE qi=newimage();
    getimage(qi, "H:/game/MC/qi.jpg");
    if(m==1&&markp(x,y)!=9)//左键翻开
    {
        switch (markp(x,y))
        {
            case 1 : getimage(pp, "H:/game/MC/1.jpg");break;
            case 2 : getimage(pp, "H:/game/MC/2.jpg");break;
            case 3 : getimage(pp, "H:/game/MC/3.jpg");break;
            case 4 : getimage(pp, "H:/game/MC/4.jpg");break;
            case 5 : getimage(pp, "H:/game/MC/5.jpg");break;
            case 0 : getimage(pp, "H:/game/MC/0.jpg");fan0(x,y);break;
        }
        bar(y*l,(x+2)*l,y*l+l-1,(x+2)*l+l-1);
        putimage(y*l,(x+2)*l,l,l,pp,0,0,getwidth(pp),getheight(pp));
        delimage(pp);
    }
    if(m==1&&markp(x,y)==9)gameover(x,y);
    if(m==2)//右键标记为炸弹
    {
        winflag++;
        //cout<<winflag<<endl;
        MineMark[x][y]=2;
        if(MineMark[x][y]-MineClearing[x][y]==1)boomleftnumber--;
        bar(y*l,(x+2)*l,y*l+l-1,(x+2)*l+l-1);
        putimage(y*l,(x+2)*l,l,l,qi,0,0,getwidth(qi),getheight(qi));
        delimage(qi);
        boomnumber();
    }
    if(winflag==Boom[nd])youwin();
}

void mine::fan0(int x,int y)//翻开的周围没炸弹，则翻开九宫格
{
    if(MineNumber[x][y]==0)//如果附近没有炸弹，则全部翻开
    {
        MineMark[x][y]=1;//标记为翻开

        for (int i=x-1;i<x+2;i++)
        {
            for(int j=y-1;j<y+2;j++)
            {
                if(i>=0&&i<Boomsize[nd][1]&&j>=0&&j<Boomsize[nd][0])
                {
                    if(i==x&&j==y)continue;
                    else
                    {
                        if(MineMark[i][j]==0)//标记为1
                        {
                            MineMark[i][j]=1;
                            mark0(i,j);
                        }
                    }
                }
            }
        }
    }
}

void mine::gameover(int x,int y)//翻开炸弹
{
    PIMAGE p=newimage();
    for(int i=0;i<Boomsize[nd][1];i++)
    {
        for(int j=0;j<Boomsize[nd][0];j++)
        {
            if(MineClearing[i][j]==1&&i==x&&j==y)//boom!
            {
                //cout<<i<<" "<<j<<endl;
                getimage(p,"H:/game/MC/boom!.jpg");
                bar(j*l,(i+2)*l,j*l+l-1,(i+2)*l+l-1);
                putimage(j*l,(i+2)*l,l,l,p,0,0,getwidth(p),getheight(p));
            }
            else if(MineClearing[i][j]==1&&(i!=x||j!=y))//boom
            {
                getimage(p,"H:/game/MC/boom.jpg");
                bar(j*l,(i+2)*l,j*l+l-1,(i+2)*l+l-1);
                putimage(j*l,(i+2)*l,l,l,p,0,0,getwidth(p),getheight(p));
            }
        }
    }
    delimage(p);
    setfont(l, 0, "宋体");
    setcolor(EGERGB(200,0,0));
    setfontbkcolor(0);
    settextjustify(CENTER_TEXT, TOP_TEXT);
	outtextxy(l * Boomsize[nd][0]/2, l * Boomsize[nd][1]/2, "You lost!");
	timemark=false;
	reset(1);
}

int mine::mousekick()//主循环
{
    if (keystate(key_esc))closegraph();
    while(mousemsg())
    {
        mouse_msg msg = getmouse();
        // 鼠标左键按下
        if (msg.is_left() && msg.is_down())
        {
            resetmine(msg.x,msg.y);
            cout<<msg.x<<" "<<msg.y<<endl;
            change(msg.x,msg.y);
            //获取鼠标位置
            if(msg.y>2*l)
            {
                x = msg.y/l-2;
                y = msg.x/l;
                MineMark[x][y]=1;
                if(t==0)//在第一次翻开后随机生成炸弹
                {
                    minestart(x,y);
                    t=1;
                }
                cout<<endl;
                for(int i=0;i<Boomsize[nd][1];i++)
                {
                    for(int j=0;j<Boomsize[nd][0];j++)
                    {
                        cout<<MineMark[i][j]<<" ";
                    }cout<<endl;
                }
                cout<<x<<" "<<y<<endl;
                mark(x,y,1);
            }
        }
        if (msg.is_right() && msg.is_down())
        {
            //获取鼠标位置
            x = msg.y/l-2;
            y = msg.x/l;
            cout<<x<<" "<<y<<endl;
            if(MineMark[x][y]==0)mark(x,y,2);
            else if(MineMark[x][y]==1)continue;
            else if(MineMark[x][y]==2)RemoveMark(x,y);
        }
    }
    return 0;
}

void mine::RemoveMark(int x,int y)//消除标记
{
    winflag--;
    MineMark[x][y]=0;
    if(MineClearing[x][y]-MineMark[x][y]==1)boomleftnumber++;
    PIMAGE pp=newimage();
    getimage(pp, "H:/game/MC/00.jpg");
    bar(y*l,(x+2)*l,y*l+l-1,(x+2)*l+l-1);
    putimage(y*l,(x+2)*l,l,l,pp,0,0,getwidth(pp),getheight(pp));
    delimage(pp);
    boomnumber();
}

void mine::youwin()//游戏胜利
{
    int win=0;
    for(int i=0;i<Boomsize[nd][1];i++)
    {
        for(int j=0;j<Boomsize[nd][0];j++)
        {
            if(MineMark[i][j]+MineClearing[i][j]==3)win++;//记录标记正确数
            cout<<win<<endl;
            if(win==Boom[nd])
            {
                setfont(l, 0, "宋体");
                setcolor(EGERGB(200,0,0));
                setfontbkcolor(0);
                settextjustify(CENTER_TEXT, TOP_TEXT);
                outtextxy(l * Boomsize[nd][0]/2, l * Boomsize[nd][1]/2, "You win!");
                winflag=0;//flag清零
                timemark=false;
                reset(2);
            }
        }
    }
}
