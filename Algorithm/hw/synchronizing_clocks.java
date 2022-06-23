import java.util.Scanner;

public class Student20181009 {

	static int[] clock = new int[16];
	static int min = 100000; 
	static int[][] btn = new int[10][]; 
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int[] items = {0, 1, 2, 3}; 
		int[] switch_num = new int[10]; 
		int idx, num; 
		
		for (int i = 0; i < 10; i++) {
			idx = scan.nextInt();
			num = scan.nextInt();
			
			btn[idx] = new int[num];
			
			for (int j = 0; j < num; j++) {
				btn[idx][j] = scan.nextInt();
			}
		}
		
		for (int i = 0; i < 16; i++) {
			clock[i] = scan.nextInt();
		}
		
		solution(items, switch_num, 10);
		
		System.out.println(min);
	}
	
	public static void solution (int[] items, int[] switch_num, int k) {
		if (k == 0) {
			int cnt = moveClock(switch_num);
			
			if (cnt != -1 && cnt < min) {
				min = cnt;
			}
			return;
		}
		
		int lastIdx = switch_num.length - k - 1;
		
		for (int i = 0; i < items.length; i++) {
			switch_num[lastIdx + 1] = items[i];
			solution(items, switch_num, k - 1);
		}
	}
	
	public static int moveClock(int[] switch_num) {
		int cnt = 0;
		int[] tmpClock = new int[16];
		
		for (int i = 0; i < clock.length; i++) { 
			tmpClock[i] = clock[i];
			
		}
		
		for (int i = 0; i < switch_num.length; i++) { 
			if (switch_num[i] == 0) { continue; } 
			
			for (int j = 0; j < btn[i].length; j++) { 
				tmpClock[btn[i][j]] += switch_num[i] * 3; 
			}
		}
		
		for (int i = 0; i < tmpClock.length; i++) {
			if (tmpClock[i] % 12 != 0) { 
				return -1;
			}
		}
		
		for (int i = 0; i < switch_num.length; i++) {
			cnt += switch_num[i];	
		}
		
		return cnt;
	}

}
