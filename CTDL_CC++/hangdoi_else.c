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
	}
}
void read(int n,Queue *Q){
	int i;
	ElementType x;
	makenull_queue(Q);
	for(i=1;i<=n;i++){
		printf("Nhap cong viec thu %d: ",i);
		scanf("%d",&x);
		EnQueue(x,Q);
		}
	}
void print(Queue Q){
	while(!empty_queue(Q)){
		printf("%d ",Front(Q));
		DeQueue(&Q);
		}
	printf("\n");
	}
int main(){
	Queue Q1,Q2;
	int n,count=0;
	printf("Nhap so luong cong viec: "); scanf("%d",&n);
	printf("\nNhap ten cong viec: \n");
	read(n,&Q1);
	printf("\nNhap thu tu uu tien cong viec: \n");
	read(n,&Q2);
	while(!empty_queue(Q1)){
		if(!empty_queue(Q2)){
			if(Front(Q1)==Front(Q2)){
				DeQueue(&Q1);
				DeQueue(&Q2);
				count++;
				}
			else{
				EnQueue(Front(Q1),&Q1);
				DeQueue(&Q1);
				count++;
			}
		}
	}
	printf("\ncount: %d",count);
	return 0;
	}
	

