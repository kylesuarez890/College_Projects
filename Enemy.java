//Name: Kyle Suarez
//COP3252: Assignment 5
//Enemy Classes
import java.util.Random;

class Enemy
{
  //superclass data
  Random rand = new Random();
  private int health;
  protected String weapon;

  //Access and Mutate functions
  public int getHealth()
  {
    return health;
  }
  public void setHealth(int health)
  {
    this.health = health;
  }
  public String getWeapon()
  {
    return weapon;
  }

  public int fight()        //abstract method to be overwritten by specific enemies
  {return 0;}

  public void takeDamage(int hit)       //conrtols enemy health: must be impplemented in the superclass
  {
    health = health - hit;

    if(health < 0)    //Invalid Damage Exception
    {
      health = 0;
    }
  }

  public static Enemy getRandomEnemy(int choice)
  {
    switch(choice)
    {
      case 0:
        return new Heartless();
      case 1:
        return new Nobody();
      default:
        return new Unversed();
    }
  }

  public String toString()
  {
    return("Enemy");
  }
}

class Heartless extends Enemy
{
    public Heartless()
    {this.weapon = "Shadow claws";}

    public int fight()
    {
      return 5;
    }

    public String toString()
    {
      return("Heartless");
    }
}

class Nobody extends Enemy
{
    public Nobody()
    {this.weapon = "Ethereal blades";}

    public int fight()
    {
      return 10;
    }

    public String toString()
    {
      return("Nobody");
    }
}

class Unversed extends Enemy
{
    public Unversed()
    {this.  weapon = "Void gear";}

    public int fight()
    {
      return 7;
    }

    public String toString()
    {
      return("Unversed");
    }
}
