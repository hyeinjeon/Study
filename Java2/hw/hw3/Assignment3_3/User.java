package Assignment3_3;

import java.util.Scanner;

public class User {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		//Book ��ü �迭 ����
		Book [] list = new Book[2];
		
		//����, ���ڸ� �Է¹޾� �����ڸ� �̿��Ͽ� ��ü�迭 ���Ҹ� ����
		for(int i=0; i<list.length; i++) {
			System.out.print("����>>");
			String title = sc.next();
		
			System.out.print("����>>");
			String author = sc.next();
			
			list[i] = new Book(title, author);
		}
		
		//�迭�� ���� ���
		
		for(int i=0; i < list.length; i++) {
			System.out.print("("+list[i].title+", "+list[i].author+")\n");
		}
		
	}

}
