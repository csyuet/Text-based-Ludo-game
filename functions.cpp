#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <unistd.h>
#include <algorithm>

#include "define.h"
using namespace std;

//Using structs to store the players' conditions

//"Chess" struct is used to store the status of a single chess
struct Chess
{
    //variables for the Chess
    int id;
    string stage;
    int pos;

    //To construct the Chess
    Chess(int id,string stage,int pos)
    {
        this->id=id;
        this->stage=stage;
        this->pos=pos;
    };
};

//"Player" struct is used to store the status of a player
struct Player
{
    //variables for the Player
    string icon;
    vector<Chess> chesss;
    map<string,int> counters;

    //To construct the player and initialize the counters of the player
    Player(string icon)
    {
        this->icon=icon;
        counters["BASE"]=0;
        counters["PEND"]=0;
        counters["ROAD"]=0;
        counters["LAST"]=0;
        counters["GOAL"]=0;
    };
};

//vector is used to store the conditins of all players
vector<Player> players;
vector<string> base(16," ");
vector<string> pend(16," ");
vector<vector<string>> road(52,{" "," "," "," "});
vector<vector<string>> last(24,{" "," "," "," "});


void addp(string s) //constructor
{
    Player p(s);
    players.push_back(p);
}

void Pboard(int n) //the board
{
    system("clear");
    cout<<CLR"                                                                                             \n";
    cout<<"                        "<<RED<<" "<<road[7][2]<<" "<<road[7][0]<<CLR<<GRN<<" "<<road[8][2]<<" "<<road[8][0]<<CLR<<MAG<<" "<<road[9][2]<<" "<<road[9][0]<<CLR<<BLU<<" "<<road[10][2]<<" "<<road[10][0]<<CLR<<RED<<" "<<road[11][2]<<" "<<road[11][0]<<CLR<<GRN<<" "<<road[12][2]<<" "<<road[12][0]<<CLR<<MAG<<" "<<road[13][2]<<" "<<road[13][0]<<CLR<<pend[4]<<" "<<pend[5]<<"                    \n";
    cout<<"                        "<<RED<<" "<<road[7][3]<<" "<<road[7][1]<<CLR<<GRN<<" "<<road[8][3]<<" "<<road[8][1]<<CLR<<MAG<<" "<<road[9][3]<<" "<<road[9][1]<<CLR<<BLU<<" "<<road[10][3]<<" "<<road[10][1]<<CLR<<RED<<" "<<road[11][3]<<" "<<road[11][1]<<CLR<<GRN<<" "<<road[12][3]<<" "<<road[12][1]<<CLR<<MAG<<" "<<road[13][3]<<" "<<road[13][1]<<CLR<<pend[6]<<" "<<pend[7]<<"                    \n";
    cout<<"    "<<MAG<<A"              "<<CLR"                                           "<<BLU"              "<<B<<CLR"\n";                                                                          //s
    cout<<"    "<<MAG<<"     "<<base[0]<<"   "<<base[1]<<"     "<<CLR<<BLU" "<<road[6][2]<<" "<<road[6][0]<<" "<<road[6][1]<<" "<<road[6][3]<<CLR"          "<<BLU<<last[6][2]<<last[6][0]<<last[6][1]<<last[6][3]<<CLR"          "<<BLU<<" "<<road[14][2]<<" "<<road[14][0]<<" "<<road[14][1]<<" "<<road[14][3]<<CLR<<BLU"     "<<base[4]<<"   "<<base[5]<<"     "<<CLR" \n";                                   //l
    cout<<"    "<<MAG<<"     "<<base[2]<<"   "<<base[3]<<"     "<<CLR"                                           "<<BLU<<"     "<<base[6]<<"   "<<base[7]<<"     "<<CLR"\n";                                                                        //s
    cout<<"    "<<MAG<<"               "<<CLR<<MAG" "<<road[5][2]<<" "<<road[5][0]<<" "<<road[5][1]<<" "<<road[5][3]<<CLR"          "<<BLU<<last[7][2]<<last[7][0]<<last[7][1]<<last[7][3]<<CLR"          "<<RED<<" "<<road[15][2]<<" "<<road[15][0]<<" "<<road[15][1]<<" "<<road[15][3]<<CLR<<BLU<<"               "<<CLR" \n";                                 //l
    cout<<CLR"                                            \n";                                                                                                                                                                                     //s
    cout<<pend[0]<<" "<<pend[1]<<" "<<GRN<<" "<<road[0][2]<<" "<<road[0][0]<<CLR<<MAG" "<<road[1][2]<<" "<<road[1][0]<<CLR<<BLU<<" "<<road[2][2]<<" "<<road[2][0]<<CLR<<RED" "<<road[3][2]<<" "<<road[3][0]<<CLR<<GRN" "<<road[4][2]<<" "<<road[4][0]<<CLR"          "<<BLU<<last[8][2]<<last[8][0]<<last[8][1]<<last[8][3]<<CLR"          "<<GRN<<" "<<road[16][2]<<" "<<road[16][0]<<CLR<<MAG" "<<road[17][2]<<" "<<road[17][0]<<CLR<<BLU" "<<road[18][2]<<" "<<road[18][0]<<CLR<<RED" "<<road[19][2]<<" "<<road[19][0]<<CLR<<GRN<<" "<<road[20][2]<<" "<<road[20][0]<<CLR"\n"; 
    cout<<pend[2]<<" "<<pend[3]<<" "<<GRN<<" "<<road[0][3]<<" "<<road[0][1]<<CLR<<MAG" "<<road[1][3]<<" "<<road[1][1]<<CLR<<BLU<<" "<<road[2][3]<<" "<<road[2][1]<<CLR<<RED" "<<road[3][3]<<" "<<road[3][1]<<CLR<<GRN" "<<road[4][3]<<" "<<road[4][1]<<CLR"                         "<<GRN<<" "<<road[16][3]<<" "<<road[16][1]<<CLR<<MAG" "<<road[17][3]<<" "<<road[17][1]<<CLR<<BLU" "<<road[18][3]<<" "<<road[18][1]<<CLR<<RED" "<<road[19][3]<<" "<<road[19][1]<<CLR<<GRN<<" "<<road[20][3]<<" "<<road[20][1]<<CLR"\n";               
    cout<<"                                       "<<BLU<<last[9][2]<<last[9][0]<<last[9][1]<<last[9][3]<<CLR<<endl;                                                                                                                        //s
    cout<<RED" "<<road[51][2]<<" "<<road[51][0]<<" "<<road[51][1]<<" "<<road[51][3]<<CLR"                                                                 "<<MAG" "<<road[21][2]<<" "<<road[21][0]<<" "<<road[21][1]<<" "<<road[21][3]<<CLR"\n";                                                                            //l
    cout<<"                                       "<<BLU<<last[10][2]<<last[10][0]<<last[10][1]<<last[10][3]<<CLR<<endl;                                                                                                                        //s
    cout<<BLU" "<<road[50][2]<<" "<<road[50][0]<<" "<<road[50][1]<<" "<<road[50][3]<<CLR"                                                                 "<<BLU" "<<road[22][2]<<" "<<road[22][0]<<" "<<road[22][1]<<" "<<road[22][3]<<CLR"\n";                                                                            //l
    cout<<"                                       "<<BLU<<last[11][2]<<last[11][0]<<last[11][1]<<last[11][3]<<CLR<<endl;    //s
    cout<<MAG" "<<road[49][2]<<" "<<road[49][0]<<" "<<road[49][1]<<" "<<road[49][3]<<CLR<<MAG<<last[0][2]<<last[0][0]<<last[0][1]<<last[0][3]<<CLR<<MAG<<last[1][2]<<last[1][0]<<last[1][1]<<last[1][3]<<CLR<<MAG<<last[2][2]<<last[2][0]<<last[2][1]<<last[2][3]<<CLR<<MAG<<last[3][2]<<last[3][0]<<last[3][1]<<last[3][3]<<CLR<<MAG<<last[4][2]<<last[4][0]<<last[4][1]<<last[4][3]<<CLR<<MAG<<last[5][2]<<last[5][0]<<last[5][1]<<last[5][3]<<CLR"     "<<RED<<last[17][2]<<last[17][0]<<last[17][1]<<last[17][3]<<CLR<<RED<<last[16][2]<<last[16][0]<<last[16][1]<<last[16][3]<<CLR<<RED<<last[15][2]<<last[15][0]<<last[15][1]<<last[15][3]<<CLR<<RED<<last[14][2]<<last[14][0]<<last[14][1]<<last[14][3]<<CLR<<RED<<last[13][2]<<last[13][0]<<last[13][1]<<last[13][3]<<CLR<<RED<<last[12][2]<<last[12][0]<<last[12][1]<<last[12][3]<<CLR<<RED" "<<road[23][2]<<" "<<road[23][0]<<" "<<road[23][1]<<" "<<road[23][3]<<CLR"\n";//l
    cout<<"                                       "<<GRN<<last[23][2]<<last[23][0]<<last[23][1]<<last[23][3]<<CLR<<endl;    //s
    cout<<GRN" "<<road[48][2]<<" "<<road[48][0]<<" "<<road[48][1]<<" "<<road[48][3]<<CLR"                                                                 "<<GRN" "<<road[24][2]<<" "<<road[24][0]<<" "<<road[24][1]<<" "<<road[24][3]<<CLR"\n";//l
    cout<<"                                       "<<GRN<<last[22][2]<<last[22][0]<<last[22][1]<<last[22][3]<<CLR<<endl;//s
    cout<<RED" "<<road[47][2]<<" "<<road[47][0]<<" "<<road[47][1]<<" "<<road[47][3]<<CLR"                                                                 "<<MAG" "<<road[25][2]<<" "<<road[25][0]<<" "<<road[25][1]<<" "<<road[25][3]<<CLR"\n";//l
    cout<<"                                       "<<GRN<<last[21][2]<<last[21][0]<<last[21][1]<<last[21][3]<<CLR<<endl;//s
    cout<<"    "<<BLU" "<<road[46][2]<<" "<<road[46][0]<<CLR<<MAG<<" "<<road[45][2]<<" "<<road[45][0]<<CLR<<GRN<<" "<<road[44][2]<<" "<<road[44][0]<<CLR<<RED" "<<road[43][2]<<" "<<road[43][0]<<CLR<<BLU" "<<road[42][2]<<" "<<road[42][0]<<CLR"                         "<<BLU<<" "<<road[30][2]<<" "<<road[30][0]<<CLR<<MAG" "<<road[29][2]<<" "<<road[29][0]<<CLR<<GRN" "<<road[28][2]<<" "<<road[28][0]<<CLR<<RED" "<<road[27][2]<<" "<<road[27][0]<<CLR<<BLU<<" "<<road[26][2]<<" "<<road[26][0]<<CLR<<pend[8]<<" "<<pend[9]<<" \n";               
    cout<<"    "<<BLU" "<<road[46][3]<<" "<<road[46][1]<<CLR<<MAG<<" "<<road[45][3]<<" "<<road[45][1]<<CLR<<GRN<<" "<<road[44][2]<<" "<<road[44][1]<<CLR<<RED" "<<road[43][3]<<" "<<road[43][1]<<CLR<<BLU" "<<road[42][3]<<" "<<road[42][1]<<CLR"          "<<GRN<<last[20][2]<<last[20][0]<<last[20][1]<<last[20][3]<<CLR"          "<<BLU<<" "<<road[30][3]<<" "<<road[30][1]<<CLR<<MAG" "<<road[29][3]<<" "<<road[29][1]<<CLR<<GRN" "<<road[28][3]<<" "<<road[28][1]<<CLR<<RED" "<<road[27][3]<<" "<<road[27][1]<<CLR<<BLU<<" "<<road[26][3]<<" "<<road[26][1]<<CLR<<pend[10]<<" "<<pend[11]<<" \n"; 
    cout<<CLR"                                            \n";
    cout<<"    "<<GRN<<"               "<<CLR<<MAG" "<<road[41][2]<<" "<<road[41][0]<<" "<<road[41][1]<<" "<<road[41][3]<<CLR"          "<<GRN<<last[19][2]<<last[19][0]<<last[19][1]<<last[19][3]<<CLR"          "<<RED<<" "<<road[31][2]<<" "<<road[31][0]<<" "<<road[31][1]<<" "<<road[31][3]<<CLR<<RED<<"               "<<CLR" \n";                                 //l
    cout<<"    "<<GRN<<"     "<<base[12]<<"   "<<base[13]<<"     "<<CLR"                                           "<<RED<<"     "<<base[8]<<"   "<<base[9]<<"     "<<CLR"\n";//s
    cout<<"    "<<GRN<<"     "<<base[14]<<"   "<<base[15]<<"     "<<CLR<<GRN" "<<road[40][2]<<" "<<road[40][0]<<" "<<road[40][1]<<" "<<road[40][3]<<CLR"          "<<GRN<<last[18][2]<<last[18][0]<<last[18][1]<<last[18][3]<<CLR"          "<<GRN<<" "<<road[32][2]<<" "<<road[32][0]<<" "<<road[32][1]<<" "<<road[32][3]<<CLR<<RED"     "<<base[10]<<"   "<<base[11]<<"     "<<CLR" \n";//l
    cout<<"    "<<GRN<<D"              "<<CLR"                                           "<<RED"              "<<C<<CLR"\n";//l
    cout<<"                    "<<pend[12]<<" "<<pend[13]<<" "<<RED<<" "<<road[39][2]<<" "<<road[39][0]<<CLR<<BLU<<" "<<road[38][2]<<" "<<road[38][0]<<CLR<<MAG<<" "<<road[37][2]<<" "<<road[37][0]<<CLR<<GRN<<" "<<road[36][2]<<" "<<road[36][0]<<CLR<<RED<<" "<<road[35][2]<<" "<<road[35][0]<<CLR<<BLU<<" "<<road[34][2]<<" "<<road[34][0]<<CLR<<MAG<<" "<<road[33][2]<<" "<<road[33][0]<<CLR"                      \n";
    cout<<"                    "<<pend[14]<<" "<<pend[15]<<" "<<RED<<" "<<road[39][3]<<" "<<road[39][1]<<CLR<<BLU<<" "<<road[38][3]<<" "<<road[38][1]<<CLR<<MAG<<" "<<road[37][3]<<" "<<road[37][1]<<CLR<<GRN<<" "<<road[36][3]<<" "<<road[36][1]<<CLR<<RED<<" "<<road[35][3]<<" "<<road[35][1]<<CLR<<BLU<<" "<<road[34][3]<<" "<<road[34][1]<<CLR<<MAG<<" "<<road[33][3]<<" "<<road[33][1]<<CLR"                      \n";
    cout<<"It's Player "<<players[n].icon<<"'s turn!"<<endl;
 }

