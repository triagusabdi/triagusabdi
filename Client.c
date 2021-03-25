//NIM 	: 12S17008
//Nama 	: Rezky Simanjuntak


#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node{
	ElementType Element;
	Position Next;
};

Position Header(List L){
	return L;
}

List Construct(List L){
	if(L == NULL){
		L = malloc(sizeof(struct Node));
		L->Next = NULL;
	}
	return L;
}

void Insert(List L, ElementType x, Position P){
	Position tmp = malloc(sizeof(struct Node));
	tmp->Element = x;
	tmp->Next = P->Next;
	P->Next = tmp;
}

Position Advanced(Position P){
	return P->Next; 
}

Position Search(ElementType x, List L){
	Position P = L->Next;
	while(P != NULL && P->Element != x){
		P = P->Next;
	}
	return P;
}

Position FindPrev(ElementType x, List L){
	Position P = L;
	while(P->Next != NULL && P->Next->Element != x){
		P = P->Next;
	}
	return P;
}

void Update(ElementType x, Position P){
	P->Element = x;
}

void Delete(ElementType x, List L){
	Position P = Search(x, L);
	Position Prev;
	if(P != NULL){
		Prev = FindPrev(x, L);
		Prev->Next = P->Next;
		free(P);
	}
}

void DeleteList(List L){
	while(L->Next != NULL){
		L->Next = L->Next->Next;
		free(L->Next);
	}
	free(L);
}

void Show(List L){
	Position P = L->Next;
	while(P != NULL){
		printf("%d  ", P->Element);
		P = P->Next;
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	int x=477,y=500;
	List L = NULL;
	Position P = NULL;
	L = Construct(L);
	P = Header(L);
	
	Insert(L, 477, P);
	Advanced(P);
	Insert(L, 377, P);
	Advanced(P);
	Insert(L, 277, P);
	Advanced(P);
	Insert(L, 100, P);
	Advanced(P);
	Insert(L, 77, P);
	Show(L);
	
	printf("\nMencari Posisi\n");
	printf("Posisi: %d\n", Search(x, L));
	printf("Pencarian Berhasil, Nilai %d Ditemukan\n", x);
	
	printf("\nUpdate Data\n");
	Update(y, Search(x, L));
	Show(L);
		
	printf("\n\nMenghapus Data\n");
	printf("Delete Elemen Dengan Nilai = %d\n", y);
	Delete(y, L);
	Show(L);
	
	printf("\n\nMenghapus List\n");
	DeleteList(L);
	
	return 0;
}
