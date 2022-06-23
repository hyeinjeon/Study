import java.util.Scanner;

public class Assignment3_2 {

   public static void main(String[] args) {
      // TODO Auto-generated method stub
      Scanner sc = new Scanner(System.in);
      
      System.out.print("첫번째 숫자를 입력하세요: ");
      int num1 = sc.nextInt();
      System.out.print("두번째 숫자를 입력하세요: ");
      int num2 = sc.nextInt();
      System.out.print("세번째 숫자를 입력하세요: ");
      int num3 = sc.nextInt();
      
      int best;
      
      if (num1 > num2)
      {
         if (num1 > num3)
            best = num1;
         else
            best = num3;
      }
      
      else
      {
         if (num2 > num3)
            best = num2;
         else
            best = num3;
      }
            
      System.out.println("가장 큰 숫자는 " + best + "입니다.");
   }

}