package proExercise3;

import java.util.Scanner;

public class proExercise3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int received = 0;
		int price = 0;
		int surtax;
		int change;
		System.out.print("���� ��: ");
		received = input.nextInt();
		System.out.print("��ǰ ����: ");
		price = input.nextInt();
		surtax = price/10;
		change = received - price;
		System.out.println("�ΰ���: "+surtax);
		System.out.println("�ܵ�: "+change);
	}

}
