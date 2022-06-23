import java.util.Scanner;

public class Week1_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int num = 0, x = -1, sum = 0;
		double avg = 0;
		
		System.out.println("정수를 입력하고 마지막에 0을 입력하세요");
		x = sc.nextInt();
		
		while(x != 0) {
			num++;
			sum += x;
			x = sc.nextInt();
		}
		
		System.out.println("입력한 수의 개수: " + num);
		avg = sum/num;
		System.out.println("평균: " + avg);
		
	}

}
