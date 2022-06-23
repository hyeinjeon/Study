import java.util.ArrayList;

public class Assignment4_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Double> list = new ArrayList<>();
		list.add(1.0);
		list.add(2.0);
		list.add(3.0);
		list.add(4.0);
		
		Double sum = 0.0;
		Double max = -1.0;
		
		for(Double obj:list)
			System.out.print(obj+" ");
		System.out.print("\n");
		
		for(int i = 0; i < list.size(); i++) {
				sum += list.get(i);
		}
		System.out.print("합은 " + sum);
		System.out.print("\n");
		
		for(int i = 0; i < 4; i++)
			if(list.get(i) >= max)
				max = list.get(i);
		
		System.out.println("최대값은 " + max);
	}

}
