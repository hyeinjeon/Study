import java.util.*;
public class Assignment4_5 {
public static void main(String[] args) {
int total = 0;
int count = 0;
int studentNum;
Scanner scan = new Scanner(System.in);
System.out.print("������ �Է¹޴� �л��� ����? : ");
studentNum = scan.nextInt();
int i = 1;
while ( i <= studentNum) {
System.out.print(i + "��° �л��� ������ �Է��Ͻÿ�: ");
int grade =scan.nextInt();
if (grade < 0)
break;
total += grade;
count++;
i++;
}
System.out.println("�հ�: " + total);
System.out.println("���: " + total / count);
 }
}