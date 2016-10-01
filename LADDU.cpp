#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int act;
        char indian[]="INDIAN";
        char non_indian[]="NON_INDIAN";
        char origin[10],x[100];
        char cw[]="CONTEST_WON";
        char tc[]="TOP_CONTRIBUTOR";
        char bf[]="BUG_FOUND";
        char ch[]="CONTEST_HOSTED";
        cin>>act;
        scanf("%s",&origin);
        int tot=0,r,sev;
        cout<<tot<<endl;
       while(act--)
       {
               scanf("%s",x);
               if(!strcmp(x,cw))
               {
                    scanf("%d",&r);
                    tot=tot+300;
                    if(r<20)
                        tot=tot+20-r;
               }
               if(!strcmp(x,tc))
                    tot=tot+300;
               if(!strcmp(x,bf))
               {
                   scanf("%d",&sev);
                   tot+=sev;
               }
               if(!strcmp(x,ch))
                    tot+=50;
                cout<<tot<<endl;
        }
        cout<<tot<<endl;
        int ans=0;
        if(!strcmp(origin,indian))
            ans=tot/200;
        if(!strcmp(origin,non_indian))
            ans=tot/400;
        cout<<ans<<endl;
    }
}
