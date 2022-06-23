package Assignment3_2;

import java.util.Scanner;

public class Test {
	public static void main(String args[]) {
		Magazine m = new Magazine();
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("잡지 이름은?");
		m.setTitle(sc.next());
		
		System.out.print("페이지수는?");
		m.setPages(sc.nextInt());
		
		System.out.print("저자는?");
		m.setAuthor(sc.next());
		
		System.out.print("발매일은?");
		m.setReleaseDate(sc.next());
		
		System.out.print("책이름:"+m.title+"\n");
		System.out.print("페이지수: "+m.pages+"\n");
		System.out.print("저자: "+m.author+"\n");
		System.out.print("발매일: "+m.releaseDate+"\n");
		
	}
}
