//Assignment 5: Knight Driver
//Name: Kyle Suarez

import java.util.Scanner;
import javax.swing.*;
import java.util.Random;
class KnightDriver
{
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    Random mixer = new Random();
    Knight Hero = new Knight();
    int exit;
    exit = 1;

    while(exit == 1)
    {
      JOptionPane.showMessageDialog(null, "Welcome to JavaBean Forest!\n");

    //Collect data about Knight
    Hero.setName(JOptionPane.showInputDialog("Enter the name of your Knight:"));
    //Assign health and weapon
    int fate = mixer.nextInt(100);
    Hero.setHealth(fate);
    fate = mixer.nextInt(4) + 1;
    Hero.setWeapon(fate);

    //decide number of enemies
    String choice = JOptionPane.showInputDialog("How many enemies shall your knight encounter in the forest?\n");
    int rounds = Integer.parseInt(choice);

    for(int i = 0; i < rounds; i++)
    {
      if(Hero.getHealth() <= 0)
      break;
      Enemy Monster = new Enemy();
      int mon = mixer.nextInt(3);
      Monster = Monster.getRandomEnemy(mon);
      mon = mixer.nextInt(100);
      Monster.setHealth(mon);

      //Hero.setArmor();
      //Enemy.setArmor();

      //Display Opponent Info
      JOptionPane.showMessageDialog(null, "Hero: " + Hero.getName() + "\nWeapon: " + Hero.getNWeapon() + "\nHP: " + Hero.getHealth());
      JOptionPane.showMessageDialog(null, "Enemy: " + Monster.toString() + "\nWeapon: " + Monster.getWeapon() + "\nHP: " + Monster.getHealth());

      JOptionPane.showMessageDialog(null,"Ready to Fight?");

      //Battle
      int first = mixer.nextInt(2);
      int flag = 0;

      if(first == 0)
      {
        flag = 0;
        while(flag == 0)
        {
          Monster.takeDamage(Hero.fight());

          if(Monster.getHealth() <= 0)
          {
            flag = 1;
            JOptionPane.showMessageDialog(null,"The Hero Wins!");
          }
          else
          {
            Hero.setHealth(Hero.getHealth() - Monster.fight());

            if(Hero.getHealth() <= 0)
            {
              flag = 1;
              JOptionPane.showMessageDialog(null,"The Enemy Wins! Your Hero did not survive the JavaBean Forest...");
            }
            else
            {
              JOptionPane.showMessageDialog(null,"Round Results:\n" + "Hero HP:" + Hero.getHealth() + "\nEnemy HP:" + Monster.getHealth());
            }
          }

        }
      }
      else
      {
        flag = 0;
        while(flag == 0)
        {
          Hero.setHealth(Hero.getHealth() - Monster.fight());

          if(Hero.getHealth() <= 0)
          {
            flag = 1;
            JOptionPane.showMessageDialog(null,"The Enemy Wins! Your hero did not survie JavaBean Forest...");
          }
          else
          {
            Monster.takeDamage(Hero.fight());

            if(Monster.getHealth() <= 0)
            {
              flag = 1;
              JOptionPane.showMessageDialog(null,"The Hero Wins!");
            }
            else
            {
              JOptionPane.showMessageDialog(null,"Round Results:\n" + "Hero HP:" + Hero.getHealth() + "\nEnemy HP:" + Monster.getHealth());
            }
          }
          }
        }
      }

    String restart = JOptionPane.showInputDialog("Start over?\n 1)Yes\n 2) No\n ");
    exit = Integer.parseInt(restart);
    }
  }
}