void fileOP(int playerN) //file output
{
    while (true)
    {
        string *filename=new string;
        ofstream fout;
        cout<<"Input the export file name: \n";
        cin>>*filename;
        if (filename->length()<filename->find(".txt") || filename->find(".txt")<0) 
            *filename+=".txt";
        fout.open(*filename);
        if (fout.fail()) cout<<"ERROR Please try again."<<endl;
        else
        {
            vector<Chess>::iterator itr;
            for (int i=0;i<4;i++)
            {
                fout<<"Player "<<players[i].icon<<endl;
                for (itr=players[i].chesss.begin();itr!=players[i].chesss.end();itr++)
                {
                    fout<<itr->id<<' '<<itr->stage<<' '<<itr->pos<<endl;
                }
            }
            fout<<playerN;
            fout.close();
            delete filename;
            break;
        }
    }
}

void fileIP(string file,int &playerN) //file input
{
    ifstream fin;
    fin.open(file);
    if (fin.fail()) 
    {
        cout<<"ERROR Please try again."<<endl;
        return;
    }
    else 
    {    
        string command;
        int i=-1;
        while (fin>>command)        
        {
            int chess_pos,chess_id;
            if (command=="Player")
            {
                string chess_icon;
                fin>>chess_icon;
                addp(chess_icon);
                i++;
                for (int j=0;j<4;j++)
                {
                    fin>>chess_id>>command>>chess_pos;
                    Chess ch(chess_id,command,chess_pos);
                    players[i].chesss.push_back(ch);
                    if (command=="BASE")
                    {
                        base[chess_pos]=players[i].icon;
                        players[i].counters[command]+=1;
                    }
                    else if (command=="PEND")
                    {
                        pend[chess_pos]=players[i].icon;
                        players[i].counters[command]+=1;
                    }
                    else if (command=="ROAD")
                    {
                        road[chess_pos/10-1][chess_pos%10]=players[i].icon;
                        players[i].counters[command]+=1;
                    }
                    else if (command=="LAST")
                    {
                        last[chess_pos/10-1][chess_pos%10]=players[i].icon;
                        players[i].counters[command]+=1;
                    }
                }
            }
            else playerN=stoi(command);
        }
        
    }
    fin.close();  
}

