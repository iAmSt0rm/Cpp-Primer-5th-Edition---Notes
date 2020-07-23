#include <iostream>
#include <string>

int main() {
    std::string s1;            // empty string
    std::string s2 = s1;       //s2 is a copy of s1
    std::string s2(s1);        //same as above
    std::string s3 = "Hello";  //s3 is a copy of string literal - Copy Initialization
    std::string s3("Hello");   //same as above - Direct Initialization
    std::string s4(10, 'c');   //std holds 10 copies of c
    std::string s7{"Hello"};   //list initialization - logic given in vector.cpp, line 114
    
    std::string s8 = std::string(10, 'c');
    /*
    Similar to:
    std::string temp(10, 'c');
    std::string s8 = temp;

    use the method of s4 as s8 initialization has no advantage over s4 and is less readable
    */

    std::cin >> s1;        //reads whitespace separated string in s1
    std::cin >> s1 >> s2;  //reads first input into s1 and second into s2
    while (std::cin >> s1)
        ;  //reads till eof

    
    //To get a line
    getline(std::cin, s1);

    s1.empty();  //evaluates true if s1 is empty

    while (getline(std::cin, s1)) {
        if (!s1.empty())
            std::cout << s1;  //read input one line at a time, print them and discards blank lines

        if (s1.size() > 80)
            std::cout << s1;  //prints line with characters more than 80
    }

    //*size doesn't return int but string::size_type but it is logical to expect it to return int

    auto len = s1.size();  //len has type string::size_type

    /*Comparing strings
    Rule 1: if same chars, shorter string is less than longer
    Rule 2: if not, then the first different char is evaluated against dictionary. greater the alphabet index in list, greater the string
    */

    std::string str("Hello");
    std::string phrase("Hello World");
    std::string slang("Hiya");

    /* According to:
    Rule 1: str<phrase
    Rule 2: slang>phrase>str
    */

    //Assignment
    str = s1;  //replaces the contents of str with s1. str is empty now

    //adding strings using +
    s1 = {"Hello"};
    s2 = ("World");
    s3 = "!";
    s4 = s1 + " " + s2 + s3;  //+ operator must have one operand on either side
    //!cannot be string literals on both sides of +

    //Adding 2 literals
    std::string s5 = (s1 + ", ") + "World";
    /*Translates to:
    string temp = s1 + ",";
    string s5 = temp +"world";
    */
    
    /*
    *Using Range Based for loop to process every character

    for(declaration : expression) { //for every char/element in expression
        statement;
    }
    */

    s1 = "Hello World!";
    for (auto c : s1) {
        std::cout << c << std::endl;
    }

    //counting punctuations
    decltype(s1.size()) punct_count = 0;
    for (auto c : s1) {
        if (ispunct(c)) {
            ++punct_count;
        }

        std::cout << punct_count << std::endl;
    }

    //* auto c: s1 is copying every element from s1 to c. It doesn't allow modifying the s1 contents

    for (auto &c : s1) {
        c = toupper(c);  //since c is a reference, so assignment to c modifies s1 elements
    }

    //to access specific chars, use subscript & iterator
    //last char s1[s1.size()  - 1]
    /*
    The values we use to subscript a string must be >= 0 and < size().
    The result of using an index outside this range is undefined.
    By implication, subscripting an empty string is undefined.
    */

    if (!s1.empty())                      // make sure there's a character to print
        std::cout << s1[0] << std::endl;  // print the first character in s

    if (!s1.empty())             // make sure there's a character in s[0]
        s1[0] = toupper(s1[0]);  // assign a new value to the first character in s

    // process characters in s until we run out of characters or we hit a whitespace

    std::string s("some string");
    for (decltype(s.size()) index = 0; index != s.size() && !isspace(s[index]); index++) {  // processes characters in s until it runs out of characters or hits a whitespace
        s[index] = toupper(s[index]);
    }  //O/P - SOME string

}