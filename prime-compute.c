/* Dylan Duhamel
 
Program to compute N prime numbers with the 'Sieve of Eratosthenes' algorithm

Also includes a less optimal approach based off trial division 

*/

#include <stdio.h>
#include <stdlib.h>

void compute_prime_sieve(int n, int* primes);
void compute_prime_trial(int n, int* primes);
int is_prime(int n);

int main() 
{
    /* Max computation */
    int n;

    int i;
 
    /* Get user input */
    printf("Enter the limit of prime computation: ");
    scanf("%d", &n);

    /* Malloc space for primes */
    int *primes = (int *)malloc((n + 1) * sizeof(int));

    for(i = 0; i <= n; i++) 
    {
        primes[i] = 1;
    }    

    /* Compute primes up to n */
    compute_prime_sieve(n, primes);

    for(i = 0; i < n; i++) 
    {
        if ( primes[i] == 1  )
        {
            printf("%d\n", i);
        }
    }
}

void compute_prime_sieve(int n, int *primes)
{
    int i;
    int j;

    /* Init 0 & 1 */
    primes[0] = 0;
    primes[1] = 0;

    /* Set every number prime for now */
    for(i = 2; i < n; i++)
    {
        primes[i] = 1;
    }

    /* If prime, then multiples are not prime */
    for(i = 2; i < n; i++)
    {
        if ( primes[i] == 1 )
        {
            for(j = 2; j*i < n; j++)
            {
                primes[j*i] = 0;
            }
        }
    }
}

void compute_prime_trial(int n, int *primes)
{
    for(int i = 0; i <= n; i++)
    {
        primes[i] = is_prime(i);
    }
}

int is_prime(int n) 
{
    /* Not prime if <= 1 */
    if( n <= 1 )
    {
        return 0;
    }
    
    /* Prime if 2 or 3 */
    if( n <= 3 )
    {
        return 1; 
    }

    /* Not prime if any multiple of 2 or 3 */
    if( n % 2 == 0 || n % 3 == 0 )
    {
        return 0;
    }
    
    int i = 5;
    
    /* All primes > 3 can be in form 6k + 1*/
    while(i *i <= n) 
    {
        if( n % i == 0 || n % (i + 2) == 0 )
        {
            return 0;
        }
        i += 6;
    }

    return 1;
}