int iconfind(string target) //find the icon
{
    for (int i=0;i<4;i++)
    {
        if (players[i].icon==target) return i;
    }
    return -1;
}

int havedifferent(string icon,int pos) //check if there is different chess in the same box
{
    for (int i=0;i<4;i++)
    {
        if (road[pos/10-1][i]!=icon && road[pos/10-1][i]!=" ") return i;   
    }
    return -1;
}

int findchess(int playernum,int pos) //fine the player number of the specific chess
{
    for (int i=0;i<4;i++)
    {
        if (players[playernum].chesss[i].pos==pos) return i;
    }
    return -1;
}

int findplayer(int pos,int i)   //find the 
{

    for (int pn=0;pn<4;pn++)
    {
        if (players[pn].icon==road[pos][i]) return pn;
    }
    return -1;
}

int findspace(int pos,string stage,string icon)
{
    if (stage=="ROAD")
    {
        for (int i=0;i<4;i++)
        {
            if (road[pos][i]==" ") return i;
            else if (road[pos][i]!=icon) return -1;

        }
    }
    if (stage=="LAST")
    {
        for (int i=0;i<4;i++)
        {
            if (last[pos][i]==" ") return i;
        }
    }
    if (stage=="PEND")
    {
        for (int i=0;i<4;i++)
        {
            if (pend[pos/4*4+i]==" ") return pos/4*4+i;
        }
    }
    return -1;
}

