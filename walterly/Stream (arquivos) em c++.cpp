#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;


   
   

int main()
{
	ifstream arq ("texto.txt");
	string x;
	string v;
	
	while(!arq.eof())
	{
	  arq >> x;	
   	  cout << x <<endl;
	}
	cout<<"informe o nome: "<<endl;
	cin >> v;
	ofstream arqe ("texto.txt",ios::app);
	arqe << v <<endl;
	
   	arqe.close();		  
}
