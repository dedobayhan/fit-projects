f
/* c206.c **********************************************************}
{* T�ma: Dvousm�rn� v�zan� line�rn� seznam
**
**                   N�vrh a referen�n� implementace: Bohuslav K�ena, ��jen 2001
**                            P�epracovan� do jazyka C: Martin Tu�ek, ��jen 2004
**                                            �pravy: Bohuslav K�ena, ��jen 2006
**
** Implementujte abstraktn� datov� typ dvousm�rn� v�zan� line�rn� seznam.
** U�ite�n�m obsahem prvku seznamu je hodnota typu int.
** Seznam bude jako datov� abstrakce reprezentov�n prom�nnou
** typu tDLList (DL znamen� Double-Linked a slou�� pro odli�en�
** jmen konstant, typ� a funkc� od jmen u jednosm�rn� v�zan�ho line�rn�ho
** seznamu). Definici konstant a typ� naleznete v hlavi�kov�m souboru c206.h.
**
** Va��m �kolem je implementovat n�sleduj�c� operace, kter� spolu
** s v��e uvedenou datovou ��st� abstrakce tvo�� abstraktn� datov� typ
** obousm�rn� v�zan� line�rn� seznam:
**
**      DLInitList ...... inicializace seznamu p�ed prvn�m pou�it�m,
**      DLDisposeList ... zru�en� v�ech prvk� seznamu,
**      DLInsertFirst ... vlo�en� prvku na za��tek seznamu,
**      DLInsertLast .... vlo�en� prvku na konec seznamu,
**      DLFirst ......... nastaven� aktivity na prvn� prvek,
**      DLLast .......... nastaven� aktivity na posledn� prvek,
**      DLCopyFirst ..... vrac� hodnotu prvn�ho prvku,
**      DLCopyLast ...... vrac� hodnotu posledn�ho prvku,
**      DLDeleteFirst ... zru�� prvn� prvek seznamu,
**      DLDeleteLast .... zru�� posledn� prvek seznamu,
**      DLPostDelete .... ru�� prvek za aktivn�m prvkem,
**      DLPreDelete ..... ru�� prvek p�ed aktivn�m prvkem,
**      DLPostInsert .... vlo�� nov� prvek za aktivn� prvek seznamu,
**      DLPreInsert ..... vlo�� nov� prvek p�ed aktivn� prvek seznamu,
**      DLCopy .......... vrac� hodnotu aktivn�ho prvku,
**      DLActualize ..... p�ep�e obsah aktivn�ho prvku novou hodnotou,
**      DLSucc .......... posune aktivitu na dal�� prvek seznamu,
**      DLPred .......... posune aktivitu na p�edchoz� prvek seznamu,
**      DLActive ........ zji��uje aktivitu seznamu.
**
** P�i implementaci jednotliv�ch funck� nevolejte ��dnou z funkc�
** implementovan�ch v r�mci tohoto p��kladu, nen�-li u funkce
** explicitn� uvedeno n�co jin�ho.
**
** Svou implementaci vhodn� komentujte!
**
** Terminologick� pozn�mka: Jazyk C nepou��v� pojem procedura.
** Proto zde pou��v�me pojem funkce i pro operace, kter� by byly
** v algoritmick�m jazyce Pascalovsk�ho typu implemenov�ny jako
** procedury (v jazyce C procedur�m odpov�daj� funkce vracej�c� typ void).
**/

#include "c206.h"

// Debugging
#ifndef NDEBUG
#define NDEBUG
#include <assert.h>
#endif

int solved;
int errflg;

void DLError() {
/*
** Vytiskne upozorn�n� na to, �e do�lo k chyb�.
** Tuto funkci budete volat v r�mci n�kter�ch d�le implementovan�ch operac�.
**/
    printf ("*ERROR* Chyba p�i pr�ci se seznamem.\n");
    errflg = TRUE;             /* glob�ln� prom�nn� -- p��znak o�et�en� chyby */
    return;
}

void DLInitList (tDLList *L)	{
/*
** Provede inicializaci seznamu L p�ed jeho prvn�m pou�it�m (tzn. ��dn�
** z n�sleduj�c�ch funkc� nebude vol�na nad neinicializovan�m seznamem).
** Tato inicializace se nikdy nebude prov�d�t nad ji� inicializovan�m
** seznamem, a proto tuto mo�nost neo�et�ujte. V�dy p�edpokl�dejte,
** �e neinicializovan� prom�nn� maj� nedefinovanou hodnotu.
**/
	assert(L != NULL);

	L->First = L->Last = L->Act = NULL;
}

