#include<stdio.h>
#include<string.h>

void get_next(char T[],int next[])
{
    int i=0,k=-1;
    next[0]=-1;
	int len=strlen(T);
    while(i<len-1)
    {
        if(k==-1||T[k]==T[i])
        {
            i++;
            k++;
            next[i]=k;                       
        }
        else k = next[k];    
    }
}
int index_KMP(char S[],char T[],int pos)
{
    int i,j;
	int k;
    i=pos-1;
    j=0;
    int next[200];
	int len1=strlen(S),len2=strlen(T);
	printf("%d\n",strlen(T));
    get_next(T,next);
	for(k=0;k<len1;k++) printf("%d ",next[k]);
	printf("\n");
	printf("%d\n",strlen(T));
    while ((i<len1)&&(j<int(strlen(T))))
    {
        if(j==-1||S[i]==T[j])
        {
            i++;
            j++;           
        }
        else j = next[j];
		printf("%d %d %d %d\n",strlen(S),strlen(T),i,j);
    }
	printf("%d %d %d %d\n",strlen(S),strlen(T),i,j);
    if(j > len2-1)
        return i-len2+1;
    else return -1;
}
int main()
{
    int pos,i,j;
    //char T[10000],S[10000];
    printf("请输入主串\n");
    //gets(S);
	char S[100]="ababcabababca";
    printf("请输入要匹配的串\n");
    //gets(T);
	char T[100]="abababca";
    printf("请输入在主串的第几个字符开始查询\n");
    //scanf("%d",&pos);
	pos=1;
    if(pos>strlen(S))
    {
        printf("error!");
        return 0;
    }
    j=index_KMP(S,T,pos);
	printf("%d\n",j);
    if (j==-1)
    {
        printf("主串中无子串\n");
        return 0;
    }
//    printf("子串在主串中第%d个字符后出现的位置为%d\n",pos,j);    
    return 0;
}
//ababcabababca
//abababca