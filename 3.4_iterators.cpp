#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<int> ivec(10, 0);  //vector ivec with 10 elements, each init.d to 0

    //Iterators allow abstracting an arbitrary container as a sequence of elements

    //objects that work like pointers by design
    //Most container classes can be traversed by iterators

    //declaring iterators
    //more verbose method
    //container<object type>::iterator <name of iterator>;
    std::vector<std::string>::iterator ivs;

    //less verbose method:
    auto b = ivec.begin();  //begin and end members return the iterator according to the container implemented
    *b = 42;
    std::cout << *b;  //42

    //location returned by 'end' is an iterator positioned "one past the end" of the associated container. The iterator denotes a non existent elmenent "off the end" of the container, referred to as off-the-end iterator or the end titerator

    //If the container is empty, the iterators returned by begin and end are equal—they are both off-the-end iterators.
    //Because the iterator returned from end does not denote an element, it may not be incremented or dereferenced.

    /* 
    *Iterator operations 
    *iter - returns a reference to the element denoted by iter itself
    iter->mem -  dereferences iter and fetches the member named mem from underlying element. Eq. to (*iter).mem

    ++iter - increments iter to refer to the next element in the container
    --iter - devrements iter to refer to the previous element in the container

    iter1==iter2 
    iter1!=iter2 : Compares two iterators. two iterators are equal if the denote the same element or if they are both off-the-end iterators.

    We can dereference iterators as pointers to obtain the element denoted by it Like pointers, dereferencing an invalid iterator or an off-the-end iterator has undefined behavior

    */

    //captalize first character of a string
    std::string s("some string");
    if (s.begin() != s.end()) {
        auto it = s.begin();  //denotes the first char in the string
        *it = toupper(*it);   //make the char uppercase
    }

    //if begin == end, the container/object is empty

    //moving iterators from one element to another
    for (auto it = s.begin(); it != s.end() && !isspace(*it); ++it) {
        *it = toupper(*it);
    }

    //his loop accesses these characters using an iterator, not a subscript.
    //all of the library containers have iterators that define the == and != operators. Most of those iterators do not have the < operator. By routinely using iterators and !=, we don’t have to worry about the precise type of container we’re processing.

    std::vector<int>::iterator it;
    std::string::iterator it2;
    std::vector<int>::const_iterator it3;  //can read but cannot write elements
    std::string::const_iterator it4;       //can read but cannot write characters

    //If a vector or string is const, we may use only its const_iterator type. With a nonconst vector or string, we can use either iterator or const_iterator.

    std::vector<int> v;
    const std::vector<int> cv;
    auto it1 = v.begin();   //has type vector<int>::iterator
    auto it2 = cv.begin();  //has type vector<int>::const_iterator

    //Should use const_iterator when only need to read
    //To let us ask specifically for the const_iterator type, the new standard introduced two new functions named cbegin and cend:

    auto it3 = v.cbegin();  //it2 has type vector<int>::const_iterator
    //cbegin & cend return const_iterator regardless of if the container is const or not

    //Combining Dereference and Member Access * & . (dot)

    std::vector<std::string> svec{"hey", "", "hi"};
    auto it = svec.begin();

    //one way is (*it).empty(), and its synonym
    //* Arrow Operator ->

    //print each line upto the first blank line
    for (auto it = svec.cbegin(); it != svec.cend() && !it->empty(); ++it) {
        std::cout << *it << std::endl;
    }
    //any operation, such as push_back, that changes the size of a vector potentially invalidates all iterators into that vector.

    /*vector & string iterator operations
    iter + n 
    iter - n - adding (subtracting) an integral value n to (from) an iterator yields that many elements forward (backward) within the container

    resulting iterator must denote elements in, or one past the end of the same container

    iter += n
    iter -+ n 

    iter1 - iter2 - yeilds n, must denote elements in, or one past the end of the same container

    > >= <= < - one is less if it points to an element before the element thich other points to ust denote elements in, or one past the end of the same container
    */

    //Iterator Arithmetic

    //compute and iterator closes to the midpoint of vi
    std::vector<int> vi(20, 0);
    auto mid = vi.begin() + vi.size() / 2;

    //vi has 20 elements. vi.size/2 = 10. vi.begin points to 0. this mid = 10; i.e. 10 past the first element

    //process elements of first half
    std::vector<int>::iterator iter;
    if (iter < mid) {
    }

    //The result type of subtaction of two iterators is a signed integral type named "difference_type". Both vector and string define difference_type. This type is signed, because subtraction might have a negative result.

    //binary search using iterators

    std::vector<int> ivec(20, 40);
    auto beg = ivec.begin(), end = ivec.end();  //const_iterator
    auto mid = ivec.begin() + (end - beg) / 2;  //const_iterator
    int sought = 40;

    // while there are still elements to look at and we haven't yet found sought element
    while (mid != end && *mid != sought) {
        if (sought < *mid) {  //is the element in first half
            end = mid;        //if so, adjust range to ignore second half
        } else {
            beg = mid + 1;
        }                             //the element is in second half, start looking with element just after mid
        mid = beg + (end - beg) / 2;  //new midpoint

        //First, there is no operator + for two iterators. Second, for arithmetic types, using mid = (beg + end) / 2 may lead to overflow.
        
    }
}