void ReturnHome(int pos,int pn,int cn,int j)
{
    cout<<"on9 id:"<<players[pn].chesss[cn].id<<" on9 stage:"<<players[pn].chesss[cn].stage<<" on9 pos:"<<players[pn].chesss[cn].pos<<endl;
    players[pn].chesss[cn].stage="BASE";
    players[pn].chesss[cn].pos=players[pn].chesss[cn].id;
    base[players[pn].chesss[cn].id]=players[pn].icon;
    cout<<"on9 id:"<<players[pn].chesss[cn].id<<" on9 stage:"<<players[pn].chesss[cn].stage<<" on9 pos:"<<players[pn].chesss[cn].pos<<endl;
    if (road[pos/10-1][j]==players[pn].icon)
        road[pos/10-1][j]=" ";
}

void animationboard(int num,string *m){
    Pboard(num);
    cout<<*m;
    sleep(1);
}

void loadsavebar(int statusnum){
    string space[10]={"   ","         ","             ","                    ","                            ","                                ","                                ","                                       ","                                           ","                                             "};
    string status[2]={"Loading...","Saving...."};
    srand(time(0));
    for (int t=0;t<10;t++){
        sleep(rand()%2);
        system("clear");
        cout<<CLR"                         "<<status[statusnum]<<CLR"                        "<<endl;
        cout<<CLR"       "<<WTE<<space[t]<<CLR"       "<<endl;
        cout<<CLR"       "<<WTE<<space[t]<<CLR"       "<<endl;
    }
}

int chessdistance(int i, int z){
    int *pos=new int (players[i].chesss[z].pos);
    *pos=*pos/10-1;
    if (players[i].chesss[z].stage=="ROAD")
    {
        return 55-(*pos-52/4*i+52*(i>0)*(*pos<(52/4*i)));
    }
    return (6*(i+1)-1)-*pos;
}

