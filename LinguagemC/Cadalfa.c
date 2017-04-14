/* Luiz, este nao funciona ainda! Dei uma boa melhorada nele no
   domingo. A um rolo na rotina Enter, porem acho que esta proximo
   Grato pela ajuda! */
   
struct addr
{
  char nome[30];
  char rua[40];
  char cidade[18];
  char estado[02];
  char cep[09];
  char lixao[10];
  struct addr *next;    /* ponteiro da prox entrada */
  struct addr *prior;   /* ponteiro p/ entrada anterior */
} lista;

struct addr *start;   /* primeiro da lista */
struct addr *last;    /* ultimo da lista */
struct addr *null;

main()
{
  int choice;
  null = (struct addr *)malloc(sizeof(lista));
  do {
       choice = menu_select();
       switch(choice)
         {
           case 1 : enter();
                    break;
           case 2 : delete();
                    break;
           case 3 : list();
                    break;
           case 4 : achar();
                    break;
           case 5 : save();
                    break;
           case 6 : load();
                    break;
           case 7 : exit(0);
         }
      } while(1);
} 

menu_select()
{
  char s[80];
  int c;
  printf("1. Inserir Nomes\n");     
  printf("2. Retirar Nomes\n");     
  printf("3. Listar  Nomes\n");     
  printf("4. Procurar Nome\n");     
  printf("5. Salvar Arquivo\n");     
  printf("6. Carregar Arquivo\n");     
  printf("7. Finalizar\n");     
  do {
     printf("\nSua opcao: ");
     gets(s);
     c = atoi(s);
     } while (c < 0 || c > 7);
  return c;
}

enter()
{ 
   struct addr *info;
   struct addr *anda;
   char *malloc();
   char key1[30],key2[30];
   char lixo;
   do {
      info = (struct addr *)malloc(sizeof(lista));
      if (info == 0)
         {
            printf("\nMemoria Esgotada!");
            return;
         }
      inputs("Entre Nome: ",info->nome,30);
      if (!info->nome[0]) break;
      inputs("Entre Rua: ",info->rua,40);
      inputs("Entre Cidade: ",info->cidade,18); 
      inputs("Entre Estado: ",info->estado,02); 
      inputs("Entre CEP: ",info->cep,10); 
      if (start!=0) {
         cls();
         anda = start;
         while (anda) {
           strcpy(key1,info->nome);
           strcpy(key2,anda->nome);
printf("%s\n%s\n",*key1,*key2);
           if(*key1 > *key2) {
printf("Atualizando");
scanf("%c",&lixo);
             info->next = last->next;
             last->next = info;
             info->prior = last;
             last = info;
             info = last->next;
             info->prior = last; 
             break;
             }
           else {
printf("Proximo");
scanf("%c",&lixo);
             anda = anda->next;
             }  
           }  
         }
      else
         {
         start = info;
         start->next = null;
         last = start;
         start->prior = null; 
         }
       } while(1);
}

inputs(prompt,s,count)
char *prompt;
char *s;
int count;
{
  char p[255];
  do {
     printf(prompt);
     gets(p);
     if (strlen(p) > count)
        puts("Muito Grande!");
    } whiLe (strlen(p) > count);
  strcpy(s,p);
}

delete()
{
  struct addr *info, *find();
         char s[255];
  int volta;
  inputs("Entre Nome: ",s,30);
  info = find(s);
  if (info) {
     if (start == info) {
        start = info->next;
        start->prior = null; 
        }
     else {
        info->prior->next = info->next;
        if (info != last) info->next->prior = info->prior;
        else
           last = info->prior;
     }
     free(info);
  }
}= null) 
     display(info);
  else 
     printf("Nao Encontrado!\n");
}

display(info)
struct addr *info;
{                           
  printf("%s\n",info->nome);
  printf("%s\n",info->rua);
  printf("%s\n",info->cidade);
  printf("%s\n",info->estado);
  printf("%s\n",info->cep);
  printf("\n\n");
}

save()
{
  int t,size;
  struct addr *info;
         char *p;
         FILE *fp;
  if ((fp = fopen("LISTA.DAT","w")) == 0) {
     puts("Falhou a Abertura!");
     exit(0);
    }
  printf("Salvando Arquivo\n");
  size = sizeof(lista);
  info = start;
  while (info && info != null) {
    p = (char *)info; /* convesao p/ ponteiro de caracter */
    for (t=0;t<size-1;++t) putc(*p++,fp); /* salva um byte */
    info = info->next; /* proximo */
    }
  putc(EOF,fp); /* marcando fim de arquivo ... opcional */
  fclose(fp);
}

load()
{
  int t,size;
  struct addr *info,*temp;
         char *p,*malloc();
         FILE *fp;
  if ((fp = fopen("LISTA.DAT","r")) == 0) {
     puts("Falhou Abertura");
     exit(0);
    }
  printf("Carregando Arquivo\n");
  size = sizeof(lista);
  start = (struct addr *)malloc(size);
  if (!start) {
     puts("Acabou Memoria! ");
     return;
  }
  info = start;
  p = (char *)info; /* ponteiro para caracter */
  while ((*p++ = getc(fp)) != EOF) {
    for (t=0;t<size-2;++t)
      *p++ = getc(fp); /* carrega byte a byte */
      info->next = (struct addr *)malloc(size); /* aloca mais memoria */
      if (!info->next) {
         printf("Memoria Esgotada!\n");
         return;
      }
      info->prior = temp;
      temp = info;
      info = info->next;
      p = (char *)info;
      if (info == null) break;
    }
  free(temp->next);
  temp->next = null;
  last = temp;
  start->prior = null;
  fclose(fp);
}
   








    
    
     
�lr�#�.�lr��.�>uru.�>lru.�lr6�>o �t 6�� u6�o���6�6�  �0�Ï��t� �����!6��6��6��A6��6��6��6��:6��\6�6���              �.�><r u7.�>rr u/.�t = (struct addr *)malloc(size); /* aloca mais memoria */
      if (!info->next) {
         printf("Memoria Esgotada!\n");
         return;
      }
      info->prior = temp;
      temp = info;
      info = info->next;
      p = (char *)info;
      if (info == null) break;
    }
  free(temp->next);
  temp->next = null;
  last = temp;
  start->prior = null;
  fclose(fp);
}
   








    
    
     
