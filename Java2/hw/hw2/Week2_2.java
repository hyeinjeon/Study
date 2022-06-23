import java.util.Scanner;

public class Week2_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		int a = 0;
		
		while(true) {
			
			System.out.print("당신의 주민번호를 입력하세요. (012345-1234567) >> ");
			String number = scan.next();
			a = (int)number.charAt(7);
		
			if(a == '1' || a == '3')
				System.out.println("당신은 남자입니다.");
			else if ( a== '2' || a == '4')
				System.out.println("당신은 여자입니다.");
			else
				System.out.println("유효하지 않은 주민번호입니다.");
		
			System.out.print("입력을 계속하시겠습니까? (y/n)");
			String ans = scan.next();
		
			if(ans.equals("n"))
				break;
			else if (ans.equals("y"))
				continue;
			
		}
	}

}
