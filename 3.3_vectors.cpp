#include <iostream>
#include <vector>

int main() {
    //vector - collection of objects of same type or container for other objects

    //It is a class template not a type thus type generated vectors must have type. for ex. int

    //create classes from templates - instantiation

    std::vector<int> ivec;  //ivec holds object of type int

    //*std:vector<Sales_item> Sales_ivec; // vector holds objects of type 'Sales_item'

    std::vector<std::vector<std::string>> files;  //a vector with vector elements

    //references are not objects, no vector of references

    //some (old) compilers - vector<vector<int> >
    //                                   ^ notice the space

    /* initialization reference

    vector<T> v1 - vector that holds objects of type T.
                   Default Initialization
                   v1 is empty
    
    vector<T> v2(v1) - v2 has a copy of each element of v1

    vector<T> v2 = v1 - Equivalent to v2(v1)

    vector<T> v3(n, val) - n elements with value val

    vector<T> v4(n) -  n copies of value initialized object

    vector<t> v5{a,b,c..} - has as many elements as there are initializers
                            Elements are initialized by corresponding initializers

    vector<T> v5 = {a,b,c..} - equivalent to v5{a,b,c...}

    */

    std::vector<std::string> svec;  //default initialization. has no elements
    //can be initialized efficiently thus generally defined empty and elements added at runtime

    std::vector<int> ivec;  //initially empty -  yes, can be declared again

    //given some values, then
    std::vector<int> ivec2(ivec);   // copy elements of ivec into ivec2
    std::vector<int> ivec3 = ivec;  //copy elements of ivec into ivec3

    //!std::vector<std::string> svec(ivec2); // error: svec holds strings, not ints

    //List Initalization
    std::vector<std::string> articles = {"a", "an", "the"};

    //The vector has 3 elements. first holds the string "a"
    //second holds the string "an"
    //third holds the string "the"

    //element values can only be supplied using list initialization

    //Creating specified Number of elements
    std::vector<int> ivec(10, -1);             // 10 int elements, each init. to -1
    std::vector<std::string> svec(10, "hi!");  //ten strings, each element is "hi"

    //value initialization - can omit the value and only supply a size
    //library creates a value-initialized element initlializer and this value is used to initialize each element in a container.

    //Value of the initializer depends type of the element stored

    //for built in types as int, it is 0
    //for class type elements, as string, it is the "default initialized" (empty)

    std::vector<int> ivec(10);          // ten elements, each init.d to 0
    std::vector<std::string> svec(10);  // ten elements, each an empty string

    //!Pitfall
    /*Restrictions on this:
    1. some classes require us to supply explicit initialier. If the vector holds the object of a type we cannot default initialize, we must supply an initial element value. Not possible to create vectors of such type by just supplying size

    2. supplying an element count without initial value requires direct initialization, copy init.n doesn't work
    */

    //! std::vector<int> i = 10; //error: must use direct initialization to supply a size

    //*difference b/w {} & () initialization

    std::vector<int> v1(10);     //10 elements, init.d to 0
    std::vector<int> v2{10};     //1 element with value 10
    std::vector<int> v3(10, 1);  //10 elements with value 1
    std::vector<int> v4{10, 1};  //2 elements with value 10 & 1

    //When we use parentheses, we are saying that the values we supply are to be used to construct the object. Thus v1 & v3 use their initializers to determine the vector's size and its size and element values, repectively.

    //Using {}, -  if possible, list initialize the object. hat is, if there is a way to use the values inside the curly braces as a list of element initializers, the class will do so.
    //The values we supply when we initialize v2 and v4 can be used as element values. These objects are list initialized; the resulting vectors have one and two elements, respectively.

    //!Pitfall:
    //Only if it is not possible to list initialize the object will the other ways to initialize the object be considered.

    std::vector<std::string> v5{"hi"};  //list init.n vs has one element with value "hi"

    //! std::vector<std::string> v6("hi");
    // error: cannot construct a vector from a string literal
    //! std::vector<int> ivec90{"hi"};
    //error: type mismatch

    std::vector<std::string> v7{10};  //10 elements, values are all empty string - default init.d

    std::vector<std::string> v8{10, "hi"};  //v8 has ten elements with value "hi"

    //* Why so?
    //only v5 is list initialized. in order to list initialize the vector, the values inside braces must match the element type. We cannot use an int to initialize a string, so the initializers for v7 and v8 can’t be element initializers. If list initialization isn’t possible, the compiler looks for other ways to initialize the object from the given values.

    //----------------------------------------------------------------------------

    //*Adding Elements to a vector
    std::vector<int> v2;  //empty vector
    for (int i = 0; i != 100; ++i) {
        v2.push_back(i);  //append sequential integers to v2
    }                     //v2 has 100 elements 0...99

    // Reading from standard input and storing as elements in vector

    std::string temp;
    std::vector<std::string> text;  //empty vector of strings
    while (std::cin>>temp) {
        text.push_back(temp);  // append word to text
    }

    //* vectors Grow Efficiently:
    //The standard requires that vector implementations can efficiently add elements at run time.
    //Because vectors grow efficiently, it is often unnecessary—and can result in poorer performance—to define a vector of a specific size. The exception to this rule is if all the elements actually need the same value.

    //* vecctor Operations
    /* v.empty() - returns true if v is empty
    v.size() - returns the no. of elements in v
    v.push_back - appends an element to the end of v
    v[n] - returns reference to an element at positino n in v
    v1=v2 - Replaces elements in v1 with a copy of elements in v2
    v1 = {a,b,c} - replaces the elements in v1 with a copy of elements in the comma-separated list
    v1==v2 - Equal if they have same no. of elements and each corresponding element in v1 & v2 is equal
    v1!=v2 
    <,<=,>=,> -  usual meaning with dictionary ordering
    */

    //Range Based For operation with vectors
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (auto &i : v) {
        i *= i;  // square each element and store back
    }

    for (auto i : v) {
        std::cout << v[i];  //prints each element in v
    }


    //!we cannot add elements to a vector inside a range for loop.


    //Vector size_type
    //To use size_type, we must name the type in which it is defined. A vector type always includes its element type

    std::vector<int>::size_type;
    //!std::vector::size_type; error

    //We can compare two vectors only if we can compare the elements in those vectors. Some class types, such as string, define the meaning of the equality and relational operators. Others, such as our Sales_item class, do not. The only operations Sales_item supports are those listed in § 1.5.1 (p. 20). Those operations did not include the equality or relational operators. As a result, we cannot compare two vector<Sales_item> objects.

    //

    /*
    Example, let’s assume that we have a collection of grades that range from 0 through 100. We’d like to count how many grades fall into various clusters of 10.Between zero and 100 there are 101 possible grades. These grades can be represented by 11 clusters: 10 clusters of 10 grades each plus one cluster for the perfect score of 100. The first cluster will count grades of 0 through 9, the second will count grades from 10 through 19, and so on. The final cluster counts how many scores of 100 were achieved.


    Clustering the grades this way, if our input is
    42 65 95 100 39 67 95 76 88 76 83 92 76 93
    then the output should be
 //(0-9 10-19 20-29 30-39 40-49 50-59 60-69 70-79 80-89 90-99 100)// - clusters
    0    0      0     1     1     0     2     3     2     4    1
    which indicates that there were no grades below 30, one grade in the 30s, one in the 40s, none in the 50s, two in the 60s, three in the 70s, two in the 80s, four in the 90s, and one grade of 100.

    We’ll use a vector with 11 elements to hold the counters for each cluster. We can determine the cluster index for a given grade by dividing that grade by 10. When wedivide two integers, we get an integer in which the  fractional part is truncated. For example, 42/10 is 4, 65/10 is 6 and 100/10 is 10. Once we’ve computed the cluster index, we can use it to subscript our vector and fetch the counter we want to increment:

    */

    //clusters - 10 +1 = 11 (1 for 100)

    std::vector<unsigned> scores(11, 0);  //11 values, all 0, cannot be -ve
    unsigned grade;
    while (std::cin >> grade) {
        if (grade <= 100) {  //check for valid grades i.e grade<=100, unsigned checks it cannot be less than 0
            ++scores[grade / 10];
            //eq. to auto ind = grade/10; // get the bucket index
            //       scores[ind] = scores[ind] + 1; // increment the count
        }
    }

    /*
    !Warning
    The subscript operator on vector (and string) fetches an existing
    element; it does not add an element.
   
    Subscript: Actual position in manual form. Example in a two dimensional array is declared as a[3][3] then  if we consider a[2][1], here 2rd row and 1nd column is a subscripted value.

    Index: actual position in a memory. Example a[3][2] is stored in a 7th position of a array. Here index value is 7.


    !Caution: Subscript Only Elements that are Known to Exist!
    It is crucially important to understand that we may use the subscript operator (the [] operator) to fetch only elements that actually exist. For example, 
    vector<int> ivec;      // empty vector
    cout << ivec[0];       // error: ivec has no elements!
    vector<int> ivec2(10); // vector with ten elements
    cout << ivec2[10];     // error: ivec2 has elements 0 . . . 9
    
    It is an error to subscript an element that doesn’t exist, but it is an error that the compiler is unlikely to detect. Instead, the value we get at run time is undefined. Attempting to subscript elements that do not exist is, unfortunately, an extremely common and pernicious programming error. So-called buffer overflow errors are the result of subscripting elements that don’t exist. Such bugs are the most common cause of security problems in PC and other applications.
    
    ?Tip
    A good way to ensure that subscripts are in range is to avoid subscripting altogether by using a range for whenever possible.
    */

    
    std::vector<int> ivec;  // empty vector

    //!Disaster
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec[ix] = ix;  // disaster: ivec has no elements

    //*Correct wat to write the loop
    for (decltype(ivec.size()) ix = 0; ix != 10; ++ix)
        ivec.push_back(ix);  // ok: adds a new element with value ix

    
}
