#include <string>
#include <iostream>
using namespace std;

string   s1     = "Hola ";
string   s2     = "mundo";
string&& s_rref = s1 + s2;	// el resultado de s1 + s2 es un rvalue asignado a s_rref, un lvalue

int main(){
    s_rref += ", mi amigo";		// se puede cambiar el string temporal
    cout << s_rref << '\n';		// imprime "Hola mundo, mi amigo"
    return 0;
}
