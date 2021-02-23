#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int ElementType;
struct Node{
	ElementType Element;
	struct Node* Next;
};
typedef struct Node* Position;
typedef struct{
	Position Front,Rear;
}Queue;
void makenull_queue(Queue *Q){
	Position header;
	header=(struct Node*)malloc(sizeof(struct Node));
	header->Next=NULL;
	Q->Front=header;
	Q->Rear=header;
	}
int empty_queue(Queue Q){
	return Q.Front==Q.Rear;
	}
void EnQueue(ElementType x, Queue *Q){
	Q->Rear->Next=(struct Node*)malloc(sizeof(struct Node));
	Q->Rear=Q->Rear->Next;
	Q->Rear->Element=x;
	Q->Rear->Next=NULL;
	}
void DeQueue(Queue *Q){
	if(!empty_queue(*Q)){
		Position temp;
		temp=Q->Front;
		Q->Front=Q->Front->Next;
		free(temp);
		}
	else{
		printf("Loi hang rong");
	}
}
ElementType Front(Queue Q){
	if(!empty_queue(Q)){
		return Q.Front->Next->Element;
		}
	else{
		printf("Loi hang rong");
		return -1;
	}
}
int countE(Queue Q){
	Position P=Q.Front;
	int count=0;
	while(P!=Q.Rear){
		count++;
		P=P->Next;
		}
	return count;
	}
int main(){
	Queue Q;
	int x,i,n,temp;
	char kt;
	makenull_queue(&Q);
	printf("Nhap so thao tac: "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		fflush(stdin);
		printf("\nNhap ki tu ban muon thao tac: "); scanf("%c",&kt); 
		if(kt=='E'){
			printf("\nNhap phan tu muon chen: "); scanf("%d",&x);
			EnQueue(x,&Q);
			printf("\nCount: %d\n",countE(Q));
			}
		else if(kt=='D'){
			if(!empty_queue(Q)){
				temp=Front(Q);
				DeQueue(&Q);
				printf("%d %d\n",temp,countE(Q));
				}
			}
		else{
			printf("-1 0\n");
		}
	}
	return 0;
	}
	
			
		
