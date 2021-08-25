#include<stdio.h>
#include<string.h>
void printsubsets(char *str,int n)
{    
  char temp[n];    
  if (n==1)    
  {        
    printf("\n %s",str);        
    return;    
  }    
  strcpy(temp,str);    
  printsubsets(temp,n-1);    
  for(unsigned i=1; i<n; i++)
  {
    for(unsigned j=0; j<n; j++)
    {
      temp[j] = str[(j+i)%n];
    }
    printsubsets(temp, n-1);
  }
  
}

int main()
{
  //printsubsets("ABCDEFG", 4);
  char word[50];
  int n;
  printf("\nEnter any string: ");
  fgets(word, 51, stdin);
  printf("\nEnter any positive integer to print all possible permutations of the first n characters: ");
  scanf("%d", &n);
  int len = strlen(word)-1;
  //printf("%d", len);
  if(n > len)
  {
    n = len;
  }
  printf("\n");
  printsubsets(word, n);
  return 0;

}