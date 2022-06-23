package Assignment3_3;

import java.util.Scanner;

public class User {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		//Book 객체 배열 선언
		Book [] list = new Book[2];
		
		//제목, 저자를 입력받아 생서자를 이용하여 객체배열 원소를 생성
		for(int i=0; i<list.length; i++) {
			System.out.print("제목>>");
			String title = sc.next();
		
			System.out.print("저자>>");
			String author = sc.next();
			
			list[i] = new Book(title, author);
		}
		
		//배열의 값을 출력
		
		for(int i=0; i < list.length; i++) {
			System.out.print("("+list[i].title+", "+list[i].author+")\n");
		}
		
	}

}