void DLDisposeList (tDLList *L)	{
/*
** Zru�� v�echny prvky seznamu L a uvede seznam do stavu, v jak�m
** se nach�zel po inicializaci. Ru�en� prvky seznamu budou korektn�
** uvoln�ny vol�n�m operace free.
**/
	assert(L != NULL);

	tDLElemPtr item_backup;
	tDLElemPtr next_item = L->First;
	while ((item_backup = next_item) != NULL) {
		next_item = next_item->rptr;
		free(item_backup);
	}

	// Set list to the initialization state
	L->First = L->Last = L->Act = NULL;
}

void DLInsertFirst (tDLList *L, int val)	{
/*
** Vlo�� nov� prvek na za��tek seznamu L.
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci DLError().
**/
	assert(L != NULL);

	// Create new item
	tDLElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		DLError();
 		return;
	}

	new_item->data = val;
	new_item->lptr = NULL;
	new_item->rptr = L->First;

	if (L->First) {
		// There is at least one item in the list
		L->First->lptr = new_item;
	}
	else {
		// There are no items in the list
		L->Last = new_item;
	}

	L->First = new_item;
}

void DLInsertLast(tDLList *L, int val)	{
/*
** Vlo�� nov� prvek na konec seznamu L (symetrick� operace k DLInsertFirst).
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci DLError().
**/
	assert(L != NULL);

	// Create new item
	tDLElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		DLError();
 		return;
	}

	new_item->data = val;
	new_item->lptr = L->Last;
	new_item->rptr = NULL;

	if (L->Last) {
		// There is at least one item in the list
		L->Last->rptr = new_item;
	}
	else {
		// There are no items in the list
		L->First = new_item;
	}

	L->Last = new_item;
}

void DLFirst (tDLList *L)	{
/*
** Nastav� aktivitu na prvn� prvek seznamu L.
** Funkci implementujte jako jedin� p��kaz (nepo��t�me-li return),
** ani� byste testovali, zda je seznam L pr�zdn�.
**/
	assert(L != NULL);

	L->Act = L->First;
}

void DLLast (tDLList *L)	{
/*
** Nastav� aktivitu na posledn� prvek seznamu L.
** Funkci implementujte jako jedin� p��kaz (nepo��t�me-li return),
** ani� byste testovali, zda je seznam L pr�zdn�.
**/
	assert(L != NULL);

	L->Act = L->Last;
}

int DLCopyFirst (tDLList *L)	{
/*
** Vr�t� hodnotu prvn�ho prvku seznamu L. Pokud je seznam L pr�zdn�,
** vol� funkci DLError.
**/
	assert(L != NULL);

	if (!L->First) {
		DLError();

		// Result is undefined, so I can return anything
		return 1;
	}

	return L->First->data;
}

int DLCopyLast (tDLList *L)	{
/*
** Vr�t� hodnotu posledn�ho prvku seznamu L. Pokud je seznam L pr�zdn�,
** vol� funkci DLError.
**/
	assert(L != NULL);

	if (!L->Last) {
		DLError();

		// Result is undefined, so I can return anything
		return 1;
	}

	return L->Last->data;
}

void DLDeleteFirst (tDLList *L)	{
/*
** Zru�� prvn� prvek seznamu L. Pokud byl prvn� prvek aktivn�, aktivita
** se ztr�c�. Pokud byl seznam L pr�zdn�, nic se ned�je.
**/
	assert(L != NULL);

	if (!L->First)
		return;

	// If the first item is active, list will become deactive
	if (L->Act == L->First)
		L->Act = NULL;

	// Delete first item
	tDLElemPtr first_item = L->First;
	L->First = L->First->rptr;
	L->First->lptr = NULL;
	free(first_item);
}

void DLDeleteLast (tDLList *L)	{
/*
** Zru�� posledn� prvek seznamu L. Pokud byl posledn� prvek aktivn�,
** aktivita seznamu se ztr�c�. Pokud byl seznam L pr�zdn�, nic se ned�je.
**/
	assert(L != NULL);

	if (!L->Last)
		return;

	// If the last item is active, list will become deactive
	if (L->Act == L->Last)
		L->Act = NULL;

	// Delete last item
	tDLElemPtr last_item = L->Last;
	L->Last = L->Last->lptr;
	if (L->Last != NULL)
		L->Last->rptr = NULL;

	free(last_item);
}

