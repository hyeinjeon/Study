import java.util.ArrayList;

public class Assignment4_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
	
		Double sum = 0.0;
		Double[] list = {1.0, 2.0, 3.0, 4.0};
		Double max = -1.0;
		
		ArrayList<Double> list2 = new ArrayList<>();
		list2.add(1.0);
		list2.add(2.0);
		list2.add(3.0);
		list2.add(4.0);
		
		System.out.println("toString()로 출력: " + list2);
		
		for(Double obj:list)
			System.out.print(obj+" ");
		System.out.print("\n");
		
		for(int i = 0; i < 4; i++)
			sum += list[i];
		
		System.out.println("합은 " + sum);
		
		for(int i = 0; i < 4; i++)
			if(list[i] >= max)
				max = list[i];
		
		System.out.println("최대값은 " + max);
		
		
		
		
	}

}
