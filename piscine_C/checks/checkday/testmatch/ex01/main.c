#include <stdio.h>

int    nmatch(char *s1, char *s2)
{
    if (*s1 == '\0' && *s2 == '\0')
        return (1);
    if (*s1 == '\0' && *s2 == '*')
        return (nmatch(s1, s2 + 1));
    if (*s1 != '\0' && *s2 == '*')
        return (nmatch(s1 + 1, s2) + (nmatch(s1, s2 + 1)));
    if (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
        return (nmatch(s1 + 1, s2 + 1));
    return (0);
}

int        main()
{
    printf("%d\n",nmatch("asdf", "asdf") == 1);
    printf("%d\n",nmatch("", "") == 1);
    printf("%d\n",nmatch("a", "a") == 1);
    printf("%d\n",nmatch("aa", "aa") == 1);
    printf("%d\n",nmatch("aaa", "aaa") == 1);
    
    printf("%d\n",nmatch("", "asdf") == 0);
    printf("%d\n",nmatch("asdf", "") == 0);
    printf("%d\n",nmatch("asdf", "a") == 0);
    printf("%d\n",nmatch("a", "asdf") == 0);
    printf("%d\n",nmatch("asdf", "asde") == 0);
    
    printf("%d\n",nmatch("asde", "asdf") == 0);
    printf("%d\n",nmatch("asdf", "asdff") == 0);
    printf("%d\n",nmatch("asdff", "asdf") == 0);
    printf("%d\n",nmatch("aasdf", "asdf") == 0);
    printf("%d\n",nmatch("asdf", "aasdf") == 0);
    
    printf("%d\n",nmatch("", "*") == 1);
    printf("%d\n",nmatch("a", "*") == 1);
    printf("%d\n",nmatch("aa", "*") == 1);
    printf("%d\n",nmatch("asdf", "*") == 1);
    printf("%d\n",nmatch("asdfasdf", "*") == 1);
    
    printf("%d\n",nmatch("asdf", "a*") == 1);
    printf("%d\n",nmatch("asdfasdf", "a*") == 1);
    printf("%d\n",nmatch("a", "a*") == 1);
    printf("%d\n",nmatch("aa", "a*") == 1);
    printf("%d\n",nmatch("aasdf", "a*") == 1);
    
    printf("%d\n",nmatch("", "a*") == 0);
    printf("%d\n",nmatch("f", "a*") == 0);
    printf("%d\n",nmatch("fdsa", "a*") == 0);
    printf("%d\n",nmatch("faaaa", "a*") == 0);
    printf("%d\n",nmatch("faaasdf", "a*") == 0);
    
    printf("%d\n",nmatch("fdsa", "*a") == 1);
    printf("%d\n",nmatch("a", "*a") == 1);
    printf("%d\n",nmatch("aa", "*a") == 1);
    printf("%d\n",nmatch("fdsaaaaaaafdsa", "*a") == 1);
    printf("%d\n",nmatch("dfsaaaaaaaaaaaa", "*a") == 1);
    
    printf("%d\n",nmatch("", "*a") == 0);
    printf("%d\n",nmatch("f", "*a") == 0);
    printf("%d\n",nmatch("asdf", "*a") == 0);
    printf("%d\n",nmatch("aaaaaf", "*a") == 0);
    printf("%d\n",nmatch("fdsaaaaf", "*a") == 0);
    
    printf("%d\n",nmatch("abc", "abc*") == 1);
    printf("%d\n",nmatch("abcdef", "abc*") == 1);
    printf("%d\n",nmatch("abccccccc", "abc*") == 1);
    printf("%d\n",nmatch("abcabc", "abc*") == 1);
    printf("%d\n",nmatch("abcdabcdabc", "abc*") == 1);
    
    printf("%d\n",nmatch("", "abc*") == 0);
    printf("%d\n",nmatch("f", "abc*") == 0);
    printf("%d\n",nmatch("abbc", "abc*") == 0);
    printf("%d\n",nmatch("ab", "abc*") == 0);
    printf("%d\n",nmatch("abb", "abc*") == 0);
    // 50
    
    printf("%d\n",nmatch("abc", "*abc") == 1);
    printf("%d\n",nmatch("defabc", "*abc") == 1);
    printf("%d\n",nmatch("aaaaaaabc", "*abc") == 1);
    printf("%d\n",nmatch("abcabc", "*abc") == 1);
    printf("%d\n",nmatch("abcdabcdabc", "*abc") == 1);
    
    printf("%d\n",nmatch("", "*abc") == 0);
    printf("%d\n",nmatch("f", "*abc") == 0);
    printf("%d\n",nmatch("abbc", "*abc") == 0);
    printf("%d\n",nmatch("ab", "*abc") == 0);
    printf("%d\n",nmatch("abb", "*abc") == 0);
    
    printf("%d\n",nmatch("a", "*a*") == 1);
    printf("%d\n",nmatch("aaa", "*a*") == 3);
    printf("%d\n",nmatch("aaabc", "*a*") == 3);
    printf("%d\n",nmatch("bcabc", "*a*") == 1);
    printf("%d\n",nmatch("sdfa", "*a*") == 1);
    
    printf("%d\n",nmatch("", "*a*") == 0);
    printf("%d\n",nmatch("f", "*a*") == 0);
    printf("%d\n",nmatch("bcd", "*a*") == 0);
    printf("%d\n",nmatch("bb", "*a*") == 0);
    printf("%d\n",nmatch("ASDF", "*a*") == 0);
    
    printf("%d\n",nmatch("ab", "*ab*") == 1);
    printf("%d\n",nmatch("abcd", "*ab*") == 1);
    printf("%d\n",nmatch("efabcd", "*ab*") == 1);
    printf("%d\n",nmatch("ababab", "*ab*") == 3);
    printf("%d\n",nmatch("bab", "*ab*") == 1);
    
    printf("%d\n",nmatch("asdf", "*ab*") == 0);
    printf("%d\n",nmatch("ba", "*ab*") == 0);
    printf("%d\n",nmatch("", "*ab*") == 0);
    printf("%d\n",nmatch("f", "*ab*") == 0);
    printf("%d\n",nmatch("bbbbbbaaaaa", "*ab*") == 0);
    
    printf("%d\n",nmatch("", "**") == 1);
    printf("%d\n",nmatch("a", "**") == 2);
    printf("%d\n",nmatch("ab", "**") == 3);
    printf("%d\n",nmatch("abc", "**") == 4);
    printf("%d\n",nmatch("abcd", "**") == 5);
    
    printf("%d\n",nmatch("a", "a**") == 1);
    printf("%d\n",nmatch("ab", "a**") == 2);
    printf("%d\n",nmatch("abc", "a**") == 3);
    printf("%d\n",nmatch("aaaa", "a**") == 4);
    printf("%d\n",nmatch("asdfa", "a**") == 5);
    
    printf("%d\n",nmatch("", "a**") == 0);
    printf("%d\n",nmatch("f", "a**") == 0);
    printf("%d\n",nmatch("fa", "a**") == 0);
    printf("%d\n",nmatch("faaaaaaa", "a**") == 0);
    printf("%d\n",nmatch("fafdsafdsa", "a**") == 0);
    
    printf("%d\n",nmatch("asdf", "*a**") == 4);
    printf("%d\n",nmatch("sdfa", "*a**") == 1);
    printf("%d\n",nmatch("faffff", "*a**") == 5);
    printf("%d\n",nmatch("fdsaasdf", "*a**") == 9);
    printf("%d\n",nmatch("aaaaaaa", "*a**") == 28);
    // 100
    
    printf("%d\n",nmatch("", "*a**") == 0);
    printf("%d\n",nmatch("qwerqwer", "*a**") == 0);
    printf("%d\n",nmatch("bbbbbb", "*a**") == 0);
    printf("%d\n",nmatch("c", "*a**") == 0);
    printf("%d\n",nmatch("AAAAAAAAAA", "*a**") == 0);
    
    printf("%d\n",nmatch("main.c", "*.c") == 1);
    printf("%d\n",nmatch("main.c.c", "*.c") == 1);
    printf("%d\n",nmatch("main.h", "*.c") == 0);
    printf("%d\n",nmatch("main.cc", "*.c") == 0);
    printf("%d\n",nmatch("main.c", "*.*") == 1);
    
    printf("%d\n",nmatch("test.main.c", "test.*.c") == 1);
    printf("%d\n",nmatch("test..c", "test.*.c") == 1);
    printf("%d\n",nmatch("test.main.h", "test.*.c") == 0);
    printf("%d\n",nmatch("main.c", "test.*.c") == 0);
    printf("%d\n",nmatch("test.c", "test.*.c") == 0);
    
    printf("%d\n",nmatch("abcde", "a*c*e") == 1);
    printf("%d\n",nmatch("abcde", "*b*d*") == 1);
    printf("%d\n",nmatch("abcde", "a*e*c") == 0);
    printf("%d\n",nmatch("abcde", "*d*c*") == 0);
    printf("%d\n",nmatch("abcde", "a*d*d") == 0);
    
    printf("%d\n",nmatch("abcbd", "*b*") == 2);
    printf("%d\n",nmatch("abc", "a**") == 3);
    printf("%d\n",nmatch("test.asdf.c.bak", "*.*.*") == 3);
    printf("%d\n",nmatch("test.bak", "*.*.*") == 0);
    printf("%d\n",nmatch("", "************************") == 1);
    
    printf("%d\n",nmatch("*a", "*") == 1);
    printf("%d\n",nmatch("**", "*") == 1);
    printf("%d\n",nmatch("*ab", "*b") == 1);
    printf("%d\n",nmatch("a*a", "a*") == 1);
    printf("%d\n",nmatch("**a", "*a") == 1);
}