void changeboard(int choice,int dn,int pn,string *m)
{
    int *movepos,*currentpos,nextpos,direction=1;
    vector<string> temp(2," ");
    for (int steps=0;steps<dn;steps++)
    {
        if (players[pn].chesss[choice].stage=="BASE")
        {
            *movepos=findspace(players[pn].chesss[choice].pos,"PEND",players[pn].icon);
            pend[*movepos]=players[pn].icon;
            base[players[pn].chesss[choice].pos]=" ";
            players[pn].chesss[choice].pos=(*movepos);
            players[pn].chesss[choice].stage="PEND";
            break;
        }
        else if (players[pn].chesss[choice].stage=="PEND")
        {
            players[pn].chesss[choice].stage="ROAD";
            pend[players[pn].chesss[choice].pos]=" ";
            nextpos=pn*13;
            *movepos=findspace(nextpos,"ROAD",players[pn].icon);
            if (*movepos>9)
            {
                temp.push_back(players[*movepos/10-1].icon);
                temp.erase(temp.begin());
                *movepos=0;
                *m=players[*movepos/10-1].icon+"BOOM!\n"+*m;
            }
            else 
            {
                temp.push_back(" ");
                temp.erase(temp.begin());
            }
            road[nextpos][*movepos]=players[pn].icon;
            players[pn].chesss[choice].pos=(nextpos+1)*10+(*movepos);
            animationboard(pn,m);
        }
        else if (players[pn].chesss[choice].stage=="ROAD")
        {
            (*currentpos)=players[pn].chesss[choice].pos/10-1;
            if ((*currentpos)+1==52) nextpos=0;
            else nextpos=(*currentpos)+1;
            *movepos=findspace(nextpos,"ROAD",players[pn].icon);
            if (*movepos==-1) *movepos=0;
            temp.push_back(road[nextpos][*movepos]);
            temp.erase(temp.begin());
            if (chessdistance(pn,choice)==6 && steps+1<=dn)
            {
                players[pn].chesss[choice].stage="LAST";
                road[*currentpos][players[pn].chesss[choice].pos%10]=temp[0];
                *movepos=findspace(6*pn,"LAST",players[pn].icon);
                last[6*pn][*movepos]=players[pn].icon;
                players[pn].chesss[choice].pos=(6*pn+1)*10+*movepos;
                animationboard(pn,m);
            }
            else
            {
                road[*currentpos][players[pn].chesss[choice].pos%10]=temp[0];
                temp.push_back(road[nextpos][*movepos]);
                temp.erase(temp.begin());
                road[nextpos][*movepos]=players[pn].icon;
                players[pn].chesss[choice].pos=((nextpos+1)*10+(*movepos));
                animationboard(pn,m);
            }     
            
        }
        else if (players[pn].chesss[choice].stage=="LAST")
        {
            (*currentpos)=players[pn].chesss[choice].pos/10-1;
            if (chessdistance(pn,choice)==0) direction=-1; 
            nextpos=(*currentpos)+direction;
            *movepos=findspace(nextpos,"LAST",players[pn].icon);
           last[nextpos][*movepos]=players[pn].icon;
           last[*currentpos][players[pn].chesss[choice].pos%10]=" ";
           players[pn].chesss[choice].pos=((nextpos+1)*10+(*movepos));
           animationboard(pn,m);
       }
   }
   if (players[pn].chesss[choice].stage=="ROAD")
   {
       if ((chessdistance(pn,choice)>6) and ((players[pn].chesss[choice].pos/10-1)%4-1==(pn) or ((players[pn].chesss[choice].pos/10-1)%4-1==-1 and pn==3)))
       {
           *m="Weee~~~\n"+*m;
           (*currentpos)=players[pn].chesss[choice].pos/10-1;
           if ((*currentpos)+4>=52) nextpos=(*currentpos+4)%52;
           else nextpos=(*currentpos)+4;
           *movepos=findspace(nextpos,"ROAD",players[pn].icon);
           if (*movepos==-1) *movepos=0;
           road[*currentpos][players[pn].chesss[choice].pos%10]=temp[0];
           temp.push_back(road[nextpos][*movepos]);
           temp.erase(temp.begin());
           road[nextpos][*movepos]=players[pn].icon;
           players[pn].chesss[choice].pos=((nextpos+1)*10+(*movepos));
           animationboard(pn,m);
       }
       if (temp[0]!=" " or havedifferent(players[pn].icon,players[pn].chesss[choice].pos)!=-1)
       {
           *m="BOOM!!!\n"+*m;
           if (temp[0]!=" ")
           {
               int i=players[pn].chesss[choice].pos;
               int returnPN=iconfind(temp[0]);
               int returnCN=findchess(returnPN,i);
               ReturnHome(i,returnPN,returnCN,i%10);
           }
           animationboard(pn,m);
       }
      
   }
}
 
int findchoice(vector<int>possiblechoices,int choice,int dicenum,int i,string *menu)
{
   vector<int>::iterator itr;
   for (itr=possiblechoices.begin();itr!=possiblechoices.end();itr++)
   {
       if (*itr==choice-1)
       {
           changeboard(choice-1,dicenum,i,menu);
           return 1;
       }
   }
   return 0;
}
 
void movemenu(int i, int dicenum, int six){
   int choice;
   vector<int> possiblechoices;
   string *menu = new string("Make your move!\n");
   string valid="";
   if (six==3) {
       cout<<"OOPS! 6 again!\n";
       return;
   }
   if (six>0) *menu="Roll one more time!"+*menu;
   for (int z=0;z<4;z++){
       if (dicenum%2==0 && players[i].chesss[z].stage=="BASE")
       {
           *menu+=players[i].icon+to_string(z+1)+": Base\n";
           possiblechoices.push_back(z);
       }
       else if (players[i].chesss[z].stage=="PEND")
       {
           *menu+=players[i].icon+to_string(z+1)+": Ready to flight\n";
           possiblechoices.push_back(z);
       }
       else if (players[i].chesss[z].stage=="ROAD" || players[i].chesss[z].stage=="LAST")
       {
           *menu+=players[i].icon+to_string(z+1)+": "+to_string(chessdistance(i,z))+" away from the goal\n";
           possiblechoices.push_back(z);
       }
   }
   if (possiblechoices.size()==0)
   {
       Pboard(i);
       cout<<"Your dice number is: "<<dicenum<<"\nNo move can be made.\n(Input any characters to continue)\n";
       cin>>valid;
       return;
   }
   else
   {
       *menu="Your dice number is: "+to_string(dicenum)+"\n"+*menu;
       while (true)
       {
           Pboard(i);
           cout<<*menu;
           cout<<valid+"Please select which chess to move : ";
           cin>>choice;
           if (findchoice(possiblechoices,choice,dicenum,i,menu)) break;
           else valid="Invalid input!\n";
       }
   }
  
}
 
