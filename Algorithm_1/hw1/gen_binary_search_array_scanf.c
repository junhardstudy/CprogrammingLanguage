/* Generation of sorted array for binary search
 * modified from https://shaeod.tistory.com/313 
 * COMP319 Algorithms, Fall 2019
 * School of Electronics Engineering, Kyungpook National University
 * Instructor: Gil-Jin Jang
 * Modified on 2019/09/05
 * File name by Argument input -> scanf read
 */

#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>

int RecursiveBinSearch( int A[], int begin, int end, int target ) 
{
  int nMid = 0;

  if( begin > end ) return -1;	// escape or search failure

  nMid = (begin+end) / 2;
  if( A[nMid] == target ) return nMid;	// found target
  else if( target < A[nMid] )
    return RecursiveBinSearch( A, begin, nMid-1, target );
  else
    return RecursiveBinSearch( A, nMid+1, end, target );
}

int add_value_for_binsearch( int A[], int loc, int val ) 
  // assumption: A[0]~A[loc-1] - sorted values
  // find the location of val in A including A[loc]
  // and re-order all the other values as well
{
	int i, j;//루프문 제어용 변수

	if (loc == 0)A[0] = val;
	else {
		for (i = 0; i < loc; i++) {//값을 비교하기 위한 반복문
			if (A[i] > val) {//배열에 넣으려는 데이터보다 더 큰 배열 요소를 찾으면
				for (j = loc - 1; j >= i; j--)A[j+1] = A[j];
				//데이터가 이미 들어있는 배열의 인덱스 끝에서부터 넣으려는 데이터가 들어갈
				//인덱스 순까지 오른쪽으로 다 차례차례씩 밀기
				break;
			}
		}
		A[i] = val;
		return i;
	}
	return 0;
}

/* Modified on 2019/09/05
 * File name by Argument input -> scanf read
 * argc, argv, command line input are no longer necessary
 * Input file name can be typed in the terminal */
int main()
{
  int *A, tmp;
  int res, smallest, largest;
  int numElements;
  int i;
  FILE *fp;

  /* for file name, max length 1023 including path */
  char filename[1024];

  /* file name given by keyboard */
  printf("File name? ");
  scanf("%s",filename);

  // check for file 
  fp = fopen(filename,"r");
  if ( !fp ) {
    fprintf(stderr, "cannot open file %s\n",filename);
    return -1;
  }
  else {
    // check for number of elements
    if ( fscanf(fp, "%d", &numElements) != 1 || numElements <= 0 ) {
      fprintf(stderr, "cannot read number of elements %s\n",filename);
      return -1;
    }
    else {
      A = (int*)malloc(sizeof(int)*numElements);
      for (i=0; i<numElements; i++) {
	if ( fscanf(fp, "%d", &tmp) != 1 ) {
	  fprintf(stderr, "cannot read value at %d/%d\n",i+1,numElements);
	  return -1;
	}
	else {
	  //A[i] = tmp;
	  res = add_value_for_binsearch(A,i,tmp);
	  printf( " %d added at %d\n",tmp,res);
	}
      }
      printf("A = \n");
      for (i=0; i<numElements; i++) printf("%d ",A[i]);
      printf("\n");

      // find the smallest and the largest
      smallest = largest = A[0];
      for (i=1; i<numElements; i++) {
	if ( smallest > A[i] ) smallest = A[i];
	if ( largest < A[i] ) largest = A[i];
      }

      // perform search
      printf("==========================================\n");
      printf("Searching from %d to %d\n",smallest,largest);
      for (i=smallest; i<=largest; i++) {
	res = RecursiveBinSearch( A, 0, numElements-1, i );
	//printf("Value %d is ", i);
	//if(res == -1) printf( "not in the array.\n" );
	//else printf( "at index %d.\n", res );
	if(res >= 0) printf( "%d:%d ", i, res );
      }
      printf("\n");
      printf("==========================================\n");

      // once allocated, should be freed after use
      free(A);
    }
    // once opened, should be closed after use
    fclose(fp);
  }

  return 0;
}
