#include <Arduino.h>
#include <unity.h>

void test_example()
{
  TEST_ASSERT_EQUAL(1, 1); // Example test
}

void setup()
{
  UNITY_BEGIN();
  RUN_TEST(test_example);
  UNITY_END();
}

void loop() {}