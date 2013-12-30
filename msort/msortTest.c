#include "testUtils.h"
#include "msort.h"
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef struct {
       int id;
       int salary;
} Account;

int compareNumbers ( void* a,  void* b){
    if(*(int*)a < *(int*)b) return 1;
    return 0;
}

void test_isort_will_sort_an_array_of_integers(){
       int expected[] = {2,5,7,9,99};
       int actual[] = {99,5,2,7,9};
       int result;
       msort(actual, 5, sizeof(int), compareNumbers);
       result = memcmp(expected, actual, sizeof(expected));
       ASSERT(0 == result);
}

int areAccountsEqual(Account* expected,Account* actual){
    return expected->id == actual->id && expected->salary == actual->salary ;
}

int compareAccountsBySalary(void* first, void* second){
       Account* firstAccount = (Account*)first;
       Account* secondAccount = (Account*)second;
       if(firstAccount->salary < secondAccount->salary) 
       return 1;
       return 0;
}

void test_isort_will_sort_Account_based_on_salary(){
       Account expected[] = {{123,1000},{345,8500},{421,9000},{599,9900}};
       Account Accounts[] = {{599,9900},{345,8500}, {421,9000},{123,1000}};
       msort(Accounts, 4, sizeof(Account), compareAccountsBySalary);
       ASSERT(1 == areAccountsEqual(expected, Accounts));
}
