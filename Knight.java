//Assignment %: Knight Class
//Name: Kyle Suarez
import java.util.Random;
import javax.swing.*;


public class Knight
{
    Random crit = new Random();
    private String name;
    private int health;
    private int weapon;
    private String nweapon;
    private int armor;


    //Default Constructor
    Knight()
    {}

    //Auto-FIll Constructor
    Knight(String name)
    {
      this.name = name;
      this.health = crit.nextInt(100);

    }

    //Name functions
    public void setName(String name)
    {
      this.name = name;
    }
    public String getName()
    {
      return name;
    }

    //health functions
    public void setHealth(int health)
    {
      this.health = health;
    }
    public int getHealth()
    {
      return health;
    }

    //weapon functions
    public void setWeapon(int weapon)
    {
      this.weapon = weapon;
      switch (weapon){
        case 1: nweapon = "Sword & Shield";
                break;
        case 2: nweapon = "Spear";
                break;
        case 3: nweapon = "Longsword";
                break;
        default: nweapon = "Bow & Arrow";
                break;
      }
    }
    public int getWeapon()
    {
      return weapon;
    }
    public String getNWeapon()
    {
      return nweapon;
    }


    //armor functions
    public void setArmor()
    {
      this.armor = crit.nextInt(4) + 1;
    }
    public int getArmor()
    {
      return armor;
    }

    //Attribute Displayer
    public void Display()
    {
      JOptionPane.showMessageDialog(null, "Knight: " + this.name + "\nWeapon: " + this.weapon + "\nHP: " + this.health);
    }

    //Damage Calculator
    public int fight()
    {
      switch (weapon){
        case 1: return crit.nextInt(5) + 5;
        case 2: return crit.nextInt(10) + 3;
        case 3: return crit.nextInt(3) + 7;
        default: return crit.nextInt(20);
      }
    }


}
