void quickSort(int a[], int l, int r); 
int partition(int a[], int l, int r);

void quickSort( int a[], int l, int r)
{
  int j;

  if( l < r ) 
    {
      // divide and conquer
      j = partition( a, l, r);
      quickSort( a, l, j-1);
      quickSort( a, j+1, r);
    }
  
}



int partition( int a[], int l, int r) {
  int pivot, i, j, t;
  pivot = a[l];
  i = l; j = r+1;
  
  while( 1)
    {
      do ++i; while( i <= r && a[i] <= pivot );
      do --j; while( a[j] > pivot );
      if( i >= j ) break; 
      t = a[i]; /* a[i] = a[j] */; a[j] = t;
    }
  t = a[l]; a[l] = a[j]; a[j] = t;
  return j;
}

int nondet_int();

int main() {
  int array[SIZE];
  int i, v;
  int pval;
  int refcount = 0, count = 0;

  array[SIZE+15] = 3;

  int s = nondet_int();
  __CPROVER_assume(s >= 0);
  __CPROVER_assume(s <= SIZE);

  pval = nondet_int();

  for (i = 0; i < s; i++) {
    v = nondet_int();
    if (v == pval) {
      refcount++;
    }
    printf ("LOG array[%d] = %d\n", i, v);
    array[i] = v;
  }

  quickSort(array, 0, s-1);

  for (i = 0; i < s; i++) {
    printf ("LOG sorted array[%d] = %d\n", i, array[i]);
    if (array[i] == pval) {
      count++;
    }
    if (i > 0) {
      assert(array[i] >= array[i-1]);
      //__CPROVER_assume(array[i] >= array[i-1]);
    }
  }

  assert(count == refcount);
  //assert(0);
}
