#include <iostream>

using namespace std;

struct noArvore{
	
	string nome1;
	string nome2;
	int id;
	string data;
	string tel;
	noArvore* esq;
	noArvore* dir;
};

  bool add (noArvore *& raiz, int id, string nome1, string nome2, string data, string tel){
  	if (raiz == NULL){
  		 
  		 raiz = new noArvore;
  		 raiz->nome1 = nome1;
  		 raiz->nome2 = nome2;
  		 raiz->id = id;
  		 raiz->data = data;
  		 raiz->tel = tel;
  		 raiz->esq = NULL; 
  		 raiz->dir = NULL;
  		 
	  }else{
	  	 if (id < raiz -> id){
   	   	  	  add (raiz -> esq, id, nome1,nome2, data, tel);
   	   	  }
		   else{
   	   	  	  if (id > raiz -> id){
   	   	  	  	 add (raiz -> dir, id, nome1, nome2, data, tel);
   	   	  	  }
			  else{
			  	return false;
			  }
   	   	  }
	  }
	  return true;
  }
  


 noArvore * buscar (noArvore * Raiz, int id){
 	if(Raiz != NULL){
 		if (id < Raiz->id){
 			buscar(Raiz->esq,id);
		 }else{
		 	if (id > Raiz->id){
 		  	  buscar(Raiz->dir,id);
		    }else{
		    	return Raiz;
			}
		 }
	 }
 }

 
  void imprimir(noArvore * Raiz, int id){
  	
  	if(buscar (Raiz, id) != NULL){
  		
  		imprimir(Raiz-> esq, id);
  		cout<<Raiz->nome1<<" ";
  	    imprimir(Raiz-> dir, id);
  	    
	  }	else{
	  	cout<<"ID "<<id<<" nao existente. "<<endl;
	  }
  	
  }
  
  
  void info(noArvore * raiz){
	
  		cout<<raiz->nome1<<" ";
  		cout<<raiz->nome2<<" ";
  		cout<<raiz->data<<" ";
  		cout<<raiz->tel<<" "<<endl;
  	
  }
  
  
  noArvore * localizar_menor(noArvore *& Raiz)
 {
 	if (Raiz != NULL)
 	{
 		if (Raiz -> esq == NULL)
 		{
 			noArvore * aux = Raiz;
 			Raiz = aux -> dir;
 			aux -> dir = NULL;
 			return aux;
 			
		}
 		return localizar_menor(Raiz -> esq);
	}
 }


 void remover(noArvore*&Raiz,int id)
 {
   if(Raiz!=NULL)
   {
     if(id<Raiz->id)
	 {	
      remover(Raiz->esq,id);
      }else 
	  {
	  	if (id > Raiz -> id)
		{
      	remover(Raiz-> dir, id);
    	}else
    	{
    		if (Raiz ->esq == NULL && Raiz -> dir == NULL)
    		{
    			delete Raiz;
    			Raiz = NULL;
			}else
			{
				if (Raiz -> esq != NULL && Raiz -> dir == NULL)
				{
					noArvore * aux = Raiz;
					Raiz = aux -> esq;
					delete aux;
				}else
				{
					if (Raiz -> dir != NULL && Raiz -> esq == NULL)
					{
						noArvore * aux = Raiz;
					    Raiz = aux -> dir;
					    delete aux;
					}else
					{
						noArvore * aux = NULL;
						aux = localizar_menor (Raiz -> dir);
						Raiz -> id = aux -> id;
						delete aux;
					}
				}
			}
		}
	  }
   }
 }
 
void tratar_tag (string* vet, char del, string nome, int x, int y){

	string aux = "";
	nome = nome+":";
	
	for (int i = 0; i < nome.length(); i++)
   {
      if (nome[i] == del) 
      {
      	if(aux == "fn" || aux == "ln" || aux == "bd" || aux == "pn"){
      		aux = "";
		  }else{
		  	vet[y] = aux;
		  	aux = "";
		  }
      }
      else
        aux = aux + nome[i]; 
   }
}

