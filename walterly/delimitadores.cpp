#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;
int main ()
{
	string frase, aux;
	getline(cin,frase);
	
	for(int i = 0; i < frase.length();i++){
	    if(frase[i] == ' '){
		  i++;	
		}
		aux = aux + frase[i]; 		
	}
	cout<<aux;
    getch();	
}

