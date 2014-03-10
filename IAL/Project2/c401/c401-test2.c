

/* Testy pro dom�c� �kol na t�ma rekurzivni implementace operaci nad BVS
(c401.c). Obsahuje procedury a funkce, kter� testuj� studentsk�
verze principem jejich vol�n� (v�pis na stdout). Toto je studentsk�
verze, obsahuj�c� zredukovan� mno�stv� procedur a funkc�
na otestov�n�. Slou�� pro studenty jako n�stroj kontroly jejich prac�. */

/* **********************SOUBOR S ST.TESTEM  *********************** */
/* **********************-----------------   *********************** */
/*  vytvo�il: Martin Tu�ek
    p�edm�t: Algoritmy (IAL) - FIT (Fakulta Informacnich Technologi�)
    test pro soubor: c401.c
	datum: ��jen 2005												 */
/* ***************************************************************** */


#include "c401.h"

tBSTNodePtr TempTree;			// deklarace testovaci promenne

int Content_of_Search;
int Content_of_Insert;
char K;

/* pro vypis budu pouzivat inorder - ktere se shoduje s vypisem uzlu podle zadanych klicu */

void InOrder_PRINT(tBSTNodePtr TempTree)	{
	if (TempTree!=NULL)   	{
		InOrder_PRINT(TempTree->LPtr);     /* pr�chod lev�m podstromem */
		printf("-------------------------------------- \n");
		printf("Vypis hodnoty klice daneho uzlu  -> %c \n", TempTree->Key);
		printf("Vypis hodnoty dat   daneho uzlu  -> %d \n", TempTree->BSTNodeCont);
		printf("-------------------------------------- \n");
		InOrder_PRINT(TempTree->RPtr);    /* pr�chod prav�m podstromem */
	}
}

/* .............................. vypis jednotlivych testu .............................. */


int test_BSTInit(tBSTNodePtr *TempTree)			{
	solved=TRUE;
	BSTInit(TempTree);
	if (!solved)	{
		printf("Operace InitList() nebyla implementovana \n");
		return(FALSE);
	}
	else
		return(TRUE);
}

int test_BSTSearch(tBSTNodePtr TempTree, char K, int *Content)	{
	solved=TRUE;
	int FOUND=FALSE;
	FOUND=BSTSearch(TempTree,K,Content);
	if (!solved)	{
		printf("Operace BSTSearch() nebyla implementovana \n");
		return(FALSE);
	}
	else	{
		if(!FOUND)
			printf("Polozka nebyla nalezena !\n");
		else {
			printf("Polozka byla nalezena !\n");
			printf("Polozka obsahovala hodnotu %d \n", *Content);
		}
		return(TRUE);
	}
}

int test_BSTInsert (tBSTNodePtr* TempTree, char K, int Content)		{
	solved=TRUE;
	BSTInsert(TempTree, K, Content);
	if (!solved)	{
		printf("Operace BSTInsert() nebyla implementovana \n");
		return(FALSE);
	}
	else	{
		InOrder_PRINT((*TempTree));
		return(TRUE);
	}
}

int test_BSTDelete (tBSTNodePtr* TempTree, char K)		{
	solved=TRUE;
	BSTDelete(TempTree,K);
	if (!solved)	{
		printf("Operace BSTDelete() nebyla implementovana \n");
		return(FALSE);
	}
	else	{
		InOrder_PRINT(*TempTree);
		return(TRUE);
	}
}

int test_BSTDispose(tBSTNodePtr* TempTree)		{
	solved=TRUE;
	BSTDispose(TempTree);
	if (!solved)	{
		printf("Operace BSTDispose() nebyla implementovana \n");
		return(FALSE);
	}
	else	{
		InOrder_PRINT(*TempTree);
		return(TRUE);
	}
}

/* .......................... sekce volani jednotlivych testu .............................*/

