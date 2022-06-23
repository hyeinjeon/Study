package Assignment3_1;

import java.util.Scanner;

public class WhatBook {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//배열의 개수를 입려받아 처리
		Scanner sc = new Scanner(System.in);
		
		System.out.print("책의 권수>>");
		int bookNum = sc.nextInt();
		
		Book[] list = new Book[bookNum];
		
		for(int i = 0; i < list.length; i++) {
			System.out.print("제목>>");
			String title = sc.next();
			System.out.print("저자>>");
			String author = sc.next();
			list[i] = new Book(title, author);
		}
		
		//입력받은 배열 출력
		for(int i = 0;i < list.length; i++) {
			System.out.print("제목: " + list[i].title + ", 저자: " + list[i].author + "\n");
		}
		
		//찾으려는 책의 제목을 입력하고
		System.out.print("찾으려는 책의 제목은>>");
		String bookName = sc.next();
		
		//존재하면 getter를 이용하여 저자를 출력
		int j = 0;
		for(int i = 0;i < list.length; i++) {
			if(bookName.equals(list[i].title)) {
				System.out.print("저자는: " + list[i].getAuthor());
				j = 1;
			}
		}
		
		//없으면 없음을 출력
		if(j == 0) {
			System.out.print("찾으려는 책이 없습니다.");
		}
	}

}
