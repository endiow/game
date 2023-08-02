#ifndef MINEFUNCTION_H
#define MINEFUNCTION_H

#include <iostream>
#include <graphics.h>
#include <bits/stdc++.h>

using namespace std;

class mine
{
    public:
        const int l=30;//像素块大小
        const int Boom[4]={10,40,99,200};//炸弹数
        const int Boomsize[4][2]={{9,9},{16,16},{30,16},{50,24}};//不同难度
        bool gamestart();
        void first_backg();
        void main_boomnumber();
        void main_mousekick();
        bool main_timemark();
        void main_time();

    private:
        int nd=0;
        int MineClearing[24][50]={0};//是否为炸弹 1为炸弹 0不是
        int MineMark[24][50]={0};//0未翻开 1翻开 2标记为雷
        int MineNumber[24][50]={0};//周围炸弹数
        int boom=Boom[nd];//炸弹数
        int x=0;
        int y=0;
        int t=0;
        int winflag=0;
        double starttime=0;//开始计时
        int boomleftnumber;//剩余炸弹数
        bool resetflag=false;
        bool game=true;//游戏开始
        bool timemark=false;//开始计时

        void backg();//格子图背景生成
        int mousekick();//鼠标点击
        void minestart(int x,int y);//第一次点击后随机生成炸弹
        void MineNumberMark();//minenumber[][]记录每个格子周围的炸弹数
        int markp(int x,int y);//翻开格子后不同的贴图
        void mark(int x,int y,int m);//左键翻开，右键标记
        void gameover(int x,int y);//翻开炸弹，游戏结束
        void dfs(int x,int y);//第一次翻开或翻开0,展开一大片
        void mark0(int x,int y);//翻开周围炸弹数为0的格子时，自动翻开周围格子，贴图
        void youwin();//获胜
        void RemoveMark(int x,int y);//取消标记
        void fan0(int x,int y);//翻开周围炸弹数为0的格子时，自动翻开周围格子
        void regame(int x,int y);//重新开始
        void rebackg(int x,int y);//重新生成背景
        void setchange();//改变难度栏设置
        void change(int msgx,int msgy);//改变难度
        void reset(int rs);//重置贴图
        void resetmine(int msgx,int msgy);//重置游戏
        void time();//时间栏
        void boomnumber();//实时记录剩余炸弹数
        void hengxian();//两栏之间的横线
        void setbk();//铺上方块
        void setmine();//初始化 mineclearing  minemark
        void setchangereset();//重置栏和难度栏底色
};

#endif
