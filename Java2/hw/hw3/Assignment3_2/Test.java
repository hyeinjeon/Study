package Assignment3_2;

import java.util.Scanner;

public class Test {
	public static void main(String args[]) {
		Magazine m = new Magazine();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("���� �̸���?");
		m.setTitle(sc.next());
		
		System.out.print("����������?");
		m.setPages(sc.nextInt());
		
		System.out.print("���ڴ�?");
		m.setAuthor(sc.next());
		
		System.out.print("�߸�����?");
		m.setReleaseDate(sc.next());
		
		System.out.print("å�̸�:"+m.title+"\n");
		System.out.print("��������: "+m.pages+"\n");
		System.out.print("����: "+m.author+"\n");
		System.out.print("�߸���: "+m.releaseDate+"\n");
		
	}
}
