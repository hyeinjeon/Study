import java.util.Scanner;

public class Week1_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num500, num100, num50, num10, sum;

		System.out.print("500원 동전 개수: ");
		num500 = sc.nextInt();
		
		System.out.print("100원 동전 개수: ");
		num100 = sc.nextInt();
		
		System.out.print("50원 동전 개수: ");
		num50 = sc.nextInt();
		
		System.out.print("10원 동전 개수: ");
		num10 = sc.nextInt();
		
		sum = num500*500 + num100*100 + num50*50 + num10*10;
		
		System.out.print("금액은 " + sum + "원 입니다.");
		
	}

}
