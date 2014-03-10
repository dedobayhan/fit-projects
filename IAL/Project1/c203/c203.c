
/* ******************************* c203.c *********************************** */
/*  P�edm�t: Algoritmy (IAL) - FIT VUT v Brn�                                 */
/*  �kol: c203 - Fronta znak� v poli                                          */
/*  Referen�n� implementace: Petr P�ikryl, 1994                               */
/*  P�epis do jazyka C: V�clav Topinka, z��� 2005                             */
/*  �pravy: Bohuslav K�ena, ��jen 2006                                        */
/* ************************************************************************** */
/*
** Implementujte frontu znak� v poli. P�esnou definici typ� naleznete
** v hlavi�kov�m souboru c203.h (ADT fronta je reprezentov�na strukturou tQueue,
** kter� obsahuje pole 'arr' pro ulo�en� hodnot ve front� a indexy f_index
** a b_index. V�echny implementovan� funkce mus� p�edpokl�dat velikost pole
** QUEUE_SIZE, i kdy� ve skute�nosti jsou rozm�ry statick�ho pole definov�ny
** QUEUE_MAX. Hodnota QUEUE_SIZE slou�� k simulaci fronty v r�zn� velk�m poli
** a nastavuje se v testovac�m skriptu p203-test.c p�ed testov�n�m
** implementovan�ch funkc�. Hodnota QUEUE_SIZE m��e nab�vat hodnot v rozsahu
** 1 a� QUEUE_MAX.
**
** Index f_index ukazuje v�dy na prvn� prvek ve front�. Index b_index
** ukazuje na prvn� voln� prvek ve front�. Pokud je fronta pr�zdn�, ukazuj�
** oba indexy na stejn� m�sto. Po inicializaci ukazuj� na prvn� prvek pole,
** obsahuj� tedy hodnotu 0. Z uveden�ch pravidel vypl�v�, �e v poli je v�dy
** minim�ln� jeden prvek nevyu�it�.
**
** P�i v�ech operac�ch se oba indexy (f_index i b_index) v�dy zv�t�uj�
** s v�jimkou p��padu, kdy index p�es�hne hranici QUEUE_SIZE. V tom p��pad�
** se "posunuje" znovu na za��tek pole. Za t�mto ��elem budete deklarovat
** pomocnou funkci NextIndex, kter� pro kruhov� pohyb p�es indexy pole
** vyu��v� operaci "modulo".
**
** Implementujte n�sleduj�c� funkce:
**
**    nextIndex ..... pomocn� funkce - viz popis v��e
**    queueInit ..... inicializace fronty
**    queueEmpty .... test na pr�zdnost fronty
**    queueFull ..... test, zda je fronta zapln�na (vy�erp�na kapacita)
**    queueFront .... p�e�te hodnoty prvn�ho prvku z fronty
**    queueRemove ... odstran� prvn� prvek fronty
**    queueGet ...... p�e�te a odstran� prvn� prvek fronty
**    queueUp ....... za�azen� prvku na konec fronty
**
** Sv� �e�en� ��eln� komentujte!
**
** Terminologick� pozn�mka: Jazyk C nepou��v� pojem procedura.
** Proto zde pou��v�me pojem funkce i pro operace, kter� by byly
** v algoritmick�m jazyce Pascalovsk�ho typu implemenov�ny jako
** procedury (v jazyce C procedur�m odpov�daj� funkce vracej�c� typ void).
**
**/

#include "c203.h"

void queueError ( int error_code ) {
/*
** Vytiskne upozorn�n� na to, �e do�lo k chyb�.
** Tuto funkci budete volat v r�mci n�kter�ch d�le implementovan�ch operac�.
**
** TUTO FUNKCI, PROS�ME, NEUPRAVUJTE!
*/
	static const char* QERR_STRINGS[MAX_QERR+1] = {"Unknown error","Queue error: UP","Queue error: FRONT","Queue error: REMOVE","Queue error: GET","Queue error: INIT"};
	if ( error_code <= 0 || error_code > MAX_QERR )
		error_code = 0;
	printf ( "%s\n", QERR_STRINGS[error_code] );
	err_flag = 1;
}

