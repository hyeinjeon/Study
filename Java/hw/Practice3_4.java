import java.util.Scanner;

public class Practice3_4 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner input = new Scanner(System.in);
		int i = (int) (Math.random() * 100);
		int guess;
		int trys = 0;

		do {
			//����ڷκ��� ���ڸ� guess�� �Է¹޴´�
			System.out.print("������ �����Ͽ� ������: ");
			guess = input.nextInt();
			//�õ�Ƚ���� �����Ѵ�
			trys++;

			int answer;
			if( guess < i ) 
				System.out.println("LOW");
				//���ڰ� ���ٰ� ���
			else if( guess > i) 
				System.out.println("High");
				//���ڰ� ���ٰ� ���
		} while( guess != i );
			//"�����մϴ�"�� �õ�Ƚ���� ���
			System.out.println("�����մϴ�.�õ� Ƚ�� = " + trys);
	}

}