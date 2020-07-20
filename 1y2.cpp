#include <iostream>
using namespace std;

//Ejemplos lvalue y rvalue
int a = 10;
int b = a + 5;

int x = 1;
int y = 3;
int z = x + y;

string s1 = "hello ";
string s2 = "world";
string s3 = s1 + s2;

string getString() {
  return "hello world";
}
string s4 = getString();

int main(){
    cout<<"a es un lvalue y 10 es un rvalue"<<endl;
    cout<<"b es un lvalue y (a + 5) son rvalue"<<endl;
    cout<<"x e y son lvalues y han sufrido una conversion implicita a rvalue"<<endl;
    cout<<"s3 es lvalue y recibe rvalue"<<endl;
    cout<<"el valor es almacenado en s4 que es lvalue"<<endl;
    return 0;
}
