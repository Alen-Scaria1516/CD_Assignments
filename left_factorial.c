#include<stdio.h>  
2:  #include<string.h>  
3:  int main()  
4:  {  
5:       char gram[20],part1[20],part2[20],modifiedGram[20],newGram[20],tempGram[20];  
6:       int i,j=0,k=0,l=0,pos;  
7:       printf("Enter Production : A->");  
8:       gets(gram);  
9:       for(i=0;gram[i]!='|';i++,j++)  
10:            part1[j]=gram[i];  
11:       part1[j]='\0';  
12:       for(j=++i,i=0;gram[j]!='\0';j++,i++)  
13:            part2[i]=gram[j];  
14:       part2[i]='\0';  
15:       for(i=0;i<strlen(part1)||i<strlen(part2);i++)  
16:       {  
17:            if(part1[i]==part2[i])  
18:            {  
19:                 modifiedGram[k]=part1[i];  
20:                 k++;  
21:                 pos=i+1;  
22:            }  
23:       }  
24:       for(i=pos,j=0;part1[i]!='\0';i++,j++){  
25:            newGram[j]=part1[i];  
26:       }  
27:       newGram[j++]='|';  
28:       for(i=pos;part2[i]!='\0';i++,j++){  
29:            newGram[j]=part2[i];  
30:       }  
31:       modifiedGram[k]='X';  
32:       modifiedGram[++k]='\0';  
33:       newGram[j]='\0';  
34:       printf("\n A->%s",modifiedGram);  
35:       printf("\n X->%s\n",newGram);  
36:  }  
