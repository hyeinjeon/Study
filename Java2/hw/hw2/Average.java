
public class Average {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("�μ��� ���: " + getAverage(10, 20));
		System.out.println("������ ���: " + getAverage(20, 30, 40));
	}
	
	public static int getAverage(int a, int b) {
		int avg = 0;
		avg = (a + b) / 2;
		return avg;
	}
	
	public static int getAverage(int a, int b, int c) {
		int avg = 0;
		avg = (a + b + c) / 3;
		return avg;
	}

}
