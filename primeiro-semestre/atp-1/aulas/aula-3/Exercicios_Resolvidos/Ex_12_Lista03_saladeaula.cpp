


#include <stdio.h>





int main()

{

   int n1, n2, n3, n4, n5;

   int maior;
int menor;

 
   printf("\n Insira 5 n�meros diferentes entre si: ");

   scanf("%d %d %d %d %d",&n1,&n2,&n3,&n4,&n5);



  //Teste Maior
  
if(n1-n2>=0 && n1-n3>=0 && n1-n4>=0 && n1-n5>=0)
  {
     
maior = n1;
  
}else if (n2-n1>=0 && n2-n3>=0 && n2-n4>=0 && n2-n5>=0)
  {
     
maior = n2;

  }else if (n3-n1>=0 && n3-n2>=0 && n3-n4>=0 && n3-n5>=0)
  {
     
maior = n3;

  }else if (n4-n1>=0 && n4-n2>=0 && n4-n3>=0 && n4-n5>=0)
  {
     
maior = n4;

  } else
  {
     
maior = n5;

  }

  
 
//Teste menor
  
if(n1-n2<=0 && n1-n3<=0 && n1-n4<=0 && n1-n5<=0)
  {
     
menor = n1;

  }else if (n2-n1<=0 && n2-n3<=0 && n2-n4<=0 && n2-n5<=0)
  {
     
menor = n2;
  
}else if (n3-n1<=0 && n3-n2<=0 && n3-n4<=0 && n3-n5<=0)
  {
     
menor = n3;

  }else if (n4-n1<=0 && n4-n2<=0 && n4-n3<=0 && n4-n5<=0)
  {  

     menor = n4;
  
}else 
  { 
     
menor = n5;

  }
  

printf("\nO maior �: %d" , maior);

  printf("\n O menor �: %d" , menor);

  return 0;

}
