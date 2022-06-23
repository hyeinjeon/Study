import java.util.ArrayList;

public class Practice4_1 {
	public static void main(String[] args) {
		ArrayList<String> list = new ArrayList<>();
		list.add("오렌지");
		list.add("사과");
		list.add("포도");
		
		System.out.print("초기 배열의 리스트: ");
		for(String obj:list)
			System.out.print(obj+" ");
		
		System.out.print("\n");
		
		System.out.print("배열의 두번째 항목: ");
		//for(String obj:list)
			System.out.print(list.get(1));
		
		System.out.print("\n");
		
		System.out.print("자몽이 추가된 배열의 리스트: ");
		list.add("자몽");
		for(String obj:list)
			System.out.print(obj+" ");
			
		System.out.print("\n");
		
		System.out.print("포도 삭제후 배열 리스트: ");
		list.remove(2);
		for(String obj:list)
			System.out.print(obj+" ");
	}
}