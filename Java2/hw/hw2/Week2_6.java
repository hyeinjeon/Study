import java.util.Scanner;

public class Week2_6 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		Phone p1 = new Phone(null, null);
		Phone p2 = new Phone(null, null);		
		
		System.out.print("�̸�, ��ȭ��ȣ�� �Է��ϼ���. >> " );
		String name = scan.next();
		p1.setName(name);
		String tel = scan.nextLine();
		p1.setTel(tel);
		
		System.out.println(p1.getName()+"�� ��ȣ��"+p1.getTel());
		
		System.out.print("�̸�, ��ȭ��ȣ�� �Է��ϼ���. >> " );
		String name2 = scan.next();
		p2.setName(name2);
		String tel2 = scan.nextLine();
		p2.setTel(tel2);
		
		System.out.println(p2.getName()+"�� ��ȣ��"+p2.getTel());

	}

}


