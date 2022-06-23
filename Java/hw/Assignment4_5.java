import java.util.*;
public class Assignment4_5 {
public static void main(String[] args) {
int total = 0;
int count = 0;
int studentNum;
Scanner scan = new Scanner(System.in);
System.out.print("성적을 입력받는 학생의 수는? : ");
studentNum = scan.nextInt();
int i = 1;
while ( i <= studentNum) {
System.out.print(i + "번째 학생의 성적을 입력하시오: ");
int grade =scan.nextInt();
if (grade < 0)
break;
total += grade;
count++;
i++;
}
System.out.println("합계: " + total);
System.out.println("평균: " + total / count);
 }
}