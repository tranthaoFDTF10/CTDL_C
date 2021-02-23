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
	makenull_queue(Q);
	int i;
	ElementType x;
	for(i=1;i<=n;i++){
		printf("Nhap cong viec thu %d: ",i);
		scanf("%d",&x);
		EnQueue(x,Q);
		}
	}
void print(Queue Q){
	Position p=Q.Front;
	while(p!=Q.Rear){
		printf("%d ",Q.Front->Next->Element);
		DeQueue(&Q);
		}
	}
int countE(Queue Q){
	int count=0;
	Position p=Q.Front;
	while(p!=Q.Rear){
		count++;
		p=p->Next;
	}
	return count;
	}
	
int main(){
    Queue Q;
    makenull_queue(&Q);
    int i,n,x,temp;
    char kt;
    printf("Nhap so thao tac ban muon thuc hien: "); scanf("%d",&n); fflush(stdin);
    for(i=1;i<=n;i++){
    	printf("\nNhap ki tu ban muon thao tac: "); scanf("%c",&kt);
    	if(kt=='E'){
    		printf("Nhap ki tu ban muon chen: "); scanf("%d",&x); fflush(stdin);
    		EnQueue(x,&Q);
    		printf("\ncount: %d",countE(Q));
    		}
		else if(kt=='D'){
			if(!empty_queue(Q)){
				temp=Front(Q);
				DeQueue(&Q);
				printf("\n%d  %d\n",temp,countE(Q));
				}
			}
	    else{
	    	printf("-1 0\n");
		}
	}
	return 0;
	}
