import java.util.Scanner;

public class Week2_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int a = 0;
		
		while(true) {
			
			System.out.print("����� �ֹι�ȣ�� �Է��ϼ���. (012345-1234567) >> ");
			String number = scan.next();
			a = (int)number.charAt(7);
		
			if(a == '1' || a == '3')
				System.out.println("����� �����Դϴ�.");
			else if ( a== '2' || a == '4')
				System.out.println("����� �����Դϴ�.");
			else
				System.out.println("��ȿ���� ���� �ֹι�ȣ�Դϴ�.");
		
			System.out.print("�Է��� ����Ͻðڽ��ϱ�? (y/n)");
			String ans = scan.next();
		
			if(ans.equals("n"))
				break;
			else if (ans.equals("y"))
				continue;
			
		}
	}

}