int dice(){
   srand(time(0));
   return (rand()%6)+1;
}
 
int rolldice(int i,int &six){
   int dicenum=dice();
   if (dicenum==6)
   {
       six++;
       movemenu(i, dicenum,six);
       return 1;
   }
   else
   {
       movemenu(i,dicenum,0);
       return 0;
   }
  
}
 
bool playerselectionmenu(int num){
   int choice,countsix=0;
   cout<<"1. Roll the dice"<<endl;
   cout<<"2. Save and quit the game"<<endl;
   cout<<"Please select (1/2): ";
   cin>>choice;
   while (true)
   {
       if (choice==1){
           if (rolldice(num,countsix))
           {
               countsix++;
               if (countsix>0)
               {
                   Pboard(num);
                   cout<<"You can roll the dice again!\n1. Roll the dice\n";
                   cout<<"2. Save and quit the game"<<endl;
                   cout<<"Please select (1/2): ";
                   cin>>choice;
                   continue;
               }
           }
           else return 1;
       }
       else if (choice==2){
           fileOP(num);
           loadsavebar(1);
           return 0;
       }
       Pboard(num);
       cout<<"1. Roll the dice"<<endl;
       cout<<"2. Save and quit the game"<<endl;
       cout<<"Invalid input!\n";
       cout<<"Please select (1/2): ";
       cin>>choice;
   }
}

int countscore(int pn)//count the score of each player base on the stage of their chess
{
   for (int i=0;i<4;i++)
   {
       if (players[pn].chesss[i].stage=="BASE") players[pn].counters["BASE"]++;//count the score of player’s chess in stage “BASE”
       if (players[pn].chesss[i].stage=="PEND") players[pn].counters["PEND"]++;//count the score of player’s chess in stage “PEND”
       if (players[pn].chesss[i].stage=="ROAD") players[pn].counters["ROAD"]++;//count the score of player’s chess in stage “ROAD”
       if (players[pn].chesss[i].stage=="LAST") players[pn].counters["LAST"]++;//count the score of player’s chess in stage “LAST”
       if (players[pn].chesss[i].stage=="GOAL") players[pn].counters["GOAL"]++;//count the score of player’s chess in stage “GOAL”
   }
   return players[pn].counters["BASE"]*1+players[pn].counters["PEND"]*2+players[pn].counters["ROAD"]*3+players[pn].counters["LAST"]*5+players[pn].counters["GOAL"]*10;//count the score of player with different weighting for the stages
}

 
void printscore(int pn,int score1, int score2, int score3, int score4){
  string *valid=new string("");
  system("clear");
  sleep(1);
  system("clear");
  cout<<CLR"                                     "<<RED"   "<<CLR"      "<<WTE"      "<<CLR"                                                          "<<endl;
  cout<<CLR"                                     "<<RED"   "<<CLR"   "<<WTE"  "<<CLR"      "<<WTE"  "<<CLR"                                                       "<<endl;
  cout<<CLR"                                  "<<RED"      "<<CLR"   "<<WTE"  "<<CLR"               "<<WTE"    "<<CLR"        "<<WTE"    "<<CLR"     "<<WTE"  "<<CLR"  "<<WTE"    "<<CLR"     "<<WTE"    "<<CLR"  "<<endl;
  cout<<CLR"        "<<RED"                                "<<CLR"      "<<WTE"      "<<CLR"     "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"     "<<CLR"       "<<WTE"  "<<CLR"    "<<WTE"  "<<endl;
  cout<<CLR"     "<<GRY"    "<<RED"  "<<GRY"  "<<RED"                       "<<WTE"   "<<CLR"             "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"          "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"          "<<WTE"          "<<endl;
  cout<<CLR"  "<<WTE"            "<<GRY"      "<<WTE"          "<<GRY"    "<<CLR"       "<<WTE"  "<<CLR"      "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"          "<<WTE"  "<<CLR"       "<<endl;
  cout<<CLR"  "<<WTE"                           "<<CLR"                "<<WTE"      "<<CLR"        "<<WTE"    "<<CLR"        "<<WTE"    "<<CLR"     "<<WTE"  "<<CLR"             "<<WTE"    "<<CLR"  "<<endl;//display airplane and “Score”
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<WTE"                                                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                        "<<"Player 1: "<<CLR"                         "<<score1<<"                                                  "<<endl;//display score of player1
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                        "<<"Player 2: "<<CLR"                         "<<score2<<"                                                  "<<endl;//display score of player 2
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                        "<<"Player 3: "<<CLR"                         "<<score3<<"                                                  "<<endl;//display score of player 3
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                        "<<"Player 4: "<<CLR"                         "<<score4<<"                                                  "<<endl;//display score of player 4
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<WTE"      "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"     "<<endl;
  cout<<WTE"                                                                                                                 "<<CLR<<endl;
  cout<<"CONGRATULATIONS to Player "<<players[pn].icon<<" !!\n";//display icon of winner
  cout<<"(Input any characters to continue)\n";
  cin>>*valid;
}
 
void game(int num)
{
   Pboard(num);
   while (playerselectionmenu(num))
   {
       if (num<3) num+=1;
       else num=0;
       Pboard(num);
   }   
 
   printscore(num,countscore(0),countscore(1),countscore(2),countscore(3));
}
 
