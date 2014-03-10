
/* c201.c *********************************************************************}
{* T�ma: Jednosm�rn� line�rn� seznam
**
**                     N�vrh a referen�n� implementace: Petr P�ikryl, ��jen 1994
**                                          �pravy: Andrea N�mcov� listopad 1996
**                                                   Petr P�ikryl, listopad 1997
**                                P�epracovan� zad�n�: Petr P�ikryl, b�ezen 1998
**                                  P�epis do jazyka C: Martin Tu�ek, ��jen 2004
**	                                          �pravy: Bohuslav K�ena, ��jen 2006
**
** Implementujte abstraktn� datov� typ jednosm�rn� line�rn� seznam.
** U�ite�n�m obsahem prvku seznamu je cel� ��slo typu int.
** Seznam bude jako datov� abstrakce reprezentov�n prom�nnou typu tList.
** Definici konstant a typ� naleznete v hlavi�kov�m souboru c201.h.
**
** Va��m �kolem je implementovat n�sleduj�c� operace, kter� spolu s v��e
** uvedenou datovou ��st� abstrakce tvo�� abstraktn� datov� typ tList:
**
**      InitList ...... inicializace seznamu p�ed prvn�m pou�it�m,
**      DisposeList ... zru�en� v�ech prvk� seznamu,
**      InsertFirst ... vlo�en� prvku na za��tek seznamu,
**      First ......... nastaven� aktivity na prvn� prvek,
**      CopyFirst ..... vrac� hodnotu prvn�ho prvku,
**      DeleteFirst ... zru�� prvn� prvek seznamu,
**      PostDelete .... ru�� prvek za aktivn�m prvkem,
**      PostInsert .... vlo�� nov� prvek za aktivn� prvek seznamu,
**      LCopy ......... vrac� hodnotu aktivn�ho prvku,
**      actualize ..... p�ep�e obsah aktivn�ho prvku novou hodnotou,
**      LSucc ......... posune aktivitu na dal�� prvek seznamu,
**      active ........ zji��uje aktivitu seznamu.
**
** P�i implementaci funck� nevolejte ��dnou z funkc� implementovan�ch v r�mci
** tohoto p��kladu, nen�-li u funkce explicitn� uvedeno n�co jin�ho.
**
** Svou implementaci vhodn� komentujte!
**
** Terminologick� pozn�mka: Jazyk C nepou��v� pojem procedura.
** Proto zde pou��v�me pojem funkce i pro operace, kter� by byly
** v algoritmick�m jazyce Pascalovsk�ho typu implemenov�ny jako
** procedury (v jazyce C procedur�m odpov�daj� funkce vracej�c� typ void).
**/

#include "c201.h"

// Debugging
#ifndef NDEBUG
#define NDEBUG
#include <assert.h>
#endif

int solved;
int errflg;

void Error()	{
/*
** Vytiskne upozorn�n� na to, �e do�lo k chyb�.
** Tuto funkci budete volat v r�mci n�kter�ch d�le implementovan�ch operac�.
**/
    printf ("*ERROR* Chyba p�i pr�ci se seznamem.\n");
    errflg = TRUE;                      /* glob�ln� prom�nn� -- p��znak chyby */
}

void InitList (tList *L)	{
/*
** Provede inicializaci seznamu L p�ed jeho prvn�m pou�it�m (tzn. ��dn�
** z n�sleduj�c�ch funkc� nebude vol�na nad neinicializovan�m seznamem).
** Tato inicializace se nikdy nebude prov�d�t nad ji� inicializovan�m
** seznamem, a proto tuto mo�nost neo�et�ujte. V�dy p�edpokl�dejte,
** �e neinicializovan� prom�nn� maj� nedefinovanou hodnotu.
**/
	assert(L != NULL);

	L->act = L->frst = NULL;
}

void DisposeList (tList *L)	{
/*
** Zru�� v�echny prvky seznamu L a uvede seznam L do stavu, v jak�m se nach�zel
** po inicializaci. V�echny prvky seznamu L budou korektn� uvoln�ny vol�n�m
** operace free.
***/
	assert(L != NULL);

	tElemPtr item_backup;
	tElemPtr next_item = L->frst;
	while ((item_backup = next_item) != NULL) {
		next_item = next_item->ptr;
		free(item_backup);
	}

	// Set list to the initialization state
	L->frst = L->act = NULL;
}

