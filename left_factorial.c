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
/*
#include <stdio.h>
#include <string.h>

#define MAX_RULES 10
#define MAX_RULE_LENGTH 10
#define MAX_NON_TERMINALS 10
#define MAX_TERMINALS 10
char rules[MAX_RULES][MAX_RULE_LENGTH];
char nonTerminals[MAX_NON_TERMINALS];
char terminals[MAX_TERMINALS];
char newRules[MAX_RULES][MAX_RULE_LENGTH];

int numRules, numNonTerminals, numTerminals, numNewRules;

void inputGrammar() {
    printf("Enter the number of rules: ");
    scanf("%d", &numRules);
    getchar(); // Consume newline

    printf("Enter the rules (e.g., A->ab|ac|b): ");
    for (int i = 0; i < numRules; i++) {
        fgets(rules[i], MAX_RULE_LENGTH, stdin);
    }

    printf("Enter the non-terminals: ");
    fgets(nonTerminals, MAX_NON_TERMINALS, stdin);
    numNonTerminals = strlen(nonTerminals) - 1;

    printf("Enter the terminals: ");
    fgets(terminals, MAX_TERMINALS, stdin);
    numTerminals = strlen(terminals) - 1;
}

int findCommonPrefixLength(char* str1, char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

void eliminateLeftFactoring() {
    numNewRules = 0;

    for (int i = 0; i < numRules; i++) {
        int commonPrefixLength = 0;

        for (int j = i + 1; j < numRules; j++) {
            commonPrefixLength = findCommonPrefixLength(rules[i] + 3, rules[j] + 3);

            if (commonPrefixLength > 0) {
                char newNonTerminal = nonTerminals[numNonTerminals];
                nonTerminals[numNonTerminals++] = newNonTerminal
sprintf(newRules[numNewRules++], "%c->%.*s%c'", rules[i][0], commonPrefixLength, rules[i] + 3, newNonTerminal);
                sprintf(newRules[numNewRules++], "%c'->%s", newNonTerminal, rules[j] + 3 + commonPrefixLength);
                sprintf(newRules[numNewRules++], "%c'->epsilon", newNonTerminal);

                break;
            }
        }

        if (commonPrefixLength == 0) {
            strcpy(newRules[numNewRules++], rules[i]);
        }
    }
}

void displayGrammar(char grammar[][MAX_RULE_LENGTH], int numRules) {
    for (int i = 0; i < numRules; i++) {
        printf("%s", grammar[i]);
    }
}

int main() {
    inputGrammar();

    printf("\nOriginal Grammar:\n");
    displayGrammar(rules, numRules);

    eliminateLeftFactoring();

    printf("\nGrammar after eliminating left factoring:\n");
    displayGrammar(newRules, numNewRules);

    return 0;
}

*/
