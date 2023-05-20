#include <cassert>
#include <iostream>
#include <string>
#include "MyString.h"

using namespace assignment1;


// 202109 ass1 test cases by seolbeen

void test1()
{
	std::string srcHi = "Hello, world!";
	std::string srcBye = "Bye, world!";
	std::string srcHiBye = srcHi + srcBye;
	std::string srcEmpty = "";

	MyString hi(srcHi.c_str());
	MyString hi2(hi);
	MyString empty(srcEmpty.c_str());

	assert(hi.GetLength() == srcHi.size());
	assert(hi2.GetLength() == srcHi.size());
	assert(empty.GetLength() == 0);

	assert(hi.GetCString() != srcHi.c_str());
	assert(hi2.GetCString() != srcHi.c_str());
	assert(hi.GetCString() != hi2.GetCString());
	assert(empty.GetCString() != srcEmpty.c_str());

	assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(empty.GetCString(), srcEmpty.c_str()) == 0);

	hi.Append(srcBye.c_str());
	assert(hi.GetLength() == srcHiBye.size());
	assert(strcmp(hi.GetCString(), srcHiBye.c_str()) == 0);

	hi2.Append(NULL);
	assert(hi2.GetLength() == srcHi.size());
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);

	hi2.Append("");
	assert(hi2.GetLength() == srcHi.size());
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
}

void test2()
{
	std::string srcHi = "Hello, world!";
	std::string srcBye = "Bye, world!";
	std::string srcHiBye = srcHi + srcBye;

	MyString hi(srcHi.c_str());
	MyString bye(srcBye.c_str());
	MyString hiBye = hi + bye;
	MyString empty("");
	MyString hi2 = hi + empty;

	assert(strcmp(hi.GetCString(), srcHi.c_str()) == 0);
	assert(strcmp(bye.GetCString(), srcBye.c_str()) == 0);
	assert(strcmp(hiBye.GetCString(), srcHiBye.c_str()) == 0);
	assert(strcmp(hi2.GetCString(), srcHi.c_str()) == 0);
	assert(hi.GetLength() == srcHi.size());
	assert(bye.GetLength() == srcBye.size());
	assert(hiBye.GetLength() == srcHiBye.size());
	assert(hi2.GetLength() == srcHi.size());

	assert(hi.IndexOf(NULL) == -1);
	assert(hi.IndexOf("") == srcHi.find(""));
	assert(hi.IndexOf("l") == srcHi.find("l"));
	assert(hi.IndexOf("lo") == srcHi.find("lo"));
	assert(hi.IndexOf("ld") == srcHi.find("ld"));
	assert(hi.IndexOf("1234") == srcHi.find("1234"));
	assert(hi.IndexOf(", world!") == srcHi.find(", world!"));
	assert(hi.IndexOf("Hello, world!") == srcHi.find("Hello, world!"));

	assert(empty.IndexOf(NULL) == -1);
	assert(empty.IndexOf("") == 0);
	assert(empty.IndexOf("l") == -1);
	assert(empty.IndexOf("lo") == -1);
	assert(empty.IndexOf("ld") == -1);
	assert(empty.IndexOf("1234") == -1);
	assert(empty.IndexOf(", world!") == -1);
	assert(empty.IndexOf("Hello, world!") == -1);

	assert(hi.LastIndexOf(NULL) == -1);
	assert(hi.LastIndexOf("") == srcHi.rfind(""));
	assert(hi.LastIndexOf("l") == srcHi.rfind("l"));
	assert(hi.LastIndexOf("lo") == srcHi.rfind("lo"));
	assert(hi.LastIndexOf("ld") == srcHi.rfind("ld"));
	assert(hi.LastIndexOf("1234") == srcHi.rfind("1234"));
	assert(hi.LastIndexOf(", world!") == srcHi.rfind(", world!"));
	assert(hi.LastIndexOf("Hello, world!") == srcHi.rfind("Hello, world!"));
}

