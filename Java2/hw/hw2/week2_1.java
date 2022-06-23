import java.util.Scanner;

public class Week2_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner num = new Scanner(System.in);
		Scanner str = new Scanner(System.in);
		
		int[] number = new int[5];
		double sum = 0;
		String[] name = new String[5];
		
		
		System.out.print("정수를 입력하세요  : ");
		for(int i = 0; i < 5; i++) {
			number[i] = num.nextInt();
			sum += number[i];
		}
		
		System.out.println("합은 " + sum);
		
		
		
		System.out.print("이름을 입력하세요: ");
		for(int i = 0; i < 5; i++) {
			name[i] = str.next();
		}
		
		System.out.print("입력된 이름은 ");
		for(int i = 0; i < 5; i++) {
			System.out.print(name[i] + " ");
		}
	
	}

}
