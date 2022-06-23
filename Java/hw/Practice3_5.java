
public class Practice3_5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.print("3 또는 4의 배수의 합 = ");
		int i, total = 0;
		
		for(i = 1; i <= 100; i++)
			if(i % 3 == 0 || i % 4 == 0)
				total += i;
		
		System.out.print(total);
	}

}
