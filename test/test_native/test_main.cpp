#include <unity.h>

void test_example()
{
  TEST_MESSAGE("This is a test message.");
  TEST_ASSERT_EQUAL(2, 1);
}

int main()
{
  UNITY_BEGIN();
  RUN_TEST(test_example);
  return UNITY_END();
}
