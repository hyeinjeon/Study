package miniproject;

import java.util.Scanner;

public class FtoC {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		double f_temp = 0;
		double c_temp;
		System.out.print("ȭ���µ��� �Է��Ͻÿ�:");
		f_temp = sc.nextDouble();
		c_temp = 5.0/9.0*(f_temp - 32);
		System.out.println("�����µ��� "+c_temp);
	}
}
