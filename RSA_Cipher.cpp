//C++ program for encryption and decryption
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<string.h>
using namespace std;

double p, q, n, t, m, flag, message,e ,d;
long int temp[50], i, j;
char msg[100];
int prime(long int); //function to check for prime number

// find gcd
int gcd(int a, int b) {
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}

int prime(long int pr)
{
   j = sqrt(pr);
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

int main() {

   cout << "\nENTER FIRST PRIME NUMBER P : ";
   cin >> p;

   //checking whether input is prime or not
   flag = prime(p);
   if(flag == 0)
   {
      cout << "\nINVALID INPUT\n";
      exit(0);
   }

   cout << "\nENTER SECOND PRIME NUMBER Q : ";
   cin >> q;

   flag = prime(q);
   if(flag == 0 || p == q)
   {
      cout << "\nINVALID INPUT\n";
      exit(0);
   }
    //public key
    //e stands for encrypt
    cout << "\nENTER VALUES OF e : ";
    cin >> e;

    double n=p*q;//calculate n
    double track;
    double phi= (p-1)*(q-1);//calculate phi


    //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
    while(e<phi) {
        track = gcd(e,phi);
        if(track==1)
            break;
        else
            e++;
    }
    //private key
    //d stands for decrypt
    //choosing d such that it satisfies d*e = 1 mod phi
    double d1=1/e;
    double d=fmod(d1,phi);
    cout << "\nENTER VALUES OF Message m : ";
    cin >> message;
    double c = pow(message,e); //encrypt the message
    double m = pow(c,d);
    c=fmod(c,n);
    m=fmod(m,n);
    cout<<"\n\n\nOriginal Message = "<<message;
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = p*q = "<<n;
    cout<<"\n"<<"phi = "<<phi;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n"<<"Encrypted message = "<<c;
    cout<<"\n"<<"Decrypted message = "<<m;
    return 0;
}
