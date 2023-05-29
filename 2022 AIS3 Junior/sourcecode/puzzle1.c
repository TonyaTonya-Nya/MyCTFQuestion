#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 45 //迷宮大小 
#define WALL 'H' //牆壁字元 
#define WAY  ' ' //迷宮路徑 
#define ANS '*' //正確路線
 
void create(int x,int y,char a[][MAX]); //亂數創造迷宮 

void find(int x,int y,char a[][MAX],int count,int memory[][3]);//尋找路徑 

int main(){
	
	char a[MAX][MAX];
	int  memory[1000][3];//迷宮路徑計算估計 
	int i, j;
	srand(time(NULL));

//初始化陣列 
	for(i=0;i<100;i++){
		for(j=0;j<3;j++){
			memory[i][j]=0;	
				}
	}
	
//初始化迷宮全部為牆壁	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			a[i][j]=WALL;
		}
	}
	
	
	int x=1,y=1;//迷宮路徑計算起點 
	
	create(x,y,a);//創造迷宮 
	
	
	a[1][0]=ANS;//迷宮入口 
	
	
//列印迷宮(無路線) 
	for(i=0;i<MAX;i++) {
	for(j=0;j<MAX;j++){
		printf("%c ",a[i][j]);
	}
	printf("\n");
}

printf("\n");


find(x,y,a,0,memory);//路徑計算 


a[MAX-2][MAX-1]=ANS;//迷宮出口 

//將無法走出迷宮的路線清空	
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
	
	//挖掘迷宮之終點未到終點前便持續挖掘 
	while(x!=MAX-2||y!=MAX-2){
	
	int b=rand()%4;//亂數決定挖掘方向 
	
	//超出邊界限制 
	while((x==1&&b==2)||(y==1&&b==1)||(x==MAX-2&&b==0)||(y==MAX-2&&b==3)){
		b=rand()%4;
	}
	
	
	
	//挖掘 如果目標沒有被開挖過，則連通通道，否則不連通 
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
		
	
	//測試用 可一步一步看出迷宮路徑生成過程
	 
/*	for(i=0;i<MAX;i++) {
	for(j=0;j<MAX;j++){
		printf("%c ",a[i][j]);
	}
	printf("\n");
}
	
	int q;
	scanf("%d",&q);
	*/ 
	
	
	
	      
	//決定方向 如果可行便移動到下一個座標 
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
	
	//如果不可行 退回上一個座標 並從下一個方向繼續嘗試 
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