void DLPostDelete (tDLList *L)	{
/*
** Zru�� prvek seznamu L za aktivn�m prvkem.
** Pokud nebyl seznam L aktivn�, nic se ned�je.
**/
	assert(L != NULL);

	if (!L->Act || (L->Act == L->Last))
		return;

	// Delete item next to the active item
	tDLElemPtr backup_item = L->Act->rptr;
	L->Act->rptr = L->Act->rptr->rptr;

	if (backup_item == L->Last) {
		// Deleted item is the last one
		L->Last = L->Act;
	}
	else {
		L->Act->rptr->lptr = L->Act;
	}
	free(backup_item);
}

void DLPreDelete (tDLList *L)	{
/*
** Zru�� prvek seznamu L p�ed aktivn�m prvkem.
** Pokud nebyl seznam L aktivn�, nic se ned�je.
**/
	assert(L != NULL);

	if (!L->Act || (L->Act == L->First))
		return;

	// Delete item before the active item
	tDLElemPtr backup_item = L->Act->lptr;
	L->Act->lptr = L->Act->lptr->lptr;

 	if (backup_item == L->First) {
		// Deleted item is the first one
		L->First = L->Act;
	}
	else {
		L->Act->lptr->rptr = L->Act;
	}
	free(backup_item);
}

void DLPostInsert (tDLList *L, int val) {
/*
** Vlo�� prvek za aktivn� prvek seznamu L.
** Pokud nebyl seznam L aktivn�, nic se ned�je.
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci DLError().
**/
	assert(L != NULL);

	if (!L->Act)
		return;

	// Create new item
	tDLElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		DLError();
 		return;
	}

	new_item->data = val;
	new_item->rptr = L->Act->rptr;
	new_item->lptr = L->Act;
	L->Act->rptr = new_item;

	// Correct pointer to the last item
	if (L->Act == L->Last)
		L->Last = new_item;
	else
		new_item->rptr->lptr = new_item;
}

void DLPreInsert (tDLList *L, int val)		{
/*
** Vlo�� prvek p�ed aktivn� prvek seznamu L.
** Pokud nebyl seznam L aktivn�, nic se ned�je.
** V p��pad�, �e nen� dostatek pam�ti pro nov� prvek p�i operaci malloc,
** vol� funkci DLError().
**/
	assert(L != NULL);

	if (!L->Act)
		return;

	// Create new item
	tDLElemPtr new_item = malloc(sizeof(*new_item));
	if (!new_item){
		DLError();
 		return;
	}

	new_item->data = val;
	new_item->lptr = L->Act->lptr;
	new_item->rptr = L->Act;
	L->Act->lptr = new_item;

	// Correct pointer to the first item
	if (L->Act == L->First)
		L->First = new_item;
	else
		new_item->lptr->rptr = new_item;
}

int DLCopy (tDLList *L)	{
/*
** Vr�t� hodnotu aktivn�ho prvku seznamu L.
** Pokud seznam L nen� aktivn�, vol� funkci DLError.
**/
	assert(L != NULL);

	if (!L->Act) {
		DLError();

		// Result is undefined, so I can return anything
		return 1;
	}

	return L->Act->data;
}

void DLActualize (tDLList *L, int val) {
/*
** P�ep�e obsah aktivn�ho prvku seznamu L.
** Pokud seznam L nen� aktivn�, ned�l� nic.
**/
	assert(L != NULL);

	if (!L->Act) {
		return;
	}

	L->Act->data = val;
}

void DLSucc (tDLList *L)	{
/*
** Posune aktivitu na n�sleduj�c� prvek seznamu L.
** Nen�-li seznam aktivn�, ned�l� nic.
** V�imn�te si, �e p�i aktivit� na posledn�m prvku se seznam stane neaktivn�m.
**/
	assert(L != NULL);

	if (!L->Act) {
		return;
	}

	L->Act = L->Act->rptr;
}


void DLPred (tDLList *L)	{
/*
** Posune aktivitu na p�edchoz� prvek seznamu L.
** Nen�-li seznam aktivn�, ned�l� nic.
** V�imn�te si, �e p�i aktivit� na prvn�m prvku se seznam stane neaktivn�m.
**/
	assert(L != NULL);

	if (!L->Act) {
		return;
	}

	L->Act = L->Act->lptr;
}

int DLActive (tDLList *L) {
/*
** Je-li seznam aktivn�, vrac� true. V opa�n�m p��pad� vrac� false.
** Funkci implementujte jako jedin� p��kaz.
**/
	assert(L != NULL);

	return (L->Act != NULL) ? TRUE : FALSE;
}

/* Konec c206.c*/
