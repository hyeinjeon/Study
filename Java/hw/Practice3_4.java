import java.util.Scanner;

public class Practice3_4 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int i = (int) (Math.random() * 100);
		int guess;
		int trys = 0;

		do {
			//사용자로부터 숫자를 guess로 입력받는다
			System.out.print("정답을 추측하여 보세요: ");
			guess = input.nextInt();
			//시도횟수를 증가한다
			trys++;

			int answer;
			if( guess < i ) 
				System.out.println("LOW");
				//숫자가 낮다고 출력
			else if( guess > i) 
				System.out.println("High");
				//숫자가 높다고 출력
		} while( guess != i );
			//"축하합니다"와 시도횟수를 출력
			System.out.println("축하합니다.시도 횟수 = " + trys);
	}

}