int main(int argc, char *argv[])			{

	printf("Bin�rn� vyhled�vac� strom\n");
	printf("=========================\n");

	printf("[TEST01]\n");
	printf("Test inicializace....\n");
	test_BSTInit(&TempTree);

	printf("[TEST02]\n");
	printf("Vlo��me n�sleduj�c� integery ve vzestupn�m po�ad� analogicky s kl��i : \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	Content_of_Insert=1;

	BSTInsert(&TempTree,'M',Content_of_Insert);
	BSTInsert(&TempTree,'O',Content_of_Insert);
	BSTInsert(&TempTree,'N',Content_of_Insert);
	BSTInsert(&TempTree,'Q',Content_of_Insert);
	BSTInsert(&TempTree,'R',Content_of_Insert);
	BSTInsert(&TempTree,'P',Content_of_Insert);
	BSTInsert(&TempTree,'C',Content_of_Insert);
	BSTInsert(&TempTree,'B',Content_of_Insert);
	BSTInsert(&TempTree,'E',Content_of_Insert);
	BSTInsert(&TempTree,'A',Content_of_Insert);
	BSTInsert(&TempTree,'D',Content_of_Insert);
	BSTInsert(&TempTree,'F',Content_of_Insert);
	InOrder_PRINT(TempTree);

	printf("[TEST03]\n");
	printf("Pokus�me se vyhledat polo�ky s kl��i 'E', 'R'\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	K='E';
	test_BSTSearch(TempTree,K,&Content_of_Search);
	K='R';
	test_BSTSearch(TempTree,K,&Content_of_Search);

	printf("[TEST04]\n");
	printf("Zru��me jeden z listov�ch uzl� s kl��em 'P'\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	K='P';
	test_BSTDelete(&TempTree,K);

	printf("[TEST5]\n");
	printf("Zru��me uzel, kter� m� jen lev� podstrom, tj. uzel s kl��em 'B' \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  \n");
	K='B';
	test_BSTDelete(&TempTree, K);

	printf("[TEST6]\n");
	printf("Vlo��me zpet klic 'B' : \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	Content_of_Insert=1;
	BSTInsert(&TempTree,'B',Content_of_Insert);
	InOrder_PRINT(TempTree);

	printf("[TEST7]\n");
	printf("Zru��me uzel, kter� m� jen prav� podstrom, tj. uzel s kl��em 'Q' \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	K='Q';
	test_BSTDelete(&TempTree, K);

	printf("[TEST8]\n");
	printf("Zru��me uzel, kter� m� oba podstromy,tj. nap��klad uzel s kl��em 'C' \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	K='C';
	test_BSTDelete(&TempTree, K);

	printf("[TEST9]\n");
	printf("Zru��me korenovy uzel 'M' \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	K='M';
	test_BSTDelete(&TempTree, K);

	printf("[TEST10]\n");
	printf("Vlo��me (aktualizujeme) nove uzly : \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	Content_of_Insert=99;

	BSTInsert(&TempTree,'G',Content_of_Insert);
	BSTInsert(&TempTree,'R',Content_of_Insert);
	BSTInsert(&TempTree,'A',Content_of_Insert);
	BSTInsert(&TempTree,'B',Content_of_Insert);
	BSTInsert(&TempTree,'N',Content_of_Insert);
	BSTInsert(&TempTree,'D',Content_of_Insert);
	BSTInsert(&TempTree,'E',Content_of_Insert);
	BSTInsert(&TempTree,'F',Content_of_Insert);
	BSTInsert(&TempTree,'H',Content_of_Insert);
	BSTInsert(&TempTree,'I',Content_of_Insert);
	BSTInsert(&TempTree,'P',Content_of_Insert);
	BSTInsert(&TempTree,'K',Content_of_Insert);
	BSTInsert(&TempTree,'L',Content_of_Insert);
	BSTInsert(&TempTree,'M',Content_of_Insert);
	BSTInsert(&TempTree,'C',Content_of_Insert);
	BSTInsert(&TempTree,'O',Content_of_Insert);
	BSTInsert(&TempTree,'J',Content_of_Insert);
	BSTInsert(&TempTree,'Q',Content_of_Insert);
	InOrder_PRINT(TempTree);

	printf("[TEST11]\n");
	printf("Pokus�me se zru�it uzel, kter� neexistuje, hodnota kl��e nap��klad 'X' \n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	K='X';
	test_BSTDelete(&TempTree, K);

	printf("[TEST12]\n");
	printf("Nakonec zru��me cel� strom\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	test_BSTDispose(&TempTree);

	printf("------------------------------ konec -------------------------------------\n");
	return(0);
}
