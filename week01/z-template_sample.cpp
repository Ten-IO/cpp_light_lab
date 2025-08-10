/* Template - generic type of paradigm, dynamic datatype*/
#include <iostream>
template <typename TYPE>
TYPE add(TYPE a, TYPE b){
    return a+b;
}
int main(){
    std::cout << "Integer: " << add(2,3);
    std::cout << "\nDouble: " << add(2.1,3.2);
    /* by default string is pointer/array of chars */
    // std::cout << "\nString: " << add("ab","cd"); // -- error
    std::cout << "\nString: " << add(std::string("ab"),std::string("cd"));
    std::cout << "\nCharacter: " << add('a','b') << " or " << int(add('a','b'));

    /* By default compiler use double over float unless define type*/
    std::cout << "\n[+] No Def-Type: "<< sizeof(2.5)<<", "<< sizeof(2.55);
    std::cout << "\n[+] Def-Type: "<< sizeof(2.5f)<<", "<< sizeof(2.55);
}