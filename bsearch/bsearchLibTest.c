#include "testUtils.h"
#include "bsearchLib.h"
#include <stdio.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareMyType (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}


void test_bsearch_will_return_searched_value_if_found(){
	int key = 9;
	int values[8] = {2,6,9,12,34,56,90,102};
	int noOfElements = 8;
	int *element;
	element = bsearch(&key,&values,noOfElements,sizeof(int),compareMyType);
	ASSERT(9==*element);
}

void test_bsearch_will_return_null_when_value_is_not_found(){
	int key = 19;
	int values[6] = {2,6,7,34,56,90};
	int noOfElements = 6;
	int *element;
	element = bsearch(&key,&values,noOfElements,sizeof(int),compareMyType);
	ASSERT(NULL==element);
}

void test_bsearch_will_return___when_value_is___found(){
	int key = 7;
	int values[10] = {1,2,3,4,5,6,7,8,9,10};
	int noOfElements = 10;
	int *element;
	element = bsearch(&key,&values,noOfElements,sizeof(int),compareMyType);
	ASSERT(7==*element);
}
