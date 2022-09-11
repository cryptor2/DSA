package Experiment2;
 import java.util.Scanner;
public class Video 
{
    String name;
    public boolean check = true;
    int rating, videoPrice; 
    String videoLang, releaseDate;


    public boolean isCheck() 
    {
        return check;
    }

    public String getName() 
    {
        return name;
    }

    public int getRating()
    {
        if (rating > 0) 
        {
            return rating;
        }
        else
        {
        System.out.println(" Rating is not available"); return 0;
        }
    }

    public String getVideoLang()
    {
    return videoLang;
    }
    public int getVideoPrice() 
    {
    if (videoPrice > 0) 
    { 
        return videoPrice;
    } 
    else 
    {
        System.out.println(" price is not available"); return 0;
    }
    }

    public void returnVideo()
    {
        check = true;
        System.out.println("Video is returned successfully");
    }
    public void rentVideo()
    {
        check = false;
    }
}