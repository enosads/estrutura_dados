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
 
void tratar_tag (string* vet2, string* vet3, char del, string nome, int x, int y){

	string aux = "";
	nome = nome+":";
	
	for (int i = 0; i < nome.length(); i++)
   {
      if (nome[i] == del) 
      {
      	if(aux == "fn" || aux == "ln" || aux == "bd" || aux == "pn"){
      		vet2[x] = aux;
      		aux = "";
		  }else{
		  	vet3[y] = aux;
		  	aux = "";
		  }
      }
      else
        aux = aux + nome[i]; 
   }
}

void tratar_nome (string nome, string*vet,string*vet1, char del){

   string aux = ""; 
   nome = nome+" ";
   int x = 0;
   int y = 0;
   
   for (int i = 1; i < nome.length(); i++)
   {
      if (nome[i] == del) 
      {
          tratar_tag (vet, vet1, ':', aux, x, y);
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


  void buscar (noArvore* raiz, string* vet, int a){
  
   if(raiz != NULL){
   	
      buscar (raiz->esq, vet, a);
      
        if (a == 1){
        	if(vet[0] == raiz->nome1 || vet[0] == raiz->nome2||vet[0] == raiz->data||vet[0] == raiz->tel)
			{
        		cout<<raiz->id<<" ";	
			}else{
					
			}
		}else{
			if (a == 2){
				if(vet[0] == raiz->nome1 || vet[0] == raiz->nome2||vet[0] == raiz->data||vet[0] == raiz->tel){
				
					if(vet[1] == raiz->nome1 || vet[1] == raiz->nome2||vet[1] == raiz->data||vet[1] == raiz->tel)
					{
	        		    cout<<raiz->id<<" ";
					}else{
							
				    }
				}
		    }else{
		    	if (a == 3){
		    		if(vet[0] == raiz->nome1 || vet[0] == raiz->nome2||vet[0] == raiz->data||vet[0] == raiz->tel)
					{ 
					   if(vet[1] == raiz->nome1 || vet[1] == raiz->nome2||vet[1] == raiz->data||vet[1] == raiz->tel)
						{ 
						   if(vet[2] == raiz->nome1 || vet[2] == raiz->nome2||vet[2] == raiz->data||vet[2] == raiz->tel)
							{
			        		    cout<<raiz->id<<" ";
							} 
						}
					}else{
							
					}
				}else{
					if (a == 4){
						if(vet[0] == raiz->nome1 || vet[0] == raiz->nome2||vet[0] == raiz->data||vet[0] == raiz->tel)
						{ 
						   if(vet[1] == raiz->nome1 || vet[1] == raiz->nome2||vet[1] == raiz->data||vet[1] == raiz->tel)
							{ 
							   if(vet[2] == raiz->nome1 || vet[2] == raiz->nome2||vet[2] == raiz->data||vet[2] == raiz->tel)
								{
									if(vet[3] == raiz->nome1 || vet[3] == raiz->nome2||vet[3] == raiz->data||vet[3] == raiz->tel)
									{
					        		    cout<<raiz->id<<" ";
									} 
								}
							}
						}
					}else{
		
				    }
			    }
	       }
	    }
      buscar (raiz->dir, vet, a);
     }  
}

 int contar (noArvore * Raiz)
   {
	   	if (Raiz == NULL)
		{
	   		return 0;
	   	}else
		{
			return 1 + contar (Raiz -> esq) + contar (Raiz -> dir);
	   	}
   }
   
    int altura(noArvore * raiz){
    	
		if(raiz == NULL)
		{
			return -1;
		}
		int ale = altura (raiz->esq);
		int ald = altura (raiz->dir);
		if(ale>ald)
		{
			return 1 + ale;
		}
		return 1+ald;
   } 
   
    bool balanceada (noArvore * raiz)
    {
    	if (raiz == NULL)
    	{
    		return true;
		}
		int AE = altura (raiz -> esq);
		int AD = altura (raiz -> dir);
		
		if ((AE - AD) <= 1 && (AE - AD) >= -1 
		&& balanceada (raiz -> esq) && balanceada (raiz -> dir))
		{
		    return true;	
		}
		return false;
	}
	
	void  criar_vetor (noArvore * raiz, noArvore *& vet, int & i){
		if (raiz != NULL)
		{
			criar_vetor (raiz -> esq, vet, i);
			vet [i] = *raiz;
			i++;
			criar_vetor (raiz -> dir, vet, i);
		}
	}
	
	void criar_arvore (noArvore *& raiz, noArvore * vet, int ini, int fim){
		
		if (ini <= fim){
			int meio = (ini+fim)/2;
			*raiz = vet [meio];
			raiz -> esq = NULL;
			raiz -> dir = NULL; 
			criar_arvore (raiz->esq, vet, ini, meio-1); 
			criar_arvore (raiz->dir, vet, meio+1, fim);	
		}	
	}
	
	
	void balanceamento_estatico (noArvore *& raiz){
		if (!balanceada (raiz)){
			
			int tam = contar(raiz);
			noArvore * vet = new noArvore [tam];
			int i = 0;
			criar_vetor (raiz, vet, i);
			//criar_arvore (raiz, vet, 0, tam-1);
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
				           balanceamento_estatico(Raiz); 
				            cin>>id;
				            aux = buscar(Raiz, id);
				            if (aux){
				            	remover (Raiz,id);
							}else{
								cout<<"ID "<<id<<" nao existente. "<<endl;
							}
				}else if( tipo == "info"){
				    	balanceamento_estatico(Raiz);
				        cin>>id;
				    	aux = buscar(Raiz, id);
				    	
				    	if (aux != NULL){
				    	    info(aux);  
						}else{
							cout<<"ID "<<id<<" nao existente. "<<endl;
						}
				}else if( tipo == "query"){
						balanceamento_estatico(Raiz);
				    		
									    getline(cin, tipo_query);
									    char d = ' ';
										//string tipo_query = "fn:otto ln:neto";
										//cout<<"\n"<<tamanho(frase, d)<<endl;
										int a = tamanho(tipo_query, d);
										//cout<<a<<endl;
										string* vet = new string[a];
										string* vet1 = new string[a];
										tratar_nome(tipo_query, vet, vet1, d);
										buscar(Raiz, vet1, a);	
										cout<<endl;		     	 
				}
				cin >> tipo;	
		   }
	}
	
	void iniciar_programa (noArvore * Raiz)
	{
	  
	programa(Raiz);
		
	}
 

int main()
{
	noArvore * Raiz = NULL;	
	iniciar_programa (Raiz);	
}

