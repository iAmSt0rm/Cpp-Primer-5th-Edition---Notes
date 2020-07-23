//C Style arrays

#include <cstring>
#include <iostream>
#include <vector>
int gs[10];  // 10 elements init.d to 0 Why?
//*As with variables of built-in type, a default-initialized array of built-in type that is defined inside a function will have undefined values.

int main() {
    //Data type similar to vector, but, better runtime performance at the cost of flexibility.
    //dimension must be known at runtime and must be a constant expression
    /*A constant expression is an expression whose value cannot change and that can be evaluated at compile time. A literal is a constant expression. A const object that is initialized from a constant expression is also a constant expression.

    *The constexpr specifier declares that it is possible to evaluate the value of the function or variable at compile time.
    */

    unsigned sz = 3;              //not a constant exression -  wont work with std::array
    constexpr unsigned szce = 2;  //constant expression

    //defining arrays
    int arr[10];
    int *parr[sz];  //an array of 42 pointers to int
    std::string bad[sz];

    //If we omit the dimension, the compiler infers it from the number of initializers.
    //If we specify a dimension, the number of initializers must not exceed the specified size.
    //If the dimension is greater than the number of initializers, the initializers are used for the first elements and any remaining elements are value initialized.

    //explicit init.n
    int ia[3] = {0, 1, 2};              // array of 3 ints, 0,1,2
    int a2[] = {0, 1, 2};               //an arrray of dimension 3 with 0,1,2;
    int s3[5] = {0, 1, 2};              // eq to 0,1,2,0,0
    std::string a4[3] = {"hi", "bye"};  //eq to a4[]={"hi", "bye", ""}
    int a6[2]{0, 1};                    //similar to ia
    //!int a5[2] = {0,1,2}; //error: too many initializers

    for (int i = 0; i < 3; i++) {
        std::cout << a4[i];
    }

    //A string array can be translated to an array of arrays of char, thus a4[0][1] will yield i from hi
    //this works for all containers supporting subscript

    char a1[] = {'C', '+', '+'};        // list initialization, no null
    char a2[] = {'C', '+', '+', '\0'};  //list initialization, explicit null
    char a3[] = "C++";                  //null terminator added automatically, a[3] is null
    //!char a4[5] = "Array"; //error: no space for null

    //No Copy or assignment
    int a[] = {0, 1, 2};
    //!int a2[] = a; error: cannot initialialize one array with another
    //!a2=a; error: cannot assign one array to another

    //Complicated Array Declarations
    int *ptrs[10];  //an array of 10 pointers to int
    //! int &refs[10] = ??// error: no array og references
    int(*parray)[10] = &arr;  //parray points to sn array of 10 ints
    int(&arrRef)[10] = arr;   //arrRef refers to an array of 10 ints
    int *(&arry)[10] = ptrs;  //arry is a reference to an array of 10 pointers

    //Accessing array elements
    //When we use a variable to subscript an array, we normally should define that variable to have type size_t. size_t is a machine-specific unsigned type that is guaranteed to be large enough to hold the size of any object in memory. The size_t type is defined in the cstddef header, which is the C++ version of the stddef.h header from the C library.

    //Example - vectors.cpp, line 174

    unsigned int scores[11] = {};  // 11 elements, all init.d to 0
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100) {
            ++scores[grade / 10];
        }
    }

    //As in the case of string or vector, it is best to use a range for when we want to traverse the entire array.

    for (auto i : scores) {
        std::cout << i << " ";  //prints the value of that counter
    }                           //Because the dimension is part of each array type, the system knows how many elements are in scores. Using a range for means that we don’t have to manage the traversal ourselves.

    //Pointers and arrays
    //when we use an array, the compiler ordinarily converts the array to a pointer

    std::string nums[] = {"one", "two", "three"};
    std::string *p = &nums[0];  //p points to the first element in nums

    //arrays have a special property—in most places when we use an array, the compiler automatically substitutes a pointer to the first element:

    std::string *p2 = nums;  //eq to *p2 = &nums[0];

    //In most expressions, when we use an object of array type, we are really using a pointer to the first element in that array.

    int iap[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto ia2(iap);  // ia2 is an int pointer that points to the first element in iap

    //!ia2 =42;// error:ia2 is a pointer

    auto ia2(&iap[0]);  //ia2 is an int*

    //but, this doesn't happen with decltype

    decltype(iap) ia3 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};  //ia3 is an array of ten elements
    //! ia3 = p; //error: can't assign int* to an array

    //! if multiple declarations, compiler will always take the first one as the standard for other decltypes

    //pointers are iterators
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = arr;  // p points to the first element in arr
    ++p;           //p points to arr[1];

    //pointer to off-the-end location

    int *e = &arr[10];  //pointer just past the last element in arr

    //traversing array
    for (int *b = arr; b != e; ++b) {
        std::cout << *b << std::endl;  //prints all elements in arr
    }

    //Library end & begin

    int ia[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *beg = std::begin(ia);  //pointer to the first element
    int *endia = std::end(ia);  //pointer one past the last element in ia

    //find the first negative element
    while (beg != endia && *beg >= 0) {  //loop ends either when we traversed all emements or a negative one is found
        ++beg;                           //
    }

    //do not derefence or increment an off-the-end pointer or iterator

    {  //Pointer Arithemetic
        //When we add (or subtract) an integral value to (or from) a pointer, the result is a new pointer. That new pointer points to the element the given number ahead of (or behind) the original pointer:

        constexpr size_t sz = 5;
        int arr[sz] = {1, 2, 3, 4, 5};
        int *ip = arr;      //eq. to *ip =
        int *ip2 = ip + 4;  //ip2 points to arr[4], last element in arr

        int *p = arr + sz;   //p points to one past the end of arr -  do not derefence
        int *p2 = arr + 10;  //gives a garbage or undefined value

        //As with iterators, subtracting two pointers gives us the distance between those pointers. The pointers must point to elements in the same array:

        auto n = std::end(arr) - std::begin(arr);  // n is 5, the number of elements
        //* n is of type ptrdiff_t - cstddef - subtraction might yeild a negative distace, its a signed integral type

        //! cannot use realtionsl operator on pointer of two unrelated objects
    }

    {  //interaction b/w derefences & pointer arithemetic
        int ia[] = {0, 2, 4, 6, 8};
        int last = *(ia + 4);  //ok: initializes last to 8, value of ia[4]

        int i = ia[2];  //i holds 4
        int *p = ia;    //points to the first element
        i = *(p + 2);   // eq to i = ia[2]

        {
            int *p = &ia[2];
            int j = p[1];   //eq to j = ia[3]
            int k = p[-2];  //eq to k = ia[0]
        }
    }

    {
        //C Style character Strings
        //c style strings are har arrays followed by a null terminator '\0'
        /*Fucntions - require cstring
            strlen(p) -  returns the length of p, not counting null
            strcmp(p1,p2) - compares p1 & p2, 
                            0 if p1==p2
                            1 if p1>p2
                            -1 if p2>p1
            strcat(p1,p2) - appends p2 to p1. returns p1
            strcpy(p1,p2) - copies p2 into p1, returns p1
        */

        {
            //comparing strings
            std::string s1 = "A string example";
            std::string s2 = "A different string";
            if (s1 < s2)
            ;  //false, s2 is less than s1

            char ca1[] = "A string example";
            char ca2[] = "A different example";
            if (ca1 < ca2)
                ;  // undefined -  as comparing two unrelated pointers
            if (strcmp(ca1, ca2) < 0)
                ;  // same as s1 <s2

            {  //concatinating strings
                std::string largeStr = s1 + " " + s2;

                {
                    char largeStr[10];
                    //disastrous if largeStr is not enough to hold both
                    strcpy(largeStr, ca1);  //copies ca1 into largeStr
                    strcpy(largeStr, " ");  //adds a space at the end of largeStr
                    strcpy(largeStr, ca2);  // concatenates ca2 onto largeStr
                }
            }
        }
   
        //* in addition to being safer, it is also more efficient to use library strings rather than C-style strings.

        {  
            //Cstyle array from C++ strings - C++ Primer 5th Edition - 3.5.5
            std::string s("Hello World!");
            //! char *str = s; error: can't initialize a char* from a string
            const char *str = s.c_str();
            //c_str function returns a C-style character string i.e. it returns a pointer to the beginning of a null-terminated character array that holds the same data as the characters in the string. The type of the pointer is const char*, which prevents us from changing the contents of the array.

            //!Warning & Pitfall
            //subsequent use of s that might change the value of s can invalidate this array.
            //If a program needs continuing access to the contents of the array returnedby str(), the program must copy the array returned by c_str.
        }
    }

    {  
        //using an array to initialize a vector
        int int_arr[] = {0, 1, 2, 3, 4, 5};

        std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));  //marking the range of values to be taken from array
        std::vector<int> subVec(int_arr + 1, int_arr + 4);              //initizlizes subVec with 3 characters, ranging from int_arr[1] to int_arr[4]
    }

    //Pointers and arrays are surprisingly error-prone. Part of the problem is conceptual: Pointers are used for low-level manipulations and it is easy to make bookkeeping mistakes. Other problems arise because of the syntax, particularly the declaration syntax used with pointers.
    //Modern C++ programs should use vectors and iterators instead of built-in arrays and pointers, and use strings rather than C-style array-based character strings.

    {                  
        //Multidimensional Arrays
        //Are an array of arrays
        int ia[3][4];  //an array of 3, each element is an array of 4

        int arr[10][20][30] = {0};  // an array of 10; each element is 20 element array whose elements are arrays of 30 ints; all intd. to 0

        //usually, first element is the row, second is the column

        {  //initializing multidimensional arrays
            {
                int ia[3][4] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};  //index representation
            }
            {
                int ia[3][4] = {
                    {0, 1, 2, 3},   //initializers for the row indexed by 0
                    {4, 5, 6, 7},   //initializers for the row indexed by 1
                    {8, 9, 10, 11}  //initializers for the row indexed by 2
                };
            }
            //explicitly intialize only one element [0] in each row
            int ia[3][4] = {{0}, {4}, {8}};  //rest are initialized as ordinary arrays

            //explicitly initialize row 0, remaining are value init.d
            int ix[3][4] = {0, 3, 6, 9};
        }

        //subscripting a multidimensional array
        ia[2][3] = arr[0][0][0];  //assign first element of arr to last element of ia
        int(&row)[4] = ia[1];     // binds row to the second four element array in ia - row is a reference to an array of 4 ints - binding that reference to 2nd row using ia[1]

        {  //using nested loops
            constexpr std::size_t rowCnt = 3, colCnt = 4;
            int ia[rowCnt][colCnt];  //12 uninit.d elements
            for (size_t i = 0; i < rowCnt; i++) {
                for (size_t j = 0; j < colCnt; j++) {
                    //assign positional index as value
                    ia[i][j] = i * colCnt + j;
                }
            }
        }

        {  //using ranged for
            size_t cnt = 0;
            for (auto &row : ia) {       //for every row in ia
                for (auto &col : row) {  //for every column/element in a row
                    col = cnt;
                    ++cnt;
                }
            }

            //not writing elements?
            for (const auto &row : ia) {
                for (auto col : row) {
                    std::cout << col << row;
                }
            }

            //why not auto row?
            /*for(auto row: ia) {
                for (auto col : row){

                }
            }
            ourr program won't compile as first for iterates through ia, whose elements are arrays of 4. Since row is not a reference, array hands over the pointer to each array's first element, making row int*
            Thus our inner loop attempts to iterate over int*
            */

            //* To use a multidimensional array in a range for, the loop control variable for all but the innermost array must be references. line 279
        }
    }
    {
        //Pointers & Multidimensional arrays
        //*Remember - MD array is actually an arrray of array

        int ia[3][4];
        int (*p)[4] = ia; //p points to an array of 4 ints
        p = &ia[2]; //p points to the last element in ia (last array)

        /*
        Note:
        The parentheses in this declaration are essential:
        int *ip[4];    // array of pointers to int
        int (*ip)[4];  // pointer to an array of four ints
        */

        //new standard

        for (auto p =ia; p !=ia+3; ++p) {//p points to an array of 4 ints
           for(auto q = *p; q!=*p+4;++q) {//q points to the first element of an array of 4 ints, q points an int
               std::cout<<*q<<" ";
           }
           std::cout<<std::endl;
        }

        //easier method
        for(auto p = std::begin(ia); p!=std::end(ia); ++p) {
            for (auto q = std::begin(*p); q!=std::end(*p); ++q) {
                std::cout<<*q<<" ";
            }
            std::cout<<std::endl;
        }

        //using type aliases
        using int_array = int[4]; // new style type alias declaration;
        typedef int int_array[4]; // equivalent typedef declaration; 
        // print the value of each element in ia, with each inner array on its own line
        for (int_array *p = ia; p != ia + 3; ++p) {
            for (int *q = *p; q != *p + 4; ++q)
                std::cout << *q << ' ';
        
            }
    }
}
