#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int seed_input ();		// The function to get the seed from the user
int seed_num_input ();		// The function to get the seed number from the user
int data_size_input ();		// The function to get the data set size from the user
void nested_loop (int seed, int seed_num, int data_size);	// The function to do the calculatin

int
main (void)
{
  int seed;			// The seed value
  int seed_num;			// The seed number
  int data_size;		// The data size 
  seed = seed_input ();
  seed_num = seed_num_input ();
  data_size = data_size_input ();
  nested_loop (seed, seed_num, data_size);
  return (0);
}

int
seed_input ()
{
  int seed_val;			// The value for the seed inputed
  printf ("Enter starting seed value -> ");
  scanf ("%d", &seed_val);
  return (seed_val);
}

int
seed_num_input ()
{
  int seed_num_val;		//The variable for the seed number inputed 
  printf ("Enter number of seeds to test -> ");
  scanf ("%d", &seed_num_val);
  while ((seed_num_val < 1) || (seed_num_val > 10))
    {
      printf ("\n\nError! number of seeds must be 1 - 10");
      printf ("\n\nEnter number of seeds to test -> ");
      scanf ("%d", &seed_num_val);

    }
  return (seed_num_val);
}

int
data_size_input ()
{
  int data_size_val;		// The variable for the data size inputed 
  printf ("Enter the data set size -> ");
  scanf ("%d", &data_size_val);
  while ((data_size_val < 1) || (data_size_val > 10000))
    {
      printf ("\nError! Data set size must be 1 - 10000");
      printf ("\nEnter the data set size -> ");
      scanf ("%d", &data_size_val);
    }
  return (data_size_val);
}

void
nested_loop (int seed, int seed_num, int data_size)
{
  int seed_pro;			// The seed value we update each time for the data sets
  int i_num;			// The index we use for counting how many numbers we generate
  int i_set;			// The index we use for counting how many data sets we evaluate
  int num_ge;			// The random number we generated
  double sum_num;		// The sum of all numbers in a data set
  double average;		// The average number of a data set 
  double standard_deviation;	// The standard deviation number of a data set
  double a;
  double sums;
  double s;

  seed_pro = seed;
  srand (seed_pro);
  printf ("\n");
  printf ("\n           Seed   Average   Std Dev");
  printf ("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
  for (i_set = 1; i_set <= seed_num; i_set++)
    {
      srand (seed_pro);

      sum_num = 0;
      for (i_num = 0; i_num < data_size; i_num++)
	{

	  num_ge = rand () % 1001;
	  sum_num = sum_num + num_ge;
	  average = sum_num / data_size;
	}

      srand (seed_pro);
      sums = 0;
      for (i_num = 0; i_num < data_size; i_num++)
	{
	  num_ge = rand () % 1001;
	  a = pow (num_ge - average, 2);
	  sums = a + sums;
	  standard_deviation = sqrt (sums / (data_size - 1));
	}
      printf ("\nSet # %d:   % d     %.1lf    %.1lf\n", i_set, seed, average,
	      standard_deviation);

      seed++;
      seed_pro++;
    }

  return;
}

