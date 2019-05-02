#include <stdio.h>

void hanoi(int n,int com, int aux, int fin);

int main(){
int n;	
char com='1';
char aux='2';
char des='3';
printf("Ingrese el numero de discos\n");
scanf("%d",&n);

hanoi(n,com,aux,des);

return 0;	
	
}


void hanoi(int n,int com, int aux, int des){
	
if(n==1)
printf("%c->%c",com,des);
else{
hanoi(n-1,com,des,aux);	
printf("\n%c->%c\n",com,des);
hanoi(n-1,aux,com,des);
	
}



}
