package primitiveRoot;
import java.util.Scanner;
import java.lang.Math;
public class PrimitiveRoots {
	public static boolean isPrime(int number) {
		int cont = 0;
		for(int i=2; i < number; i++) {
			if(number % i == 0){
				cont++;
	        }
		}
		if(cont == 0){
			return true;
		}else{
			return false;
		}
	}
	public static void main(String[] args) {
		Scanner userInput = new Scanner(System.in);

		System.out.print("Enter Any Prime Number: ");
		int primeNumber = userInput.nextInt();

		if(isPrime(primeNumber)) {
			int primitiveRoot[] = new int[primeNumber];;
			int temp[] = new int[primeNumber];;
			int row, col, counter = 0, len=0;

			for(row=1; row < primeNumber; row++) {
				for(col=1; col < primeNumber; col++) {
					double sqr = Math.pow(row, col);
					int sqrVal = (int) sqr;
					temp[col] = sqrVal % primeNumber;
				}
				for(int m=1; m < primeNumber; m++) {
					for(int n=m+1; n < primeNumber; n++) {
						if(temp[m] == temp[n]) {
							counter++;
						}
					}
				}
				if(counter == 0) {
					primitiveRoot[len] = row;
					len++;
				}
				counter = 0;
			}
			if(len != 0) {
				System.out.print("Primitive Roots of " + primeNumber + " are: ");
				for(int p=0; p < len; p++) {
					System.out.print(primitiveRoot[p] + " ");
				}
			}else {
				System.out.print("Primitive Roots of " + primeNumber + " are: No Primitive Root");
			}
		}else {
			System.out.print("Number is not Prime!");
		}
	}
}