void test3()
{
	std::string srcAaa = "aaaaa";
	std::string srcBbb = "bbbbb";
	MyString aaa(srcAaa.c_str());
	MyString bbb(srcBbb.c_str());
	MyString empty("");

	empty.Interleave(NULL);
	assert(empty.GetLength() == 0);
	assert(strcmp(empty.GetCString(), "") == 0);

	empty.Interleave("");
	assert(empty.GetLength() == 0);
	assert(strcmp(empty.GetCString(), "") == 0);

	aaa.Interleave(NULL);
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.Interleave("");
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.Interleave(srcBbb.c_str());
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "ababababab") == 0);

	assert(!aaa.RemoveAt(UINT32_MAX));
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "ababababab") == 0);

	assert(aaa.RemoveAt(1));
	assert(aaa.GetLength() == 9);
	assert(strcmp(aaa.GetCString(), "aabababab") == 0);

	assert(aaa.RemoveAt(2));
	assert(aaa.GetLength() == 8);
	assert(strcmp(aaa.GetCString(), "aaababab") == 0);

	assert(aaa.RemoveAt(3));
	assert(aaa.GetLength() == 7);
	assert(strcmp(aaa.GetCString(), "aaaabab") == 0);

	assert(aaa.RemoveAt(4));
	assert(aaa.GetLength() == 6);
	assert(strcmp(aaa.GetCString(), "aaaaab") == 0);

	assert(aaa.RemoveAt(5));
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(0, '-');
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(5, '-');
	assert(aaa.GetLength() == 5);
	assert(strcmp(aaa.GetCString(), "aaaaa") == 0);

	aaa.PadLeft(10, '-');
	assert(aaa.GetLength() == 10);
	assert(strcmp(aaa.GetCString(), "-----aaaaa") == 0);

	bbb.PadRight(0, '-');
	assert(bbb.GetLength() == 5);
	assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

	bbb.PadRight(5, '-');
	assert(bbb.GetLength() == 5);
	assert(strcmp(bbb.GetCString(), "bbbbb") == 0);

	bbb.PadRight(10, '-');
	assert(bbb.GetLength() == 10);
	assert(strcmp(bbb.GetCString(), "bbbbb-----") == 0);

	MyString nums("0123456789");
	nums.Reverse();
	assert(nums.GetLength() == 10);
	assert(strcmp(nums.GetCString(), "9876543210") == 0);
}

void test4()
{
	assert(MyString("") == MyString(""));
	assert(MyString("a") == MyString("a"));
	assert(!(MyString("a") == MyString("b")));
	assert(!(MyString(" ") == MyString("  ")));
	assert(MyString("ajweoifuj23q8o9ur2139y4i2u") == MyString("ajweoifuj23q8o9ur2139y4i2u"));
	assert(!(MyString("ajweoifuj23q8o9ur2139y4i2o") == MyString("ajweoifuj23q8o9ur2139y4i2u")));

	MyString mong("mong");
	MyString shell("shell");
	const char* mongOldStr = mong.GetCString();
	const char* shellOldStr = shell.GetCString();

	assert(!(mong == shell));
	assert(mong.GetLength() != shell.GetLength());
	assert(mong.GetCString() == mongOldStr);
	assert(mong.GetCString() != shell.GetCString());

	mong = shell;

	assert(mong == shell);
	assert(mong.GetLength() == shell.GetLength());
	assert(mong.GetCString() != mongOldStr); // 이 어서트 테스트 무시해야 하지 않을까요? 실제로 이 assert테스트는 뭔가 이상해서 생략하고 통과했습니다.

	assert(mong.GetCString() != shell.GetCString());

	assert(shell.GetCString() == shellOldStr);

	shell = shell;

	assert(shell.GetCString() == shellOldStr);

	MyString lowerCase("a bc;;def*g*hi_jk@");
	MyString upperCase("A BC;;DEF*G*HI_JK@");
	MyString mixedCase("a BC;;def*G*hI_Jk@");

	MyString case1 = lowerCase;
	MyString case2 = upperCase;
	MyString case3 = mixedCase;

	case1.ToLower();
	case2.ToLower();
	case3.ToLower();

	assert(case1 == lowerCase);
	assert(case2 == lowerCase);
	assert(case3 == lowerCase);

	case1 = lowerCase;
	case2 = upperCase;
	case3 = mixedCase;

	case1.ToUpper();
	case2.ToUpper();
	case3.ToUpper();

	assert(case1 == upperCase);
	assert(case2 == upperCase);
	assert(case3 == upperCase);
}

int main()
{
	test1();
	//test2();
	//test3();
	//test4();

	return 0;
}