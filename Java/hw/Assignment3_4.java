import java.util.Scanner;

public class Assignment3_4 {

   public static void main(String[] args) {
      // TODO Auto-generated method stub
      Scanner sc = new Scanner(System.in);
      
      System.out.print("구하려는 범위의 숫자를 입력하세요: ");
      int num = sc.nextInt();
      
      int i = 0;
      int sum = 0;
      while (i * 3 <= num)
      {
         if (i != 0 && i % 5 == 0)
            System.out.print("\n");
         System.out.print((i * 3) + "\t");
         sum += i * 3;
         i++;
      }
      
      System.out.println("\n0부터 " + num + "까지의 3의 배수 합 : " + sum);
   }

}