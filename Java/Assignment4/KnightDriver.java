//Assignment 4: Knight Driver
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
      JOptionPane.showMessageDialog(null, "Welcome to KnightFight!\n");

    //Collect data about Knight
    Hero.setName(JOptionPane.showInputDialog("Enter the name of your Knight:"));
    String weapon = JOptionPane.showInputDialog("What weapon shall your knight wield?\n 1) Sword & Shield\n 2) Spear\n 3) Longsword\n 4) Bow & Arrow\n Your choice:");
    Hero.setWeapon(Integer.parseInt(weapon));


    //Prep enemy
    int fate = mixer.nextInt(100);
    Knight Enemy = new Knight(fate);
    int flag = 0;
    String choice = JOptionPane.showInputDialog("Would you like the enemy to be summoned automatically? (y|n)\n");


    while(flag == 0)
    {

      if(choice.equals("y") || choice.equals("yes"))
      {
        flag = 1;
      }
      else if(choice.equals("n") || choice.equals("no"))
      {
        flag = 1;
        Enemy.setName(JOptionPane.showInputDialog("What is your enemy's name?"));
        String eweapon = JOptionPane.showInputDialog("What weapon does your enemy possess?\n 1) Sword & Shield\n 2) Spear\n 3) Longsword\n 4) Bow & Arrow\n Your choice:");
        Enemy.setWeapon(Integer.parseInt(eweapon));
      }
      else
      {
        choice = JOptionPane.showInputDialog("Invalid Entry. Please Try Again.\n Would you like the enemy to be summoned automatically? (y|n)\n");
      }

    }

    //Assign health and armor type
    fate = mixer.nextInt(100);
    Hero.setHealth(fate);
    Hero.setArmor();
    Enemy.setArmor();

    //Display Opponent Info
    JOptionPane.showMessageDialog(null, "Hero: " + Hero.getName() + "\nWeapon: " + Hero.getNWeapon() + "\nHP: " + Hero.getHealth());
    JOptionPane.showMessageDialog(null, "Enemy: " + Enemy.getName() + "\nWeapon: " + Enemy.getNWeapon() + "\nHP: " + Enemy.getHealth());

    JOptionPane.showMessageDialog(null,"Ready to Fight?");

    //Battle
    int first = mixer.nextInt(2);

    if(first == 0)
    {
      flag = 0;
      while(flag == 0)
      {
        Enemy.setHealth(Enemy.getHealth() - Hero.fight());
        if(Enemy.getArmor() == Hero.getWeapon())
        {
          Enemy.setHealth(Enemy.getHealth() + 5);
        }
        if(Enemy.getHealth() <= 0)
        {
          flag = 1;
          JOptionPane.showMessageDialog(null,"The Hero Wins!");
        }
        else
        {
          Hero.setHealth(Hero.getHealth() - Enemy.fight());
          if(Hero.getArmor() == Enemy.getWeapon())
          {
            Hero.setHealth(Hero.getHealth() + 5);
          }
          if(Hero.getHealth() <= 0)
          {
            flag = 1;
            JOptionPane.showMessageDialog(null,"The Enemy Wins!");
          }
          else
          {
            JOptionPane.showMessageDialog(null,"Round Results:\n" + "Hero HP:" + Hero.getHealth() + "\nEnemy HP:" + Enemy.getHealth());
          }
        }

      }
    }
    else
    {
      flag = 0;
      while(flag == 0)
      {
        Hero.setHealth(Hero.getHealth() - Enemy.fight());
        if(Hero.getArmor() == Enemy.getWeapon())
        {
          Hero.setHealth(Hero.getHealth() + 5);
        }
        if(Hero.getHealth() <= 0)
        {
          flag = 1;
          JOptionPane.showMessageDialog(null,"The Enemy Wins!");
        }
        else
        {
          Enemy.setHealth(Enemy.getHealth() - Hero.fight());
          if(Enemy.getArmor() == Hero.getWeapon())
          {
            Enemy.setHealth(Enemy.getHealth() + 5);
          }
          if(Enemy.getHealth() <= 0)
          {
            flag = 1;
            JOptionPane.showMessageDialog(null,"The Hero Wins!");
          }
          else
          {
            JOptionPane.showMessageDialog(null,"Round Results:\n" + "Hero HP:" + Hero.getHealth() + "\nEnemy HP:" + Enemy.getHealth());
          }
        }
      }
    }


    String restart = JOptionPane.showInputDialog("Start over?\n 1)Yes\n 2) No\n ");
    exit = Integer.parseInt(restart);
    }
  }
}
