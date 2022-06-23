
public class Practice4_2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String [] list1 = { "Clubs", "Diamonds", "Hearts", "Spades" };
		String [] list2 = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
		
		int matrix[][] = new int[4][13];

		for(int i=0;i<5;i++) {
			int k = (int) (Math.random() * 4);
			int m = (int) (Math.random() * 13);

			if( matrix[k][m] == 1 ) continue;
			matrix[k][m] = 1;
			System.out.println(list1[k] +"ÀÇ "+ list2[m]);
		}
	}
}
