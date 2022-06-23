package miniproject;

import java.util.Scanner;

public class FtoC {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double f_temp = 0;
		double c_temp;
		System.out.print("È­¾¾¿Âµµ¸¦ ÀÔ·ÂÇÏ½Ã¿À:");
		f_temp = sc.nextDouble();
		c_temp = 5.0/9.0*(f_temp - 32);
		System.out.println("¼·¾¾¿Âµµ´Â "+c_temp);
	}
}
