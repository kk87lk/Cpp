#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef char elemtype;

#define Maxsize 100

typedef struct stack{

    elemtype data[Maxsize];

    int top;

} Stack;

void print(Stack* S){

	int i=S->top;

	while(i!=-1){

		printf("%c  ",S->data[i--]);

	}

}

Stack* CreateStack(){

    Stack *S = (Stack *)malloc(sizeof(Stack));

    if(S==NULL){

        return 0;

    }

    S->top = -1;

    return S;

}

int isfull(Stack *S){

    return (S->top == Maxsize - 1);

}

int isempty(Stack *S){

    return (S->top == -1);

}

int push(Stack *S,elemtype x){

    if(isfull(S)){

        return 0;

    }else{

        S->data[++S->top] = x;

        return 1;

    }

}

elemtype pop(Stack* S){

    if(isempty(S)){

        return 0;

    }else{

        return S->data[S->top--];

    }

}

int Judge(Stack *S){

    elemtype s1, s2;

   // int cnt=0;

    printf("Please input S1(end with @):");

    do{

    	scanf("%c",&s1);

    	if(s1!='@')

        push(S, s1);

    }while(s1!='@');

    printf("Please input S2(end with #):");

    getchar();

    do{

    	scanf("%c",&s2);

        while(!isempty(S)){

            if(pop(S)==s2&&s2!='#'){

            	//cnt++;

                break;

            }else

            {

                printf("NO!\n");

                return 0;

            }

        }

        continue;

    }while (s2!= '#');

   // if(cnt)

    printf("YES!\n");

    return 1;

}

int main(){

    Stack *S = CreateStack();

    Judge(S);

}