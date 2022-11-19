#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 20
int main()
{
    int i,j;
    char str[N][50];
    char temp[50];
    FILE *fp;
    fp=fopen("kizk.txt","r+");//读写打开
    if(fp==NULL)
    {
        printf("file is error");
        return -1;
    }
    
    while(fp != NULL)
    {
        fgets(str[j],255,fp);
        printf("%s", str[j]);
        fclose(fp);
    }//从文件读入数据到数组
    return 0;
    for(j=0;j<N;j++)
    {
        printf("%s\n", str[j]);
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1-i;j++)
        {
            if(strcmp(str[j],str[j+1])<0)
            {
                strcpy(temp,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],temp);
            }
        }
    }//排序
    
    for(i=0;i<N;i++)
    {
        fputs(str[i],fp);
    }//将数组中的数据写入到文件
    fclose(fp);
    return 0;
}