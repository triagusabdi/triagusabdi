//NIM 	: 12S17008
//Nama 	: Rezky Simanjuntak


#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node{
	Position Prev;
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
		L->Prev = NULL;
	}
	return L;
}

void Insert(List L, ElementType x, Position P){
	Position tmp = malloc(sizeof(struct Node));
	tmp->Element = x;
	tmp->Next = P->Next;
	tmp->Prev = P;
	P->Next = tmp;
	P->Next->Prev = tmp;
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
		P->Next->Prev = Prev;
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
		printf("%d\t", P->Element);
		P = P->Next;
	}
	printf("\n");
//	P = NULL;
//	while(P != L){
//		printf("%d\t", P->Element);
//		P = P->Prev;
//	}
}

int main(int argc, char *argv[]){
	List L = NULL;
	Position P = NULL;
	L = Construct(L);
	P = Header(L);
	
	printf("~~ Pengisian Data ~~\n");
	Insert(L, 3, P);
	Advanced(P);
	Insert(L, 5, P);
	Advanced(P);
	Insert(L, 7, P);
	Show(L);
	
	printf("\n\n~~ Menambah Data ~~\n");
	Insert(L, 6, Search(5, L));
	Show(L);
	printf("\n");
	
	printf("\n~~ Mencari Posisi ~~\n");
	printf("Posisi: %d\n", Search(5, L));
	printf("Posisi: %d\n", Search(8, L));
	
	printf("\n~~ Update Data ~~\n");
	Update(10, Search(7, L));
	Show(L);
		
	printf("\n\n~~ Menghapus Data ~~\n");
	Delete(5, L);
	Show(L);
	
	printf("\n\n~~ Menghapus List ~~\n");
	DeleteList(L);
	
	printf("\nEND\n");
	
	return 0;
}
