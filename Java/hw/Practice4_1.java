import java.util.ArrayList;

public class Practice4_1 {
	public static void main(String[] args) {
		ArrayList<String> list = new ArrayList<>();
		list.add("������");
		list.add("���");
		list.add("����");
		
		System.out.print("�ʱ� �迭�� ����Ʈ: ");
		for(String obj:list)
			System.out.print(obj+" ");
		
		System.out.print("\n");
		
		System.out.print("�迭�� �ι�° �׸�: ");
		//for(String obj:list)
			System.out.print(list.get(1));
		
		System.out.print("\n");
		
		System.out.print("�ڸ��� �߰��� �迭�� ����Ʈ: ");
		list.add("�ڸ�");
		for(String obj:list)
			System.out.print(obj+" ");
			
		System.out.print("\n");
		
		System.out.print("���� ������ �迭 ����Ʈ: ");
		list.remove(2);
		for(String obj:list)
			System.out.print(obj+" ");
	}
}