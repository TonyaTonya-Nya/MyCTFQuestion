#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 45 //�g�c�j�p 
#define WALL 'H' //����r�� 
#define WAY  ' ' //�g�c���| 
#define ANS '*' //���T���u
 
void create(int x,int y,char a[][MAX]); //�üƳгy�g�c 

void find(int x,int y,char a[][MAX],int count,int memory[][3]);//�M����| 

int main(){
	
	char a[MAX][MAX];
	int  memory[1000][3];//�g�c���|�p����p 
	int i, j;
	srand(time(NULL));

//��l�ư}�C 
	for(i=0;i<100;i++){
		for(j=0;j<3;j++){
			memory[i][j]=0;	
				}
	}
	
//��l�ưg�c���������	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			a[i][j]=WALL;
		}
	}
	
	
	int x=1,y=1;//�g�c���|�p��_�I 
	
	create(x,y,a);//�гy�g�c 
	
	
	a[1][0]=ANS;//�g�c�J�f 
	
	
//�C�L�g�c(�L���u) 
	for(i=0;i<MAX;i++) {
	for(j=0;j<MAX;j++){
		printf("%c ",a[i][j]);
	}
	printf("\n");
}

printf("\n");


find(x,y,a,0,memory);//���|�p�� 


a[MAX-2][MAX-1]=ANS;//�g�c�X�f 

//�N�L�k���X�g�c�����u�M��	
for(i=0;i<MAX;i++) {
	for(j=0;j<MAX;j++){
		
		if(a[i][j]=='X')
		{a[i][j]=' ';
		}
		
		
		printf("%c ",a[i][j]);
	}
	printf("\n");
}




	} 
	
	
void create(int x,int y,char a[][MAX]){
	
	a[x][y]=WAY;
	a[1][0]=WAY;
	a[MAX-2][MAX-1]=WAY;
	
	//�����g�c�����I������I�e�K������� 
	while(x!=MAX-2||y!=MAX-2){
	
	int b=rand()%4;//�üƨM�w������V 
	
	//�W�X��ɭ��� 
	while((x==1&&b==2)||(y==1&&b==1)||(x==MAX-2&&b==0)||(y==MAX-2&&b==3)){
		b=rand()%4;
	}
	
	
	
	//���� �p�G�ؼШS���Q�}���L�A�h�s�q�q�D�A�_�h���s�q 
	if(b==0){
		if(a[x+2][y]==WALL){	
		a[x+2][y]=WAY;
		a[x+1][y]=WAY;
		}x=x+2;
	}else if(b==1){
		if(a[x][y-2]==WALL){	
		a[x][y-2]=WAY;
		a[x][y-1]=WAY;
		}y=y-2;
	}else if(b==2){
		if(a[x-2][y]==WALL){
		a[x-2][y]=WAY;
		a[x-1][y]=WAY;
		}x=x-2;
	}else if(b==3){
		if(a[x][y+2]==WALL){	
		a[x][y+2]=WAY;
		a[x][y+1]=WAY;
		}y=y+2;
	}
	
	
	
	
	
	}
	
	
	
}	



void find(int x,int y,char a[][MAX],int count,int memory[][3]){
	
int i,j;
	while(x!=MAX-2,y!=MAX-1){
		
	
	//���ե� �i�@�B�@�B�ݥX�g�c���|�ͦ��L�{
	 
/*	for(i=0;i<MAX;i++) {
	for(j=0;j<MAX;j++){
		printf("%c ",a[i][j]);
	}
	printf("\n");
}
	
	int q;
	scanf("%d",&q);
	*/ 
	
	
	
	      
	//�M�w��V �p�G�i��K���ʨ�U�@�Ӯy�� 
     	if(memory[count][2]==0){
		
		if(a[x][y+1]==' '){
			a[x][y]=ANS;
			
			memory[count][0]=x;
			memory[count][1]=y;
			count++;
		
			
			return find(x,y+1,a,count,memory);
		}else memory[count][2]=1;
		
	}
		
		
		if(memory[count][2]==1){
			
		if(a[x+1][y]==' '){
			a[x][y]=ANS;
			
			memory[count][0]=x;
			memory[count][1]=y;
			count++;
		    
			return find(x+1,y,a,count,memory);
			
		}else memory[count][2]=2;
		
	}
		
		if(memory[count][2]==2){
			
	    if(a[x][y-1]==' '){
			a[x][y]=ANS;
			
			memory[count][0]=x;
			memory[count][1]=y;
			count++;
			
			return find(x,y-1,a,count,memory);
		}else memory[count][2]=3;
		
	}

		if(memory[count][2]==3){
			
	    if(a[x-1][y]==' '){
			a[x][y]=ANS;
			
			memory[count][0]=x;
			memory[count][1]=y;
			count++;
			
		    return find(x-1,y,a,count,memory);
		}else memory[count][2]=4;
			
	}
	
	//�p�G���i�� �h�^�W�@�Ӯy�� �ñq�U�@�Ӥ�V�~����� 
	if(memory[count][2]==4)	{
			a[x][y]='X';
		
			memory[count][0]=0;
			memory[count][1]=0;
			memory[count][2]=0;
			return find(memory[count-1][0],memory[count-1][1],a,count-1,memory);
			 
		}
	
	
	
	
	
	
	
	
}
	system("PAUSE");
	
}