void instruction(){
  string *valid=new string;
  sleep(1);
  system("clear");
   cout<<CLR"                                     "<<RED"   "<<CLR"   "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"                                         "<<WTE"         "<<CLR"    "<<endl;
  cout<<CLR"                                     "<<RED"   "<<CLR"   "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"                                      "<<WTE"  "<<CLR"         "<<WTE"  "<<CLR" "<<endl;
  cout<<CLR"                                  "<<RED"      "<<CLR"   "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"      "<<WTE"    "<<CLR"     "<<WTE"  "<<CLR"        "<<WTE"  "<<CLR"                  "<<WTE"  "<<CLR" "<<endl;
  cout<<CLR"        "<<RED"                                "<<CLR"   "<<WTE"           "<<CLR"   "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"        "<<WTE"  "<<CLR"               "<<WTE"  "<<CLR"    "<<endl;
  cout<<CLR"     "<<GRY"    "<<RED"  "<<GRY"  "<<RED"                       "<<WTE"   "<<CLR"   "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"   "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"            "<<WTE"  "<<CLR"       "<<endl;
  cout<<CLR"  "<<WTE"            "<<GRY"      "<<WTE"          "<<GRY"    "<<CLR"       "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"   "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"                       "<<endl;
  cout<<CLR"  "<<WTE"                           "<<CLR"             "<<WTE"  "<<CLR"     "<<WTE"  "<<CLR"      "<<WTE"    "<<CLR"        "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"               "<<WTE"  "<<CLR"       "<<endl;//display airplane and  “How?”
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<WTE"                                                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"1.Each player would be given four chess. Each round,they will have a chance to roll a "<<CLR"                 "<<endl;//display instructions of the game
  cout<<CLR"           "<<"dice and move their chess accordingly."<<CLR"                                                               "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"2.For number \"2\", \"4\", \"6\" rolled from the dice, players can choose to move their chess"<<CLR"                "<<endl;
  cout<<CLR"           "<<"from base to ready position. For number \"6\" rolled from the dice, players can have"<<CLR"                   "<<endl;
  cout<<CLR"           "<<"an extra chance to roll the dice."<<CLR"                                                                    "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"3.If the chess landed on the box that have that same colour as the player, the chess"<<CLR"                   "<<endl;
  cout<<CLR"           "<<"will jump to the next box that has the same colour."<<CLR"                                                  "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"4.If the chess landed on the box with chess of other players in it, chess of other players"<<CLR"             "<<endl;
  cout<<CLR"           "<<"will return to their base."<<CLR"                                                                           "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"5.If the two rules above happened at the same time, chess of other players will still"<<CLR"                  "<<endl;
  cout<<CLR"           "<<"return to their base, but the player's chess would not further move to the next box"<<CLR"                  "<<endl;
  cout<<CLR"           "<<"with the same colour"<<CLR"                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"6.The first player with all chess reached finish box will be the winner."<<CLR"                               "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"7.To reach to the finish box,the chess will have to go around the board to enter the"<<CLR"                   "<<endl;
  cout<<CLR"           "<<"finish path and roll the dice with exact number to reach the finish box."<<CLR"                             "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"         "<<"8.Score will be counted according to the chess movement with different weighting."<<CLR"                      "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<CLR"                                                                                                                 "<<endl;
  cout<<WTE"      "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"         "<<WTE"         "<<CLR"     "<<endl;//display footer
  cout<<WTE"                                                                                                                 "<<CLR<<endl;
  cout<<"Input any characters to start the game...\n";//promt user’s acknowledgement
  cin>>*valid;
  system("clear");
}
 
