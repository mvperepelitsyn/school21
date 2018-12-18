#include <stdio.h>

int    match(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s1 == '\0' && *s2 == '*')
        return (match(s1, s2 + 1));
    if (*s1 != '\0' && *s2 == '*')
        return (match(s1 + 1, s2) || (match(s1, s2 + 1)));
    if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
        return (match(s1 + 1, s2 + 1));
    return (0);
}

int        main()
{
    printf("%d\n",match("asd*f 0v", "asd*0v"));
    printf("%d\n",match("asdf", "asdf") == 1);
    printf("%d\n",match("", "") == 1);
    printf("%d\n",match("a", "a") == 1);
    printf("%d\n",match("aa", "aa") == 1);
    printf("%d\n",match("aaa", "aaa") == 1);
    
    printf("%d\n",match("", "asdf") == 0);
    printf("%d\n",match("asdf", "") == 0);
    printf("%d\n",match("asdf", "a") == 0);
    printf("%d\n",match("a", "asdf") == 0);
    printf("%d\n",match("asdf", "asde") == 0);
    
    printf("%d\n",match("asde", "asdf") == 0);
    printf("%d\n",match("asdf", "asdff") == 0);
    printf("%d\n",match("asdff", "asdf") == 0);
    printf("%d\n",match("aasdf", "asdf") == 0);
    printf("%d\n",match("asdf", "aasdf") == 0);
    
    printf("%d\n",match("", "*") == 1);
    printf("%d\n",match("a", "*") == 1);
    printf("%d\n",match("aa", "*") == 1);
    printf("%d\n",match("asdf", "*") == 1);
    printf("%d\n",match("asdfasdf", "*") == 1);
    
    printf("%d\n",match("asdf", "a*") == 1);
    printf("%d\n",match("asdfasdf", "a*") == 1);
    printf("%d\n",match("a", "a*") == 1);
    printf("%d\n",match("aa", "a*") == 1);
    printf("%d\n",match("aasdf", "a*") == 1);
    
    printf("%d\n",match("", "a*") == 0);
    printf("%d\n",match("f", "a*") == 0);
    printf("%d\n",match("fdsa", "a*") == 0);
    printf("%d\n",match("faaaa", "a*") == 0);
    printf("%d\n",match("faaasdf", "a*") == 0);
    
    printf("%d\n",match("fdsa", "*a") == 1);
    printf("%d\n",match("a", "*a") == 1);
    printf("%d\n",match("aa", "*a") == 1);
    printf("%d\n",match("fdsaaaaaaafdsa", "*a") == 1);
    printf("%d\n",match("dfsaaaaaaaaaaaa", "*a") == 1);
    
    printf("%d\n",match("", "*a") == 0);
    printf("%d\n",match("f", "*a") == 0);
    printf("%d\n",match("asdf", "*a") == 0);
    printf("%d\n",match("aaaaaf", "*a") == 0);
    printf("%d\n",match("fdsaaaaf", "*a") == 0);
    
    printf("%d\n",match("abc", "abc*") == 1);
    printf("%d\n",match("abcdef", "abc*") == 1);
    printf("%d\n",match("abccccccc", "abc*") == 1);
    printf("%d\n",match("abcabc", "abc*") == 1);
    printf("%d\n",match("abcdabcdabc", "abc*") == 1);
    
    printf("%d\n",match("", "abc*") == 0);
    printf("%d\n",match("f", "abc*") == 0);
    printf("%d\n",match("abbc", "abc*") == 0);
    printf("%d\n",match("ab", "abc*") == 0);
    printf("%d\n",match("abb", "abc*") == 0);
    // 50
    
    printf("%d\n",match("abc", "*abc") == 1);
    printf("%d\n",match("defabc", "*abc") == 1);
    printf("%d\n",match("aaaaaaabc", "*abc") == 1);
    printf("%d\n",match("abcabc", "*abc") == 1);
    printf("%d\n",match("abcdabcdabc", "*abc") == 1);
    
    printf("%d\n",match("", "*abc") == 0);
    printf("%d\n",match("f", "*abc") == 0);
    printf("%d\n",match("abbc", "*abc") == 0);
    printf("%d\n",match("ab", "*abc") == 0);
    printf("%d\n",match("abb", "*abc") == 0);
    
    printf("%d\n",match("a", "*a*") == 1);
    printf("%d\n",match("aaa", "*a*") == 1);
    printf("%d\n",match("aaaaaaabc", "*a*") == 1);
    printf("%d\n",match("bcabc", "*a*") == 1);
    printf("%d\n",match("sdfa", "*a*") == 1);
    
    printf("%d\n",match("", "*a*") == 0);
    printf("%d\n",match("f", "*a*") == 0);
    printf("%d\n",match("bcd", "*a*") == 0);
    printf("%d\n",match("bb", "*a*") == 0);
    printf("%d\n",match("ASDF", "*a*") == 0);
    
    printf("%d\n",match("ab", "*ab*") == 1);
    printf("%d\n",match("abcd", "*ab*") == 1);
    printf("%d\n",match("efabcd", "*ab*") == 1);
    printf("%d\n",match("ababab", "*ab*") == 1);
    printf("%d\n",match("bab", "*ab*") == 1);
    
    printf("%d\n",match("asdf", "*ab*") == 0);
    printf("%d\n",match("ba", "*ab*") == 0);
    printf("%d\n",match("", "*ab*") == 0);
    printf("%d\n",match("f", "*ab*") == 0);
    printf("%d\n",match("bbbbbbaaaaa", "*ab*") == 0);
    
    printf("%d\n",match("", "**") == 1);
    printf("%d\n",match("a", "**") == 1);
    printf("%d\n",match("ab", "**") == 1);
    printf("%d\n",match("abc", "**") == 1);
    printf("%d\n",match("abcd", "**") == 1);
    
    printf("%d\n",match("a", "a**") == 1);
    printf("%d\n",match("ab", "a**") == 1);
    printf("%d\n",match("abc", "a**") == 1);
    printf("%d\n",match("aaaaaa", "a**") == 1);
    printf("%d\n",match("asdfaaaaa", "a**") == 1);
    
    printf("%d\n",match("", "a**") == 0);
    printf("%d\n",match("f", "a**") == 0);
    printf("%d\n",match("fa", "a**") == 0);
    printf("%d\n",match("faaaaaaa", "a**") == 0);
    printf("%d\n",match("fafdsafdsa", "a**") == 0);
    
    printf("%d\n",match("asdf", "*a**") == 1);
    printf("%d\n",match("sdfa", "*a**") == 1);
    printf("%d\n",match("faffff", "*a**") == 1);
    printf("%d\n",match("fdsaasdf", "*a**") == 1);
    printf("%d\n",match("aaaaaaa", "*a**") == 1);
    // 100
    
    printf("%d\n",match("", "*a**") == 0);
    printf("%d\n",match("qwerqwer", "*a**") == 0);
    printf("%d\n",match("bbbbbb", "*a**") == 0);
    printf("%d\n",match("c", "*a**") == 0);
    printf("%d\n",match("AAAAAAAAAA", "*a**") == 0);
    
    printf("%d\n",match("main.c", "*.c") == 1);
    printf("%d\n",match("main.c.c", "*.c") == 1);
    printf("%d\n",match("main.h", "*.c") == 0);
    printf("%d\n",match("main.cc", "*.c") == 0);
    printf("%d\n",match("main.c", "*.*") == 1);
    
    printf("%d\n",match("test.main.c", "test.*.c") == 1);
    printf("%d\n",match("test..c", "test.*.c") == 1);
    printf("%d\n",match("test.main.h", "test.*.c") == 0);
    printf("%d\n",match("main.c", "test.*.c") == 0);
    printf("%d\n",match("test.c", "test.*.c") == 0);
    
    printf("%d\n",match("abcde", "a*c*e") == 1);
    printf("%d\n",match("abcde", "*b*d*") == 1);
    printf("%d\n",match("abcde", "a*e*c") == 0);
    printf("%d\n",match("abcde", "*d*c*") == 0);
    printf("%d\n",match("abcde", "a*d*d") == 0);
    
    printf("%d\n",match("*a", "*") == 1);
    printf("%d\n",match("**", "*") == 1);
    printf("%d\n",match("*ab", "*b") == 1);
    printf("%d\n",match("a*a", "a*") == 1);
    printf("%d\n",match("**a", "*a") == 1);

}
