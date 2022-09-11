package Experiment2;
import Experiment2.*;
import java.util.Scanner;
public class VideoStore extends Video
{ 
    Video[] v = new Video[10];
    static int i=0; 
    String name;
    void addVideo(String name)
    { 
        v[i] = new Video();
        v[i].name = name;
    }

    public void receiveprice() 
    {
    System.out.print("Enter the price for movie " + v[i].name + " :- ");
    Scanner ob = new Scanner(System.in); 
    v[i].videoPrice = ob.nextInt();
    }

    void checkOutVideo(String title)
    { 
        for (int k = 0; k < i; k++)
        {
            if (v[k].name.equalsIgnoreCase(name))
            {
                if (v[k].isCheck()) 
                    { 
                        v[k].rentVideo();
                        System.out.println("Video is rented");
                    } 
                else 
                    {
                        System.out.println("Sorry Video not available");
                    }
            }
        }
    }

    void returnVideo(String name)
    {
        if (i == 0)
        {
            System.out.println("You have no video to return");
        }
        for (int k = 0; k < i; k++)
        {
            if (v[k].name.equalsIgnoreCase(name))
            {
                v[k].check = true;
            }
        }
    }

    public void receiveRating()
    {
        for (int j = 0; j < i; j++)
        {
            System.out.print("Enter the rating for movie " + v[j].name + " :- ");
            Scanner ob = new Scanner(System.in);
            v[j].rating = ob.nextInt();
        }
    }

    public void listInventory() 
    { 
        if (i == 0)
        {
            System.out.println("No Video in Inventory");
        }
        else
        {
            for (int k = 0; k < i; k++) 
            {
                System.out.println(k + 1 + ". " + v[k].name + " " + " Rating :- " + v[k].rating + " " +
                " Availability :- " + v[k].isCheck() + " " + " Price :- " + v[k].videoPrice+ " " + " Language :- " + v[k].videoLang + " Release year :- " + v[k].releaseDate);
            }
        }
    }

    void receivelanguage()
    {
    System.out.print("Enter the Language for movie " + v[i].name + " :- ");
    Scanner ob = new Scanner(System.in);
    v[i].videoLang = ob.nextLine();
    }

    public void setReleaseDate()
    {
    System.out.print("Enter the Release year for movie " + v[i].name + " :- ");
    Scanner ob = new Scanner(System.in);
    v[i].releaseDate = ob.nextLine(); i++;
    }

}