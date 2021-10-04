#include <fcntl.h>
#include <gtest/gtest.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
extern "C"
{
#include "ft_printf.h"
}

/* *******
 * printf
 *********/

TEST(printf, no_specifier1)
{
	testing::internal::CaptureStdout();
	int res1 = printf("a");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("a");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, no_specifier2)
{
	testing::internal::CaptureStdout();
	int res1 = printf("abcdefghijklmnopqrstuvwxyz");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("abcdefghijklmnopqrstuvwxyz");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, new_line)
{
	testing::internal::CaptureStdout();
	int res1 = printf("\n");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("\n");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, space)
{
	testing::internal::CaptureStdout();
	int res1 = printf("\t  ");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("\t  ");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * %c
 *********/

TEST(printf, percent_c)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%c\n", 'a');
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%c\n", 'a');
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_c_double)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%c %c\n", 'a', 'z');
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%c %c\n", 'a', 'z');
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * %s
 *********/

TEST(printf, percent_str)
{
	char s[] = "abc";
	testing::internal::CaptureStdout();
	int res1 = printf("%s\n", s);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%s\n", s);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_str_double)
{
	char s[] = "abc";
	char s2[] = "01234567";
	testing::internal::CaptureStdout();
	int res1 = printf("%s %s\n", s, s2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%s %s\n", s, s2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_str_NULL)
{
	testing::internal::CaptureStdout();
	char *s = NULL;
	int res1 = printf("%s %s\n", s, s);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%s %s\n", s, s);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_str_not_null_terminated)
{
	char *str = (char *)malloc(3);
	memset(str, '\0', 3);

	testing::internal::CaptureStdout();
	int res1 = printf("%s", str);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%s", str);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
	free(str);
}

TEST(printf, percent_str_not_ascii_include)
{
	unsigned char *str = (unsigned char *)malloc(257);
	for (int i = 0; i < 256; i++)
	{
		str[i] = (unsigned char)(i + 1);
	}
	str[256] = '\0';
	testing::internal::CaptureStdout();
	int res1 = printf("%s", str);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%s", str);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
	free(str);
}

/* *******
 * %p
 *********/

TEST(printf, percent_pointer)
{
	int d = 0;
	testing::internal::CaptureStdout();
	int res1 = printf("%p\n", &d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%p\n", &d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_pointer_double)
{
	int d = 0;
	int d2 = 1;
	testing::internal::CaptureStdout();
	int res1 = printf("%p, %p\n", &d, &d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%p, %p\n", &d, &d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_pointer_malloc)
{
	char *p = (char *)malloc(2);
	testing::internal::CaptureStdout();
	int res1 = printf("%p\n", &p);
	std::string output1 = testing::internal::GetCapturedStdout();

	p[0] = 'a';
	testing::internal::CaptureStdout();
	int res2 = ft_printf("%p\n", &p);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
	free(p);
}

TEST(printf, percent_pointer_immidiate)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%p\n", (void *)1);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%p\n", (void *)1);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_pointer_null)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%p\n", (void *)0);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%p\n", (void *)0);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}
/* *******
 * %d
 *********/

TEST(printf, percent_dec)
{
	int d = INT_MAX;
	testing::internal::CaptureStdout();
	int res1 = printf("%d\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%d\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_dec_double)
{
	int d = INT_MAX;
	int d2 = INT_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%d %d\n", d, d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%d %d\n", d, d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_dec_overflow)
{
	int64_t d = (long long)INT_MAX + 1;
	int64_t d2 = (long long)INT_MIN - 1;
	testing::internal::CaptureStdout();
	int res1 = printf("%d %d\n", (int)d, (int)d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%d %d\n", (int)d, (int)d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_dec_overflow_longmax)
{
	int64_t d = (long long)LONG_MAX;
	int64_t d2 = (long long)LONG_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%d %d\n", (int)d, (int)d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%d %d\n", (int)d, (int)d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}
/* *******
 * %i
 *********/

TEST(printf, percent_int)
{
	int d = INT_MAX;
	testing::internal::CaptureStdout();
	int res1 = printf("%i\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%i\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_int_double)
{
	int d = INT_MAX;
	int d2 = INT_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%i %i\n", d, d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%i %i\n", d, d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_int_overflow)
{
	int64_t d = (long long)INT_MAX + 1;
	int64_t d2 = (long long)INT_MIN - 1;
	testing::internal::CaptureStdout();
	int res1 = printf("%i %i\n", (int)d, (int)d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%i %i\n", (int)d, (int)d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_long_overflow)
{
	int64_t d = (long long)LONG_MAX;
	int64_t d2 = (long long)LONG_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%i %i\n", (int)d, (int)d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%i %i\n", (int)d, (int)d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * %i
 *********/

TEST(printf, percent_uint)
{
	int d = INT_MAX;
	testing::internal::CaptureStdout();
	int res1 = printf("%u\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%u\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_uint_double)
{
	int d = INT_MAX;
	int d2 = INT_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%u %u\n", d, d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%u %u\n", d, d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_uint_overflow_int)
{
	for (int i = 1; i < 5; i++)
	{
		int64_t d = (long long)INT_MAX + i;
		int64_t d2 = (long long)INT_MIN - i;
		testing::internal::CaptureStdout();
		int res1 = printf("%u %u\n", (int)d, (int)d2);
		std::string output1 = testing::internal::GetCapturedStdout();

		testing::internal::CaptureStdout();
		int res2 = ft_printf("%u %u\n", (int)d, (int)d2);
		std::string output2 = testing::internal::GetCapturedStdout();

		EXPECT_STREQ(output1.c_str(), output2.c_str());
		EXPECT_EQ(res1, res2);
	}
}

TEST(printf, percent_uint_overflow_long)
{
	int64_t d = (long long)LONG_MAX;
	int64_t d2 = (long long)LONG_MIN;
	testing::internal::CaptureStdout();
	int res1 = printf("%u %u\n", (int)d, (int)d2);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%u %u\n", (int)d, (int)d2);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * %x
 *********/

TEST(printf, percent_hex_low_case)
{
	int d = 1;
	testing::internal::CaptureStdout();
	int res1 = printf("%x\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%x\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_hex_low_case_2)
{
	int d = 60000;
	testing::internal::CaptureStdout();
	int res1 = printf("%x\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%x\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_hex_low_case_negative)
{
	for (int i = -1; i >= -50; i -= 10)
	{
		int d = -1;
		testing::internal::CaptureStdout();
		int res1 = printf("%x\n", d);
		std::string output1 = testing::internal::GetCapturedStdout();

		testing::internal::CaptureStdout();
		int res2 = ft_printf("%x\n", d);
		std::string output2 = testing::internal::GetCapturedStdout();

		EXPECT_STREQ(output1.c_str(), output2.c_str());
		EXPECT_EQ(res1, res2);
	}
}

/* *******
 * %x
 *********/

TEST(printf, percent_hex_up_case)
{
	int d = 1;
	testing::internal::CaptureStdout();
	int res1 = printf("%X\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%X\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_hex_up_case_2)
{
	int d = 60000;
	testing::internal::CaptureStdout();
	int res1 = printf("%X\n", d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%X\n", d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_hex_up_case_negative)
{
	for (int i = -1; i >= -50; i -= 10)
	{
		int d = -1;
		testing::internal::CaptureStdout();
		int res1 = printf("%X\n", d);
		std::string output1 = testing::internal::GetCapturedStdout();

		testing::internal::CaptureStdout();
		int res2 = ft_printf("%X\n", d);
		std::string output2 = testing::internal::GetCapturedStdout();

		EXPECT_STREQ(output1.c_str(), output2.c_str());
		EXPECT_EQ(res1, res2);
	}
}

/* *******
 * %%
 *********/

TEST(printf, percent_percent)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%%\n");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%%\n");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

TEST(printf, percent_percent_double)
{
	testing::internal::CaptureStdout();
	int res1 = printf("%%%%\n");
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf("%%%%\n");
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * all
 *********/

TEST(printf, percent_all)
{
	char str[] = "abc";
	int d = -100;

	testing::internal::CaptureStdout();
	int res1 =
		printf("%s %c %p %d %i %u %x %X %%\n", str, str[0], str, d, d, d, d, d);
	std::string output1 = testing::internal::GetCapturedStdout();

	testing::internal::CaptureStdout();
	int res2 = ft_printf(
		"%s %c %p %d %i %u %x %X %%\n", str, str[0], str, d, d, d, d, d);
	std::string output2 = testing::internal::GetCapturedStdout();

	EXPECT_STREQ(output1.c_str(), output2.c_str());
	EXPECT_EQ(res1, res2);
}

/* *******
 * extras (you have to comment out your compile option in CMakeLists.txt if you
 *want to test below)
 *********/

// TEST(printf, percent_not_working)
// {
// 	char str[] = "abc";
// 	int d = -100;

// 	testing::internal::CaptureStdout();
// 	int res1 = printf("%t\n", str);
// 	std::string output1 = testing::internal::GetCapturedStdout();

// 	testing::internal::CaptureStdout();
// 	int res2 = ft_printf("%t\n", str);
// 	std::string output2 = testing::internal::GetCapturedStdout();

// 	EXPECT_STREQ(output1.c_str(), output2.c_str());
// 	EXPECT_EQ(res1, res2);
// }

// TEST(printf, too_many_args)
// {
// 	testing::internal::CaptureStdout();
// 	int res1 = printf("\n", 1, 2, 3, 4, 5, 6);
// 	std::string output1 = testing::internal::GetCapturedStdout();

// 	testing::internal::CaptureStdout();
// 	int res2 = ft_printf("\n", 1, 2, 3, 4, 5, 6);
// 	std::string output2 = testing::internal::GetCapturedStdout();

// 	EXPECT_STREQ(output1.c_str(), output2.c_str());
// 	EXPECT_EQ(res1, res2);
// }

// TEST(printf, too_few_args)
// {
// 	testing::internal::CaptureStdout();
// 	int res1 = printf("%d %d\n", 1);
// 	std::string output1 = testing::internal::GetCapturedStdout();

// 	testing::internal::CaptureStdout();
// 	int res2 = ft_printf("%d %d\n", 1);
// 	std::string output2 = testing::internal::GetCapturedStdout();

// 	EXPECT_STREQ(output1.c_str(), output2.c_str());
// 	EXPECT_EQ(res1, res2);
// }
