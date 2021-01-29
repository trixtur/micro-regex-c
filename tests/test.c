#include <CUnit/Basic.h>
#include <stdlib.h>
#include <string.h>
#include "../regex.c"

void test_basicMatch(void)
{
    char *testText = "Hello World!";
    char *regex = "o W"; // Match the center of the string.
    CU_ASSERT(match(regex,testText) == 1);
}

CU_ErrorCode matchBasic(CU_pSuite pSuite)
{
   if (NULL == CU_add_test(pSuite, "Basic Match", test_basicMatch)) {
       CU_cleanup_registry();
       return CU_get_error();
   }

   return 0;
}
void test_basicStar(void)
{
    char *testText = "Hello World!";
    char *regex = "lo.*!";
    CU_ASSERT(match(regex,testText) == 1);
}


CU_ErrorCode matchStar(CU_pSuite pSuite)
{
   if (NULL == CU_add_test(pSuite, "Basic Star", test_basicStar)) {
       CU_cleanup_registry();
       return CU_get_error();
   }

   return 0;
}

void test_basicEnd(void)
{
    char *testText = "Hello World!";
    char *regex = ".*!$";
    CU_ASSERT(match(regex,testText) == 1);
}

CU_ErrorCode matchEnd(CU_pSuite pSuite)
{
   if (NULL == CU_add_test(pSuite, "Basic End", test_basicEnd)) {
       CU_cleanup_registry();
       return CU_get_error();
   }

   return 0;
}

int main() {
    CU_ErrorCode err;
   // Initialize the CUnit test registry
   if (CUE_SUCCESS != CU_initialize_registry())
      return CU_get_error();

   // Sets the basic run mode, CU_BRM_VERBOSE will show maximum output of run details
   // Other choices are: CU_BRM_SILENT and CU_BRM_NORMAL
   CU_basic_set_mode(CU_BRM_VERBOSE);

   CU_pSuite pSuite = NULL;

   // Add a suite to the registry
   pSuite = CU_add_suite("getText_test_suite", 0, 0);

   // Always check if add was successful
   if (NULL == pSuite) {
       CU_cleanup_registry();
       return CU_get_error();
   }

   err = matchBasic(pSuite);
   if (err) return err;
   err = matchStar(pSuite);
   if (err) return err;
   err = matchEnd(pSuite);
   if (err) return err;

   // Run the tests and show the run summary
   CU_basic_run_tests();
   return CU_get_error();
}
