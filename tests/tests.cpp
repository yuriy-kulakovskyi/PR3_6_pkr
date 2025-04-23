#include <gtest/gtest.h>
#include "../functions/functions.h"

TEST(SearchBySurnameTest, FindsExistingSubscriber) {
  Elem* first = nullptr;
  Elem* last = nullptr;

  // Add subscribers to the queue
  enqueue(first, last, { "Іваненко", "0971234567" });
  enqueue(first, last, { "Петренко", "0507654321" });
  enqueue(first, last, { "Сидоренко", "0639876543" });

  Subscriber result;

  // Test finding an existing subscriber
  EXPECT_TRUE(searchBySurname(first, "Петренко", result));
  EXPECT_EQ(result.surname, "Петренко");
  EXPECT_EQ(result.phone, "0507654321");

  // Test searching for a non-existing subscriber
  EXPECT_FALSE(searchBySurname(first, "Коваленко", result));

  // Clean up
  destroyQueue(first, last);
}