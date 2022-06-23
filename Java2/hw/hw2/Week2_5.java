import java.util.Scanner;

public class Week2_5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scan = new Scanner(System.in);
		
		String str;           
		int length;        
		
		System.out.println("문자열을 입력하시오:");
		str = scan.nextLine();
		
		length = str.length();

		for(int i = length-1; i >= 0; i--){
			System.out.print(str.charAt(i));
		}
	}

}
