package proExercise2;

import java.util.Scanner;

public class proExercise2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		double mile = 0;
		double kilo;
		System.out.print("������ �Է��Ͻÿ�.: ");
		mile = input.nextDouble();
		kilo = mile * 1.609;
		System.out.print(mile+"�� "+kilo+"ų�ι����Դϴ�.");
	}
}