void quitgame ()
{
   sleep(1);
   system("clear");
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"    "<<WTE"        "<<BLU"                                                                  "<<endl;
   cout<<BLU"    "<<WTE"            "<<BLU"                                                              "<<endl;
   cout<<BLU"        "<<WTE"        "<<BLU"                          "<<WTE"    "<<BLU"  "<<WTE"        "<<BLU"                    "<<endl;
   cout<<BLU"                                      "<<WTE"                      "<<BLU"                  "<<endl;
   cout<<BLU"                    "<<WTE"    "<<BLU"                                                      "<<endl;
   cout<<BLU"                  "<<WTE"        "<<BLU"                                                    "<<endl;//last line of sky
   cout<<BLU"   "<<CLR"  "<<BLU"                                                                         "<<endl;
   cout<<CLR"  "<<WTE"  "<<CLR"  "<<BLU"                                                                      "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"  "<<CLR"  "<<BLU"                                                                   "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"  "<<CLR"  "<<BLU"                      "<<CLR"                       "<<BLU"                     "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"  "<<CLR"  "<<BLU"                  "<<CLR"   "<<WTE"                       "<<CLR"     "<<BLU"               "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"     "<<CLR"  "<<BLU"   "<<CLR"           "<<WTE"                                 "<<CLR"  "<<BLU"            "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"        "<<CLR"  "<<WTE"  "<<RED"    "<<WTE"  "<<RED"  "<<WTE"           "<<CLR"  "<<WTE"  "<<CLR"  "<<WTE"  "<<CLR"    "<<WTE"  "<<CLR"      "<<BLU"          "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"              "<<RED"    "<<WTE"  "<<RED"  "<<WTE"           "<<GRY"   "<<WTE"  "<<GRY"   "<<WTE"  "<<GRY"     "<<WTE"  "<<GRY"       "<<CLR"   "<<BLU"      "<<endl;
   cout<<BLU"   "<<CLR"  "<<GRY"  "<<WTE"                "<<RED"   "<<WTE" "<<RED"  "<<WTE"                                        "<<CLR"  "<<BLU"   "<<endl;
   cout<<CLR"  "<<GRY"   "<<WTE"     "<<GRY"   "<<WTE"         "<<RED"   "<<WTE" "<<RED"  "<<WTE"                                      "<<GRY"  "<<CLR"  "<<BLU"   "<<endl;
   cout<<CLR"              "<<GRY"            "<<RED"   "<<WTE" "<<RED"  "<<WTE"  "<<CLR"  "<<GRY"  "<<WTE"                         "<<GRY"   "<<CLR" "<<BLU"      "<<endl;
   cout<<BLU"               "<<CLR"    "<<GRY"       "<<RED"   "<<WTE" "<<RED"  "<<CLR"  "<<GRY"   "<<WTE"               "<<CLR"  "<<WTE"      "<<GRY"  "<<CLR"  "<<BLU"        "<<endl;
   cout<<BLU"                    "<<CLR"             "<<GRY"   "<<WTE"               "<<CLR"   "<<WTE"  "<<GRY"     "<<CLR"  "<<BLU"           "<<endl;
   cout<<BLU"                             "<<CLR"  "<<GRY"  "<<WTE"               "<<CLR"               "<<BLU"             "<<endl;
   cout<<BLU"                          "<<CLR"  "<<GRY"   "<<WTE"               "<<CLR"  "<<BLU"                            "<<endl;
   cout<<BLU"                             "<<CLR"                  "<<BLU"                               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   sleep(3);
   system("clear");
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"    "<<WTE"        "<<BLU"                                                                  "<<endl;
   cout<<BLU"    "<<WTE"            "<<BLU"                                                              "<<endl;
   cout<<BLU"        "<<WTE"        "<<BLU"                          "<<WTE"    "<<BLU"  "<<WTE"        "<<BLU"                    "<<endl;
   cout<<BLU"                                      "<<WTE"                      "<<BLU"                  "<<endl;
   cout<<BLU"                    "<<WTE"    "<<BLU"                                                      "<<endl;
   cout<<BLU"                  "<<WTE"        "<<BLU"                                                    "<<endl;//last line of sky
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"      "<<CLR"          "<<BLU"        "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"     "<<CLR"          "<<BLU"              "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"     "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"     "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"     "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"     "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"   "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"   "<<CLR"  "<<BLU"       "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"          "<<BLU"          "<<CLR"  "<<BLU"   "<<CLR"  "<<BLU"       "<<CLR"        "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"  "<<BLU"        "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"          "<<CLR"  "<<BLU"               "<<endl;
   cout<<BLU"      "<<CLR"          "<<BLU"             "<<CLR"  "<<BLU"          "<<CLR"          "<<BLU"               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   cout<<BLU"                                                                               "<<endl;
   cout<<CLR;
}
 
void startmenu(){
   int choice,playerN;
   string file;
   while (choice!=3)
   {
       system("clear");
       cout<<CLR"          "<<GRN"  "<<CLR"        "<<MAG"  "<<CLR"     "<<MAG"  "<<CLR" "<<BLU"       "<<CLR"     "<<RED"     "<<CLR"            "<<endl;
       cout<<CLR"          "<<GRN"  "<<CLR"        "<<MAG"  "<<CLR"     "<<MAG"  "<<CLR" "<<BLU"  "<<CLR"    "<<BLU"  "<<CLR" "<<RED"  "<<CLR"    "<<RED"  "<<CLR"          "<<endl;
       cout<<CLR"          "<<GRN"  "<<CLR"        "<<MAG"  "<<CLR"     "<<MAG"  "<<CLR" "<<BLU"  "<<CLR"    "<<BLU"  "<<CLR" "<<RED"  "<<CLR"    "<<RED"  "<<CLR"          "<<endl;
       cout<<CLR"          "<<GRN"  "<<CLR"        "<<MAG"  "<<CLR"     "<<MAG"  "<<CLR" "<<BLU"  "<<CLR"    "<<BLU"  "<<CLR" "<<RED"  "<<CLR"    "<<RED"  "<<CLR"          "<<endl;
       cout<<CLR"          "<<GRN"  "<<CLR"        "<<MAG"  "<<CLR"     "<<MAG"  "<<CLR" "<<BLU"  "<<CLR"    "<<BLU"  "<<CLR" "<<RED"  "<<CLR"    "<<RED"  "<<CLR"          "<<endl;
       cout<<CLR"          "<<GRN"         "<<CLR"   "<<MAG"      "<<CLR"   "<<BLU"       "<<CLR"     "<<RED"     "<<CLR"            "<<endl;
       cout<<"                           Menu"<<CLR"                                 "<<endl;
       cout<<"                    1. Start a new game"<<CLR"                         "<<endl;
       cout<<"                  2. Resume previous game"<<CLR"                       "<<endl;
       cout<<"                         3. Quit"<<CLR"                                "<<endl;
       cout<<CLR"                                                                    "<<endl;
       cout<<"Please select (1/2/3): ";
       cin>>choice;
 
       if (choice==1){
           fileIP("default.txt",playerN);
           loadsavebar(0);
           instruction();
           game(playerN);
           break;
       }
       else if (choice ==2){
           cout<<"Please input the import file name: "<<endl;
           cin>>file;
           if (file.length()<file.find(".txt") || file.find(".txt")<0)
               file+=".txt";
           fileIP(file,playerN);
           loadsavebar(0);
           game(playerN);
           break;
       }
   }
   quitgame();
}

