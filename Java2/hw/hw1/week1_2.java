import java.util.Scanner;

public class Week1_2 {

	public static void main(String[] args) 		{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int a = 0;
		
		while(true) {
			System.out.print("문자를 입력하세요: ");
			
			String aString =sc.next();
			
			if(aString != null && aString != "") {
			    a = (int)aString.charAt(0);
			}
			else{
			    continue;
			}
			
			if(a == '0') {
				break;
			}
			
			if (a >= 'a' && a <= 'z') 
				a = a - ('a'-'A');
			else if (a >= 'A' && a <= 'Z')
				a = a + ('a'-'A');
			else
				System.out.println("영문자가 아닙니다.");
		
			System.out.println((char)a);		
		}

	}
}