void queueInit ( tQueue* q ) {
/*
** Inicializujte frontu n�sleduj�c�m zp�sobem:
** - v�echny hodnoty v poli q->arr nastavte na '?',
** - index na za��tek fronty nastavte na 0,
** - index prvn�ho voln�ho m�sta nastavte tak� na 0.
**
** V p��pad�, �e funkce dostane jako parametr q == NULL, volejte funkci
** queueError(QERR_INIT).
*/
	if (!q) {
		queueError(QERR_INIT);
		return;
	}

	for (int i = 0; i < QUEUE_SIZE + 1; i++)
		q->arr[i] = '?';

	q->f_index = q->b_index = 0;
}

int nextIndex ( int index ) {
/*
** Pomocn� funkce, kter� vrac� index n�sleduj�c�ho prvku v poli.
** Funkci implementujte jako jedin� prikaz vyu��vaj�c� operace '%'.
** Funkci nextIndex budete vyu��vat v dal��ch implementovan�ch funkc�ch.
*/
 	return (index + 1) % QUEUE_SIZE;
}

int queueEmpty ( const tQueue* q ) {
/*
** Vrac� nenulovou hodnotu, pokud je frona pr�zdn�, jinak vrac� hodnotu 0.
** Funkci implementujte jako jedin� p��kaz.
*/
	return (q->f_index == q->b_index);
}

int queueFull ( const tQueue* q ) {
/*
** Vrac� nenulovou hodnotu, je-li fronta pln�, jinak vrac� hodnotu 0.
** Funkci implementujte jako jedin� p��kaz s vyu�it�m pomocn� funkce nextIndex.
*/
	return nextIndex(q->b_index) == q->f_index;
}

char queueFront ( const tQueue* q ) {
/*
** Vr�t� znak ze za��tku fronty. Pokud je fronta pr�zdn�, o�et�ete to vol�n�m
** funkce queueError(QERR_FRONT) a jako n�vratovou hodnotu vra�te hodnotu 1.
** P�i implementaci vyu�ijte d��ve definovan� funkce queueEmpty.
**
** Vol�n� t�to funkce p�i pr�zdn� front� je v�dy nutn� pova�ovat za nekorektn�.
** B�v� to toti� d�sledek �patn�ho n�vrhu algoritmu, ve kter�m je fronta
** pou�ita. O takov� situaci se proto mus� program�tor-v�voj�� dozv�d�t.
** V opa�n�m p��pad� je lad�n� program� obt��n�j��!
*/
	if (queueEmpty(q)) {
		queueError(QERR_FRONT);
		return 1;
	}

	return q->arr[q->f_index];
}

void queueRemove ( tQueue* q ) {
/*
** Odstran� znak ze za��tku fronty. Pokud je fronta pr�zdn�, o�et�ete
** vzniklou chybu vol�n�m funkce queueError(QERR_REMOVE).
** Hodnotu na uvoln�n� pozici ve front� nijak neo�et�ujte (nep�episujte).
** P�i implementaci vyu�ijte d��ve definovan� funkce queueEmpty a nextIndex.
*/
	if (queueEmpty(q)) {
		queueError(QERR_REMOVE);
		return;
	}

	q->f_index = nextIndex(q->f_index);
}

char queueGet ( tQueue* q ) {
/*
** Odstran� znak ze za��tku fronty a vr�t� jej jako n�vratovou hodnotu.
** Pokud je fronta pr�zdn�, o�et�ete vzniklou chybu vol�n�m
** funkce queueError(QERR_GET). N�vratovou hodnota v p��pad� chyby
** je nedefinovan� (stejn� p��pad jako queueFront).
**
** P�i implementaci vyu�ijte d��ve definovan�ch funkc� queueEmpty,
** queueFront a queueRemove.
*/
	if (queueEmpty(q)) {
		queueError(QERR_GET);
		return 1;
	}

	char value = queueFront(q);
	queueRemove(q);

	return value;
}

void queueUp ( tQueue* q, char c ) {
/*
** Vlo�� znak c do fronty. Pokud je fronta pln�, o�et�ete chybu vol�n�m
** funkce queueError(QERR_UP). Vkl�d�n� do pln� fronty se pova�uje za
** nekorektn� operaci. Situace by mohla b�t �e�ena i tak, �e by operace
** neprov�d�la nic, ale v p��pad� pou�it� takto definovan� abstrakce by se
** obt��n� odhalovaly chyby v algoritmech, kter� by abstrakci vyu��valy.
**
** P�i implementaci vyu�ijte d��ve definovan�ch funkc� queueFull a nextIndex.
*/
	if (queueFull(q)) {
		queueError(QERR_UP);
		return;
	}

	q->arr[q->b_index] = c;
	q->b_index = nextIndex(q->b_index);
}
/* Konec p��kladu c203.c */