void tratar_nome (string nome, string* vet, char del){

   string aux = ""; 
   nome = nome+" ";
   int x = 0;
   int y = 0;
   
   for (int i = 1; i < nome.length(); i++)
   {
      if (nome[i] == del) 
      {
          tratar_tag (vet, ':', aux, x, y);
		  x++;
		  y++;       
          aux = "";
      }
      else
        aux = aux + nome[i]; 
   }
}

int tamanho (string nome, char del){
	
	int a = 0;
	 
	for (int i = 0; i < nome.length(); i++)
   {
      if (nome[i] == del) 
      {
         a++;
      }
   }
	return  a;
}

bool buscar_no(noArvore * raiz, string* vet, int n){
	if(vet[n] == raiz->nome1 || vet[n] == raiz->nome2||vet[n] == raiz->data||vet[n] == raiz->tel)
	{
	   return true;
	}else{
	   return false;		
	}	
}




  void buscar (noArvore* raiz, string* vet, int a){
   if(raiz != NULL){
   	
      buscar (raiz->esq, vet, a);
      
        if (a == 1){
        	if (buscar_no(raiz, vet, 0))
			{
        		cout<<raiz->id<<" ";	
			}
		}else{
			if (a == 2){
				if(buscar_no(raiz, vet, 0)){
				
					if(buscar_no(raiz, vet, 1))
					{
	        		    cout<<raiz->id<<" ";
					}
				}
		    }else{
		    	if (a == 3){
		    		if(buscar_no(raiz, vet, 0))
					{ 
					   if(buscar_no(raiz, vet, 1))
						{ 
						   if(buscar_no(raiz, vet, 2))
							{
			        		    cout<<raiz->id<<" ";
							} 
						}
					}
				}else{
					if (a == 4){
						if(buscar_no(raiz, vet, 0))
						{ 
						   if(buscar_no(raiz, vet, 1))
							{ 
							   if(buscar_no(raiz, vet, 2))
								{
									if(buscar_no(raiz, vet, 3))
									{
					        		    cout<<raiz->id<<" ";
									} 
								}
							}
						}
					}
			    }
	       }
	    }
      buscar (raiz->dir, vet, a);
     }  
}

    void programa (noArvore * Raiz)
    { 
    noArvore * aux ;
        
		    int a = 1, x;
			string nome1;
			string nome2;
			int id;
			string data;
			string tel;
			string tipo;
			string tipo_query;
			int num;
		    
		    cin >> tipo;
			while (!cin.eof())
			{
				if( tipo == "add"){
					        cin>> id;
							cin>> nome1; 
							cin>> nome2;
							cin>> data;
							cin>> tel;
							
							if(!add(Raiz, id, nome1, nome2, data, tel)){   
							  cout<<"ID "<<id<<" ja cadastrado."<<endl;								
							}

				}else if( tipo == "del"){
				         
				            cin>>id;
				            aux = buscar(Raiz, id);
				            if (aux){
				            	remover (Raiz,id);
							}else{
								cout<<"ID "<<id<<" nao existente. "<<endl;
							}
				}else if( tipo == "info"){
				    
				        cin>>id;
				    	aux = buscar(Raiz, id);
				    	
				    	if (aux != NULL){
				    	    info(aux);  
						}else{
							cout<<"ID "<<id<<" nao existente. "<<endl;
						}
				}else if( tipo == "query"){
					
				    		
									    getline(cin, tipo_query);
									    char d = ' ';
										int a = tamanho(tipo_query, d);
										string* vet1 = new string[a];
										tratar_nome(tipo_query, vet1, d);
										buscar(Raiz, vet1, a);	
										cout<<endl;		     	 
				}
				cin >> tipo;	
		   }
	}
	
int main()
{
	noArvore * Raiz = NULL;
	programa(Raiz);	
	
}

