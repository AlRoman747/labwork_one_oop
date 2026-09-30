#include <gtest/gtest.h>
#include "../src/str_ops.h"
#include "../src/task_14.h"

TEST(BasicFunctionsTest, HandleLenFunc)
{
	char test_s[] = "hello world";
	EXPECT_EQ(str_len(test_s), 11);
}

TEST(BasicFunctionsTest, HandleCopyFunc)
{
	char test_copy_s[] = "this string copied";
	const std::size_t len = str_len(test_copy_s);
	char *buffer = new char[len + 1];
	str_copy(buffer, test_copy_s);
	EXPECT_STREQ(buffer, test_copy_s);
	EXPECT_NE((void *)test_copy_s, (void *)buffer);
	delete[] buffer;
}

TEST(BasicFunctionsTest, HandleDeleteFunc)
{
	const char *text = "this string will be delete";
	const std::size_t len = str_len(text);
	char *test_del_s = new char[len + 1];
	str_copy(test_del_s, text);
	str_delete(test_del_s);
	EXPECT_EQ(test_del_s, nullptr);
}

TEST(BasicFunctionsTest, HandleAllocFunc)
{
	char test_copy_s[] = "this string copied";
	char *alloc_s = str_alloc(test_copy_s);
	EXPECT_STREQ(alloc_s, test_copy_s);
	EXPECT_NE((void *)test_copy_s, (void *)alloc_s);
	str_print(alloc_s);
}

TEST(TaskFunctionsTest, HandleReversFunc)
{
	char new_s[] = "one two three";
	char res[] = "three two one";
	str_reverse_words(new_s);
	EXPECT_STREQ(new_s, res);
}

TEST(TaskFunctionTest, HandleTrimFunc)
{
	char *s = new char[20];
	str_copy(s, "   hello    ");
	char *res = str_trim(s);
	char test_res[] = "hello";
	EXPECT_STREQ(res, test_res);
	EXPECT_GT(str_len(s), str_len(res));
}