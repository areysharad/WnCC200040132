#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

struct Groundwork
{
    float start;
    float duration;
    float endt;
};

struct Available_Groundworks
{
    int n;
    vector<Groundwork> gw;
};

Available_Groundworks* av_gw(Available_Groundworks* ag)
{
    ag->n=0;
    Groundwork s;   
    string a;
    ifstream fin;
    fin.open("Schedule.txt",ios::in);
    fin.seekg(0);
    while(fin>>a>>s.start>>s.duration)
    {
        ag->n++;
        s.endt=s.start+s.duration;
        ag->gw.push_back(s);
        //cout<<s.start<<" "<<s.duration<<" "<<s.endt<<endl;
    }
    fin.close();
    //cout<<ag->gw[21].start<<" "<<ag->gw[21].duration<<" "<<ag->gw[21].endt<<endl;
    //cout<<ag->n;
    return ag;
} 
int CalculateMaxGroundworks(Available_Groundworks* ag)
{   
    //sorting the array
    Groundwork temp;
    int i, j;
    for (i = 0; i < ag->n-1; i++) 
    {  
        for (j = 0; j < ag->n-i-1; j++)
        {
            if (ag->gw[j].endt > ag->gw[j+1].endt)
            {
                temp=ag->gw[j];
                ag->gw[j]=ag->gw[j+1];
                ag->gw[j+1]=temp;
            }
        }
    }
    //for (i = 0; i < ag->n; i++)
    //    cout<<ag->gw[i].start<<" "<<ag->gw[i].duration<<" "<<ag->gw[i].endt<<endl;
    int count=0;
    if (ag->n>0) count++;
    float endcheck =ag->gw[0].endt;
    for(i=1;i < ag->n; i++)
    {
        if(ag->gw[i].start>=endcheck)
        {
            count++;
            endcheck=ag->gw[i].endt;
            //cout<<ag->gw[i].start<<" "<<ag->gw[i].duration<<" "<<ag->gw[i].endt<<endl;
        }
    }
    return count;
}

int main()
{
    //cout<<"hello"<<endl;
    int b;
    Available_Groundworks* ag = new Available_Groundworks;
    ag=av_gw(ag);
    //cout<<ag->gw[21].start<<" "<<ag->gw[21].duration<<" "<<ag->gw[21].endt<<endl;
    //cout<<ag->n;
    b=CalculateMaxGroundworks(ag);
    cout<<"Max Events He/She/They can Attend = "<<b;
    return 0;
}