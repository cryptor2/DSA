package Experiment2;
import Experiment2.*;
import java.util.Scanner; 
public class Main 
{ 
    public static void main(String[] args) 
    { 
     VideoStore vs = new VideoStore();
    int ch, uCh, aCh;
    String title, choice;
        do
         {
            System.out.println("=========Menu=========");
            System.out.println("\t1. Login as User");
            System.out.println("\t2. Login as Admin");
            System.out.print("Enter Your Choice :-"); 
            Scanner s = new Scanner(System.in);
            ch = s.nextInt(); 
                do 
                {
                     switch (ch) 
                        { 
                            case 1 : {
                                        System.out.println("\t1. List Inventory");
                                        System.out.println("\t2. Rent Video");
                                        System.out.println("\t3. Enter the rating of Video");
                                        System.out.println("\t4. Return Video");
                                         System.out.print("Enter the choice :- ");
                        uCh = s.nextInt();
                switch (uCh) {
                            case 1 : vs.listInventory();
                            case 2 : {
                            vs.listInventory();
                            System.out.print("Enter the video Name you want :- ");
                            title = s.next();
                            vs.checkOutVideo(title);
                            }
                            case 3 : vs.receiveRating(); 
                            case 4 : vs.rentVideo();
                            default : System.out.println("No such Option is available");
                               }    }
                            case 2 : {
                                        System.out.println("\t1. List Inventory");
                                        System.out.println("\t2. Add Video and details");
                                        System.out.print("Enter the choice :- ");
                                        aCh = s.nextInt();
                                        switch (aCh) 
                                        {
                                            case 1 : vs.listInventory();
                                            case 2 : {
                                                    System.out.print("\nEnter the name of Video :- ");
                                                    title = s.next(); 
                                                    vs.addVideo(title);
                                                    vs.receiveprice();
                                                    vs.receivelanguage();
                                                    vs.setReleaseDate();
                                                    System.out.println("Video added successfully!!");
                                                    }
                                            default : System.out.println("Sorry Wrong Choice");
                                         }
                                     }
                        } // end of switch case...
                        System.out.print("\nDo you want to repeat yes/no :- ");
                        choice = s.next();
                } 
            while (choice.equalsIgnoreCase("yes"));
            System.out.print("\nWant to Return to main Menu yes/no :- "); 
            choice = s.next();
        } 
        while (choice.equalsIgnoreCase("yes")); 
    }
 }