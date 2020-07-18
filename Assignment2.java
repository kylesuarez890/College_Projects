/*
Name: Kyle Suarez
Class: COP3252
Section 2
Assignment 2
*/
import java.util.Scanner;
class Warrior
{
  //our warriors data points
  /*String name;
  int health;
  int battles;
  int age;
  int gold;*/

public static void main(String[] args)
{
    Scanner input = new Scanner(System.in);
    System.out.print("Please enter your knight's name:" + System.lineSeparator());                             //name prompt
    String name = input.nextLine();
    System.out.print("Please enter your knight's health:" + System.lineSeparator());                           //health prompt
    int health = input.nextInt();
    System.out.print("Please enter how many battles your knight has fought in:" + System.lineSeparator());    //# of battles
    int battles = input.nextInt();
    System.out.print("Please enter your knight's age:" + System.lineSeparator());                             //age
    int age = input.nextInt();
    System.out.print("Please enter how much gold your knight has aquired:" + System.lineSeparator());         //amount of gold
    int gold = input.nextInt();

    int average = gold / battles;

    System.out.printf("Name: %S\n", name);
    System.out.printf("%d HP\n", health);
    System.out.printf("%S has faced %d battles and is %d years old\n", name, battles, age);
    System.out.printf("They have accrued %d gold with an average of %d gold per battle\n", gold, average);
}

}
