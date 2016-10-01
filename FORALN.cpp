#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,j=0,k=0;
    char  x[]="ashhi",y[]="ashhi";
    printf("%d",strcmp(x,y));
    char ki[1000][100],ka[1000][100];
    cin>>n;
    char temp[100];
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        if(temp[strlen(temp)-1]=='i')
            strcpy(ki[j++],temp);
        else
            strcpy(ka[k++],temp);
    }
    int counter=0;
    for(int i=0;i<k;i++)
    {
        for(int l=0;l<j;l++)
        {
            printf("%s %s -%d\n",ka[i],ka[l],strcmp(ka[i],ki[l]));
            if(strcmp(ka[i],ki[l])==0)
                counter++;
        }
        printf("\n");
    }
    cout<<counter;
}
