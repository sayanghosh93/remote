#include<stdio.h>
#include<math.h>

void arrayInput(int array[][10],int,int);
void arrayOutput(int array[][10],int,int);
void arrayTranspose(int array1[][10],int array2[][10],int,int);
void arrayTrace(int array1[][10],int array2[][10],int,int);
void arrayAddition(int array1[][10],int array2[][10],int,int);
void arraySubtraction(int array1[][10],int array2[][10],int,int);
void arrayMultiplication(int array1[][10],int array2[][10],int,int);

int i,j,k,n;
void main()
{
  int firstArray[10][10],secondArray[10][10],rows,columns;
  printf("Enter no of rows and columns: ");
  scanf("%d%d",&rows,&columns);
  printf("Enter elements for the First Array: ");
  arrayInput(firstArray,rows,columns);
  printf("Enter elements for the Second Array: ");
  arrayInput(secondArray,rows,columns);
  printf("Displaying The First Array:\n");
  arrayOutput(firstArray,rows,columns);
  printf("Displaying The Second Array:\n");
  arrayOutput(secondArray,rows,columns);
  printf("Options:\n  1. Addition\n  2. Subtraction\n  3. Multiplication\n");
  printf("  4. Transpose\n  5. Trace\n");
  while(n>5||n<1)
  {
      printf("Enter an option: ");
      scanf("%d",&n);
      switch(n)
       {
         case 1:
           arrayAddition(firstArray,secondArray,rows,columns);
           break;
         case 2:
           arraySubtraction(firstArray,secondArray,rows,columns);
           break;
         case 3:
           arrayMultiplication(firstArray,secondArray,rows,columns);
           break;
         case 4:
           arrayTranspose(firstArray,secondArray,rows,columns);
           break;
         case 5:
           arrayTrace(firstArray,secondArray,rows,columns);
           break;
         default:
           printf("Please enter a number between 1 to 5.");
           break;
         }
  }
}

void arrayInput(int array[][10],int r,int c)           //input to the matrix
{
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      scanf("%d",&array[i][j]);
    }
  }
}

void arrayOutput(int array[][10],int r,int c)        //output of the array in matrix format
{
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      printf("%d ",array[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void arrayTranspose(int array1[][10],int array2[][10],int r,int c)        //transpose of a matrix
{
  int newArray[10][10];
  while(n!=1||n!=2)
  {
    printf("Which matrix do you want to transpose: ");
    scanf("%d",&n);
    if(n>2||n<1)
    printf("Please enter 1 or 2\n");
  }
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(n==1)
      newArray[i][j]=array1[j][i];
      else if(n==2)
      newArray[i][j]=array2[j][i];
    }
  }
  printf("Transpose of matrix %d:\n",n);
  arrayOutput(newArray,c,r);
}

void arrayTrace(int array1[][10],int array2[][10],int r,int c)       //trace of a matrix
{
  int sum=0;
  traceStart:
  printf("Choose a matrix: ");
  scanf("%d",&n);
  if(n>2||n<1)
  printf("Please enter 1 or 2.");
  goto traceStart;
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      if(i==j)
      {
        if(n==1)
        sum=sum+array1[i][j];
        else if(n==2)
        sum=sum+array2[i][j];
      }
      else
      continue;
    }
  }
  printf("Trace of matrix %d is %d",n,sum);
}

void arrayAddition(int array1[][10],int array2[][10],int r,int c)         //addition of two matrices
{
  int newArray[10][10];
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      newArray[i][j]=array1[i][j]+array2[i][j];
    }
  }
  printf("After addition:\n");
  arrayOutput(newArray,r,c);
}

void arraySubtraction(int array1[][10],int array2[][10],int r,int c)            //subtraction of two matrices
{
  int newArray[10][10];
  for(i=0;i<r;i++)
  {
    for(j=0;j<c;j++)
    {
      newArray[i][j]=fabs(array1[i][j]-array2[i][j]);
    }
  }
  printf("After subtraction:\n");
  arrayOutput(newArray,r,c);
}

void arrayMultiplication(int array1[][10],int array2[][10],int r,int c)         //multiplication of matrices
{
  int newArray[10][10]={0};
  for(k=0;k<r;k++)
  {
    for(i=0;i<r;i++)
    {
      for(j=0;j<c;j++)
      {
        newArray[i][k]=newArray[i][k]+array1[i][j]*array2[j][k];
      }
    }
  }
  printf("After multiplication:\n");
  arrayOutput(newArray,r,c);
}
