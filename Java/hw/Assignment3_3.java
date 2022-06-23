import java.util.Scanner;
public class Assignment3_3 {

   public static void main(String[] args) {
      // TODO Auto-generated method stub
      Scanner sc = new Scanner(System.in);
      String str = "";
      
      while (str.equals("quit") == false)
      {
         System.out.print("문자를 입력하세요: ");
         str = sc.next();
         
         if (str.equals("A") || str.equals("a") || str.equals("E") || str.equals("e") || str.equals("I") || str.equals("i") || str.equals("O") || str.equals("o") || str.equals("U") || str.equals("u"))
            System.out.println("모음입니다.");
         else if (str.equals("quit") == false)
            System.out.println("자음입니다.");
      }
      System.out.println("프로그램 종료!");
   }

}