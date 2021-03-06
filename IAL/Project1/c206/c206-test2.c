
/*
 *  P�edm�t: Algoritmy (IAL) - FIT VUT v Brn�
 *  Z�kladn� testy pro p��klad c206.c (Dvousm�rn� v�zan� line�rn� seznam)
 *  Vytvo�il: Martin Tu�ek, z��� 2005
 *  �prava: Bohuslav K�ena, ��jen 2006
 */

#include "c206.h"
                                                         /* pracovn� prom�nn� */
tDLList TEMPLIST;
int obsah=1;

/*******************************************************************************
 * Pomocn� funkce usnad�uj�c� testov�n� vlastn� implementace.
 ******************************************************************************/

void print_elements_of_list(tDLList SEZNAM)	{

	tDLList temp_S=SEZNAM;
	printf("-----------------");
	while (temp_S.First!=NULL)	{
		printf("\n \t%d",temp_S.First->data);
		if ((temp_S.First==SEZNAM.Act) && (SEZNAM.Act!=NULL))
			printf("\t <= toto je aktivn� prvek ");
		temp_S.First=temp_S.First->rptr;
	}
	printf("\n-----------------\n");
}

int test_DLInitList()	{
	solved=TRUE;
	DLInitList(&TEMPLIST);
	if (!solved)	{
		printf("Operace InitList nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLDisposeList()	{
	solved=TRUE;
	DLDisposeList(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDisposeList nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLInsertFirst()	{
	solved=TRUE;
	DLInsertFirst(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace DLInsertFirst nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLInsertLast()	{
	solved=TRUE;
	DLInsertLast(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace DLInsertLast nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLFirst()	{
	solved=TRUE;
	DLFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLFirst nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLLast()	{
	solved=TRUE;
	DLLast(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLLast nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopyFirst()	{
	solved=TRUE;
    int temp=DLCopyFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLCopyFirst nebyla implementov�na!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopyFirst volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}
		else	{
			printf("Operace DLCopyFirst vrac� obsah %d.\n",temp);
			return(TRUE);
		}
	}
}

int test_DLCopyLast()	{
	solved=TRUE;
    int temp=DLCopyLast(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLCopyLast nebyla implementov�na!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopyLast volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}
		else	{
			printf("Operace DLCopyLast vrac� obsah %d.\n",temp);
			return(TRUE);
		}
	}
}

int test_DLDeleteFirst ()	{
	solved=TRUE;
	DLDeleteFirst(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDeleteFirst nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLDeleteLast ()	{
	solved=TRUE;
	DLDeleteLast(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLDeleteLast nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPostDelete()	{
	solved=TRUE;
	DLPostDelete(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPostDelete nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPreDelete()	{
	solved=TRUE;
	DLPreDelete(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPreDelete nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPostInsert()	{
	solved=TRUE;
	DLPostInsert(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace DLPostInsert nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPreInsert()	{
	solved=TRUE;
	DLPreInsert(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace DLPreInsert nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLCopy()	{
	solved=TRUE;
	int temp=DLCopy(&TEMPLIST);

	if (!solved)	{
		printf("Operace DLCopy nebyla implementov�na!\n");
		return(FALSE);
	}
	else {
		if (errflg)	{
			printf("Operace DLCopy volala funkci DLError.\n");
			errflg=FALSE;
			return(FALSE);
		}
		else	{
			printf("Operace DLCopy vrac� obsah %d.\n",temp);
			return(TRUE);
		}
	}
}

int test_DLActualize()	{
	solved=TRUE;
	DLActualize(&TEMPLIST,obsah);
	if (!solved)	{
		printf("Operace DLActualize nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLSucc()	{
	solved=TRUE;
	DLSucc(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLSucc nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLPred()	{
	solved=TRUE;
	DLPred(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLPred nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		print_elements_of_list(TEMPLIST);
		return(TRUE);
	}
}

int test_DLActive()	{
	solved=TRUE;
	int tmp=DLActive(&TEMPLIST);
	if (!solved)	{
		printf("Operace DLActive nebyla implementov�na!\n");
		return(FALSE);
	}
	else	{
		if (tmp)
			printf("Operace DLActive vrac� hodnotu true.\n");
		else
			printf("Operace DLActive vrac� hodnotu false.\n");
		return(TRUE);
	}
}

/*******************************************************************************
 * Z�KLADN� TESTY
 * --------------
 * Za jejich �sp�n� proj�t� z�sk� student prvn� ��st bod� za p��klad.
 * P�i hodnocen� v�ak budou pou�ity roz���en� testy, kter� se zam���
 * i na okrajov� situace. Doporu�ujeme proto, aby si ka�d� student
 * zkusitl tyto z�kladn� testy roz���it o dal�� zaj�mav� situace.
 *
 ******************************************************************************/

int main(int argc, char *argv[])	{

    printf("Dvousm�rn� v�zan� line�rn� seznam\n");
    printf("=================================\n");

    printf("\n[TEST01]\n");
    printf("Inicializace seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~\n");
    test_DLInitList();

    printf("\n[TEST02]\n");
    printf("Zavol�me 2x operaci DLInsertFirst a 2x operaci DLInsertLast.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=1;
    test_DLInsertFirst();
    obsah=2;
    test_DLInsertFirst();
    obsah=3;
    test_DLInsertLast();
    obsah=4;
    test_DLInsertLast();

    printf("\n[TEST03]\n");
    printf("Otestujeme funkci DLFirst p�i neaktivn�m seznamu a funkci DLActive.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();
    test_DLActive();

    printf("\n[TEST04]\n");
    printf("Otestujeme funkci DLLast.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();
    test_DLActive();

    printf("\n[TEST05]\n");
    printf("Test funkce DLCopy p�i aktivit� na posledn�m prvku\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();

    printf("\n[TEST06]\n");
    printf("Test funkce DLPred -- vol�me 3x, aktivita z�stane na prvn�m prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPred();
    test_DLPred();
    test_DLPred();
    test_DLActive();

    printf("\n[TEST07]\n");
    printf("Aktualizujeme obsah aktivn�ho prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    obsah=5;
    test_DLActualize();
    test_DLActive();
    test_DLCopy();

    printf("\n[TEST08]\n");
    printf("Test funkce DLSucc -- vol�me 3x, aktivita z�stane na posledn�m prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();
    test_DLSucc();
    test_DLSucc();
    test_DLActive();

    printf("\n[TEST09]\n");
    printf("Provedeme je�t� jednou DLSucc - aktivita se ztrat�.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLSucc();
    test_DLActive();

    printf("\n[TEST10]\n");
    printf("Nastav�me aktivitu na za��tek a pak ji zru��me operac� DLPred.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLFirst();
    test_DLPred();
    test_DLActive();

    printf("\n[TEST11]\n");
    printf("Pokus o DLCopy p�i neaktivn�m seznamu => o�et�en� chyba.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopy();

    printf("\n[TEST12]\n");
    printf("Pou�it� operace DLCopyFirst p�i neaktivn�m seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyFirst();

    printf("\n[TEST13]\n");
    printf("Pou�it� operace DLCopyLast p�i neaktivn�m seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLCopyLast();

    printf("\n[TEST14]\n");
    printf("Pou�it� operace DLDeleteFirst p�i neaktivn�m seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteFirst();
    test_DLActive();

    printf("\n[TEST15]\n");
    printf("Pou�it� operace DLDeleteLast p�i neaktivn�m seznamu\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDeleteLast();
      test_DLActive();

    printf("\n[TEST16]\n");
    printf("Zkus�me DLPostDelete p�i aktivit� na posledn�m prvku.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLLast();
    test_DLPostDelete();
    test_DLActive();

    printf("\n[TEST17]\n");
    printf("Operace DLPreDelete nyn� sma�e prvn� prvek.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLPreDelete();
    test_DLActive();

    printf("\n[TEST18]\n");
    printf("Seznam nakonec zru��me.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
    test_DLDisposeList();
    test_DLActive();

    printf("\n[TEST19]\n");
    printf("My tests.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~\n");

	for (int i = 0; i < 10; i++) {
		obsah=i;
    	test_DLInsertLast();
    }
    test_DLFirst();
    test_DLLast();

    test_DLPred();
    obsah=10;
    test_DLPostInsert();
    obsah=11;
    test_DLPostInsert();
    test_DLSucc();
    test_DLFirst();
    obsah=12;
    test_DLPreInsert();
    obsah=13;
    test_DLPreInsert();
    test_DLSucc();
    test_DLSucc();
    obsah=14;
    test_DLPreInsert();
    test_DLSucc();
    test_DLSucc();
// printf("111111111111111111----------------------\n");
// 	test_DLFirst();
// 	for (int i = 0; i < 20; i++) {
// 		test_DLSucc();
//     }
printf("111111111111111111----------------------\n");
     test_DLPreDelete();
     test_DLPreDelete();
     test_DLPostDelete();
     test_DLPostDelete();
test_DLDisposeList();
    test_DLActive();

    for (int i = 0; i < 10; i++) {
		obsah=i;
    	test_DLInsertLast();
    }
    test_DLFirst();
    test_DLLast();
     test_DLPred(); test_DLPred(); test_DLPred(); test_DLPred(); test_DLPred(); test_DLPred(); test_DLPred(); test_DLPred();
      test_DLCopy();
      test_DLSucc();
      test_DLCopy();
      test_DLSucc();
      test_DLCopy();
      test_DLPred();
      test_DLCopy();
    printf("\n----------------------- konec p��kladu c206 -------------------------\n");
test_DLDisposeList();
    return(0);
}
