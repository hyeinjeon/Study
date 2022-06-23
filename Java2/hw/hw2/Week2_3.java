
public class Week2_3 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int[] num = new int[100];
		int sum = 0;
		double avg = 0.0;
		
		System.out.println("random() 으로 발생한 수 : ");
		
		for(int k = 0; k < 100; k++) {
			num[k] = (int)(Math.random()*100)+1;
		}
		
		for(int i = 0; i < 100; i++) {
			if(i%10 == 0 && i != 0) {
				System.out.print("\n");
			}
			System.out.printf("%5d", num[i]);
			sum += num[i];
		}
		System.out.print("\n");
		
		avg = sum/100;
		
		System.out.println("합계: " + sum);
		System.out.println("평균: " + avg);
		
		
	}

}
