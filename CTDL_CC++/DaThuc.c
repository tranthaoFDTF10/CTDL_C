#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct {
    double he_so;
    int bac;
} DonThuc;
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;
DaThuc khoitao(){
	DaThuc d;
	d=(struct Node*)malloc(sizeof(struct Node));
	d->Next=NULL;
	return d;
}
void chenDonThuc(DonThuc s, DaThuc *pD){
	Position p=(*pD);	
	int Found=0;
	while(p->Next!=NULL && !Found){
		if (p->Next->e.bac>s.bac)
			p=p->Next;
		else			
			Found=1;				
	}
	if (p->Next!=NULL){
		if(p->Next->e.bac==s.bac)
			p->Next->e.he_so += s.he_so;
		else {
			struct Node *t=(struct Node*)malloc(sizeof(struct Node));
			t->e=s;
			t->Next=p->Next;
			p->Next=t;
		}				
	}
	else{
		struct Node *t=(struct Node*)malloc(sizeof(struct Node));
		t->e=s;
		t->Next=p->Next;
		p->Next=t;
	}
}
DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc d;
	d=khoitao();
	Position p=D1;
	while (p->Next!=NULL){
		chenDonThuc(p->Next->e,&d);
		p=p->Next;
	}
	p=D2;
	while (p->Next!=NULL){
		chenDonThuc(p->Next->e,&d);
		p=p->Next;
	}
	return d;
}
DaThuc tinhDaoHam(DaThuc D){
	DaThuc dt;
	DonThuc e;
	dt=khoitao();
	Position p=D;
	while(p->Next!=NULL){
		e=p->Next->e;
		e.he_so *= e.bac;
		e.bac--;
		chenDonThuc(e,&dt);
		p=p->Next;
	}
	return dt;
}
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
	DaThuc d;
	DonThuc e,temp;
	d=khoitao();
	Position q,p;
	p=D1;
	while (p->Next!=NULL){
		e=p->Next->e;
		q=D2;
		while (q->Next!=NULL){
			temp.he_so = e.he_so * q->Next->e.he_so;
			temp.bac = e.bac + q->Next->e.bac;
			chenDonThuc(temp,&d);
			q=q->Next;
		}	
		p=p->Next;
	}
	return d;
}
DaThuc nhapDaThuc(){
	DaThuc d;
	DonThuc s;
	int i,n;	
	d=khoitao();
	printf("Hay cho biet so phan tu cua da thuc: ");
	scanf("%d",&n);
	for (i=1; i<=n; i++){
		printf("Nhap vao he so cua cua phan tu thu %d: ",i);
		scanf("%lf",&s.he_so);
		printf("Nhap vao so mu cua phan tu thu %d: ",i);
		scanf("%d",&s.bac);
		chenDonThuc(s,&d);
	}
	return d;
}
void inDaThuc(DaThuc d){
	Position p=d;
	while(p->Next!=NULL){
		if (p->Next->Next==NULL)
			printf("%.3fX^%d",p->Next->e.he_so,p->Next->e.bac);
		else
			printf("%.3fX^%d + ",p->Next->e.he_so,p->Next->e.bac);
		p=p->Next;	
	}
	printf("\n");
}
int main(){
	DaThuc d;
	d=nhapDaThuc();
	inDaThuc(d);
	return 0;
	}
