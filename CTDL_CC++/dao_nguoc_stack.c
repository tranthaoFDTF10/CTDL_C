#include<stdio.h>
#include<conio.h>
#define maxlength 100
typedef int ElementType;
typedef struct{
	ElementType Elements[maxlength];
	int Top_idx;
}Stack;
void makenull_stack(Stack *S){
	S->Top_idx=maxlength;
	}
int empty_stack(Stack S){
	return S.Top_idx==maxlength;
	}
int full_stack(Stack S){
	return S.Top_idx==0;
	}
ElementType Top(Stack S){
	if(S.Top_idx!=maxlength){
		return S.Elements[S.Top_idx];
		}
	else{
		printf("Loi Stack rong");
	}
}
void Push(ElementType x, Stack *S){
	if(S->Top_idx!=0){
		S->Top_idx=S->Top_idx-1;
		S->Elements[S->Top_idx]=x;
		}
	else{
		printf("Khong the them");
	}
}
void Pop(Stack *S){
	if(S->Top_idx!=maxlength){
		S->Top_idx=S->Top_idx+1;
		}
	else{
		printf("Loi stack rong");
	}
}
void read(Stack *S){
	int i,n;
	ElementType x;
	makenull_stack(S);
	printf("Nhap so phan tu danh sach stack: "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Phan tu thu %d: ",i);
		scanf("%d",&x);
		Push(x,S);
		}
	}
void print(Stack S){
	while(S.Top_idx!=maxlength){
		printf("%d ",S.Elements[S.Top_idx]);
		Pop(&S);
		}
	printf("\n");
	}
//-------------------------------------------------//
//cai dat hang doi
typedef struct{
	ElementType Elements[maxlength];
	int Front,Rear;
}Queue;
void makenull_queue(Queue *Q){
	Q->Front=-1;
	Q->Rear=-1;
	}
int empty_queue(Queue Q){
	return Q.Front==-1;
}
int full_queue(Queue Q){
	return (Q.Rear-Q.Front+1)==maxlength;
}
void EnQueue(ElementType x, Queue *Q){
	if(!full_queue(*Q)){
		if(empty_queue(*Q)) Q->Front=0;
		int i;
		if(Q->Rear==maxlength-1){
			for(i=Q->Front;i<=Q->Rear;i++){
				Q->Elements[i-Q->Front]=Q->Elements[i];
				}
			Q->Rear=maxlength-Q->Front-1;
			Q->Front=0;
			}
		Q->Rear=Q->Rear+1;
		Q->Elements[Q->Rear]=x;
	}
	else{
		printf("\nLoi hang rong");
	}
}
void EnQueue1(ElementType x, Queue *Q){
	if(!full_queue(*Q)){
		if(empty_queue(*Q)) Q->Front=0;
		Q->Rear=(Q->Rear+1)%maxlength;
		Q->Elements[Q->Rear]=x;
	}
	else{
		printf("loi hang day");
	}
}
void DeQueue(Queue *Q){
	if(!empty_queue(*Q)){
		Q->Front=Q->Front+1;
		if(Q->Front>Q->Rear) makenull_queue(Q);
	}
	else printf("Loi Hang Rong");
}
ElementType Front(Queue Q){
	return Q.Elements[Q.Front];
}
void read_queue(Queue *Q){
	makenull_queue(Q);
	ElementType x;
	int i,n;
	printf("So phan tu cua hang doi n = "); scanf("%d",&n);
	for(i=1;i<=n;i++){
		printf("Phan tu thu %d: ",i); scanf("%d",&x);
		EnQueue(x,Q);
	}
}
void print_queue(Queue Q){
	while(!empty_queue(Q)){
		printf("%d ",Front(Q));
		DeQueue(&Q);
	}
	printf("\n");
}
int count(Queue Q){
	int dem=0;
	dem=Q.Rear-Q.Front+1;
	return dem;
	}
//ham su dung hang doi de dao nguoc noi dung ngan xep
void dao_nguoc(Stack *S){
	Queue Q;
	makenull_queue(&Q);
	while(!empty_stack(*S)){
		EnQueue(Top(*S),&Q);
		Pop(S);
		}
	while(!empty_queue(Q)){
		Push(Front(Q),S);
		DeQueue(&Q);
		}
	}
int main(){
	Stack S;
	printf("Nhap du lieu cho stack: \n");
	read(&S);
	printf("\nStack sau khi dao thu tu la: ");
	dao_nguoc(&S);
	print(S);
	return 0;
	}
