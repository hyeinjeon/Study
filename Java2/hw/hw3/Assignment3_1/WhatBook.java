package Assignment3_1;

import java.util.Scanner;

public class WhatBook {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//�迭�� ������ �Է��޾� ó��
		Scanner sc = new Scanner(System.in);
		
		System.out.print("å�� �Ǽ�>>");
		int bookNum = sc.nextInt();
		
		Book[] list = new Book[bookNum];
		
		for(int i = 0; i < list.length; i++) {
			System.out.print("����>>");
			String title = sc.next();
			System.out.print("����>>");
			String author = sc.next();
			list[i] = new Book(title, author);
		}
		
		//�Է¹��� �迭 ���
		for(int i = 0;i < list.length; i++) {
			System.out.print("����: " + list[i].title + ", ����: " + list[i].author + "\n");
		}
		
		//ã������ å�� ������ �Է��ϰ�
		System.out.print("ã������ å�� ������>>");
		String bookName = sc.next();
		
		//�����ϸ� getter�� �̿��Ͽ� ���ڸ� ���
		int j = 0;
		for(int i = 0;i < list.length; i++) {
			if(bookName.equals(list[i].title)) {
				System.out.print("���ڴ�: " + list[i].getAuthor());
				j = 1;
			}
		}
		
		//������ ������ ���
		if(j == 0) {
			System.out.print("ã������ å�� �����ϴ�.");
		}
	}

}