void InsertFirst (tList *L, int val)	{
/*
** Vlo�� prvek s hodnotou val na za��tek seznamu L.
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci Error().
**/
	assert(L != NULL);

	// Create new item
 	tElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		Error();
 		return;
	}

	new_item->data = val;
	new_item->ptr = L->frst;
	L->frst = new_item;
}

void First (tList *L)		{
/*
** Nastav� aktivitu seznamu L na jeho prvn� prvek.
** Funkci implementujte jako jedin� p��kaz, ani� byste testovali,
** zda je seznam L pr�zdn�.
**/
	assert(L != NULL);

	L->act = L->frst;
}

void CopyFirst (tList *L, int *val)	{
/*
** Vr�t� hodnotu prvn�ho prvku seznamu L.
** Pokud je seznam L pr�zdn�, vol� funkci Error().
**/
	assert(L != NULL && val != NULL);

	// Check whether list is not empty
	if (!L->frst) {
		Error();
		return;
	}

	*val = L->frst->data;
}

void DeleteFirst (tList *L)	{
/*
** Ru�� prvn� prvek seznamu L. Pokud byl seznam L aktivn�, aktivita se ztr�c�.
** Pokud byl seznam L pr�zdn�, nic se ned�je!
**/
	assert(L != NULL);

	// Check whether list is not empty
	if (!L->frst)
		return;

	// If the first item is active, list will become deactive
	if (L->act == L->frst)
		L->act = NULL;

	tElemPtr frst_item_backup = L->frst;
	L->frst = L->frst->ptr;
	free(frst_item_backup);
}

void PostDelete (tList *L)			{
/*
** Ru�� prvek seznamu L za aktivn�m prvkem. Pokud nen� seznam L aktivn�
** nebo pokud je aktivn� posledn� prvek seznamu L, nic se ned�je!
**/
	assert(L != NULL);

	// Check whether list is active
	// and we're not at the last item of the list
	if (!L->act || L->act->ptr == NULL)
		return;

	tElemPtr item_backup = L->act->ptr;
	L->act->ptr = L->act->ptr->ptr;
	free(item_backup);
}

void PostInsert (tList *L, int val)	{
/*
** Vlo�� prvek s hodnotou val za aktivn� prvek seznamu L.
** Pokud nebyl seznam L aktivn�, nic se ned�je!
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci Error().
**/
	assert(L != NULL);

	// Check whether list is active
	if (!L->act) {
		return;
	}

	// Create new item
	tElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		Error();
 		return;
	}

	new_item->data = val;
	new_item->ptr = L->act->ptr;
	L->act->ptr = new_item;
}

void Copy (tList *L, int *val)		{
/*
** Vr�t� hodnotu aktivn�ho prvku seznamu L.
** Pokud seznam nen� aktivn�, vol� se funkce Error().
**/
	assert(L != NULL && val != NULL);

	// Check whether list is active
	if (!L->act) {
		Error();
		return;
	}

	*val = L->act->data;
}

void Actualize (tList *L, int val)	{
/*
** P�ep�e data aktivn�ho prvku seznamu L.
** Pokud seznam L nen� aktivn�, ned�l� nic!
**/
	assert(L != NULL);

	// Check whether list is active
	if (!L->act)
		return;

	L->act->data = val;
}

void Succ (tList *L)	{
/*
** Posune aktivitu na n�sleduj�c� prvek seznamu L.
** V�imn�te si, �e touto operac� se m��e aktivn� seznam st�t neaktivn�m.
** Pokud seznam L nen� aktivn�, ned�l� nic!
**/
	assert(L != NULL);

	// Check whether list is active
	if (!L->act)
		return;

	L->act = L->act->ptr;
}

int Active (tList *L) 	{
/*
** Je-li seznam L aktivn�, vrac� True. V opa�n�m p��pad� vrac� false.
** Tuto funkci implementujte jako jedin� p�i�azovac� p��kaz,
**/
	assert(L != NULL);

	return (L->act != NULL) ? TRUE : FALSE;
}

/* Konec c201.c */
