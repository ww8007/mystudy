#include<stdio.h>

//사용자에게서 정수 5개를 입력받는다. 첫 번째 큰 수와 두 번째 
//큰 수를 각각 출력하시오.
int main()
{
   int n[5], max1=0, max2=0, i,temp=0;

   printf("정수 5개를 입력하세요, : ");

   for (i = 0; i < 5; i++)
      scanf_s("%d", &n[i]);
   for (i = 0; i < 5; i++)
   {
      if (max1 < n[i])
      {
         temp = max1;
         max1 = n[i];
      }
      else if (max2<max1 && temp>n[i])
         max2 = temp;
   }
   printf("%d는(은) 첫 번째로 큰 수입니다.\n", max1);
   printf("%d는(은) 두 번째로 큰 수입니다.\n", max2);
   return 0;
}