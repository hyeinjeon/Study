import java.util.Scanner;

public class Assignment3_2 {

   public static void main(String[] args) {
      // TODO Auto-generated method stub
      Scanner sc = new Scanner(System.in);
      
      System.out.print("ù��° ���ڸ� �Է��ϼ���: ");
      int num1 = sc.nextInt();
      System.out.print("�ι�° ���ڸ� �Է��ϼ���: ");
      int num2 = sc.nextInt();
      System.out.print("����° ���ڸ� �Է��ϼ���: ");
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
            
      System.out.println("���� ū ���ڴ� " + best + "�Դϴ�.");
   }

}