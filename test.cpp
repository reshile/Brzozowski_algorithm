#include "regex.h"

void RUN_ALL_TESTS() {
  std::string regex;
  std::string word;
  int answer = 0;

  // a*b*. <=> a*b*, word: aaabb, answer = 5
  {
    regex = "a*b*.";
    word = "aaabb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*b*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*b*. <=> a*b*, word: aaabbbc, answer = 6
  {
    regex = "a*b*.";
    word = "aaabbbc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*b*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab+c*. <=> (a + b)c*, word: bccc, answer = 4
  {
    regex = "ab+c*.";
    word = "bccc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(a + b)c*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab+c*. <=> (a + b)c*, word: abccc, answer = 1
  {
    regex = "ab+c*.";
    word = "abccc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(a + b)c*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*c.b*. <=> a*cb*, word: aaaacbbbbaaa, answer = 9
  {
    regex = "a*c.b*.";
    word = "aaaacbbbbaaa";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*cb*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.ca.+* <=> (ab + ca)*, word: ababcacaa, answer = 8
  {
    regex = "ab.ca.+*";
    word = "ababcacaa";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + ca)*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*c.b*. <=> a*cb*, word: aaaabbbb, answer = 0
  {
    regex = "a*c.b*.";
    word = "aaaabbbb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*cb*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.ca.+* <=> (ab + ca)*, word: ababac, answer = 4
  {
    regex = "ab.ca.+*";
    word = "ababac";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + ca)*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*bc..c*. <=> a*bcc*, word: aabccc, answer = 6
  {
    regex = "a*bc..c*.";
    word = "aabccc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*bcc*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*bc..c*. <=> a*bcc*, word: aaaabbbc, answer = 0
  {
    regex = "a*bc..c*.";
    word = "aaaabbbbc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*bcc*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // a*bc..c*. <=> a*bcc*, word: aaaabcaaaa, answer = 6
  {
    regex = "a*bc..c*.";
    word = "aaaabcaaaa";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "a*bcc*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ac+*ba+*. <=> (a + c)*(ba)*, word: acacbac, answer = 6
  {
    regex = "ac+*ba.*.";
    word = "acacbac";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(a + c)*(ba)*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ac+*ba+*. <=> (a + c)*(ba)*, word: acacccbaba, answer = 10
  {
    regex = "ac+*ba.*.";
    word = "acacccbaba";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(a + c)*(b + a)*" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // bc.a*.b.c*.b. <=> bca*bc*b, word: bcbba, answer = 4
  {
    regex = "bc.a*.b.c*.b.";
    word = "bcbba";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "bca*bc*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // bc.a*.b.c*.b. <=> bca*bc*b, word: bcaabccb, answer = 6
  {
    regex = "bc.a*.b.c*.b.";
    word = "bcaabb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "bca*bc*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.c.*a. <=> (abc)*a, word: abacaba, answer = 1
  {
    regex = "ab.c.*a.";
    word = "abacaba";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(abc)*a" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.c.*a. <=> (abc)*a, word: abcabcabca, answer = 10
  {
    regex = "ab.c.*a.";
    word = "abcabcabca";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(abc)*a" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.c.*a. <=> (abc)*a, word: abcabcc, answer = 0
  {
    regex = "ab.c.*a.";
    word = "abacabc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(abc)*a" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.bb.*.ba.. <=> ab(bb)*ba, word: abbacccc, answer = 4
  {
    regex = "ab.bb.*b.a..";
    word = "abbacccc";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "ab(bb)*ba" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.bb.*.ba.. <=> ab(bb)*ba, word: abbbbbba, answer = 8
  {
    regex = "ab.bb.*b.a..";
    word = "abbbbbba";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "ab(bb)*ba" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.bb.*.ba.. <=> ab(bb)*ba, word: abbbbbaaaa, answer = 0
  {
    regex = "ab.bb.*b.a..";
    word = "abbbbbaaaa";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "ab(bb)*ba" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.a+*c.cc.*.aa.*.b. <=> (ab + a)*c(cc)*(aa)*b, word: ababab, answer = 6
  {
    regex = "ab.a+*c.cc.*.aa.*.b.";
    word = "ababcb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + a)*c(cc)*(aa)*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.a+*c.cc.*.aa.*.b. <=> (ab + a)*c(cc)*(aa)*b, word: abaacccccbaabb, answer = 10
  {
    regex = "ab.a+*c.cc.*.aa.*.b.";
    word = "abaacccccbaabb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + a)*c(cc)*(aa)*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.a+*c.cc.*.aa.*.b. <=> (ab + a)*c(cc)*(aa)*b, word: abaacccccaaabaabb, answer = 0
  {
    regex = "ab.a+*c.cc.*.aa.*.b.";
    word = "abaacccccaaabaabb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + a)*c(cc)*(aa)*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.a+*c.cc.*.aa.*.b. <=> (ab + a)*c(cc)*(aa)*b, word: abaacccccaaaabaabb, answer = 14
  {
    regex = "ab.a+*c.cc.*.aa.*.b.";
    word = "abaacccccaaaabaabb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + a)*c(cc)*(aa)*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // ab.a+*c.cc.*.aa.*.b. <=> (ab + a)*c(cc)*(aa)*b, word: abaacccccaaaaccb, answer = 0
  {
    regex = "ab.a+*c.cc.*.aa.*.b.";
    word = "abaacccccaaaaccb";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(ab + a)*c(cc)*(aa)*b" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // Something funny)
  // fo.r.m.al.s.ul.a.+. <=> (form)(als + ula), word: formula, answer = 7
  {
    regex = "fo.r.m.al.s.ul.a.+.";
    word = "formula";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(form)(als + ula)" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // fo.r.m.al.s.ul.a.+. <=> (form)(als + ula), word: formula1, answer = 7
  {
    regex = "fo.r.m.al.s.ul.a.+.";
    word = "formula1";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(form)(als + ula)" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }


  // fo.r.m.al.s.ul.a.+. <=> (form)(als + ula), word: formals, answer = 7
  {
    regex = "fo.r.m.al.s.ul.a.+.";
    word = "formals";
    answer = Evaluate(regex, word);
    std::cout << "Regular expression: " << regex << " <=> " << "(form)(als + ula)" << '\n'
              << "Word: " << word << '\n'
              << "Answer: " << answer << '\n' << '\n';
  }
}

int main() {
  RUN_ALL_TESTS();
}
